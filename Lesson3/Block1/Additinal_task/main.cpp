#include <iostream>

using namespace std;

int main()
{
    cout << "Enter your string: ";
    char *your_string = new char [80] { ' ' };
    int string_len = 80;

    // Read input from the console. String's end - line separator \n
    for (int i = 0; i < 80; i++) {
        char new_char = getchar();
        if (new_char == '\n') {
            string_len = i;
            break;
        }
        *(your_string + i) = new_char;
    }

    // Find the first not empty symbol in line
    int first_not_empty_symbol = 0;
    for (int i = 0; i < 80; i++) {
        if (!isspace(*(your_string + i))) {
            first_not_empty_symbol = i;
            break;
        }
    }

    // Find the last not empty symbol in line
    int last_not_empty_symbol = 0;
    for (int i = string_len - 1; i >= 0; i--) {
        if (!isspace(*(your_string + i))) {
            last_not_empty_symbol = i;
            break;
        }
    }

    bool space_flag = false;
    char *new_string = new char [80] { ' ' };
    int new_string_index = 0;

    // Replace all one by one multiple space with only one space symbol
    for (int i = first_not_empty_symbol; i <= last_not_empty_symbol; i++) {
        if (isspace(*(your_string + i)) and !space_flag) {
            space_flag = true;
        }
        else if (isspace(*(your_string + i)) and space_flag) {
            continue;
        }
        else {
            space_flag = false;
        }

        *(new_string + new_string_index) = *(your_string + i);
        new_string_index++;
    }

    // Cut extra chars in array
    char *temp = new char [new_string_index + 1];
    for (int i = 0; i < new_string_index + 1; i++) {
        *(temp + i) = *(new_string + i);
    }
    delete new_string;
    new_string = temp;

    cout << "Original string (using ` to show space): `" << your_string << "`" << endl;
    cout << "New string (using ` to show space): `" << new_string << "`" << endl;
    delete your_string;

    cin.get();
    return 0;
}
