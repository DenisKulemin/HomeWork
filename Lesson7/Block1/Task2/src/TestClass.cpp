#include "TestClass.h"

struct TestPimpl {
    int money = 0;
};

TestClass::TestClass() : testClassPimpl (new TestPimpl)
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;
}

TestClass::~TestClass()
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;
}

 void TestClass::changeMoney(int value)
{
    testClassPimpl->money = value;
}

 int TestClass::getMoney()
{
    return testClassPimpl->money;
}

