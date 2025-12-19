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
    cout << left << setw(12) << "Дата" 
         << setw(10) << "Время" 
         << setw(10) << "Вид" 
         << setw(15) << "Счет" 
         << setw(12) << "Сумма" 
         << "Назначение" << endl;
    
    cout << setfill('-') << setw(80) << "-" << setfill(' ') << endl;
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    cout << "================================================" << endl;
    cout << "ЗАДАНИЕ: ОБРАБОТКА БАНКОВСКИХ ОПЕРАЦИЙ" << endl;
    cout << "Вариант: 7" << endl;
    cout << "Автор: [Твое Имя] [Твоя Фамилия]" << endl;
    cout << "Группа: [Твоя Группа]" << endl;
    cout << "================================================" << endl;

    BankOperation* operations[MAX_ROWS];

    int count = readData("data.txt", operations);

    if (count == 0) {
        cout << "Файл пуст или не найден!" << endl;
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
    cout << "Всего записей: " << count << endl;

    // Очистка памяти (ВАЖНО для работы с указателями)
    for (int i = 0; i < count; i++) {
        delete operations[i];
    }

    return 0;
}