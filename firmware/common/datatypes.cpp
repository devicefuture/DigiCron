#ifndef DC_COMMON_DATATYPES_CPP_
#define DC_COMMON_DATATYPES_CPP_

#ifndef DIGICRON_H_
    #include "datatypes.h"
#endif

template<typename T> T* store(T value) {
    auto storedValue = new dataTypes::StoredValue<T>(value);

    return &storedValue->value;
}

template<typename T> T discard(T* itemPtr) {
    auto itemValue = *itemPtr;

    free(itemPtr);

    return itemValue;
}

template<typename T> dataTypes::StoredValue<T>::StoredValue(T valueToStore) {
    value = valueToStore;
}

template<typename T> dataTypes::StoredValue<T>::~StoredValue() {}

#ifdef DIGICRON_H_
    dataTypes::String::String(const char* value) {
        while (value[_length] != '\0') {
            _length++;
        }

        _value = (char*)malloc(_length + 1);

        for (unsigned int i = 0; i <= _length; i++) {
            _value[i] = value[i];
        }
    }

    dataTypes::String::String(const dataTypes::String& other) : String(other.c_str()) {}

    dataTypes::String::~String() {
        if (_value) {
            free(_value);
        }
    }

    dataTypes::String& dataTypes::String::operator=(const dataTypes::String& other) {
        if (this == &other) {
            return *this;
        }

        char* otherCstr = other.c_str();

        _length = other.length();
        _value = (char*)malloc(_length + 1);

        for (unsigned int i = 0; i <= _length; i++) {
            _value[i] = otherCstr[i];
        }

        return *this;
    }

    char dataTypes::String::operator[](int index) {
        return charAt(index);
    }

    char* dataTypes::String::c_str() const {
        return _value;
    }

    unsigned int dataTypes::String::length() const {
        return _length;
    }

    char dataTypes::String::charAt(int index) {
        if (!_value || index >= _length) {
            return '\0';
        }

        return _value[index];
    }
#endif

template<typename T> dataTypes::List<T>::List() {
    _firstItemPtr = nullptr;
    _length = 0;
}

template<typename T> dataTypes::List<T>::~List() {
    empty();
}

template<typename T> dataTypes::_ListItem<T>* dataTypes::List<T>::getItemAtIndex(int index) {
    if (!_firstItemPtr) {
        return nullptr;
    }

    if (index < 0) {
        int resolvedIndex = _length + index;

        if (resolvedIndex < 0) {
            return nullptr;
        }

        return getItemAtIndex(resolvedIndex);
    }

    auto currentItemPtr = _firstItemPtr;

    while (index > 0) {
        if (!currentItemPtr) {
            return nullptr;
        }

        currentItemPtr = currentItemPtr->nextItemPtr;
        index--;
    }

    return currentItemPtr;
}

template<typename T> T* dataTypes::List<T>::operator[](int index) {
    auto item = getItemAtIndex(index);

    if (!item) {
        return nullptr;
    }

    return item->valuePtr;
}

template<typename T> dataTypes::_ListItem<T>* dataTypes::List<T>::getLastItem() {
    if (!_firstItemPtr) {
        return nullptr;
    }

    auto currentItemPtr = _firstItemPtr;
    _ListItem<T>* previousItemPtr;

    do {
        previousItemPtr = currentItemPtr;
        currentItemPtr = currentItemPtr->nextItemPtr;
    } while (currentItemPtr);

    return previousItemPtr;
}

template<typename T> void dataTypes::List<T>::start(Iterator* iterator) {
    if (iterator == nullptr) {
        iterator = &_defaultIterator;
    }

    *iterator = _firstItemPtr;
}

template<typename T> T* dataTypes::List<T>::next(Iterator* iterator) {
    if (iterator == nullptr) {
        iterator = &_defaultIterator;
    }

    auto itemPtr = *iterator;

    if (!*iterator) {
        return nullptr;
    }

    *iterator = (*iterator)->nextItemPtr;

    return itemPtr->valuePtr;
}

template<typename T> unsigned int dataTypes::List<T>::length() {
    return _length;
}

template<typename T> void dataTypes::List<T>::empty() {
    if (!_firstItemPtr) {
        return;
    }

    auto currentItemPtr = _firstItemPtr;

    while (currentItemPtr) {
        auto nextItemPtr = currentItemPtr->nextItemPtr;

        delete currentItemPtr;

        currentItemPtr = nextItemPtr;
    }

    _firstItemPtr = nullptr;
    _length = 0;
}

template<typename T> unsigned int dataTypes::List<T>::push(T* valuePtr) {
    auto itemPtr = new _ListItem<T> {
        .valuePtr = valuePtr,
        .nextItemPtr = nullptr
    };

    _length++;

    if (!_firstItemPtr) {
        _firstItemPtr = itemPtr;

        return 1;
    }

    getLastItem()->nextItemPtr = itemPtr;

    return _length;
}

