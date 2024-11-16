#include <lab.hpp>

void plusesDeleter(std::vector<int>& vec){
    std::vector<int> tmp{};
    for(auto i : vec){
        if(i > 0) continue;
        tmp.push_back(i);
    }
    tmp.shrink_to_fit();
    vec = tmp;
    //Похожая ситуация с задачей 7
}