#!/bin/bash

CC=clang

if command -v clang-14 2>&1 /dev/null; then
    CC=clang-14
fi

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
    apptest/app.cpp -o apptest/app.wasm

xxd -i apptest/app.wasm > apptest/app.wasm.h