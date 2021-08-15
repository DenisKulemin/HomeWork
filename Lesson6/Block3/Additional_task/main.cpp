#include <iostream>
#include "ArrayInt.h"

using namespace std;

int main()
{
    ArrayInt<int, 10> * new_array = new ArrayInt<int, 10>();

    cout << new_array->GetArrayLenght() << " - Lenght of new array." << endl;

    for (int i = 0; i < 10; i++) {
        (*new_array)[i] = rand();
        cout << "Element with index " << i << " is equal " << (*new_array)[i] << endl;
    }

    cout << "Hello world!" << endl;
    return 0;
}
