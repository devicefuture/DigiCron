#ifndef DATATYPES_H_
#define DATATYPES_H_

template<typename T> T* store(T value);
template<typename T> T discard(T* itemPtr);

namespace dataTypes {
    template<typename T> struct _ListItem {
        T* valuePtr;
        _ListItem<T>* nextItemPtr;
    };

    template<typename T> class StoredValue {
        public:
            T value;

            StoredValue<T>(T valueToStore);
            ~StoredValue<T>();
    };

    template<typename T> class List {
        public:
            typedef void (*IterationCallback)(T* itemPtr, unsigned int index);
            typedef T* (*MappingFunction)(T* itemPtr, unsigned int index);
            typedef bool (*FilteringFunction)(T* itemPtr, unsigned int index);

            List<T>();
            ~List<T>();

            T* operator[](int index);

            void start();
            T* next();
            unsigned int length();
            void empty();
            unsigned int push(T* valuePtr);
            T* pop();
            unsigned int unshift(T* valuePtr);
            T* shift();
            unsigned int insert(unsigned int index, T* valuePtr);
            T* remove(unsigned int index);
            void set(unsigned int index, T* valuePtr);
            int indexOf(T* valuePtr);
            void forEach(IterationCallback iterationCallback);
            List<T> map(MappingFunction mappingFunction);
            List<T> filter(FilteringFunction filteringFunction);
            List<T> concat(List<T> otherList);

        private:
            _ListItem<T>* _firstItemPtr;
            _ListItem<T>* _currentItemPtr;
            unsigned int _length;

            _ListItem<T>* getItemAtIndex(int index);
            _ListItem<T>* getLastItem();
    };
}

#endif