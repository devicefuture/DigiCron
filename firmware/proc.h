#ifndef PROC_H_
#define PROC_H_

namespace proc {
    class Process {
        public:
            bool isRunning();

        private:
            bool _running = true;
    };
}

#endif