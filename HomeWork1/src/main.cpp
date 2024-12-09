#include <iostream>
#include "../include/Calculator.hpp"

int main() {
    try {
        std::string expression;
        std::cout << "Enter an expression: ";
        // std::cin >> expression;
        std::cout << std::endl;

        Calculator calc("2+2*2");
        calc.checkExpression();
        calc.solve();

        std::cout << "Result: " << calc.getResult() << std::endl;
        
    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    } catch (...) {
        std::cerr << "Unknown exception occurred" << std::endl;
    }
    return 0;
}