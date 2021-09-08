#include <iostream>
#include <vector>

using namespace std;

void print_vector(vector<int> &v);

void fill_vector_with_rand_int(vector<int> &v, int st_pos, int fin_pos, int from = 0, int to = RAND_MAX);

int main()
{
    // Create new vector and fill it with random values from 0 to 50
    vector<int> new_vector;
    new_vector.resize(10);
    fill_vector_with_rand_int(new_vector, 0, 10, 0, 50);

    cout << "Print vector" << endl;
    print_vector(new_vector);

    // Increase the size of vector to 100 items, and fill the last 90 items with random values from 0 to 100
    new_vector.resize(100);
    fill_vector_with_rand_int(new_vector, 10, 100, 0, 100);

    cout << "Print new vector" << endl;
    print_vector(new_vector);

    cin.get();
    return 0;
}


void print_vector(vector<int> &v) {
    int vec_size = v.size();
    for (int i = 0; i < vec_size; i++) {
        cout << v[i] << " ";
        if (i % 10 == 9) {
            cout << endl;
        }
    }
    cout << endl << endl;
}

void fill_vector_with_rand_int(vector<int> &v, int st_pos, int fin_pos, int from, int to) {
    if (to <= from) {
        cout << "Your range from " << from << " to " << to << " is wrong." << endl;
        cout << "Finish the function work without any changes.";
    }
    else if (fin_pos < st_pos) {
        cout << "Your possitions for vector " << st_pos << " (start) and "
            << fin_pos << " (finish) are wrong." << endl;
        cout << "Finish the function work without any changes.";
    }
    else {
        for (int i = st_pos; i < fin_pos; i++) {
            v[i] = (from + rand() % (to - from));
        }
    }
}
