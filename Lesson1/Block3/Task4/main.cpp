#include <iostream>

using namespace std;

int main()
{
    const double pi = 3.1415926535897932384626433832795;
    double r;
    cout << "Enter the radius of the circle: " << endl;
    cin >> r;
    double circle_square = pi * r * r;
    cout << "The square of the circle is " << circle_square << endl;

    cin.get();
    return 0;
}
