#include <lab.hpp>

std::map<std::string, int> wordsMapCounter(const std::string& str){
    std::map<std::string, int> res{};
    const std::string delims = " ,.\n";
    std::string base = "";
    for(auto it = str.begin(); it != str.end(); ++it){
        if(delims.find(*it) != std::string::npos){
            if(base != ""){
                if(res.find(base) == res.end()){
                    res.insert({base,1});
                }else{
                    res[base]++;
                }
            }
            base = "";
        }
        else{
            base += *it;
        }
    }
    return res;
}