#include <iostream>

using namespace std;

int main()
{
    char symbol;
    cout << "Enter your symbol: " << endl;
    cin >> symbol;

    if (symbol == '#') {
        cout << "Finish the programm!";
    }
    else if (isdigit(symbol)) {
        cout << "Ignore the digits.";
    }
    else if (isupper(symbol)) {
        cout << (char) tolower(symbol);
    }
    else if (islower(symbol)) {
        cout << (char) toupper(symbol);
    }

    cin.get();
    return 0;
}
