// Zemin Wong A1780385
// Practical 9: ExpressionConvert.cpp

#include <iostream>
#include <string>
#include <stack>
#include <cctype>
#include "ExpressionConvert.h"
using namespace std;


bool ExpressionConvert::isOperator(char x){
    switch(x){
        case '+':
        case '-':
        case '*':
        case '/':
        return true;
    }
    return false;
}

bool ExpressionConvert::isValid(string prefix){
    int countOperator = 0;
    int countNumber = 0;

    string number = "";
    bool previousNumber =  false;
    for (int i = 0; i < prefix.size(); i++){

        if (!isOperator(prefix[i]) && !isdigit(prefix[i]) && prefix[i] != ' ') return false;

        if (isOperator(prefix[i])) countOperator++;

        else if (prefix[i] == ' ' && previousNumber){
            if (stoi(number) > 99) return false;
            countNumber++;
            previousNumber = false;
            number = "";
        } 
        
        else if (isdigit(prefix[i])){
            number += prefix[i];
            previousNumber = true;
        }
    }
    
    if (previousNumber) countNumber++;

    if (countNumber - countOperator != 1) return false;
    return true;
}

int ExpressionConvert::operatorCalculator(int a, int b, char x){
    switch (x){
        case '+':
            return a + b;
        case '-':
            return a - b;
        case '*':
            return a * b;
        case '/':
            return a / b;
    }
    return 0;
}

int ExpressionConvert::prefixCalculator(string prefix){
    if (prefix.size() < 2) return stoi(prefix);

    stack<int> expression;

    int len = prefix.size();
    string number = "";
    bool previousNumber = false;
    for (int i = len-1; i >= 0; i--){
        if (isOperator(prefix[i])) {
            int op1 = expression.top();
            expression.pop();
            int op2 = expression.top();
            expression.pop();

            int temp = operatorCalculator(op1, op2, prefix[i]);
            expression.push(temp);

        } else if (prefix[i] == ' ' && previousNumber){
            int temp = stoi(number);
            expression.push(temp);
            number = "";
            previousNumber = false;

        } else if (isdigit(prefix[i])){
            number = prefix[i] + number;
            previousNumber = true;
        }
    }

    return expression.top();
}

string ExpressionConvert::prefixToInfix(string prefix){
    if (prefix.size() < 2) return prefix;

    stack<string> expression;

    int len = prefix.size();
    string number = "";
    bool previousNumber = false;
    for (int i = len-1; i >= 0; i--){
        if (isOperator(prefix[i])) {
            string op1 = expression.top();
            expression.pop();
            string op2 = expression.top();
            expression.pop();

            string temp = "(" + op1 + " " + prefix[i] + " " + op2 + ")";
            if (i == 0 || prefix[i] == '*' || prefix[i] == '/') temp =  op1 + " " + prefix[i] + " " + op2;

            expression.push(temp);

        } else if (prefix[i] == ' ' && previousNumber){
            expression.push(number);
            number = "";
            previousNumber = false;

        } else if (isdigit(prefix[i])){
            number = prefix[i] + number;
            previousNumber = true;
        }
    }

   return expression.top();
}