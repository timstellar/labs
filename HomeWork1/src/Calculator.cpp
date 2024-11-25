#include "../include/Calculator.hpp"

Calculator::Calculator(const std::string& expression) :
            expression(expression)
{
    this->parseExp('+');
}
