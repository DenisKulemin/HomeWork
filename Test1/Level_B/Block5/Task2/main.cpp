#include <iostream>

using namespace std;

int main()
{
    cout << "Enter your string: ";
    char *your_string = new char [80]();

    // Counter for words starting with a
    int counter = 0;

    // Read input from the console. String's end - line separator \n
    for (int i = 0; i < 80; i++) {
        char new_char = getchar();
        if (new_char == '\n') {
            if (i == 0 ) {
                cout << "You enter empty string!";
                return 1;
            }
            break;
        }
        *(your_string + i) = new_char;
    }

    // Sentence can start with a symbol and doesn't have a space before.
    if (*your_string == 'a' or *your_string == 'A') {counter++;}
    // Check all symbols except the last one
    for (int i = 0; i < 79; i++) {
        if (isspace(*(your_string + i)) and
            (*(your_string + i + 1) == 'a' or *(your_string + i + 1) == 'A')) {
            counter++;
        }
    }

    if (counter == 0) {
        cout << "There aren't words starting with 'a' or 'A' symbol in this sentence!" << endl;
    }
    else if (counter == 1 ) {
        cout << "There is only one word starting with 'a' or 'A' symbol in this sentence!";
    }
    else {
        cout << "There are " << counter << " words starting with 'a' or 'A' symbol in this sentence!";
    }

    delete your_string;

    cin.get();
    return 0;
}
