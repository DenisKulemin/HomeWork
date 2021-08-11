#include <iostream>

using namespace std;

int main()
{
    // Task 1. Answer: x min = 105, x max = 600

    // Task 2. Answer: s = 10

    // Start counter with -1 to add last 0 value.
    int counter = -1;
    int biggest_value = 0;
    int almost_biggest_value = 0;
    int number = -1;

    cout << "Enter numbers: ";
    do {
        cin >> number;
        counter++;
        if (number > biggest_value) {
            almost_biggest_value = biggest_value;
            biggest_value = number;
        }
        else if (number > almost_biggest_value) {
            almost_biggest_value = number;
        }
    } while (number != 0);

    cout << "Enter reference value: ";
    int reference_value = 0;
    cin >> reference_value;

    // Print the report
    cout << "Recieved " << counter << " number(s)." << endl;
    cout << "Recieved reference value: " << reference_value << endl;
    cout << "Calculated reference value: " << biggest_value * almost_biggest_value << endl;
    if (reference_value == (biggest_value * almost_biggest_value)) {
        cout << "Control passed!";
    }
    else {
        cout << "Control not passed!";
    }

    cin.get();
    return 0;
}
