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
    // Middle digit is change from 0 to 9
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 80; j++) {
            if (*(my_array + j) / 10 % 10 == i) {
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
