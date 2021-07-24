#include <iostream>

using namespace std;

int main()
{
    cout << "Making all calculation one by one (with new values)." << endl;
    int x = 10, y = 12, z = 3;
    cout << "Initial values: x = 10, y = 12, z = 3" << endl << endl;

    x += y - x++ * z;
    cout << "Result of 'x += y - x++ * z' is equal " << x << endl;
    cout << "Now x = " << x << " y = " << y << " z = " << z << endl << endl;


    z = --x - y * 5;
    cout << "Result of 'z = --x - y * 5' is equal " << z << endl;
    cout << "Now x = " << x << " y = " << y << " z = " << z << endl << endl;

    y /= x++ + z * 5;
    cout << "Result of 'y /= x++ + z * 5' is equal " << y << endl ;
    cout << "Now x = " << x << " y = " << y << " z = " << z << endl << endl;


    z = x++ + y * 5;
    cout << "Result of 'z = x++ + y * 5' is equal " << z << endl ;
    cout << "Now x = " << x << " y = " << y << " z = " << z << endl << endl;


    x = y - x++ * z;
    cout << "Result of 'x = y - x++ * z' is equal " << x << endl ;
    cout << "Now x = " << x << " y = " << y << " z = " << z << endl << endl;


    cout << "Using the same initial values for each calculations." << endl;
    x = 10, y = 12, z = 3;
    cout << "Initial values: x = 10, y = 12, z = 3" << endl << endl;

    x += y - x++ * z;
    cout << "Result of 'x += y - x++ * z' is equal " << x << endl;
    x = 10;
    cout << "Back x to " << x << endl << endl;

    z = --x - y * 5;
    cout << "Result of 'z = --x - y * 5' is equal " << z << endl;
    z = 3;
    cout << "Back z to " << z << endl << endl;

    y /= x++ + z * 5;
    cout << "Result of 'y /= x++ + z * 5' is equal " << y << endl ;
    y = 12;
    cout << "Back y to " << y << endl << endl;

    z = x++ + y * 5;
    cout << "Result of 'z = x++ + y * 5' is equal " << z << endl ;
    z = 3;
    cout << "Back z to " << z << endl << endl;

    x = y - x++ * z;
    cout << "Result of 'x = y - x++ * z' is equal " << x << endl ;
    x = 10;
    cout << "Back x to " << x << endl << endl;

    cin.get();
    return 0;
}
