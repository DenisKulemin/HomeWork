#include <iostream>

using namespace std;

int main()
{
    cout << "Enter 5 numbers: " << endl;
    int my_array [5];
    int counter = 0;

    for (int i = 0; i < 5; i++) {
        cin >> *(my_array + i);
        if (*(my_array + i) % 10 == 8 and *(my_array + i) % 3 == 0) {
            counter++;
        }
    }

    if (counter == 0) {
        cout << "There are no digits ending in 8 and multiples of 3." << endl;
    }
    else if (counter == 1) {
        cout << "There is one digit ending in 8 and multiples of 3." << endl;
    }
    else {
        cout << "There are " << counter << " digits ending in 8 and multiples of 3." << endl;
    }

    cin.get();
    return 0;
}
