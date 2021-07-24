#include <iostream>

using namespace std;

int main()
{
    double first_number, second_number, third_number;
    cout << "Enter three numbers (separate them with space): " << endl;
    cin >> first_number >> second_number >> third_number;

    double average3 = (first_number + second_number + third_number) / 3;
    cout << "Average of " << first_number << ", " << second_number << ", and "
    << third_number << " is " << average3 << endl;

    cin.get();
    return 0;
}
