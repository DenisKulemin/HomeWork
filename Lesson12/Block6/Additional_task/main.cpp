#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void print_vector(vector<int> &v);

void fill_vector_with_rand_int(vector<int> &v, int st_pos, int fin_pos, int from = 0, int to = RAND_MAX);

void print_common_elem(vector<int> &v_1, vector<int> &v_2);

void print_even_elem(vector<int> &v);

int main()
{
    // Create vector # 1 and fill it with random values from 10 to 50
    vector<int> vec_1;
    vec_1.resize(13);
    fill_vector_with_rand_int(vec_1, 0, 13, 10, 50);

    // Create vector # 2 and fill it with random values from 10 to 50
    vector<int> vec_2;
    vec_2.resize(20);
    fill_vector_with_rand_int(vec_2, 0, 20, 10, 50);

    cout << "Print vector # 1" << endl;
    print_vector(vec_1);

    cout << "Print vector # 2" << endl;
    print_vector(vec_2);

    print_common_elem(vec_1, vec_2);

    // Print even elements from vectors
    cout << endl << "Print even element from vector #1: " << endl;
    print_even_elem(vec_1);
    cout << endl << "Print even element from vector #2: " << endl;
    print_even_elem(vec_2);

    // Reverse vector #1 and print it
    reverse(vec_1.begin(), vec_1.end());
    print_vector(vec_1);

    // Reverse vector #2 and print it
    reverse(vec_2.begin(), vec_2.end());
    print_vector(vec_2);

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
    if (to <= from or to == 0) {
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

void print_common_elem(vector<int> &v_1, vector<int> &v_2) {
    vector<int>::iterator it;
    cout << "Find elements from vector #1 in vector #2:" << endl;
    for (auto el : v_1) {
        it = find(v_2.begin(), v_2.end(), el);
        if (it != v_2.end()) {
            cout << "This element from vector #1 was found in #2: " << el << endl;
        }
    }
    cout << "Find elements from vector #2 in vector #1:" << endl;
    for (auto el : v_2) {
        it = find(v_1.begin(), v_1.end(), el);
        if (it != v_1.end()) {
            cout << "This element from vector #2 was found in #1: " << el << endl;
        }
    }
}

void print_even_elem(vector<int> &v) {
    int vec_size = v.size();
    for (int i = 0; i < vec_size; i++) {
        if (i % 2 == 0) {
            cout << "Element # " << i << " is " << v[i] << endl;
        }
    }
}
