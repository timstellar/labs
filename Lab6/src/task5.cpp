#include <lab.hpp>

std::vector<std::string> uniqueWords(const std::string& str){
    auto word_map = wordsMapCounter(str);
    std::vector<std::string> res{};
    for(auto [key,_] : word_map){
        res.emplace_back(key);
    }
    return res;
}