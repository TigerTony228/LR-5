#include "Maltsev_MathTask.h"
#include <cmath>
#include <cctype>

bool validateFloatInput(const string& input) {
    if (input.empty()) return false;
    
    bool hasDecimal = false;
    bool hasDigit = false;
    
    for (size_t i = 0; i < input.size(); ++i) {
        char c = input[i];
        
        if (i == 0 && (c == '+' || c == '-')) {
            continue;
        }
        
        if (c == '.') {
            if (hasDecimal) return false;
            hasDecimal = true;
        } 
        else if (isdigit(c)) {
            hasDigit = true;
        }
        else {
            return false;
        }
    }
    
    return hasDigit;
}

bool validateNaturalInput(const string& input) {
    if (input.empty()) return false;
    
    for (char c : input) {
        if (!isdigit(c)) return false;
    }
    
    return true;
}

double roundToNDigits(double x, int n) {
    if (n < 0) throw invalid_argument("n must be non-negative");
    
    double factor = pow(10.0, n);
    return round(x * factor) / factor;
}

double getFractionalPart(double x) {
    return x - trunc(x);
}