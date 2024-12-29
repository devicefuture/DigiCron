#ifndef PROC_H_
#define PROC_H_

#include <wasm3.h>
#include <Arduino.h>

#include "datatypes.h"

namespace proc {
    const unsigned int WASM_STACK_SLOTS = 4096;
    const unsigned int NATIVE_STACK_SIZE = 32 * 1024;

    enum ProcessType {
        SYSTEM,
        WASM
    };

    enum WasmError {
        NONE,
        INIT_FAILURE,
        PARSE_FAILURE,
        LOAD_FAILURE,
        RUN_FAILURE
    };

    extern unsigned int pidCounter;

    class Process {
        public:
            typedef void (*StopCallback)(Process* self);

            StopCallback onStop = nullptr;

            Process();

            ~Process();

            virtual ProcessType getType() {return ProcessType::SYSTEM;}
            unsigned int getPid();
            virtual bool isRunning();
            virtual void step();
            virtual void stop();

        protected:
            unsigned int _pid;
            bool _running = true;
    };

    class WasmProcess : public Process {
        public:
            WasmProcess(char* code, unsigned int codeSize);

            ProcessType getType() override {return ProcessType::WASM;}
            bool isRunning() override;
            void step() override;
            void stop() override;
            template<typename ...Args> void callVoid(const char* name, Args... args);
            template<typename T, typename ...Args> T call(const char* name, T defaultValue, Args... args);
            template<typename ...Args> void callVoidOn(void* instance, const char* name, Args... args);
            template<typename T, typename ...Args> T callOn(void* instance, const char* name, T defaultValue, Args... args);

        protected:
            IM3Environment _environment;
            IM3Runtime _runtime;
            IM3Module _module;
            IM3Function _stepFunction;
            WasmError _error = WasmError::NONE;
    };

    extern dataTypes::List<Process> processes;

    void stepProcesses();
}

#endif