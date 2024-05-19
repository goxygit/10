#include <iostream>

// Опис структури TDate
struct TDate {
    int Day;
    int Month;
    int Year;
};

// Перевірка, чи є рік високосним
bool isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

// Перевірка, чи є дата правильною
bool isValidDate(TDate date) {
    if (date.Year < 1 || date.Month < 1 || date.Month > 12 || date.Day < 1) {
        return false;
    }
    int daysInMonth[] = { 31, isLeapYear(date.Year) ? 29 : 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    if (date.Day > daysInMonth[date.Month - 1]) {
        return false;
    }
    return true;
}

// Процедура для отримання попередньої дати
void PrevDate(TDate &date) {
    if (!isValidDate(date)) {
        std::cout << "Неправильна дата: " << date.Day << "." << date.Month << "." << date.Year << std::endl;
        return;
    }
    
    // Зменшення дня на 1
    date.Day -= 1;
    
    // Якщо день стає менше 1, то треба змінити місяць і рік
    if (date.Day < 1) {
        date.Month -= 1;
        
        if (date.Month < 1) {
            date.Month = 12;
            date.Year -= 1;
        }
        
        int daysInMonth[] = { 31, isLeapYear(date.Year) ? 29 : 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
        date.Day = daysInMonth[date.Month - 1];
    }
}

int main() {
    TDate dates[5] = {
        {1, 1, 2020},
        {15, 3, 2021},
        {28, 2, 2022},
        {1, 3, 2020},
        {31, 12, 2020}
    };

    std::cout << "Оригінальні дати та їх попередні дати:" << std::endl;
    for (int i = 0; i < 5; ++i) {
        std::cout << "Оригінальна дата: " << dates[i].Day << "." << dates[i].Month << "." << dates[i].Year << std::endl;
        PrevDate(dates[i]);
        std::cout << "Попередня дата: " << dates[i].Day << "." << dates[i].Month << "." << dates[i].Year << std::endl;
    }

    return 0;
}