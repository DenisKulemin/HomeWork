#include <iostream>

using namespace std;

void convert_to_new_notation(int, int);

int main()
{
    // 1) i will have 1 and 2 values. Result will be 6 + 5 = 11.

    int number = 0, notation = 0;
    cout << "Enter number (should be > 1) and notation (should be > 1 and <= 9): " << endl;
    cin >> number >> notation;

    if (number <= 1 || notation <= 1) {
        cout << "Your number and notation should be bigger than 1!";
        return 1;
    }

    convert_to_new_notation(number, notation);

    cin.get();
    return 0;
}

void convert_to_new_notation(int n, int a) {

    if (n < a) {
        cout << n;
    }
    else {
        convert_to_new_notation(n / a, a);
        cout << n % a;
    }
}
