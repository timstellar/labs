#include "../include/lab.hpp"

int wordsCounter(const std::string& str) {
    const std::string signs = " .,";
    int cnt{};
    bool isPrevSign = false;
    for (int i{}; i < str.length(); ++i) {
        if (signs.find(str[i]) && !isPrevSign) {
            cnt++;
            isPrevSign = true;
        } else if (!signs.find(str[i]) && isPrevSign) {
            isPrevSign = false;
        } else if (signs.find(str[i]) && isPrevSign) {
            isPrevSign = true;
        }
    }
    if (!signs.find(str.length()-1)) {
        cnt++;
    }
    return cnt;
}