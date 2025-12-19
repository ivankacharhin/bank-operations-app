#include <iostream>
#include <iomanip>
#include "bank_operation.h"
#include "file_reader.h"
#include "constants.h"

using namespace std;

int main() {
    setlocale(LC_ALL, "Russian"); // или SetConsoleCP(1251)...

    BankOperation* operations[MAX_ROWS]; // Массив указателей
    int count = readData("data.txt", operations);

    cout << "Считано операций: " << count << endl;
    cout << "----------------------------------------------------------------" << endl;

    for (int i = 0; i < count; i++) {
        cout << operations[i]->date.day << "." << operations[i]->date.month << "." << operations[i]->date.year << " | ";
        cout << operations[i]->type << " | ";
        cout << operations[i]->amount << " | ";
        cout << operations[i]->purpose << endl;
    }

    for (int i = 0; i < count; i++) delete operations[i];

    return 0;
}