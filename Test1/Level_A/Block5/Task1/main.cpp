#include <iostream>

using namespace std;

int main()
{
    cout << "Enter your string: ";
    char *your_string = new char [80];
    int counter = 0;

    // Read input from the console. String's end - line separator \n
    for (int i = 0; i < 80; i++) {
        char new_char = getchar();
        if (new_char == '\n') {
            break;
        }
        *(your_string + i) = new_char;

        if (isdigit(new_char)) {
            counter++;
        }
    }

    if (counter == 0) {
        cout << "There aren't any digits in this string!!!";
    }
    else if (counter == 1) {
        cout << "There is only one digit in this string!";
    }
    else {
        cout << "There are " << counter << " digits in this string!";
    }

    delete your_string;

    cin.get();
    return 0;
}
