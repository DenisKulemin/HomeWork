#include <iostream>

using namespace std;

bool logical_conjunction(bool, bool);

bool logical_disjunction(bool, bool);

bool exclusive_disjunction(bool, bool);

int bitwise_and(int, int);

int bitwise_or(int, int);

int bitwise_xor(int, int);

int main()
{
    // There aren't functions for NOT operations, as they require only one parameter
    cout << logical_conjunction(1, 'd') << endl;
    cout << logical_conjunction(11, 0) << endl;
    cout << logical_conjunction(0, 0) << endl;
    cout << logical_disjunction(1, 'd') << endl;
    cout << logical_disjunction(11, 0) << endl;
    cout << logical_disjunction(0, 0) << endl;
    cout << exclusive_disjunction(1, 'd') << endl;
    cout << exclusive_disjunction(11, 0) << endl;
    cout << exclusive_disjunction(0, 0) << endl;
    cout << bitwise_and(15, 7) << endl;
    cout << bitwise_and(15, 8) << endl;
    cout << bitwise_and(15, 0) << endl;
    cout << bitwise_or(15, 7) << endl;
    cout << bitwise_or(15, 8) << endl;
    cout << bitwise_or(15, 0) << endl;
    cout << bitwise_xor(15, 7) << endl;
    cout << bitwise_xor(15, 8) << endl;
    cout << bitwise_xor(15, 0) << endl;
    return 0;
}

bool logical_conjunction(bool a, bool b) {
    return a && b;
}

bool logical_disjunction(bool a, bool b) {
    return a || b;
}

bool exclusive_disjunction(bool a, bool b) {
    return (a || b) && !(a && b);
}

int bitwise_and(int a, int b) {
    return a & b;
}

int bitwise_or(int a, int b) {
    return a | b;
}

int bitwise_xor(int a, int b) {
    return a ^ b;
}
