#ifndef API_H_
#define API_H_

#include <stdint.h>

#define WASM_EXPORT extern "C" __attribute__((used)) __attribute__((visibility ("default")))
#define WASM_EXPORT_AS(name) WASM_EXPORT __attribute__((export_name(name)))
#define WASM_IMPORT(module, name) __attribute__((import_module(module))) __attribute__((import_name(name)))
#define WASM_CONSTRUCTOR __attribute__((constructor))

void setup();

extern "C" {

WASM_IMPORT("digicron", "log") void dc_log(uint8_t* text, uint8_t length);

void _start() {
    setup();
}

}

#endif