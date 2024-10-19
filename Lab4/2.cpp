#include "lab05.hpp"

std::pair<float, float> minMax(const std::vector<float>& vec) {
    if (vec.empty()) return {0.0f, 0.0f};
    auto [min_it, max_it] = std::minmax_element(vec.begin(), vec.end());
    return {*min_it, *max_it};
}