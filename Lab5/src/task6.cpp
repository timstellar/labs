#include "header.hpp"

std::vector<std::string> GroupsId(const std::vector<Student>& students){
    std::vector<std::string> groups{};
    auto is_in = [&groups](const std::string& group_name){
        for(const auto& name : groups){
            if(name == group_name){
                return true;
            }
        }
        return false;
    };
    for(const auto& student : students){
        if(!is_in(student.GroupId)){
            groups.push_back(student.GroupId);
        }
    }
    return groups;
}