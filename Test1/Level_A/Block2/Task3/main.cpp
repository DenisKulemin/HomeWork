#include <iostream>

using namespace std;

int main()
{
    // Task 1. Answer: s = 1030

    // Task 2. Answer: s = 4

    // Start counter with -1 to add last 0 value.
    int counter = -1;
    int max_value = 0;
    int number = -1;

    cout << "Enter numbers: ";
    do {
        cin >> number;
        counter++;
        if (number > max_value) {
            max_value = number;
        }
    } while (number != 0);

    cout << "Enter reference value: ";
    int reference_value = 0;
    cin >> reference_value;

    // Print the report
    cout << "Recieved " << counter << " number(s)." << endl;
    cout << "Recieved reference value: " << reference_value << endl;
    cout << "Calculated reference value: " << max_value / 10 << endl;
    if (reference_value == (max_value / 10)) {
        cout << "Control passed!";
    }
    else {
        cout << "Control not passed!";
    }

    cin.get();
    return 0;
}
