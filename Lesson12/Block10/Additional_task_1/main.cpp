#include <iostream>
#include <iterator>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
    cout << "Enter strings:" << endl;
    // Something goes wrong if use cin without std::
    vector<string> vec(istream_iterator<string>(std::cin), istream_iterator<string>());

    cout << "Print vector's elements:" << endl;
    copy(vec.begin(), vec.end(), ostream_iterator<string>(cout, "\n "));
    cout << "Hello world!" << endl;
    return 0;
}
