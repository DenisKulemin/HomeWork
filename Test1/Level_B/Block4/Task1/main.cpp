#include <iostream>

using namespace std;

int main()
{
    cout << "Enter 5 numbers: " << endl;
    int my_array [5];
    int counter = 0;

    for (int i = 0; i < 5; i++) {
        int number;
        cin >> number;
        *(my_array + i) = number;
        int most_signigicant_digit = 0;
        do {
            most_signigicant_digit = number % 10;
            number /= 10;
        } while (number > 0);

        if (most_signigicant_digit == 8) {
            counter++;
        }
    }

    if (counter == 0) {
        cout << "There are no digits starting with 8." << endl;
    }
    else if (counter == 1) {
        cout << "There is one digit starting with 8." << endl;
    }
    else {
        cout << "There are " << counter << " digits starting with 8." << endl;
    }

    cin.get();
    return 0;
}
