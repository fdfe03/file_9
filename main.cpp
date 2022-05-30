// Zemin Wong A1780385
// Practical 9: main.cpp

#include <iostream>
#include <string>
#include "ExpressionConvert.h"
using namespace std;

int main() {
    ExpressionConvert* convert = new ExpressionConvert();
    string expression;
    getline(cin, expression);

    if (convert->isValid(expression)){
        cout << convert->prefixToInfix(expression) << " = ";
        cout << convert->prefixCalculator(expression) << endl;
    }else{
        cout << "Error" << endl;
    }
}