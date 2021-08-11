#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    // 1) `else` part related to the third `if`.
    // That means programm doesn't reply if the first or the second condition is wrong.
    // But they all should be. x = 1, y = 1

    // 2)  We can combine two conditions into one with OR operator.
    // We can also check if multiplication of this two numbers is even.
    cout << "Enter two coordinates (x and y): ";
    double x = 0.0, y = 0.0;
    cin >> x >> y;

    if (y >= -1 and y <= sin(x) and y >= x - 1) {
        cout << "This coordinate belongs the area!";
    }
    else {
        cout << "This coordinate doesn't belong the area!";
    }

    cin.get();
    return 0;
}
