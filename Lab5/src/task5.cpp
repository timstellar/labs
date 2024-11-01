#include "header.hpp"

std::vector<Student> VectorMathExcellent(const std::vector<Student>& students){
    std::vector<Student> res{};
    for(const auto& student : students){
        for(auto i = 0; i < std::min(student.Ratings.size(),student.Subjects.size()); ++i){
            if(student.Subjects.at(i) == "Math" && student.Ratings.at(i) == 5){
                res.push_back(student);
            }
        }
    }
    return res;
}