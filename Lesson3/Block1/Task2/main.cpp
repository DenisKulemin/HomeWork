#include <iostream>

using namespace std;

int main()
{
    cout << "Enter your string: ";
    char *your_string = new char [80];

    // Create an array for 10 digits. Initial value - 0
    int *counter = new int [10];
    for (int i = 0; i < 10; i++) {
        *(counter + i) = 0;
    }

    // Read input from the console. String's end - line separator \n
    for (int i = 0; i < 80; i++) {
        char new_char = getchar();
        if (new_char == '\n') {
            break;
        }
        *(your_string + i) = new_char;

        // If the symbol is a digit, add 1 to value in counter[int) new_char - (int) '0']
        if (isdigit(new_char)) {
            *(counter + (int) new_char - (int) '0') += 1;
        }
    }

    int highest_freq = 0;
    int highest_freq_number = 0;
    // Find the highest frequency and number
    for (int i = 0; i < 10; i++) {
        if (*(counter +i) > highest_freq) {
            highest_freq = *(counter +i);
            highest_freq_number = i;
        }
    }
    if (highest_freq == 0) {
        cout << "There aren't any digits in this string!!!";
    }
    else {
        cout << highest_freq_number << " has the highest frequency in the string.";
    }

    delete your_string;
    delete counter;
    cin.get();
    return 0;
}
