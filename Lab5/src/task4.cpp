#include "header.hpp"

size_t CountExcellent(const std::vector<Student>& students){
    size_t count = 0;
    for(const auto& student : students){
        bool perfect = true;
        for(const auto mark : student.Ratings){
            perfect &= (mark == 5);
            if(!perfect){
                break;
            }
        }
        if(perfect){
            count++;
        }
    }
    return count;
}