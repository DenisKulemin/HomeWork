#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    // Create 0-size array to avoid code duplication
	int arr_size = 0;
	int *curr_arr = new int [0];
	int user_number = 0;

	do {
        cout << "Enter your number (should be negative if you wanna quit): ";
        cin >> user_number;
        if (user_number < 0) {
            cout << "You enter a negative number. Good bye!" << endl;
            break;
        }
        else if (user_number == 0) {
            cout << "You enter 0. Doing nothing!" << endl;
            continue;
        }
        else {
            // Create temp array with bigger size
            arr_size++;
            int *new_arr = new int [arr_size];

            // Copy values from original array to temp
            for (int i = 0; i < arr_size - 1; i++) {
                *(new_arr + i) = *(curr_arr + i);
            }

            // Add user value as last array element
            *(new_arr + arr_size - 1) = user_number;
            // Delete old and request new memory allocation
            delete curr_arr;
            curr_arr = new int [arr_size];

            // Copy values from temp array to current
            for (int i = 0; i < arr_size; i++) {
                *(curr_arr + i) = *(new_arr + i);
            }
            delete new_arr;
        }
	} while (user_number >= 0);

    delete curr_arr;
    cin.get();
	return 0;
}
