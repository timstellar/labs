#include <lab.hpp>

void reverseNum(std::list<int>& lst){
    std::list<int> tmp{};
    for(auto el : lst){
        tmp.emplace_back(-el);
        tmp.emplace_back(el);
    }
    lst = tmp;
}