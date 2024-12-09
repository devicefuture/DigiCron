typedef unsigned long size_t;

extern "C" {
    void* malloc(size_t size) {
        static void* next = (void*)0x1000;
        void* current = next;

        next = (void*)((size_t)next + size);

        return current;
    }
}

void* operator new(size_t size) {
    return malloc(size);
}

void* operator new[](size_t size) {
    return malloc(size);
}