#include "lab05.hpp"

int argmax(const std::vector<float>& vec) {
    if (vec.empty()) return -1;
    return std::distance(vec.begin(), std::max_element(vec.begin(), vec.end()));
}