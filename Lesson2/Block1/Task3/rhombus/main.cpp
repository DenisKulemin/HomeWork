#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int diag_1 = 0, diag_2 = 0;
    cout << "Enter the length of diagonals of a rhombus (between 1 and 10): " << endl;
    cin >> diag_1 >> diag_2;

    if (diag_1 <= 0 || diag_2 <= 0) {
        cout << "Rhoumbus diagonals should be bigger than 0!";
        return 1;
    }

    // using positions of symbols (solution for triangle).
    // diag_1 = triangle_base, diag_2 / 2 = triangle_height.
    int triangle_base = diag_1;
    double triangle_height = (double) diag_2 / 2;
    // y1 = 1, y2 = diag_1; x1 = 1, x2 = diag_2 / 2.
    // Means tan =(y2 - y1) / (x2 - x1).
    double step = ((double) triangle_base / 2 - 1) / ((double) triangle_height - 1);

    // this cycle create values for printing rhoumbus
    // sign should be 1 for printing the top and -1 for printing the bottom of the rhoumbus
    for (int sign = 1; sign > -2; sign -= 2) {

        // initiate the values for the printing cycle.
        int initial_val = sign;
        int limit = triangle_height;

        // if sign = -1, the cycle will print a mirror image of the part where sign = 1
        if (sign < 0) {
            initial_val = triangle_height * sign;
            limit = sign;
        }

        for (int i = initial_val; i <= limit; i++) {

            // skip first/last and several lines before second * might be added
            if (i != sign and i * sign >= round(1 / step + 1)) {

                // position for the first symbol in line = (y2 - i) * step + 1
                int start_tr_pos = round((triangle_height - i * sign) * step + 1);
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
            else if (i * sign <= round(1 / step + 1)) {
                for (int k = 0; k < (double) triangle_base / 2 - 1; k++)
                    cout << " ";
                if (triangle_base % 2 == 0) {
                    cout << "**";
                }
                else {
                    cout << "*";
                }
                cout << endl;
            }
        }
    }

    cin.get();
    return 0;
}
