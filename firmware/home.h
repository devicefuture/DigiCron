#ifndef HOME_H_
#define HOME_H_

#include "proc.h"
#include "ui.h"

namespace home {
    extern proc::Process homeProcess;

    class HomeScreen : public ui::Screen {
        public:
            HomeScreen() : ui::Screen() {
                ownerProcess = &homeProcess;
            }

            void update() override;
            void handleEvent(ui::Event event) override;

        private:
            unsigned int _mode = 0;
            bool _buttonIsDown = false;
    };

    extern HomeScreen homeScreen;
}

#endif