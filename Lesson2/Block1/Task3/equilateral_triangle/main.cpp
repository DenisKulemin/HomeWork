#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int triangle_base, triangle_height;
    cout << "Enter the length of base and height of equilateral triangle (between 1 and 10): " << endl;
    cin >> triangle_base >> triangle_height;

    if (triangle_base <= 0 || triangle_height <= 0) {
        cout << "Triangle base and height should be bigger than 0!";
        return 1;
    }

    // using positions of symbols
    // y1 = 1, y2= triangle_height; x1 = 1, x2 = triangle_base / 2.
    // Means tan =(y2 - y1) / (x2 - x1). Use double to make the line smooth
    double step = ((double) (triangle_base) / 2 - 1) / ((double) triangle_height  - 1);

    for (int i = 1; i <= triangle_height; i++) {

        // skip first, last and several lines before second * might be added
        if (i != 1 and i >= round(1 / step + 1) and i != triangle_height) {

            // position for the first symbol in line = (y2 - i) * step + 1
            int start_tr_pos = round((triangle_height - i) * step + 1);
            for (int k = 1; k < start_tr_pos; k++) {
                cout << " ";
            }
            // the first triangle symbol in line = first_tr_pos
            cout << "*";
            // empty space on the segment [first_tr_pos + 1, triangle_base - start_tr_pos]
            for (int k = start_tr_pos + 1;
            k <  triangle_base - start_tr_pos + 1; k++) {
                cout << " ";
            }
            cout << "*" << endl;
        }
        else if (i <= round(1 / step + 1)) {
            for (int k = 0; k < (double) triangle_base / 2 - 1; k++)
                cout << " ";

            // print triangle's top above the middle of the triangle's base
            if (triangle_base % 2 == 0) {
                cout << "**";
            }
            else {
                cout << "*";
            }
            cout << endl;
        }
        else {
            for (int j = 0; j < triangle_base; j++) {
                cout << "*";
            }
            cout << endl;
        }
    }

    cin.get();
    return 0;
}
