#include <iostream>

using namespace std;

int main()
{
    cout << "Enter your string: ";
    char *your_string = new char [80];

    // Create array for each symbol's code
    int *symbols_counter = new int [256];
    // Set initial value for each symbol - 0
    for (int i = 0; i < 256; i++) {
        *(symbols_counter + i) = 0;
    }

    // Read input from the console. String's end - line separator \n
    for (int i = 0; i < 80; i++) {
        char new_char = getchar();
        if (new_char == '\n') {
            break;
        }
        *(your_string + i) = new_char;
        // Add +1 to value with index equals symbol's code
        *(symbols_counter + (int) new_char) += 1;
    }

    int biggest_counter_index = 0;
    for (int i = 0; i < 256; i++) {
        if (*(symbols_counter + i) > *(symbols_counter + biggest_counter_index)) {
            biggest_counter_index = i;
        }
    }

    cout << "The most often symbol in your string is " << (char) biggest_counter_index << endl;

    delete your_string;
    delete symbols_counter;

    cin.get();
    return 0;
}
