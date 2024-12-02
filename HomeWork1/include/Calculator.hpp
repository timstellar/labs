#include <stack>
#include <sstream>
#include <string>
#include <vector>
#include <cmath>

class Calculator {
    private:
        std::string expression;
        double result;
        int x;
        int precendence(char op) {
            if (op == '+' || op == '-') {
                return 1;
            } else if (op == '*' || op == '/') {
                return 2;
            } else if (op == '^') {
                return 3;
            } else if (op == 'c' || op == 's' || op == 't' || op == 'g' || op == 'e') {
                return 4;
            }
            return 0;
        }

        int isOperator(char c) {
            return c == '+' || c == '-' || c == '*' || c == '/' || c == 'e' || c == 'c' || c == 's' || c == 't' || c == 'g' || c == '^';
        };

        std::vector<std::string> infixToPostfix() {
            std::stack<char> operators;
            std::vector<std::string> output;
            std::istringstream iss(expression);
            std::string token;

            while (iss >> token) {
                if (isdigit(token[0])) {
                    output.push_back(token);
                } else if (token[0] == '(') {
                    operators.push(token[0]);
                } else if (token[0] == ')') {
                    while (!operators.empty() && operators.top() != '(') {
                        output.push_back(std::string(1, operators.top()));
                        operators.pop();
                    }
                    operators.pop();
                } else if (isOperator(token[0])) {
                    while (!operators.empty() && precendence(operators.top()) >= precendence(token[0])) {
                        output.push_back(std::string(1, operators.top()));
                        operators.pop();
                    }
                    operators.push(token[0]);
                }
            }

            while (!operators.empty()) {
                output.push_back(std::string(1, operators.top()));
                operators.pop();
            }
            return output;
        };

        double evaluatePostfix(const std::vector<std::string>& tokens) {
            std::stack<double> stack;
            for (const auto& token : tokens) {
                if (token == "+" || token == "-" || token == "*" || token == "/" || token == "^") {
                    double y = stack.top();
                    stack.pop();
                    double x = stack.top();
                    stack.pop();
                    if (token == "+") {
                        stack.push(x + y);
                    } else if (token == "-") {
                        stack.push(x - y);
                    } else if (token == "*") {
                        stack.push(x * y);
                    } else if (token == "/") {
                        stack.push(x / y);
                    } else if (token == "^") {
                        stack.push(pow(x, y));
                    } 
                } else if (token == "e" || token == "c" || token == "s" || token == "t" || token == "g") {
                    double x = stack.top(); stack.pop();
                    if (token == "g") {
                        stack.push(1 / tan(x));
                    } else if (token == "e") {
                        stack.push(exp(x));
                    } else if (token == "c") {
                        stack.push(cos(x));
                    } else if (token == "s") {
                        stack.push(sin(x));
                    } else if (token == "t") {
                        stack.push(tan(x));
                    }
                } else {
                    stack.push(std::stod(token));
                }
            }
            return stack.top();
        };
    public:
        Calculator(const std::string& expression) : expression(expression), result(0) {};
        void checkExpression();
        void solve();
        double getResult();
};