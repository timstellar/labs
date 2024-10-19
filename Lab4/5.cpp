#include "lab05.hpp"

bool remove_first_negative_element(std::vector<int>& vec, int& removed_element) {
    auto it = std::find_if(vec.begin(), vec.end(), [](int x) { return x < 0; });
    if (it != vec.end()) {
        removed_element = *it;
        vec.erase(it);
        return true;
    }
    return false;
}