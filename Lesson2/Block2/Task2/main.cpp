#include <iostream>

using namespace std;

int Hello(int counter);

int main()
{
    int counter = 0;
    // let's call the function three times
    counter = Hello(counter);
    counter = Hello(counter);
    counter = Hello(counter);
    cout << "The function Hello() was used " << counter << " times." << endl;

    cin.get();
    return 0;
}

int Hello(int counter) {

    counter++;
    cout << "Hello, user!" << endl;
    return counter;
}
