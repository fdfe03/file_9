// Zemin Wong A1780385
// Practical 9: ExpressionConvert.h
#ifndef EXPRESSION_CONVERT_H
#define EXPRESSION_CONVERT_H

#include <string>

class ExpressionConvert {
    public:
    bool isOperator(char x);
    bool isValid(std::string prefix); 
    int operatorCalculator(int a, int b, char x);
    int prefixCalculator(std::string prefix);
    std::string prefixToInfix(std::string prefix);
};

#endif // EXPRESSION_CONVERT_H