#include "lab05.hpp"

float mean(const std::vector<float>& vec) {
    if (vec.empty()) return 0.0f;
    float sum = std::accumulate(vec.begin(), vec.end(), 0.0f);
    return sum / vec.size();
}