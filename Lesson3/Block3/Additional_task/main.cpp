#include <iostream>

using namespace std;

int main()
{
    int my_array [7][7] = {
        { 10, 0, 10, 6, 9, 0, 6 },
        { 9, 0, 50, 6, 9, 0, 7 },
        { 5, 3, 25, 6, 9, 0, 8 },
        { 3, 4, 5, 6, 9, 0, 3 },
        { 1, 3, 500, 6, 9, 0, 9 },
        { 6, 11, 5, 6, 9, 0, 1 },
        { 0, 10, -1, 6, 9, 0, 5 }
    };

    // For each column
    for (int column = 0; column < 7; column++) {
        // Start checking from the first and the last element
        int max_el_index = 6;
        int min_el_index = 0;

        // Check not more than n times, where n == number of items in line
        for (int i = 0; i < 7; i++) {
            // Using as initial values the first and last value in list that we check
            int new_max_el_index = max_el_index;
            int new_min_el_index = min_el_index;
            int new_max_el = my_array[max_el_index][column];
            int new_min_el = my_array[min_el_index][column];

            // For each item in line check if this value bigger then last item before max value
            // or less then next value after min value in line.
            for (int line = min_el_index; line < max_el_index + 1; line++) {

                // If value less then example, replace minimum with that
                if (my_array[new_min_el_index][column] > my_array[line][column]) {
                    new_min_el_index = line;
                    new_min_el = my_array[line][column];
                }

                // If value bigger then example, replace maximum with that
                if (my_array[new_max_el_index][column] < my_array[line][column]) {
                    new_max_el_index = line;
                    new_max_el = my_array[line][column];
                }
            }

            if (i > 0) {
                // If max value has the first position in list, it will be swapped
                // when we change min value, so we need to change the index of max value
                if (new_max_el_index == min_el_index) {
                    new_max_el_index = new_min_el_index;
                }

                // Swap the first value in the list with the minimum value
                my_array[new_min_el_index][column] = my_array[min_el_index][column];
                my_array[min_el_index][column] = new_min_el;

                // Swap the last value in the list with the maximum value
                my_array[new_max_el_index][column] = my_array[max_el_index][column];
                my_array[max_el_index][column] = new_max_el;
            }

            // For the first time we just searching for min and max value in list
            else {
                max_el_index = new_max_el_index;
                min_el_index = new_min_el_index;

                // If min value has bigger index then max, switch them.
                if (min_el_index > max_el_index) {
                    int temp = my_array[max_el_index][column];
                    my_array[max_el_index][column] = my_array[min_el_index][column];
                    my_array[min_el_index][column] = temp;
                    int temp_index = max_el_index;
                    max_el_index = min_el_index;
                    min_el_index = temp_index;
                }
            }
            // shrink the range of the list for checking
            max_el_index--;
            min_el_index++;
        }

        // Check if we sort all values
        if (min_el_index == max_el_index or
            max_el_index - min_el_index == 1
            ) {
            break;
        }
    }

    // Print sorted matrix
    for (int i = 0; i < 7; i++) {
        for (int j = 0; j < 7; j++) {
            cout << my_array[i][j] << " ";
        }
        cout << endl;
    }

    cin.get();
    return 0;
}
