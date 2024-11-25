#include <iostream>
#include "../include/Calculator.hpp"

int main() {
    std::string exp = "(123 + 123) + (321 + 321) + 543";
    Calculator calc(exp);

    return 0;
}