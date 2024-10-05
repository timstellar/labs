#include <iostream>
#include <vector>
// Variant 20
int main(int argc, char* argv[]) {
    int a{};
    int b{};
    int c{};
    int d{};

    std::vector<std::string> positive;
    std::vector<std::string> negative;

    std::cout << "Enter number A: ";
    std::cin >> a;
    std::cout << "Enter number B: ";
    std::cin >> b;
    std::cout << "Enter number C: ";
    std::cin >> c;
    std::cout << "Enter number D: ";
    std::cin >> d;

    if (a >= 0) {
        positive.push_back("A");
    } else {
        negative.push_back("A");
    }
    if (b >= 0) {
        positive.push_back("B");
    } else {
        negative.push_back("B");
    }
    if (c >= 0) {
        positive.push_back("C");
    } else {
        negative.push_back("C");
    }
    if (d >= 0) {
        positive.push_back("D");
    } else {
        negative.push_back("D");
    }

    std::cout << "Positive numbers: ";
    for (std::string &i : positive) {
        std::cout << i << " ";
    }
    std::cout << std::endl;


    std::cout << "Negative numbers: ";
    for (std::string &i : negative) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
}