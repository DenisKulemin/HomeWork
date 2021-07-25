#include <iostream>

using namespace std;

int main()
{

	int a = 0, b = 0;
	cout << "Enter two numbers: " << endl;
	cin >> a >> b;

	if (a > b) {
        int temp = a;
        a = b;
        b = temp;
	}

	int sum = 0;
	// numbers between a and b belong to the segment [a + 1, b - 1]
	for (int i = a + 1; i < b; i++) {
        sum += i;
        // type the odd numbers between a and b
        if (i % 2 == 1) {
            cout << "Odd number between " << a << " and " << b << ": " << i << endl;
        }
	}
    cout << "The sum of all numbers between "  << a << " and " << b << " is " << sum << endl;

    cin.get();
    return 0;
}
