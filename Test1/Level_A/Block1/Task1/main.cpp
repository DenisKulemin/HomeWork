#include <iostream>

using namespace std;

int main()
{
    cout << "Enter your nubmer (from 100 to 999): " << endl;
    int number = 0;
    cin >> number;

    if ((number / 100) % 2 == 0 and
        ((number / 10) % 10) % 2 == 0 and
        (number % 10) % 2 == 0) {
            cout << "Yes! All three digits are even!";
        }
    else {
        cout << "No! Not all digits are even!";
    }

    cin.get();
    return 0;
}
