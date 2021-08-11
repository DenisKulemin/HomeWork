#include <iostream>

using namespace std;

void convert_to_new_notation(char *, int, int);

int main()
{
    // 1) Result will be 654321.

    int number = 0, notation = 0;
    // code_line to convert numbers to alpha-numeric values
    char *code_line = "0123456789abcdefghij";
    cout << "Enter number (should be > 1) and notation (should be > 1 and <= 20): " << endl;
    cin >> number >> notation;

    if (number <= 1 || notation <= 1) {
        cout << "Your number and notation should be bigger than 1!";
        return 1;
    }

    convert_to_new_notation(code_line, number, notation);

    cin.get();
    return 0;
}

void convert_to_new_notation(char *code_line, int n, int a) {

    if (n < a) {
        cout << *(code_line + n);
    }
    else {
        convert_to_new_notation(code_line, n / a, a);
        cout << *(code_line + n % a);
    }
}
