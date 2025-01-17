#ifndef TEST_H_
#define TEST_H_

namespace test {
    class TestClass {
        public:
            TestClass(unsigned int seed);
            TestClass();

            ~TestClass();

            virtual void identify();
            unsigned int add(unsigned int value, unsigned int value2);
            void bools(bool a, bool b, bool c);
            unsigned int nextRandomNumber();

        protected:
            unsigned int _counter = 0;
    };

    class TestSubclass : public TestClass {
        public:
            using TestClass::TestClass;

            void identify() override;
            void subclass();
    };

    void sayHello();
    int add(int a, int b);
}

#endif