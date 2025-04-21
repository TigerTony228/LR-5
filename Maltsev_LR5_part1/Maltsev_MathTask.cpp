#include "CUTE/cute/cute.h"
#include "CUTE/cute/ide_listener.h"
#include "CUTE/cute/cute_runner.h"
// Подключение модуля с тестируемыми методами
#include "Maltsev_MathTask.h"

using namespace cute;

void testCalculateRectangleArea() {
    // Входные значения
    int a = 3;
    int b = 5;
    // Ожидаемый результат
    int expected = 15;

    // Получение значения с помощью тестируемого метода
    int actual = CalcRectangleArea(a, b);

    // Сравнение ожидаемого результата с полученным
    ASSERT_EQUAL(expected, actual);
}

// Тест, проверяющий отсев пустых значений
void testUserInput_Empty() {
    // Исходные данные
    string str = "";
    // Ожидаемое значение результата работы функции UserInput
    bool expected = false;

    // Получение значения с помощью тестируемого метода
    bool actual = UserInput(str);

    // Сравнение ожидаемого результата с полученным
    ASSERT_EQUAL(expected, actual);
}

//тест, проверяющий отсев нецифровых символов
void testUserInput_Letter() {
    // исходные данные
    string str = "a";
    // ожидаемое значение результата работы функции UserInput
    bool expect = false;
    // получение значения с помощью тестируемого метода
    bool actual = UserInput(str);
    // сравнение ожидаемого результата с полученным
    ASSERT_EQUAL(expect, actual);
}

//тест, проверяющий отсев цифро-буквенных значений
void testUserInput_DigitLetterValue() {
    // исходные данные
    string str = "5a";
    // ожидаемое значение результата работы функции UserInput
    bool expect = false;
    // получение значения с помощью тестируемого метода
    bool actual = UserInput(str);
    // сравнение ожидаемого результата с полученным
    ASSERT_EQUAL(expect, actual);
}

//тест, проверяющий отсев отрицательных значений
void testUserInput_NegativeValue() {
    // исходные данные
    string str = "-5";
    // ожидаемое значение результата работы функции UserInput
    bool expect = false;
    // получение значения с помощью тестируемого метода
    bool actual = UserInput(str);
    // сравнение ожидаемого результата с полученным
    ASSERT_EQUAL(expect, actual);
}

int main() {
    // Создаем тестовый набор
    suite s;

    // Добавляем тестовую функцию в набор
    s.push_back(CUTE(testCalculateRectangleArea));
    s.push_back(CUTE(testUserInput_Empty));
    s.push_back(CUTE(testUserInput_Letter));
    s.push_back(CUTE(testUserInput_NegativeValue));
    s.push_back(CUTE(testUserInput_DigitLetterValue));

    // Создаем listener и runner
    ide_listener<> listener;
    makeRunner(listener)(s, "All Rectangle Tests");

    return 0;
}