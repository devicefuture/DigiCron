#!/bin/bash

wasicc -Os \
    -z stack-size=4096 \
    -Wl,--initial-memory=65536 \
    -Wl,--allow-undefined-file=api.syms \
    -Wl,--strip-all -nostdlib \
    app.cpp -o app.wasm

xxd -i app.wasm > app.wasm.h