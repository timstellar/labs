#include "header.hpp"
#include <cstddef>

std::vector<Group> Groups(const std::vector<Student>& students){
    std::vector<Group> groups;

    auto contain_group_name = [&groups](const std::string& name) -> std::size_t{
        for(auto i = 0; i < groups.size(); ++i){
            if(groups.at(i).Id == name){
                return i;
            }
        }
        return (std::size_t)(-1);
    };

    for(const auto& student : students){
        auto ind = contain_group_name(student.GroupId);
        if(ind == (std::size_t)(-1)){
            groups.push_back(Group{student.GroupId,{student}});
        }
        else{
            groups.at(ind).Students.push_back(student);
        }
    }

    return groups;
}