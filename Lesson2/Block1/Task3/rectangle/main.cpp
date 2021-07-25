#include <iostream>

using namespace std;

int main()
{
    int rectangle_length = 0, rectangle_width = 0;
    cout << "Enter the length and width of rectangle (between 1 and 10): " << endl;
    cin >> rectangle_length >> rectangle_width;

    if (rectangle_length <= 0 || rectangle_width <= 0) {
        cout << "Rectangle's parameters should be bigger than 0";
        return 1;
    }

    // using positions of symbols (the first symbol - 1, the last - rectangle_width)
    for (int i = 1; i <= rectangle_width; i++) {
        if (i != 1 and i != rectangle_width) {
            cout << "*";
            // empty space inside start position - 2 and finish position - rectangle_length - 1
            for (int j = 2; j <= rectangle_length - 1; j++) {
                cout << " ";
            }
            cout << "*" << endl;
        }
        else {
            for (int j = 1; j <= rectangle_length; j++) {
                cout << "*";
            }
            cout << endl;
        }
    }

    cin.get();
    return 0;
}
