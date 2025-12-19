#include <iostream>
#include <fstream>
#include <string>
#include "file_reader.h"

using namespace std;

int readData(const char* filename, BankOperation* data[]) {
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Ошибка: не удалось открыть файл " << filename << endl;
        return 0;
    }

    int count = 0;
    string dateStr, timeStr;

    while (count < MAX_ROWS && !file.eof()) {
        BankOperation* op = new BankOperation();
        
        if (!(file >> dateStr >> timeStr >> op->type >> op->account >> op->amount)) {
            delete op;
            break;
        }

        getline(file >> ws, op->purpose);

        sscanf(dateStr.c_str(), "%d.%d.%d", &op->date.day, &op->date.month, &op->date.year);
        sscanf(timeStr.c_str(), "%d:%d:%d", &op->time.hour, &op->time.minute, &op->time.second);

        data[count] = op;
        count++;
    }

    file.close();
    return count;
}