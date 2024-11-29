#include "../include/header.hpp"

char* CopyString(const char* str) {
    int size = 0;
    while (str[size] != '\0') size++;

    char* copy = new char[size + 1];
    for (int i = 0; i < size; i++) {
        copy[i] = str[i];
    }
    return copy;
}

char* ConcatinateStrings(const char* a, const char* b) {
    int size_a = 0;
    while (a[size_a] != '\0') size_a++;
    
    int size_b = 0;
    while (b[size_b] != '\0') size_b++;

    char* res = new char[size_a + size_b + 1];
    for (int i = 0; i < size_a; i++) {
        res[i] = a[i];
    }
    for (int i = 0; i < size_b; i++) {
        res[size_a + i] = b[i];
    }
    return res;
}