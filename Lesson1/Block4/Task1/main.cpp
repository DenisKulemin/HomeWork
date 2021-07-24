#include <iostream>

using namespace std;

int main()
{
    double a, b, c;
    cout << "Enter the lengths of the triangle sides: " << endl;
    cin >> a >> b >> c;
    if (a >= (b + c) or b >= (a + c) or c >= (a + b)) {
        cout << "Triangle with sides " << a << ", "<< b
        << ", and "<< c << " DOESN'T exist!!!" << endl;
    }
    else {
        cout << "Triangle with sides " << a << ", " << b
        << ", and " << c << " exists!!!";
    }

    cin.get();
    return 0;
}
