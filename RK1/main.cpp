#include <iostream>
#include <vector>

int main(int argc, char* argv[]) {
    std::vector<int> numbers;
    int input{};
    std::cout << "Enter numbers (enter -1 to stop): ";
    while (true) {
        std::cin >> input;
        if (input == -1) {
            break;
        }
        numbers.push_back(input);
    }
    
    for (int i{}; i < 6; i++) {
        std::cout << numbers[i] << " ";
    }
    std::cout << std::endl;

    int sum{};
    for (int i : numbers) {
        sum += i;
    }
    std::cout << "Summ = " << sum << std::endl;
}