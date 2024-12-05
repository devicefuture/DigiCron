#!/bin/bash

wasicc -Os \
    -z stack-size=4096 \
    -Wl,--initial-memory=65536 \
    -Wl,--allow-undefined-file=applib/digicron.syms \
    -Wl,--strip-all -lstdc++ \
    apptest/app.cpp -o apptest/app.wasm

xxd -i apptest/app.wasm > apptest/app.wasm.h