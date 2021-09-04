#include <iostream>
#include <clocale>
#include <fstream>
#include <string>
#include <codecvt>
#include <chrono>

using namespace std;

// Using chrono to get information about execution time for part of code
// that works with files.

int main()
{
    // Write data with default locale
    string filename = "written_data_default_locale.txt";

    auto process_start = chrono::steady_clock::now();
    ofstream ofile;
    ofile.open(filename);
    cout << "Started writing data" << endl;
    ofile << "New line in file, just for checking.\n";
    ofile.close();
    auto process_end = chrono::steady_clock::now();
    cout << "Finished writing data" << endl;
    chrono::duration<double> process_duration = process_end - process_start;
    cout << "It takes: " << process_duration.count() << " second(s)." << endl << endl;

    process_start = chrono::steady_clock::now();
    ifstream ifile;
    ifile.open(filename);
    if (!ifile) {
        cerr << "Cannot read the file " << filename << endl;
    }
    char ch;
    // Read the data
    while (ifile.get(ch)) {
        cout << ch;
    }
    cout << endl;
    ifile.close();
    process_end = chrono::steady_clock::now();
    process_duration = process_end - process_start;
    wcout << "It takes: " << process_duration.count() << " second(s)." << endl << endl;

    // Write data with russian characters in binary file
    filename = "written_data_russian_locale_binary.dat";
    setlocale(LC_ALL, "Russian");
    process_start = chrono::steady_clock::now();
    ofile.open(filename, ios::binary);
    cout << "Started writing data" << endl;

    wstring line1 = L"Пример записи данных на русском языке.\n";
    int line_size = line1.size();
    ofile.write(reinterpret_cast<char*>(&line_size), sizeof(int));
    ofile.write(reinterpret_cast<char*>(&line1[0]), line_size*sizeof(wchar_t));

    wstring line2 = L"New line in file, just for checking.\n";
    line_size = line2.size();
    ofile.write(reinterpret_cast<char*>(&line_size), sizeof(int));
    ofile.write(reinterpret_cast<char*>(&line2[0]), line_size*sizeof(wchar_t));

    wstring line3 = L"Последняя строка.\n";
    line_size = line3.size();
    ofile.write(reinterpret_cast<char*>(&line_size), sizeof(int));
    ofile.write(reinterpret_cast<char*>(&line3[0]), line_size*sizeof(wchar_t));

    ofile.close();
    process_end = chrono::steady_clock::now();
    cout << "Finished writing data" << endl << endl;
    process_duration = process_end - process_start;
    cout << "It takes: " << process_duration.count() << " second(s)." << endl << endl;

    process_start = chrono::steady_clock::now();
    ifile.open(filename, ios::binary);
    if (!ifile) {
        cerr << "Cannot read the file " << filename << endl;
    }

    // Using .eof() doesn't help to finish reading after the last line
    // and I get one more duplicate of the last line before while cycle stopped.
    // So I decided to use comparison of the last and current position with .good()
    ifile.seekg(0, ios::end);
    int pos_end_of_file = ifile.tellg();
    ifile.seekg(0, ios::beg);
    int cur_pos_of_file = 0;

    wstring line = L"";
    while (ifile.good() and cur_pos_of_file != pos_end_of_file) {
        ifile.read(reinterpret_cast<char*>(&line_size), sizeof(int));
        line.resize(line_size, ' ');
        ifile.read(reinterpret_cast<char*>(&line[0]), line_size*sizeof(wchar_t));
        wcout << line;
        cur_pos_of_file = ifile.tellg();
    }
    wcout << endl;
    ifile.close();
    process_end = chrono::steady_clock::now();
    process_duration = process_end - process_start;
    cout << "It takes: " << process_duration.count() << " second(s)." << endl << endl;


    // Write data with russian sybmols
    filename = "written_data_russain_locale.txt";

    process_start = chrono::steady_clock::now();
    wofstream wofile;
    wofile.open(filename);
    cout << "Started writing data" << endl;
    wofile << L"Пример записи данных на русском языке.\n";
    wofile << L"New line in file, just for checking.\n";
    wofile << L"Последняя строка.\n";
    wofile.close();
    process_end = chrono::steady_clock::now();
    cout << "Finished writing data" << endl << endl;
    process_duration = process_end - process_start;
    cout << "It takes: " << process_duration.count() << " second(s)." << endl << endl;

    process_start = chrono::steady_clock::now();
    wifstream wifile;
    wifile.open(filename);
    if (!wifile) {
        cerr << "Cannot read the file " << filename << endl;
    }
    wchar_t wch;
    // Read the data
    while (wifile.get(wch)) {
        wcout << wch;
    }
    wcout << endl;
    wifile.close();
    process_end = chrono::steady_clock::now();
    process_duration = process_end - process_start;
    wcout << "It takes: " << process_duration.count() << " second(s)." << endl << endl;

    cin.get();
    return 0;
}


