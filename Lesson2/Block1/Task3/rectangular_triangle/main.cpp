#include <iostream>
#include <cmath>

using namespace std;

int main()
{

    int triangle_base = 0, triangle_height = 0;
    cout << "Enter the length of base and height of rectangular triangle (between 1 and 10): " << endl;
    cin >> triangle_base >> triangle_height;

    if (triangle_base <= 0 || triangle_height <= 0) {
        cout << "Triangle base and height should be bigger than 0!";
        return 1;
    }

    // using positions of symbols
    // y1 = 1, y2= triangle_height; x1 = 1, x2 = triangle_base.
    // Means tan =(y2 - y1) / (x2 - x1). Use double to make the line smooth
    double step = (double) (triangle_base - 1) / (double) (triangle_height - 1);

    // using round() to add symbol if more than 0.5 symbol should be added
    for (int i = 1; i <= triangle_height; i++) {

        // skip first, last and several lines before second * might be added
        if (i != 1 and i >= round(1 / step + 1) and i != triangle_height) {

            // drawing triangle from top to bottom.
            // position for the first symbol in line = (y2 - i) * step + 1
            int first_tr_pos = round((triangle_height - i) * step) + 1;

            for (int k = 1; k < first_tr_pos; k++) {
                cout << " ";
            }
            // the first triangle symbol in line = first_tr_pos
            cout << "*";
            // empty space on the segment [first_tr_pos + 1, triangle_base - 1]
            for (int k = first_tr_pos + 1; k < triangle_base; k++) {
                cout << " ";
            }
            // the last position in line
            cout << "*" << endl;
        }
        else if (i <= round(1 / step + 1)) {
            for (int k = 1; k < triangle_base; k++) {
                cout << " ";
            }
            cout << "*" << endl;
        }
        else {
            for (int k = 1; k <= triangle_base; k++) {
                cout << "*";
            }
            cout << endl;
        }
    }

    cin.get();
    return 0;
}
