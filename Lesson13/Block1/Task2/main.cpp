#include <iostream>
#include <MyVector.h>

using namespace std;

int main()
{
    MyVector<int> my_vector;
    cout << "Print initial values" << endl;
    for (int i=0; i < 6; ++i) {
        int new_value = rand() % 100;
        cout << new_value << endl;
        my_vector.my_push_back(new_value);
    }
    cout << "Print all items" << endl;
    my_vector.printAllItems();

    my_vector.sortComb();
    cout << "Print sorted items" << endl;
    my_vector.printAllItems();

    //Delete all items and show information about an empty list
    for (int i = 0; i < 4; ++i) {
        cout << "Delete first and last items (iteration # " << i + 1 << ")"<< endl;
        my_vector.deleteFirstItem();
        my_vector.deleteLastItem();
        my_vector.printAllItems();
    }

    cin.get();
    return 0;
}
