#pragma once
#include <string>

struct Date {
    int day;
    int month;
    int year;
};

struct Time {
    int hour;
    int minute;
    int second;
};

struct BankOperation {
    Date date;
    Time time;
    std::string type;      // приход или расход
    std::string account;   // номер счета
    double amount;         // сумма
    std::string purpose;   // назначение платежа
};