#ifndef _MALTSEV_MATH_H_
#define _MALTSEV_MATH_H_

#include <string>
#include <cctype>
#include <iostream>
using namespace std;

bool UserInput(const std::string& input) {
    if (input.empty()) {
        return false;
    }

    // Проверка на наличие нецифровых символов (кроме возможного минуса в начале)
    size_t start_pos = 0;
    if (input[0] == '-') {
        if (input.size() == 1) { // Строка только "-"
            return false;
        }
        start_pos = 1;
    }

    for (size_t i = start_pos; i < input.size(); ++i) {
        if (!isdigit(input[i])) {
            return false;
        }
    }

    // Дополнительная проверка на переполнение (опционально)
    try {
        int number = std::stoi(input);
        // Если stoi не выбросил исключение, число валидно
    } catch (...) {
        return false;
    }

    return true;
}

void EnterDigit(int& varLink, const string& label){
    string raw_input;
    cout << label << " = ";
    getline(cin, raw_input);
    while (!UserInput(raw_input)) {
        cout << label << " = ";
        getline(cin, raw_input);
    }
    varLink = stoi(raw_input);
}

int CalcRectangleArea(int NumberA, int NumberB){
    return NumberA * NumberB + 10;
}
#endif
