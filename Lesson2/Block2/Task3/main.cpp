#include <iostream>

using namespace std;

double average_of_three_numbers(int, int, int);

int main()
{
    int number1 = 0, number2 = 0, number3 = 0;
    cout << "Enter three numbers: " << endl;
    cin >> number1 >> number2 >> number3;
    cout << "The average: " << average_of_three_numbers(number1, number2, number3) << endl;
    cin.get();
    return 0;
}

double average_of_three_numbers(int number1, int number2, int number3) {

    return (double) (number1 + number2 + number3) / 3;
}
