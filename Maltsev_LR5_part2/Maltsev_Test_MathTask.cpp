// Surname_Test_MathTask.cpp
#include "CUTE/cute.h"
#include "CUTE/ide_listener.h"
#include "CUTE/cute_runner.h"
#include "Maltsev_MathTask.h"

void testValidateFloatInput_Correct() {
    ASSERT(validateFloatInput("3.14"));
    ASSERT(validateFloatInput("-123.456"));
    ASSERT(validateFloatInput("0.5"));
    ASSERT(validateFloatInput("+42.0"));
}

void testValidateFloatInput_Incorrect() {
    ASSERT(!validateFloatInput("abc"));
    ASSERT(!validateFloatInput("12a.34"));
    ASSERT(!validateFloatInput("12.34.56"));
    ASSERT(!validateFloatInput(""));
}

void testValidateNaturalInput_Correct() {
    ASSERT(validateNaturalInput("123"));
    ASSERT(validateNaturalInput("0"));
    ASSERT(validateNaturalInput("999"));
}

void testValidateNaturalInput_Incorrect() {
    ASSERT(!validateNaturalInput("12.3"));
    ASSERT(!validateNaturalInput("-123"));
    ASSERT(!validateNaturalInput("abc"));
    ASSERT(!validateNaturalInput(""));
}

void testRoundToNDigits() {
    ASSERT_EQUAL_DELTA(3.14, roundToNDigits(3.14159, 2), 0.0001);
    ASSERT_EQUAL_DELTA(-2.65, roundToNDigits(-2.645, 2), 0.0001);
    ASSERT_EQUAL_DELTA(123.0, roundToNDigits(123.456, 0), 0.0001);
}

void testGetFractionalPart() {
    ASSERT_EQUAL_DELTA(0.14159, getFractionalPart(3.14159), 0.0001);
    ASSERT_EQUAL_DELTA(0.0, getFractionalPart(42.0), 0.0001);
    ASSERT_EQUAL_DELTA(0.5, getFractionalPart(-3.5), 0.0001);
}

int main() {
    cute::suite s;
    
    s.push_back(CUTE(testValidateFloatInput_Correct));
    s.push_back(CUTE(testValidateFloatInput_Incorrect));
    s.push_back(CUTE(testValidateNaturalInput_Correct));
    s.push_back(CUTE(testValidateNaturalInput_Incorrect));
    s.push_back(CUTE(testRoundToNDigits));
    s.push_back(CUTE(testGetFractionalPart));
    
    cute::ide_listener<> listener;
    cute::makeRunner(listener)(s, "Math Task Tests");
    
    return 0;
}