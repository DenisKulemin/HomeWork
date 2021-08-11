#include <iostream>

using namespace std;

int main()
{
    int my_array [80];
    for (int i = 0; i < 80; i++) {
        *(my_array + i) = rand() % 1000;
        cout << i << " " << *(my_array + i) << endl;
    }

    int biggest_mul = 0;
    int index = 0;

    // Check all elements except the last one
    for (int i = 0; i < 79; i++) {
        // Compare multiplication result for two closest indexes with current value
        if (*(my_array + i) * *(my_array + i + 1) > biggest_mul) {
            index = i;
            biggest_mul = *(my_array + i) * *(my_array + i + 1);
        }
    }

    cout << "Numbers with indexes " << index << " and " << index + 1
        << " have the biggest multiplication result." << endl;

    cin.get();
    return 0;
}
