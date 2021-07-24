#include <iostream>

using namespace std;

int main()
{
    int number;
    cout << "Enter the number; " << endl;
    cin >> number;
    int temp_number = number >> 1;

    if (number == temp_number << 1) {
        cout << "Number " << number << " is even. The output is based on a binary shift operation.";
    }
    else {
        cout << "Number " << number << " is odd. The output is based on a binary shift operation.";
    }
    cout << endl;

    if (number % 2 == 0) {
        cout << "Number " << number
        << " is even. The output is based on calculating the remainder of division by 2.";
    }
    else {
        cout << "Number " << number
        << " is odd. The output is based on calculating the remainder of division by 2.";
    }

    cin.get();
    return 0;
}
