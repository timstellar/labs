#include "header.hpp"

size_t CountTwoness(const std::vector<Student>& students){
    size_t counter = 0;
    for(const auto& student : students){
        for(const auto mark : student.Ratings){
            if(mark == 2){
                counter++;
                break;
            }
        }
    }
    return counter;
}