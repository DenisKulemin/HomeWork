#include <iostream>

using namespace std;

int main()
{
    cout << "Enter number of clients: " << endl;
    int number_of_clients = 0;
    cin >> number_of_clients;

    if (number_of_clients <= 0) {
        cout << "The number of clients should be bigger than 0!";
        return 1;
    }

    int number_of_paths = 1;
    do {

        if (number_of_clients == 1) {
            break;
        }
        number_of_paths *= number_of_clients;
        number_of_clients--;

    } while (number_of_clients > 1);

    if (number_of_paths == 1) {
        cout << "There is only one way to deliver goods!";
    }
    else {
        cout << "There are " << number_of_paths << " ways to deliver goods!";
    }
    cin.get();
    return 0;
}
