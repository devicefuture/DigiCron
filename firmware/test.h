#ifndef TEST_H_
#define TEST_H_

namespace test {
    class TestClass {
        public:
            TestClass(unsigned int seed);
            TestClass();

            unsigned int add(unsigned int value, unsigned int value2);
            void bools(bool a, bool b, bool c);
            unsigned int nextRandomNumber();

        private:
            unsigned int _counter = 0;
    };
}

#endif