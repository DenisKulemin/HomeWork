#include <iostream>

using namespace std;

int main()
{
    int my_array [80];
    for (int i = 0; i < 80; i++) {
        *(my_array + i) = 100 + rand() % 899;
    }

    int new_array [80];
    int new_array_index = 0;
    // the biggest sum for 999 is equal 27
    for (int i = 0; i < 27; i++) {
        for (int j = 0; j < 80; j++) {
            if ((*(my_array + j) / 100 +
                 *(my_array + j) / 10 % 10 +
                 *(my_array + j) % 10) == i) {
                *(new_array + new_array_index) = *(my_array + j);
                new_array_index++;
            }
        }
    }

    for (int i = 0; i < 80; i++) {
        cout << *(new_array + i) << endl;
    }

    cin.get();
    return 0;
}
