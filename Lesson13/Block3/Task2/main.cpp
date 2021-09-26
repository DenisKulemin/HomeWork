#include <iostream>
#include <MyList.h>

using namespace std;

int main()
{
    MyList<int> new_list;
    cout << "Print initial values" << endl;
    for (int i = 0; i < 4; ++i) {
        int new_value = rand() % 100;
        cout << new_value << endl;
        new_list.my_push_back(new_value);
        new_list.my_push_front(new_value);
    }
    cout << "Print added values" << endl;
    new_list.printAllItems();

    for (int i = 0; i < 3; ++i) {
        cout << "Delete first item" << endl;
        new_list.deleteFirstItem();
        new_list.printAllItems();
        cout << "Delete last item" << endl;
        new_list.deleteLastItem();
        new_list.printAllItems();
    }

    for (int i = 0; i < 5; ++i) {
        new_list.showItem(i);
    }

    cin.get();
    return 0;
}
