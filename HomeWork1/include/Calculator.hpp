#include <iostream>
#include <vector>
#include <string>
#include <iterator>

class Calculator
{

public:
    Calculator(const std::string& expression);

private:
    std::string expression;

    std::vector<std::string> parseExp(const char sign) {
        int cnt{};
        std::vector<std::string> result;
        std::vector<unsigned long> indices = {this->expression.length()};
        for (int i = this->expression.length()-1; i >= 0; --i) {
            if (this->expression.at(i) == ')')
                cnt++;
            if (this->expression.at(i) == '(')
                cnt--;
            if (this->expression.at(i) == sign && cnt == 0) {
                indices.emplace_back(i);
            }
        }
        indices.emplace_back(-1);
        for (int i{}; i < indices.size(); ++i) {
            if (indices.at(i) != 0 && indices.at(i) != this->expression.length()-1) {
                result.emplace_back(this->expression.substr(indices.at(i+1)+1, indices.at(i)-1));
            }
        }
        return result;
    }
};