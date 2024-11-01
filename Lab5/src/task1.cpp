#include "header.hpp"

void SortByName(std::vector<Student>& students){
    for(auto i = 0; i < students.size(); ++i){
        for(auto j = 0; j < i; ++j){
            if(students.at(j).Name > students.at(i).Name){
                auto tmp = students.at(j);
                students.at(j) = students.at(i);
                students.at(i) = tmp;
            }
        }
    }
}