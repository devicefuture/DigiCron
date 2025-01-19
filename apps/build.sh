#!/bin/bash

APP=$1
CC=clang

if command -v clang-14 2>&1 /dev/null; then
    CC=clang-14
fi

echo "Building \`$APP\` using \`$CC\`..."

mkdir -p apps/$APP/build

$CC \
    -Oz \
    --target=wasm32 \
    -z stack-size=16384 \
    -fno-rtti \
    -nostdlib \
    -mexec-model=reactor \
    -Wl,--initial-memory=65536 \
    -Wl,--allow-undefined-file=applib/digicron.syms \
    -Wl,--strip-all \
    -Wl,--no-entry \
    -Wl,--export=__heap_base \
    -Wl,--export=__wasm_call_ctors \
    -Wl,-error-limit=0 \
    apps/$APP/*.cpp applib/digicron-stdlib.cpp -o apps/$APP/build/app.wasm

xxd -i apps/$APP/build/app.wasm > apps/$APP/build/app.wasm.h