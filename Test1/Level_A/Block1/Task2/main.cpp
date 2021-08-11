#include <iostream>

using namespace std;

int main()
{
    // 1) `else` part related to the second `if`.
    // That means program doesn't care if number `a` is even.
    // If a = 8, b = 9, there is no massage from the program.

    // 2) Add `else` to the first `if` instead `else` in the second `if`.

    // 3) We can combine two conditions into one with OR operator.
    // We can also check if multiplication of this two numbers is even.
    cout << "Enter two numbers: ";
    int a = 0, b = 0;
    cin >> a >> b;

    if (a % 2 == 0 or b % 2 == 0) {
        cout << "There is a even number!";
    }
    else {
        cout << "There aren't even numbers!";
    }

    cin.get();
    return 0;
}
