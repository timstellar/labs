#include "lab05.hpp"

std::vector<std::string> split(const std::string& str, char sep) {
    std::vector<std::string> result;
    std::stringstream ss(str);
    std::string item;
    while (std::getline(ss, item, sep)) {
        result.push_back(item);
    }
    return result;
}