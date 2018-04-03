#include <cstdio>
#include <iostream>
#include <string>
#include <locale>
#include <codecvt>
#include <fstream>
#include <sstream>
#include <fcntl.h>
#include <io.h>
using namespace std;

// std::wstring readFile(const char* filename)
// {
//     std::wifstream wifs(filename);
//     wifs.imbue(std::locale(std::locale::empty(), new std::codecvt_utf8<wchar_t>));
//     std::wstringstream wss;
//     wss << wifs.rdbuf();
//     return wss.str();
// }

// void read_all_lines(const wchar_t *filename)
// {
//     wifstream wifs;
//     wstring txtline;
//     int c = 0;
//
//     wifs.open(filename);
//     if(!wifs.is_open())
//     {
//         wcerr << L"Unable to open file" << endl;
//         return;
//     }
//     // We are going to read an UTF-8 file
//     wifs.imbue(locale(wifs.getloc(), new codecvt_utf8<wchar_t, 0x10ffff, consume_header>()));
//     while(getline(wifs, txtline))
//         wcout << ++c << L'\t' << txtline << L'\n';
//     wcout << endl;
// }

int main() {
    // const char *filename = "工作表 2-分组名单.csv";
    // wstring id0, id1, id2, name0, name1, name2, title;
    // wifstream wif;
    // wif.open(filename);
    // wif.getline(id0, 256, ',');
    // wcout << id0;

    // std::wstring wstr = readFile("data.csv");
    // std::wcout<<wstr<<std::endl;

    // read_all_lines("data.csv");

    // locale::global(locale(""));
    wstring word;

    cout << "Hello\n";
    wcout << L"好运";
    while (wcin >> word)
        wcout << word << '\n';
    wcout << L"好運n";
    return 0;
}
