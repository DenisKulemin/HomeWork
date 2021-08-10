#include <iostream>
#include <string>
using namespace std;

int main()
{
    typedef unsigned int unint;

    enum charColor {
        red, green, blue
    };

    struct furniture {
        string name;
        unint quantity;
        charColor color;
    };

    union roomParameters {
        double area;
        unint windowsNumber;
    };

    // Describe my room
    roomParameters my_room;
    my_room.area = 18.9;
    cout << "My room's area is equal " << my_room.area << endl;

    furniture my_chairs;
    my_chairs.name = "My beautiful chairs";
    my_chairs.quantity = 3;
    my_chairs.color = red;

    cout << "In my room we can find: " << endl;
    cout << "- " << my_chairs.name << ". I have " << my_chairs.quantity << " of them."
        << "Their color has index " << my_chairs.color << " in my color list." << endl;


    return 0;
}
