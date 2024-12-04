#!/bin/bash

echo "Running API builder..."

export NAMESPACE=
export ENUM=
export CLASS=
export LAST_NAMESPACE_MEMBER=
export HAD_CONSTRUCTOR=false
export TAG_TYPES=

function _closeNamespace {
    if [ "$NAMESPACE" != "" ]; then
        _closeClass

        echo } >> applib/digicron.h
        echo >> applib/digicron.h

        export NAMESPACE=
        export LAST_NAMESPACE_MEMBER=
    fi
}

function namespace {
    _closeNamespace

    export NAMESPACE=$1

    echo namespace $NAMESPACE { >> applib/digicron.h
    echo "#include \"$NAMESPACE.h\"" >> tools/api/_api-includes.h
    echo Including namespace: dc::$NAMESPACE
}

function enum {
    if [ "$LAST_NAMESPACE_MEMBER" != "" ]; then
        echo "" >> applib/digicron.h
    fi

    export LAST_NAMESPACE_MEMBER=$1

    echo "    enum $1 {" >> applib/digicron.h
    echo -n "Including enum: dc::$NAMESPACE::$1 {"

    shift

    while (($#)); do
        echo -n "        $1" >> applib/digicron.h
        echo -n $1

        shift

        if (($#)); then
            echo "," >> applib/digicron.h
            echo -n ", "
        fi
    done

    echo >> applib/digicron.h
    echo "    };" >> applib/digicron.h
    echo "}"
}

function _closeClass {
    if [ "$CLASS" != "" ]; then
        echo "    };" >> applib/digicron.h

        export CLASS=
    fi
}

function class {
    _closeClass

    if [ "$LAST_NAMESPACE_MEMBER" != "" ]; then
        echo "" >> applib/digicron.h
    fi

    export CLASS=$1
    export LAST_NAMESPACE_MEMBER=$1
    export HAD_CONSTRUCTOR=false
    export TAG_TYPES="$TAG_TYPES${NAMESPACE}_$CLASS, "

    (
        echo "    class $CLASS {"
        echo "        private:"
        echo "            _dc_Sid _sid;"
        echo
        echo "        public:"
        echo "            _dc_Sid _getSid() {return _sid;}"
        echo
    ) >> applib/digicron.h

    # echo "template $NAMESPACE::$CLASS* api::getBySid<$NAMESPACE::$CLASS>(api::Type type, api::Sid sid)" >> tools/api/_api-templates.h
    # echo "template api::Sid api::store<$NAMESPACE::$CLASS>(api::Type type, $NAMESPACE::$CLASS* instance)" >> tools/api/_api-templates.h

    echo Including class: dc::$NAMESPACE::$CLASS
}

function method {
    if [ "$INTERNAL_NAME" = "" ]; then
        local INTERNAL_NAME=dc_${NAMESPACE}_${CLASS}_$2
    fi

    name="$2"
    returnType="$1"
    nameAndType="$1 $2"

    if [ "$IN_CONSTRUCTOR" = true ]; then
        nameAndType=$1
    elif [ "$HAD_CONSTRUCTOR" = true ]; then
        echo >> applib/digicron.h

        export HAD_CONSTRUCTOR=false
    fi

    echo -n "            $nameAndType(" >> applib/digicron.h
    echo "    m3ApiRawFunction($INTERNAL_NAME);" >> firmware/_api.h

    echo "m3ApiRawFunction(api::$INTERNAL_NAME) {" >> firmware/_api.cpp

    firmwareArgs=

    if [ "$IN_CONSTRUCTOR" = true ]; then
        passArgs=
        shortReturnType=i

        echo -n "WASM_IMPORT(\"digicron\", \"$INTERNAL_NAME\") _dc_Sid $INTERNAL_NAME(" >> tools/api/_digicron-imports.h
        echo -n "    m3_LinkRawFunction(runtime->modules, MODULE_NAME, \"$INTERNAL_NAME\", \"i(" >> tools/api/_api-linker.h

        shift
    else
        passArgs="this->_sid"

        echo -n "WASM_IMPORT(\"digicron\", \"$INTERNAL_NAME\") $1 $INTERNAL_NAME(_dc_Sid sid" >> tools/api/_digicron-imports.h

        shortReturnType=i

        case "$1" in
            "void")
                shortReturnType=v ;;
        esac

        echo -n "    m3_LinkRawFunction(runtime->modules, MODULE_NAME, \"$INTERNAL_NAME\", \"$shortReturnType(" >> tools/api/_api-linker.h
        echo "    m3ApiGetArg(Sid, _sid)" >> firmware/_api.cpp

        shift
        shift

        if (($#)); then
            echo -n ", " >> tools/api/_digicron-imports.h
            passArgs="$passArgs, "
        fi
    fi

    echo -n "Including class method: $1 dc::$NAMESPACE::$CLASS::$2("

    while (($#)); do
        argType=$1
        internalArgType=$argType
        shortArgType=i
        argName=$2
        internalArgCall=$argName
        firmwareArgType=$internalArgType
        firmwareArgCall=$internalArgCall

        case "$argType" in
            "char*"|"STRING")
                shortArgType=* ;;
        esac

        if [[ "$argType" =~ ^ENUM\  ]]; then
            argType=${argType##ENUM }
            internalArgType=_dc_Enum
            firmwareArgType="unsigned int"
            firmwareArgCall="($argType)$argName"
        fi

        if [[ "$argType" =~ ^CLASS\  ]]; then
            argType=${argType##CLASS }
            internalArgType=_dc_Sid
            internalArgCall="_dc_getClassSid<$argType>(&$argName)"
            firmwareArgType=Sid
            firmwareArgCall="*api::getBySid<$argType>(Type::${NAMESPACE}_$CLASS, $argName)"
        fi

        if [[ "$argType" =~ ^CLASSPTR\  ]]; then
            argType=${argType##CLASSPTR }
            internalArgType=_dc_Sid
            internalArgCall="_dc_getClassSid<$argType>($argName)"
            firmwareArgType=Sid
            firmwareArgCall="api::getBySid<$argType>(Type::${NAMESPACE}_$CLASS, $argName)"
            argType="$argType*"
        fi

        if [ "$argType" = "STRING" ]; then
            argType=_dc_String
            internalArgType=_dc_String
            firmwareArgType="char*"
        fi

        echo -n "$argType $argName" >> applib/digicron.h
        echo -n "$internalArgType $argName" >> tools/api/_digicron-imports.h
        echo -n "$shortArgType" >> tools/api/_api-linker.h
        passArgs="$passArgs$internalArgCall"
        firmwareArgs="$firmwareArgs$firmwareArgCall"
        echo -n "$argType $argName"

        if [ "$firmwareArgType" = "char*" ]; then
            echo "    m3ApiGetArgMem(char*, $argName)" >> firmware/_api.cpp
        else
            echo "    m3ApiGetArg($firmwareArgType, $argName)" >> firmware/_api.cpp
        fi

        shift
        shift

        if (($#)); then
            echo -n ", " >> applib/digicron.h
            echo -n ", " >> tools/api/_digicron-imports.h
            passArgs="$passArgs, "
            firmwareArgs="$firmwareArgs, "
            echo -n ", "
        fi
    done

    if [ "$IN_CONSTRUCTOR" = true ]; then
        echo ") {_sid = $INTERNAL_NAME($passArgs);}" >> applib/digicron.h

        (
            echo "    m3ApiReturnType(Sid)"
            echo
            echo -n "    auto instance = new $NAMESPACE::$CLASS("
        ) >> firmware/_api.cpp
    else
        echo ") {return $INTERNAL_NAME($passArgs);}" >> applib/digicron.h

        if [ "$returnType" != "void" ]; then
            (
                echo "    m3ApiReturnType($returnType)"
                echo
                echo -n "    $returnType result = api::getBySid<$NAMESPACE::$CLASS>(Type::${NAMESPACE}_$CLASS, _sid)->$name("
            ) >> firmware/_api.cpp
        else
            echo >> firmware/_api.cpp
            echo -n "    api::getBySid<$NAMESPACE::$CLASS>(Type::${NAMESPACE}_$CLASS, _sid)->$name(" >> firmware/_api.cpp
        fi
    fi

    echo ");" >> tools/api/_digicron-imports.h
    echo ")\", &$INTERNAL_NAME);" >> tools/api/_api-linker.h
    echo "$firmwareArgs);" >> firmware/_api.cpp
    echo "" >> firmware/_api.cpp
    echo ")"

    if [ "$IN_CONSTRUCTOR" = true ]; then
        echo "    Sid result = api::store<$NAMESPACE::$CLASS>(Type::${NAMESPACE}_$CLASS, instance);" >> firmware/_api.cpp
        echo >> firmware/_api.cpp
    fi

    if [ "$returnType" = "void" ]; then
        echo "    m3ApiSuccess();" >> firmware/_api.cpp
    else
        echo "    m3ApiReturn(result);" >> firmware/_api.cpp
    fi

    echo "}" >> firmware/_api.cpp
    echo >> firmware/_api.cpp

    echo $INTERNAL_NAME >> applib/digicron.syms
}

function constructor {
    if [ "$INTERNAL_NAME" = "" ]; then
        local INTERNAL_NAME=dc_${NAMESPACE}_${CLASS}_new
    fi

    IN_CONSTRUCTOR=true INTERNAL_NAME=$INTERNAL_NAME method $CLASS "$@"

    export HAD_CONSTRUCTOR=true
}

> tools/api/_api-linker.h
> tools/api/_api-includes.h
> tools/api/_api-templates.h
> firmware/_api.cpp
> firmware/_api.h

tee -a tools/api/_api-linker.h > /dev/null << EOF
void api::linkFunctions(IM3Runtime runtime) {
    const char* MODULE_NAME = "digicron";

EOF

tee -a firmware/_api.cpp > /dev/null << EOF
// Autogenerated by \`tools/api/builder.sh\` using declarations from \`tools/api/api.sh\`

#include <Arduino.h>
#include <m3_env.h>

#include "_api.h"
#include "proc.h"
#include "datatypes.h"
// {{ includes }}

dataTypes::List<api::StoredInstance> api::storedInstances;

template<typename T> T* api::getBySid(api::Type type, api::Sid sid) {
    StoredInstance* storedInstance = api::storedInstances[sid];

    if (!storedInstance || storedInstance->type != type) {
        return new T(); // To ensure an object is always referenced
    }

    return (T*)storedInstance->instance;
}

template<typename T> api::Sid api::store(api::Type type, T* instance) {
    auto storedInstance = new StoredInstance();

    storedInstance->type = type;
    storedInstance->instance = instance;

    return api::storedInstances.push(storedInstance);
}

EOF

tee -a firmware/_api.h > /dev/null << EOF
// Autogenerated by \`tools/api/builder.sh\` using declarations from \`tools/api/api.sh\`

#ifndef API_H_
#define API_H_

#include <wasm3.h>

// {{ includes }}

namespace api {
    typedef unsigned int Sid;

    enum Type {/* {{ tagTypes }} */};

    struct StoredInstance {
        Type type;
        void* instance;
    };

    extern dataTypes::List<StoredInstance> storedInstances;

    template<typename T> T* getBySid(Type type, Sid sid);
    template<typename T> Sid store(Type type, T* instance);

EOF

mkdir -p applib

> tools/api/_digicron-imports.h
> applib/digicron.h
> applib/digicron.syms

tee -a applib/digicron.h > /dev/null << EOF
// Autogenerated by \`tools/api/builder.sh\` using declarations from \`tools/api/api.sh\`

#ifndef DIGICRON_H_
#define DIGICRON_H_

#include <stdint.h>

#define WASM_EXPORT extern "C" __attribute__((used)) __attribute__((visibility ("default")))
#define WASM_EXPORT_AS(name) WASM_EXPORT __attribute__((export_name(name)))
#define WASM_IMPORT(module, name) __attribute__((import_module(module))) __attribute__((import_name(name)))
#define WASM_CONSTRUCTOR __attribute__((constructor))

void setup();
void loop();

typedef unsigned int _dc_Enum;
typedef unsigned int _dc_Sid;
typedef char* _dc_String;

extern "C" {

WASM_IMPORT("digicronold", "log") void dc_log(uint8_t* text, uint8_t length);
WASM_IMPORT("digicronold", "stop") void dc_stop();

// {{ imports }}

}

template<typename T> _dc_Sid _dc_getClassSid(T* instance) {
    return instance->_getSid();
}

WASM_EXPORT void _start() {
    setup();
}

WASM_EXPORT void _step() {
    loop();
}

namespace dc {

EOF

# TODO: Make these functions part of full API
echo dc_log >> applib/digicron.syms
echo dc_stop >> applib/digicron.syms

export -f _closeNamespace namespace _closeClass class method constructor

. tools/api/api.sh

_closeNamespace

echo "}" >> tools/api/_api-linker.h

cat tools/api/_api-linker.h >> firmware/_api.cpp

tee -a firmware/_api.h > /dev/null << EOF

    void linkFunctions(IM3Runtime runtime);
}

#endif
EOF

tee -a applib/digicron.h > /dev/null << EOF
}

#endif
EOF

TAG_TYPES=$(echo $TAG_TYPES | sed "s/\(.*\),/\1/")

sed -i -e "\|// {{ includes }}|{r tools/api/_api-includes.h" -e "d}" firmware/_api.cpp
sed -i -e "\|// {{ templates }}|{r tools/api/_api-templates.h" -e "d}" firmware/_api.cpp
sed -i -e "\|// {{ includes }}|{r tools/api/_api-includes.h" -e "d}" firmware/_api.h
sed -i "s|/\* {{ tagTypes }} \*/|$TAG_TYPES|" firmware/_api.h
sed -i -e "\|// {{ imports }}|{r tools/api/_digicron-imports.h" -e "d}" applib/digicron.h