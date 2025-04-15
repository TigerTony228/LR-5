#ifndef _MALTSEV_MATH_H_
#define _MALTSEV_MATH_H_

#include <string>
#include <iostream>
using namespace std;

bool UserInput(string input)
{
    if (input.empty()) return false;
    try{
        int number = stoi(input);
    }
    catch(...){
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
    return NumberA * NumberB;
}
#endif
