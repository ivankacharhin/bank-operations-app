#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <windows.h>
#include <vector>
#include "bank_operation.h"
#include "file_reader.h"
#include "constants.h"

using namespace std;

void printHeader() {
    cout << endl;
    cout << left << setw(12) << "Äàòà"
        << setw(10) << "Âðåìÿ"
        << setw(10) << "Âèä"
        << setw(15) << "Ñ÷åò"
        << setw(12) << "Ñóììà"
        << "Íàçíà÷åíèå" << endl;

    cout << setfill('-') << setw(80) << "-" << setfill(' ') << endl;
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    cout << "================================================" << endl;
    cout << "ÇÀÄÀÍÈÅ: ÎÁÐÀÁÎÒÊÀ ÁÀÍÊÎÂÑÊÈÕ ÎÏÅÐÀÖÈÉ" << endl;
    cout << "Âàðèàíò: 7" << endl;

    cout << "Àâòîð: [Êî÷åðãèí Èâàí]" << endl;
    cout << "Ãðóïïà: [25ÏÈíæ1ä]" << endl;

    cout << "================================================" << endl;

    BankOperation* operations[MAX_ROWS];

    int count = readData("data.txt", operations);

    if (count == 0) {
        cout << "Ôàéë ïóñò èëè íå íàéäåí!" << endl;
        return 0;
    }

    printHeader();

    for (int i = 0; i < count; i++) {
        cout << left
            << setfill('0') << setw(2) << operations[i]->date.day << "."
            << setw(2) << operations[i]->date.month << "."
            << left << setfill(' ') << setw(6) << operations[i]->date.year

            << setfill('0') << setw(2) << operations[i]->time.hour << ":"
            << setw(2) << operations[i]->time.minute << ":"
            << left << setfill(' ') << setw(4) << operations[i]->time.second

            << setw(10) << operations[i]->type
            << setw(15) << operations[i]->account
            << setw(12) << fixed << setprecision(2) << operations[i]->amount
            << operations[i]->purpose << endl;
    }

    cout << setfill('-') << setw(80) << "-" << setfill(' ') << endl;
    cout << "Âñåãî çàïèñåé: " << count << endl;


    for (int i = 0; i < count; i++) {
        delete operations[i];
    }

    return 0;
}