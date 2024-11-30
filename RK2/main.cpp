#include <iostream>

void Del (int* out, int size, int index) {
    int* buffer = new int[size-1];
    for (int i = 0, j = 0; i < size; ++i) {
        if (i == index) {
            continue;
        }
        buffer[j++] = out[i];
    }
    for (int i = 0; i < size-1; ++i) {
        out[i] = buffer[i];
    }
    delete[] buffer;
}

int main() {

    int* str = new int(5);
    str[0] = 1;
    str[1] = 0;
    str[2] = 3;
    str[3] = 4;
    str[4] = 0;
    for (size_t i = 0; i < 5; ++i) {
        std::cout << str[i] << " ";
    }
    Del(str, 5, 1);
    for (size_t i = 0; i < 4; ++i) {
        std::cout << str[i] << " ";
    }
    std::cout << std::endl;


    return 0;
}