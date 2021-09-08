#include <iostream>
#include <iterator>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    string i_filename;
    string o_filename;
    cout << "Enter filenames for input file and output file: " << endl;
    cin >> i_filename >> o_filename;

    ifstream ifile(i_filename);
    ofstream ofile(o_filename);
    // Stop coping if met not int value in file (in 1.txt in line #6)
    copy(istream_iterator<int>(ifile), istream_iterator<int>(), ostream_iterator<int>(ofile, "\n"));

    cout << "Hello world!" << endl;
    return 0;
}
