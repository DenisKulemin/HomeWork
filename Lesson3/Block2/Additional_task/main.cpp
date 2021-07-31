#include <iostream>

using namespace std;

double area(double);

double area(double, double);

double area(double, double, double);

int main()
{
    double a = 2;
    cout << "A cube with side " << a << " has a surface area equal to " << area(a) << endl;
    double h = 3;
    cout << "A regular quadrangular prism with side " << a << " and hight " << h
    <<  " has a surface area equal to " << area(a, h) << endl;
    double b = 3;
    double c = 4;
    cout << "A rectangular parallelepiped with sides " << a << ", " << b << ", and " << c
    << " has a surface area equal to " << area(a, b, c) << endl;

    return 0;
}

double area(double a) {
    return 6 * a * a;
}

double area(double a, double h) {
    return 2 * a * a + 4 * a * h;
}

double area(double a, double b, double c) {
    return 2 * a * b + 2 * b * c + 2 * a * c;
}
