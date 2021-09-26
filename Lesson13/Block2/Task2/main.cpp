#include <iostream>
#include "MyForwardList.h"

using namespace std;

int main()
{
    MyForwardList<int> new_forward_list;

    cout << "Print initial values" << endl;
    for (int i = 0; i < 5; ++i) {
        int new_value = rand() % 100;
        cout << new_value << endl;
        new_forward_list.my_push_back(new_value);
        new_forward_list.my_push_front(new_value);
    }

    cout << "Pring added values" << endl;
    new_forward_list.printAllItems();

    cout << "Show items one by one" << endl;
    for (int i = 0; i < 10; ++i) {
        new_forward_list.showItem(i);
    }

    // Delete all items and show information about an empty list
    for (int i=0; i < 11; ++i) {
        cout << "Delete first and last items (iteration # " << i + 1 << ")"<< endl;
        new_forward_list.deleteFirstItem();
        new_forward_list.printAllItems();
    }

    cin.get();
    return 0;
}
