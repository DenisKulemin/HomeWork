#include <iostream>
#include <typeinfo>
#include <limits>
using namespace std;

int main()
{
    cout << "Bool: min value is " << numeric_limits<bool>::min()
    << " max  value is " << numeric_limits<bool>::max() << endl << endl;

	cout << "Signed char: min value is " << (int) numeric_limits<signed char>::min()
	<< " max value is " << (int) numeric_limits<signed char>::max() << endl;

	cout << "Unsigned char: min value is " << (int) numeric_limits<unsigned char>::min()
	<< " max value is " << (int) numeric_limits<unsigned char>::max() << endl << endl;

	cout << "Signed short: min value is " << numeric_limits<signed short>::min()
	<< " max value is " << numeric_limits<signed short>::max() << endl;

    cout << "Unsigned short: min value is " << numeric_limits<unsigned short>::min()
	<< " max value is " << numeric_limits<unsigned short>::max() << endl << endl;

	cout << "Signed int: min value is " << numeric_limits<signed int>::min()
	<< " max value is " << numeric_limits<signed int>::max() << endl;

	cout << "Unigned int: min value is " << numeric_limits<unsigned int>::min()
	<< " max value is " << numeric_limits<unsigned int>::max() << endl << endl;

	cout << "Signed long long: min value is " << numeric_limits<signed long long>::min()
	<< " max value is " << numeric_limits<signed long long>::max() << endl;

	cout << "Unsigned long long: min value is " << numeric_limits<unsigned long long>::min()
	<< " max value is " << numeric_limits<unsigned long long>::max() << endl << endl;

	cout << "Float: min value is " << numeric_limits<float>::min()
	<< " max value is " << numeric_limits<float>::max() << endl << endl;

	cout << "Double: min value is " << numeric_limits<double>::min()
	<< " max value is " << numeric_limits<double>::max() << endl;

    cin.get();
    return 0;
}