template<typename T> T* dataTypes::List<T>::pop() {
    if (!_firstItemPtr) {
        return nullptr;
    }

    if (!_firstItemPtr->nextItemPtr) {
        auto item = _firstItemPtr;

        _firstItemPtr = nullptr;
        _length--;

        return item->valuePtr;
    }

    auto lastItemPtr = getLastItem();
    auto lastItemValuePtr = lastItemPtr->valuePtr;

    getItemAtIndex(-2)->nextItemPtr = nullptr;
    _length--;

    delete lastItemPtr;

    return lastItemValuePtr;
}

template<typename T> unsigned int dataTypes::List<T>::unshift(T* valuePtr) {
    auto itemPtr = new _ListItem<T> {
        .valuePtr = valuePtr,
        .nextItemPtr = nullptr
    };

    _length++;

    if (!_firstItemPtr) {
        _firstItemPtr = itemPtr;

        return 1;
    }

    auto oldFirstItemPtr = _firstItemPtr;

    _firstItemPtr = itemPtr;

    itemPtr->nextItemPtr = oldFirstItemPtr;

    return _length;
}

template<typename T> T* dataTypes::List<T>::shift() {
    if (!_firstItemPtr) {
        return nullptr;
    }

    _length--;

    auto itemPtr = _firstItemPtr;
    auto itemValuePtr = itemPtr->valuePtr;

    _firstItemPtr = _firstItemPtr->nextItemPtr;

    delete itemPtr;

    return itemValuePtr;
}

template<typename T> unsigned int dataTypes::List<T>::insert(unsigned int index, T* valuePtr) {
    if (index == 0) {
        return unshift(valuePtr);
    }

    if (index == _length) {
        return push(valuePtr);
    }

    auto previousItemPtr = getItemAtIndex(index - 1);

    if (!previousItemPtr) {
        return _length;
    }

    _length++;

    auto itemPtr = new _ListItem<T> {
        .valuePtr = valuePtr,
        .nextItemPtr = previousItemPtr->nextItemPtr
    };

    previousItemPtr->nextItemPtr = itemPtr;

    return _length;
}

template<typename T> T* dataTypes::List<T>::remove(unsigned int index) {
    if (index == 0) {
        return shift();
    }

    if (index == _length - 1) {
        return pop();
    }

    auto previousItemPtr = getItemAtIndex(index - 1);

    if (!previousItemPtr) {
        return nullptr;
    }

    auto itemPtr = previousItemPtr->nextItemPtr;

    if (!itemPtr) {
        return nullptr;
    }

    _length--;

    auto itemValuePtr = itemPtr->valuePtr;
    auto nextItemPtr = itemPtr->nextItemPtr;

    previousItemPtr->nextItemPtr = nextItemPtr;

    delete itemPtr;

    return itemValuePtr;
}

template<typename T> void dataTypes::List<T>::set(unsigned int index, T* valuePtr) {
    auto item = getItemAtIndex(index);

    if (!item) {
        return;
    }

    item->valuePtr = valuePtr;
}

template<typename T> int dataTypes::List<T>::indexOf(T* valuePtr) {
    auto currentItemPtr = _firstItemPtr;
    int index = 0;

    while (currentItemPtr) {
        if (currentItemPtr->valuePtr == valuePtr) {
            return index;
        }

        currentItemPtr = currentItemPtr->nextItemPtr;
        index++;
    }

    return -1;
}

template<typename T> void dataTypes::List<T>::forEach(IterationCallback iterationCallback) {
    auto currentItemPtr = _firstItemPtr;
    unsigned int index = 0;

    while (currentItemPtr) {
        iterationCallback(currentItemPtr->valuePtr, index);

        currentItemPtr = currentItemPtr->nextItemPtr;
        index++;
    }
}

template<typename T> dataTypes::List<T> dataTypes::List<T>::map(MappingFunction mappingFunction) {
    List<T> newList;
    auto currentItemPtr = _firstItemPtr;
    unsigned int index = 0;

    while (currentItemPtr) {
        newList.push(mappingFunction(currentItemPtr->valuePtr, index));

        currentItemPtr = currentItemPtr->nextItemPtr;
        index++;
    }

    return newList;
}

template<typename T> dataTypes::List<T> dataTypes::List<T>::filter(FilteringFunction filteringFunction) {
    List<T> newList;
    auto currentItemPtr = _firstItemPtr;
    unsigned int index = 0;

    while (currentItemPtr) {
        if (filteringFunction(currentItemPtr->valuePtr, index)) {
            newList.push(currentItemPtr->valuePtr);
        }

        currentItemPtr = currentItemPtr->nextItemPtr;
        index++;
    }

    return newList;
}

template<typename T> dataTypes::List<T> dataTypes::List<T>::concat(dataTypes::List<T> otherList) {
    List<T> newList;

    start();

    while (auto itemPtr = next()) {
        newList.push(itemPtr);
    }

    otherList.start();

    while (auto itemPtr = otherList.next()) {
        newList.push(itemPtr);
    }

    return newList;
}

#endif