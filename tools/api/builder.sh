#!/bin/bash

export NAMESPACE=
export ENUM=
export CLASS=
export LAST_NAMESPACE_MEMBER=

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
}

function _closeClass {
    if [ "$CLASS" != "" ]; then
        echo "    };" >> applib/digicron.h

        export CLASS=
    fi
}

function enum {
    if [ "$LAST_NAMESPACE_MEMBER" != "" ]; then
        echo "" >> applib/digicron.h
    fi

    export LAST_NAMESPACE_MEMBER=$1

    echo "    enum $1 {" >> applib/digicron.h

    shift

    while (($#)); do
        echo -n "        $1" >> applib/digicron.h

        shift

        if (($#)); then
            echo "," >> applib/digicron.h
        fi
    done

    echo >> applib/digicron.h
    echo "    };" >> applib/digicron.h
}

function class {
    _closeClass

    if [ "$LAST_NAMESPACE_MEMBER" != "" ]; then
        echo "" >> applib/digicron.h
    fi

    export CLASS=$1
    export LAST_NAMESPACE_MEMBER=$1

    echo "    class $CLASS {" >> applib/digicron.h
    echo "        public:" >> applib/digicron.h
}

function method {
    echo -n "            $1 $2(" >> applib/digicron.h

    shift
    shift

    while (($#)); do
        echo -n "$1 $2" >> applib/digicron.h

        shift
        shift

        if (($#)); then
            echo -n ", " >> applib/digicron.h
        fi
    done

    echo ");" >> applib/digicron.h
}

> firmware/_api.cpp
> firmware/_api.h

mkdir -p applib

> applib/digicron.h
> applib/digicron.syms

tee -a applib/digicron.h > /dev/null << EOF
#ifndef DIGICRON_H_
#define DIGICRON_H_

#include <stdint.h>

#define WASM_EXPORT extern "C" __attribute__((used)) __attribute__((visibility ("default")))
#define WASM_EXPORT_AS(name) WASM_EXPORT __attribute__((export_name(name)))
#define WASM_IMPORT(module, name) __attribute__((import_module(module))) __attribute__((import_name(name)))
#define WASM_CONSTRUCTOR __attribute__((constructor))

void setup();
void loop();

extern "C" {

WASM_IMPORT("digicron", "log") void dc_log(uint8_t* text, uint8_t length);
WASM_IMPORT("digicron", "stop") void dc_stop();

}

WASM_EXPORT void _start() {
    setup();
}

WASM_EXPORT void _step() {
    loop();
}

class String {};

namespace dc {

EOF

export -f _closeNamespace namespace _closeClass class method

. tools/api/api.sh

_closeNamespace

tee -a applib/digicron.h > /dev/null << EOF
}
#endif
EOF