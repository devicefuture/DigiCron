#ifndef PROC_H_
#define PROC_H_

#include <wasm3.h>
#include <Arduino.h>

namespace proc {
    const unsigned int WASM_STACK_SLOTS = 2048;
    const unsigned int NATIVE_STACK_SIZE = 32 * 1024;

    enum WasmError {
        NONE,
        INIT_FAILURE
    };

    extern unsigned int pidCounter;

    class Process {
        public:
            Process();

            unsigned int getPid();
            virtual bool isRunning();

        protected:
            unsigned int _pid;
    };

    class WasmProcess : public Process {
        public:
            WasmProcess(char* code);

            bool isRunning() override;
            void step();

        protected:
            IM3Environment _environment;
            IM3Runtime _runtime;
            WasmError _error = WasmError::NONE;
            bool _running = true;
    };
}

#endif