#ifndef DIGICRON_H_
    #define WASM_EXPORT_AS(name)
#endif

#define _DC_CALLABLE(type, namespace, class, method) WASM_EXPORT_AS("_callable_" #namespace "_" #class "_" #method) inline type _callable_##namespace##_##class##_##method

#define _DC_MAP_TO_METHOD(namespace, class, method, ...) do { \
        if (auto instance = dc::_getBySid<dc::namespace::class>(dc::_Type::namespace##_##class, sid)) { \
            return instance->method(__VA_ARGS__); \
        } \
    } while (0);

_DC_CALLABLE(void, ui, Screen, update)(dc::_Sid sid) {
    _DC_MAP_TO_METHOD(ui, Screen, update);
}

_DC_CALLABLE(void, ui, Screen, handleSimpleEvent)(dc::_Sid sid, dc::ui::EventType eventType) {
    _DC_MAP_TO_METHOD(ui, Screen, handleEvent, (dc::ui::Event) {
        .type = eventType
    });
}

_DC_CALLABLE(void, ui, Screen, handleButtonEvent)(dc::_Sid sid, dc::ui::EventType eventType, dc::input::Button button) {
    _DC_MAP_TO_METHOD(ui, Screen, handleEvent, (dc::ui::Event) {
        .type = eventType,
        .data.button = button
    });
}

_DC_CALLABLE(void, ui, Screen, handleItemEvent)(dc::_Sid sid, dc::ui::EventType eventType, unsigned int index) {
    _DC_MAP_TO_METHOD(ui, Screen, handleEvent, (dc::ui::Event) {
        .type = eventType,
        .data.index = index
    });
}