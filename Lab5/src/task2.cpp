#include "header.hpp"

float mean(const Student& student){
    if(student.Ratings.empty()){
        return 0.f;
    }
    auto res = 0.f;
    for(const auto mark : student.Ratings){
        res += mark;
    }
    return res / student.Ratings.size();
}

void SortByRating(std::vector<Student>& students){
    for(auto i = 0; i < students.size(); ++i){
        for(auto j = 0; j < i; ++j){
            if(mean(students.at(j)) > mean(students.at(i))){
                auto tmp = students.at(j);
                students.at(j) = students.at(i);
                students.at(i) = tmp;
            }
        }
    }
}