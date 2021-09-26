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

    // Delete all items and show information about an empty list
    for (int i = 0; i < 4; ++i) {
        cout << "Delete first and last items (iteration # " << i + 1 << ")"<< endl;
        my_vector.deleteFirstItem();
        my_vector.deleteLastItem();
        my_vector.printAllItems();
    }

    cout << "Print added values in different possitions of the list" << endl;
    for (int i=0; i < 5; ++i) {
        int new_value = rand() % 100;
        cout << i << " " << new_value << endl;
        if (i < 2) {
            my_vector.insertItem(new_value, 0);
        }
        else {
            my_vector.insertItem(new_value, i - 2);
        }
    }
    my_vector.printAllItems();

    cout << "Print list after deleting values from different possitions" << endl;
    for (int i = 3; i > 0; --i) {
        if (i % 2 == 0) {
            cout << "Delete first item" << endl;
            my_vector.deleteItem(0);
            my_vector.printAllItems();
            cout << "Delete last item" << endl;
            my_vector.deleteItem(my_vector.getFirstAvailableItemIndex() - 1);
            my_vector.printAllItems();
        }
        else {
            cout << "Delete i / 2 item" << endl;
            my_vector.deleteItem(i / 2);
            my_vector.printAllItems();
        }
    }

    cin.get();
    return 0;
}
