#include "TestClass.h"

using namespace std;

int main()
{
    // Create new pointer on class TestCLass that has link on TestPimpl struct
    shared_ptr<TestClass> new_ptr = make_shared<TestClass>();

    // Check initial value
    cout << "In your wallet " << new_ptr->getMoney() << " bucks." << endl;

    // Change the value
    new_ptr->changeMoney(11);

    // Check new value
    cout << "In your wallet " << new_ptr->getMoney() << " bucks." << endl;

    return 0;
}
