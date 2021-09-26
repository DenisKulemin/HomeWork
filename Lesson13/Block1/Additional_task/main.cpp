#include <iostream>
#include <MyVector.h>

using namespace std;

int main()
{
    MyVector<int> my_vector;
    cout << "Print initial values" << endl;
    for (int i=0; i < 5; ++i) {
        int new_value = rand() % 100;
        cout << new_value << endl;
        my_vector.my_push_back(new_value);
    }
    cout << "Print all items" << endl;
    my_vector.printAllItems();

    cin.get();
    return 0;
}
