#include <iostream>

using namespace std;

int main()
{
    int my_array [80];
    for (int i = 0; i < 80; i++) {
        *(my_array + i) = rand() % 1000;
    }

    // Check all elements except the last one
    for (int i = 0; i < 79; i++) {
        // Compare with the last array element
        if (*(my_array + i) == *(my_array + 79)) {
            // Print index of such element
            cout << i << endl;
        }
    }

    cin.get();
    return 0;
}
