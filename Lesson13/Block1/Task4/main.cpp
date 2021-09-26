#include <iostream>
#include <MyVector.h>
#include <chrono>

using namespace std;

void compare_time(int number);

int main()
{
    // According to tests average time per iteration for
    compare_time(100); // comb - 1.985e-05 sec, bubble - 4.108e-05 sec
    compare_time(1000); // comb - 0.000320 sec, bubble - 0.002959 sec
    compare_time(10000); // comb - 0.00230 sec, bubble - 0.16858 sec
    compare_time(100000); // comb - 0.033 sec, bubble - 24.012 sec
    cin.get();
    return 0;
}

void compare_time(int number)
{
    MyVector<int> my_vector1;
    MyVector<int> my_vector2;
    chrono::duration<double> process_duration_comb;
    chrono::duration<double> process_duration_bubble;

    cout << "Find average sort time for " << number << " items (10 iterations)" << endl;
    for (int iteration = 0; iteration < 10; ++iteration) {
        for (int i = 0; i < number; ++i) {
            int new_item = rand() % 1000;
            my_vector1.my_push_back(new_item);
            my_vector2.my_push_back(new_item);
        }
        auto process_start_comb = chrono::steady_clock::now();
        my_vector1.sortComb();
        auto process_end_comb = chrono::steady_clock::now();
        process_duration_comb += (process_end_comb - process_start_comb);
        auto process_start_bubble = chrono::steady_clock::now();
        my_vector2.sortBubble();
        auto process_end_bubble = chrono::steady_clock::now();
        process_duration_bubble += (process_end_bubble - process_start_bubble);
    cout << "Full time for comb sorting: " << process_duration_comb.count() << " seconds." << endl;
    cout << "Full time for bubble sorting: " << process_duration_bubble.count() << " seconds." << endl;
        my_vector1.erase();
        my_vector2.erase();
    }

    cout << "Full time for comb sorting of " << number << " items: " << process_duration_comb.count() <<
        " seconds. Average " << process_duration_comb.count() / 10 << " seconds." << endl;
    cout << "Full time for bubble sorting of " << number << " items: " << process_duration_bubble.count() <<
        " seconds. Average " << process_duration_bubble.count() / 10 << " seconds." << endl;
}
