#include <iostream>

using namespace std;

int main()
{
    double numb1, numb2, numb3;
    cout << "Enter three numbers (separate them with space): " << endl;
    cin >> numb1 >> numb2 >> numb3;

    if (numb1 == numb2 or numb2 == numb3 or numb1 == numb3) {
        cout << "Error!!!";
    }
    else if ((numb1 > numb2 and numb3 > numb1) or
             (numb1 < numb2 and numb3 < numb1)) {
        cout << "Middle value is " << numb1;
    }
    else if ((numb2 > numb1 and numb3 > numb2) or
             (numb2 < numb1 and numb3 < numb2)) {
        cout << "Middle value is " << numb2;
    }
    else if ((numb3 > numb1 and numb2 > numb3) or
             (numb3 < numb1 and numb2 < numb3)) {
        cout << "Middle value is " << numb3;
    }

    cin.get();
    return 0;
}
