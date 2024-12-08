#ifndef UI_H_
#define UI_H_

#include <Arduino.h>

#include "datatypes.h"
#include "input.h"
#include "display.h"
#include "proc.h"

namespace ui {
    const unsigned int SCROLL_DELAY = 1000;
    const unsigned int SCROLL_INTERVAL = 250;
    const unsigned int POPUP_TRANSITION_DURATION = 250;

    template <typename T>
    void defaultCancellationCallback(T* self);

    enum EventType {
        BUTTON_DOWN,
        BUTTON_UP
    };

    enum PopupTransitionState {
        NONE,
        OPENING,
        CLOSING
    };

    enum PenMode {
        OFF,
        ON
    };

    struct Event {
        EventType type;
        union {
            input::Button button;
        } data;
    };

    class Icon {
        public:
            char iconData[display::CHAR_COLUMNS];

            void setPixel(unsigned int x, unsigned int y, PenMode value);
    };

    class Screen {
        public:
            proc::Process* ownerProcess = nullptr;
            bool canGoHome = true;

            char displayData[display::DATA_SIZE];

            Screen();
            Screen(proc::Process* process);

            void clear();
            void setPosition(unsigned int column, unsigned int row);
            void setPixel(unsigned int x, unsigned int y, PenMode value);
            void print(char c);
            void print(char* chars);
            void print(String string);
            void print(Icon icon);
            void printf(String format, ...);
            void printRepeated(String string, unsigned int times);
            void scroll(String string, unsigned int maxLength = display::COLUMNS);
            void resetScroll();
            void rect(unsigned int x1, unsigned int y1, unsigned int x2, unsigned int y2, PenMode value);
            void filledRect(unsigned int x1, unsigned int y1, unsigned int x2, unsigned int y2, PenMode value);

            virtual void open(bool urgent = false);
            virtual void close();
            virtual void swapWith(Screen* currentScreen);

            virtual void update() {}
            virtual void handleEvent(Event event) {}

            virtual void _update();
            virtual void _handleEvent(Event event);

        protected:
            unsigned int _currentPosition = 0;
            unsigned long _scrollStartTime = 0;
    };

    class Menu : public Screen {
        public:
            typedef void (*CancellationCallback)(Menu* self);
            typedef void (*SelectionCallback)(Menu* self, unsigned int selectedIndex);

            dataTypes::List<String> items;

            CancellationCallback onCancel = defaultCancellationCallback<Menu>;
            SelectionCallback onSelect = nullptr;

            Menu() : Screen() {};

            Menu(dataTypes::List<String> menuItems) : Screen() {
                items = menuItems;
            }

            virtual void open(bool urgent = false) override;

            void update() override;
            void handleEvent(Event event) override;

        protected:
            unsigned int _currentIndex = 0;
            unsigned int _scrollPosition = 0;
    };

    class ContextualMenu : public Menu {
        public:
            String title;

            ContextualMenu(String menuTitle) : Menu() {
                title = menuTitle;
            }

            void update() override;
    };

    class Popup : public Screen {
        public:
            void open(bool urgent = false) override;
            void close() override;

            void _update() override;
            void _handleEvent(Event event) override;

        protected:
            PopupTransitionState _transitionState = PopupTransitionState::NONE;
            unsigned long _transitionEndsAt = 0;
    };

    extern input::Button lastButton;
    extern Screen* currentScreen;
    extern proc::Process* foregroundProcess;
    extern proc::Process* lastNonHomeProcess;
    extern dataTypes::List<Screen> screenStack;

    Screen* determineCurrentScreen();
    void renderCurrentScreen();
}

#include "common/ui.h"

#endif