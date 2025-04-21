#include <iostream>
#include "Maltsev_MathTask.h"

using namespace std;

int main() {
    try {
        string input;
        double x;
        int y;
        
        // Ввод вещественного числа
        do {
            cout << "Введите вещественное число x: ";
            getline(cin, input);
        } while (!validateFloatInput(input));
        x = stod(input);
        
        // Ввод натурального числа
        do {
            cout << "Введите натуральное число y: ";
            getline(cin, input);
        } while (!validateNaturalInput(input));
        y = stoi(input);
        
        // Вычисление и вывод результатов
        cout << "x округленное до " << y << " знаков: " 
             << roundToNDigits(x, y) << endl;
        cout << "Дробная часть x: " << getFractionalPart(x) << endl;
        
    } catch (const exception& e) {
        cerr << "Ошибка: " << e.what() << endl;
        return 1;
    }
    
    return 0;
}