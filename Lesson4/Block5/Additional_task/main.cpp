#include <iostream>
//#define PRODUCTION 10
#define DEVELOPMENT 1

using namespace std;

int main()
{

    #ifdef PRODUCTION
        int a = 1;
        cout << "Product version." << endl;
    #elif DEVELOPMENT
        cout << "Dev version." << endl;
    #endif

    #ifdef DEVELOPMENT
        int a = 0;
        cout << "Dev version." << endl;
    #elif PRODUCTION
        cout << "Product version." << endl;
    #endif

    cout << "The variable a is equal to " << a << endl;
    return 0;
}


