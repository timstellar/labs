#include <iostream>
#include <vector>
#include <cmath>

void tableMult(int m) {
    for (int i = 1; i <= 10; i++) {
        std::cout << i << " x " << m << " = " << i * m << std::endl;
    }
}

void multFromTo(int from, int to) {
    for (int i = from; i <= to; i++) {
        for (int j = from; j <= to; j++) {
            std::cout << i << " x " << j << " = " << i * j << std::endl;
        }
    }
}

int main(int argc, char* argv[]) {

    // Task 1
    std::cout << "Task 1" << std::endl;

    int x{};
    int y{};
    int z{};

    std::cin >> x >> y >> z;

    if (x % 2 == 1 && x % 2 == 1) {
        std::cout << "First condition is true" << std::endl;
    } else {
        std::cout << "First condition is false" << std::endl;
    }

    if ((x < 20 && y >= 20) || (x >= 20 && y < 20)) {
        std::cout << "Second condition is true" << std::endl;
    } else {
        std::cout << "Second condition is false" << std::endl;
    }

    if (x == 0 && y == 0) {
        std::cout << "Third condition is true" << std::endl;
    } else {
        std::cout << "Third condition is false" << std::endl;
    }

    if (x < 0 && y < 0 && z < 0) {
        std::cout << "Fourth condition is true" << std::endl;
    } else {
        std::cout << "Fourth condition is false" << std::endl;
    }

    if ((x % 5 == 0 && y % 5 != 0 && z % 5 != 0) || 
        (x % 5 != 0 && y % 5 == 0 && z % 5 != 0) || 
        (x % 5 != 0 && y % 5 != 0 && z % 5 == 0)) {
        std::cout << "Fifth condition is true" << std::endl;
    } else {
        std::cout << "Fifth condition is false" << std::endl;
    }

    if (x > 100 || y > 100 || z > 100) {
        std::cout << "Sixth condition is true" << std::endl;
    } else {
        std::cout << "Sixth condition is false" << std::endl;
    }


    // Task 2
    std::cout << "Task 2" << std::endl;

    using byte = unsigned char;
    std::pair<byte, byte> positionA;
    std::pair<byte, byte> positionB;
    std::cin >> positionA.first >> positionA.second;
    std::cin >> positionB.first >> positionB.second;

    if (positionA.first == positionB.first || positionA.second == positionB.second) {
        std::cout << "First condition is true" << std::endl;
    } else {
        std::cout << "First condition is false" << std::endl;
    }

    if (positionA.first - positionA.second == positionB.first - positionB.second) {
        std::cout << "Second condition is true" << std::endl;
    } else {
        std::cout << "Second condition is false" << std::endl;
    }

    if (std::abs(positionB.first - positionA.first) <= 1 && std::abs(positionB.second - positionA.second) <= 1) {
        std::cout << "Third condition is true" << std::endl;
    } else {
        std::cout << "Third condition is false" << std::endl;
    }

    if (positionA.first == positionB.first || positionA.second == positionB.second || 
        positionA.first - positionA.second == positionB.first - positionB.second) {
        std::cout << "Fourth condition is true" << std::endl;
    } else {
        std::cout << "Fourth condition is false" << std::endl;
    }

    if ((std::abs(positionA.first - positionB.first) <= 2) || 
        ((std::abs(positionA.second - positionB.second) == 1) && (std::abs(positionA.first - positionB.first) == 1))) {
        std::cout << "Fifth condition is true" << std::endl;
    } else {
        std::cout << "Fifth condition is false" << std::endl;
    }

    // Task 3
    std::cout << "Task 3" << std::endl;

    tableMult(7);
    int mult{};
    std::cin >> mult;
    tableMult(mult);

    // Task 4
    std::cout << "Task 4" << std::endl;

    multFromTo(8, 15);
    int a{};
    std::cin >> a;
    multFromTo(a, 20);
    int b{};
    std::cin >> b;
    multFromTo(1, b);
    multFromTo(a, b);
}
