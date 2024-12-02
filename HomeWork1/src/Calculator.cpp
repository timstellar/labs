#include <iostream>
#include <stack>
#include <sstream>
#include <string>
#include <vector>
#include <cmath>
#include "../include/Calculator.hpp"

void Calculator::checkExpression() {

    if (expression.empty()) {
        std::cerr << "Error: Empty expression" << std::endl;
        exit(1);
    }

    size_t pos = 0;
    while ((pos = expression.find("exp", pos)) != std::string::npos) {
        expression.replace(pos, 3, "e");
        pos += 1;
    }
    pos = 0;
    if (expression.find("x") != std::string::npos) {
        std::cout << "Enter x: ";
        try
        {
            std::cin >> x;
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
        
        std::cout << std::endl;
        std::string x_str = std::to_string(x);
        while ((pos = expression.find("x", pos)) != std::string::npos) {
            expression.replace(pos, 1, x_str);
            pos += x_str.length();
        }
    }
    pos = 0;
    while ((pos = expression.find("ctg", pos)) != std::string::npos) {
        expression.replace(pos, 3, "g");
        pos += 1;
    }

    for (int i = 0; i < expression.size(); i++) {
        if (isOperator(expression[i])) {
            if (i == 0 || i == expression.size() - 1) {
                std::cerr << "Error: Operator at the beginning or end of the expression" << std::endl;
                exit(1);
            } else if (isOperator(expression[i - 1]) || isOperator(expression[i + 1])) {
                std::cerr << "Error: Two operators in a row or unknown operator" << std::endl;
                exit(1);
            }
        } else if (expression[i] == '(') {
            if (i == expression.size() - 1) {
                std::cerr << "Error: Opening bracket at the end of the expression" << std::endl;
                exit(1);
            } else if (expression[i + 1] == ')') {
                std::cerr << "Error: Empty brackets" << std::endl;
                exit(1);
            }
        } else if (expression[i] == ')') {
            if (i == 0) {
                std::cerr << "Error: Closing bracket at the beginning of the expression" << std::endl;
                exit(1);
            } else if (expression[i - 1] == '(') {
                std::cerr << "Error: Empty brackets" << std::endl;
                exit(1);
            }
            
        }
    }

    int brackets = 0;
    for (int i = 0; i < expression.size(); i++) {
        if (expression[i] == '(') {
            brackets++;
        } else if (expression[i] == ')') {
            brackets--;
        }
    }
    if (brackets != 0) {
        std::cerr << "Error: Unbalanced brackets" << std::endl;
        exit(1);
    }

    std::string spacedExpression;
    for (size_t i = 0; i < expression.length(); ++i) {
        if (isOperator(expression[i]) || expression[i] == '(' || expression[i] == ')') {
            spacedExpression += ' ';
            spacedExpression += expression[i];
            spacedExpression += ' ';
        } else {
            spacedExpression += expression[i];
        }
    }
    expression = spacedExpression;
}

void Calculator::solve() {
    std::vector<std::string> postfix = infixToPostfix();
    result = evaluatePostfix(postfix);
}

double Calculator::getResult() {
    return result;
}