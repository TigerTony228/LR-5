#ifndef MATH_TASK_H
#define MATH_TASK_H

#include <string>
#include <cmath>
#include <stdexcept>

using namespace std;

// Функция проверки ввода вещественного числа
bool validateFloatInput(const string& input);

// Функция проверки ввода натурального числа
bool validateNaturalInput(const string& input);

// Функция округления до N знаков
double roundToNDigits(double x, int n);

// Функция получения дробной части
double getFractionalPart(double x);

#endif