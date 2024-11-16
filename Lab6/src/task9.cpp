#include <lab.hpp>

void Sort(std::list<int>& lst){
    for(auto i = lst.begin(); i != lst.end(); ++i){
        for(auto j = lst.begin(); j != i; ++j){
            if(*i > *j){
                std::swap(*i,*j);
            }
        }
    }
}