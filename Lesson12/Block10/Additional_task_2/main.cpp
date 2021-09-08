#include <iostream>
#include <iterator>
#include <list>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
    cout << "Enter strings:" << endl;
    // Something goes wrong if use cin without std::
    list<string> list_of_strings(istream_iterator<string>(std::cin), istream_iterator<string>());

    cout << "Print list's elements:" << endl;
    copy(list_of_strings.begin(), list_of_strings.end(), ostream_iterator<string>(cout, "\n "));
    cout << "Hello world!" << endl;

    return 0;
}
