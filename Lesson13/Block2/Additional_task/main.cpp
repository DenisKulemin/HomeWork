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
    MyForwardListItem<int> *tmp = new_forward_list.getFirstItem();
    cout << tmp->value << endl;
    for (int i = 1; i < 10; ++i) {
        tmp = tmp->nextItem;
        cout << tmp->value << endl;
    }

    cin.get();
    return 0;
}
