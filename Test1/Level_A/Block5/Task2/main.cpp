#include <iostream>

using namespace std;

int main()
{
    cout << "Enter your string: ";
    char *your_string = new char [80];
    // The number of words is equal number of space + 1
    int counter = 1;

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

        //
        if (isspace(new_char)) {
            counter++;
        }
    }

    if (counter == 1) {
        cout << "There is only one word in this sentence!";
    }
    else {
        cout << "There are " << counter << " words in this sentence!";
    }

    delete your_string;

    cin.get();
    return 0;
}
