#include <iostream>
#include <map>
#include <clocale>
#include <windows.h>

using namespace std;

void add_word_to_dict(multimap<wstring, wstring> &dict, wstring key = L"", wstring value = L"");

void print_dict(multimap<wstring, wstring> &dict);

void delete_word_from_dict(multimap<wstring, wstring> &dict, wstring key = L"", wstring value = L"");

void print_one_word_from_dict(multimap<wstring, wstring> &dict, wstring key = L"", wstring value = L"");

int main()
{
    multimap<wstring, wstring> en_ru_dict;
    setlocale(LC_ALL, "Russian");
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    wchar_t answer;
    wstring key;
    key.resize(1000);
    wstring value;
    value.resize(1000);

    add_word_to_dict(en_ru_dict, L"apple", L"яблоко");
    add_word_to_dict(en_ru_dict, L"banana", L"банан");
    add_word_to_dict(en_ru_dict, L"tomato", L"томат");
    add_word_to_dict(en_ru_dict, L"tomato", L"помидор");
    wcout << endl;

    // Start session with the user
    while (true) {
        wcout << L"Choose the option." << endl;
        wcout << L"a - add new pair to the dictionary." << endl;
        wcout << L"d - delete pair from the dictionary." << endl;
        wcout << L"p - print pair from the dictionary." << endl;
        wcout << L"s - show all pairs from the dictionary." << endl;
        wcout << L"e - exit the program." << endl;
        wcout << L"Your command: ";
        wcin.get(answer);
        wcin.clear();
        wcin.ignore(10000, L'\n');
        wcout << endl;


        if (answer == L'e') {
            wcout << L"Finish the work with dictionary." << endl;
            break;
        }
        else if (answer == L'a') {
            add_word_to_dict(en_ru_dict);
        }
        else if (answer == L'd') {
            delete_word_from_dict(en_ru_dict);
        }
        else if (answer == L'p') {
            print_one_word_from_dict(en_ru_dict);
        }
        else if (answer == L's') {
            print_dict(en_ru_dict);
        }
        else {
            wcout << L"Unknown command " << answer << endl;
            wcout << L"Try again." << endl;
        }
    }

    cin.get();
    return 0;
}

void add_word_to_dict(multimap<wstring, wstring> &dict, wstring key, wstring value) {
    if (key.empty() and value.empty()) {
        wcout << L"Enter word in English: ";
        getline(wcin, key);
        wcin.ignore(10000, L'\n');
        wcout << L"Enter translation: ";
        getline(wcin, value);
        wcin.ignore(10000, L'\n');
    }

    if (dict.find(key) == dict.end()) {
        dict.insert({key, value});
        wcout << L"Pair - " << key << L":" << value << L" was added to the dictionary." << endl;
    }
    else {
        auto iter = dict.equal_range(key);
        bool flag = false;
        for (auto it = iter.first; it != iter.second; it++) {
            // Check if value already in the dictionary for this key
            if (it->second == value) {
                flag = true;
                break;
            }
        }

        if (!flag) {
            dict.insert({key, value});
            wcout << L"Pair - " << key << L":" << value << L" was added to the dictionary." << endl;
        }
        else {
            wcout << L"Duplicated pair - " << key << L":" << value << L" already in the dictionary." << endl;
        }
    }
}

void print_dict(multimap<wstring, wstring> &dict) {
    wcout << L"Print all pairs from the current dictionary." << endl;
    for (auto el : dict) {
        wcout << L"Word: " << el.first << L". Translation: " << el.second << endl;
    }
}

void delete_word_from_dict(multimap<wstring, wstring> &dict, wstring key, wstring value) {
    if (key.empty()) {
        wcout << L"Enter word in English that you wanna delete: ";
        getline(wcin, key);
        wcin.ignore(10000, L'\n');
    }

    int n_of_words = dict.count(key);
    if (n_of_words == 0) {
        wcout << "There isn't word (" << key << ") that you try to delete in the dictionary." << endl;
    }
    else if (n_of_words == 1) {
        dict.erase(key);
    }
    // TODO finish this part
    else {
        wcout << "There are more than one translation for this word. Would you like to delete all of them or not?" << endl;
        wcout << "Enter a for deleting all translation for this word, or n for deleting only several of them: ";
        wchar_t answer;
        wcin.get(answer);
        wcin.clear();
        wcin.ignore(10000, L'\n');
    }
}

void print_one_word_from_dict(multimap<wstring, wstring> &dict, wstring key, wstring value) {
    if (key.empty()) {
        wcout << L"Enter word in English: ";
        getline(wcin, key);
        wcin.ignore(10000, L'\n');
    }

    if (dict.find(key) == dict.end()) {
        dict.insert({key, value});
        wcout << L"There isn't word " << key << L" in the dictionary." << endl;
    }
    else {
        auto iter = dict.equal_range(key);
        for (auto it = iter.first; it != iter.second; it++) {
            wcout << L"Word: " << it->first << L". Translation: " << it->second << endl;
        }
    }
}
