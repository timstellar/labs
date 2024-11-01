#include <iostream>
#include <vector>
#include "header.hpp"

int main(){
    auto print_vec = [](const std::vector<Student>& students){
        std::cout << "{\n";
        for(auto student : students){
            std::cout << "\t{\"Name\": " << "\"" << student.Name << "\", ";
            std::cout << "\"GroupId\": \"" << student.GroupId << "\", ";
            std::cout << "\"Ratings\": [";
            for(auto t : student.Ratings){
                std::cout << t << ",";
            } 
            std::cout << "], ";
            std::cout << "\"Subjects\": [";
            for(auto t : student.Subjects){
                std::cout << t << ",";
            } 
            std::cout << "]},\n";
        }
        std::cout << "}\n";
    };
    std::vector<Student> students = {
        {"User1", "МТ10-11Б",{5,5},{"Math","Physics"}},
        {"User2","ФН4-11Б",{2,5},{"Math","Physics"}},
        {"User3","ИУ8-14", {5,3},{"Math","Physics"}}
    };
    print_vec(students);
    SortByName(students);
    print_vec(students);
    SortByRating(students);
    std::cout << CountTwoness(students) << std::endl;
    std::cout << CountExcellent(students) << std::endl;
    print_vec(VectorMathExcellent(students));
    auto samples = Groups(students);
    for(const auto& sample : samples){
        std::cout << sample.Id << "\n";
        print_vec(sample.Students);
    }
}