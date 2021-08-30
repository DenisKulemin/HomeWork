#ifndef TESTCLASS_H
#define TESTCLASS_H
#include <memory>
#include <iostream>

struct TestPimpl;

class TestClass
{
    public:
        TestClass();
        virtual ~TestClass();

        // Methods for work with TestPimpl->money field
        void changeMoney(int value);
        int getMoney();

    protected:

    private:
        std::shared_ptr<TestPimpl> testClassPimpl;
};

#endif // TESTCLASS_H
