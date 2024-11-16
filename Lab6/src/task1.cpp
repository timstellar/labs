#include "../include/lab.hpp"

std::vector<int>::iterator Find(std::vector<int>::iterator first, std::vector<int>::iterator last, int el) 
{
    while (first != last) {
        if (*first == el) {
            return first;
        }
        first++;
    }
    return last;
}