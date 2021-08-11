#include <iostream>
#include <cstring>
#include <fstream>

using namespace std;

int main()
{
    ifstream input_file("colors_input.csv");
    ofstream output_file("colors_output.csv");
    char buff [12];
    input_file.getline(buff, 12);

    do {
        // 0 - for red, 1 - for green, and 2 - for blue
        int color_index = 2;
        char red_index [4] = "000";
        char green_index [4] = "000";
        char blue_index [4] = "000";
        int char_position = strlen(buff) - 1;
        // Check each color in line
        for (int i = color_index; i >= 0; i--) {
            // Check each digit for this color
            for (int j = 2; j >= 0; j--) {
                // Check char from the line
                if (char_position < 0) {
                    break;
                }

                // Replace initial 0 chars with chars from the file
                if (isdigit(*(buff + char_position)) and i == 2) {
                    *(blue_index + j) = *(buff + char_position);
                }
                else if (isdigit(*(buff + char_position)) and i == 1) {
                    *(green_index + j) = *(buff + char_position);
                }
                else if (isdigit(*(buff + char_position)) and i == 0) {
                    *(red_index + j) = *(buff + char_position);
                }
                else {
                    break;
                }
                char_position--;
            }
            char_position--;
        }

        // Write color value to the file.
        output_file << to_string(atoi(red_index) * 256 * 256 + atoi(green_index) * 256 + atoi(blue_index)) << endl;
        } while (input_file.getline(buff, 11));

    input_file.close();
    output_file.close();
    cin.get();
    return 0;
}
