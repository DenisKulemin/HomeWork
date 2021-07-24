#include <iostream>

using namespace std;

int main()
{
    float salary;
    cout << "Enter your salary: ";
    cin >> salary;
    float seniority;
    cout << "How many years do you work here? " << endl;
    cin >> seniority;
    float bonus;

    if (seniority < 5) {
        bonus = 0.1;
    }
    else if (seniority < 10) {
        bonus = 0.15;
    }
    else if (seniority < 15) {
        bonus = 0.25;
    }
    else if (seniority < 20) {
        bonus = 0.35;
    }
    else if (seniority < 25) {
        bonus = 0.45;
    }
    else {
        bonus = 0.5;
    }

    cout << "Your bonus is " << bonus * 100 << "% of your salary!" << endl;
    cout << "That's " << salary * bonus << endl;

    cin.get();
    return 0;
}
