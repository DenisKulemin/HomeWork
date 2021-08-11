#include <iostream>

using namespace std;

void delete_extra_spaces(char *, char *, int);

int main()
{
    cout << "Enter your string: ";
    int string_size = 1;
    int string_len = 0;
    char *your_string = new char [string_size];

    char next_char = getchar();
    // Read input from the console. String's end - line separator \n
    while (next_char != '\n') {
        if (string_len < string_size) {
            *(your_string + string_len) = next_char;
            string_len++;
        }
        else {
            string_size *= 2;
            char *temp_string = new char[string_size];
            for (int i = 0; i < string_len; i++) {
                *(temp_string + i) = *(your_string + i);
            }
            delete your_string;
            your_string = temp_string;
            *(your_string + string_len) = next_char;
            string_len++;
        }
        next_char = getchar();
    }

    char *new_string = new char [string_len];

    delete_extra_spaces(new_string, your_string, string_len);
    cout << new_string << endl;

    delete your_string;
    delete new_string;
    cin.get();
    return 0;
}

void delete_extra_spaces(char *new_string, char *your_string, int your_string_size) {
    int new_string_index = 0;
    bool space_flag = false;

    // Cut all extra space (two and more spaces one by one) and write to a new stirng
    for (int i = 0; i < your_string_size; i++) {

        // If we have space after space
        if (isspace(*(your_string + i)) and space_flag) {continue;}

        // If it is the first space after letters, change space_flag to true, else, false
        space_flag = (isspace(*(your_string + i)) and !space_flag) ? true : false;
        *(new_string + new_string_index) = *(your_string + i);
        new_string_index++;
    }

    // Clear the rest of new string
    for (int i = new_string_index; i < your_string_size; i++) {

        *(new_string + i) = '\0';
    }
}
