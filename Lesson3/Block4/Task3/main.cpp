#include <iostream>

using namespace std;

int main()
{
    int string_size = 1;
    char *my_string = new char[string_size];
    cout << "Enter your string: ";
    char next_char = getchar();
    int string_len = 0;
    while (next_char != '\n') {
        if (string_len < string_size) {
            *(my_string + string_len) = next_char;
            string_len++;
        }
        else {
            string_size *= 2;
            char *temp_string = new char[string_size];
            for (int i = 0; i < string_len; i++) {
                *(temp_string + i) = *(my_string + i);
            }
            delete my_string;
            my_string = temp_string;
            *(my_string + string_len) = next_char;
            string_len++;
            cout << "New size " << string_size << endl;
        }
        next_char = getchar();
    }

    cout << "Reversed string: " << endl;
    for (int i = string_len - 1; i >= 0; i--) {
        cout << *(my_string + i);
    }

    cin.get();
    return 0;
}
