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
        }
        next_char = getchar();
    }

    int word_size = 1000000;
    int start_word = 0;
    int new_word_size = 0;
    int start_new_word = 0;

    for (int i = 0; i < string_len; i++) {
        // If char is not space - it's a part of word
        if (!isspace(*(my_string + i))) {
            new_word_size++;
        }
        else {
            // If new word is not empty and it's size less then current min -
            // add information about new min word.
            if (new_word_size and new_word_size < word_size) {
                word_size = new_word_size;
                start_word = start_new_word;
                start_new_word += (new_word_size + 1);
                new_word_size = 0;

            }
            // Else - move start index to the end of new word and clear new word
            else {
                start_new_word += (new_word_size + 1);
                new_word_size = 0;
            }
        }
    }

    cout << "The sortest word in string: ";
    for (int i = 0; i < word_size; i++) {
        cout << *(my_string + start_word + i);
    }

    cin.get();
    return 0;
}
