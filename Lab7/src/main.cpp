#include <iostream>
#include <vector>
#include "../include/header.hpp"

int main() {
    std::string filename = "file.txt";

    //Task1
    std::vector<std::string> data1 = { "0", "1", "2", "3", "4", "5" };
    saveToFile(filename, data1);
    std::vector<std::string> outData1{};
    loadFromFile(filename, outData1);
    for (auto i : outData1) {
        std::cout << i << std::endl;
    }

    //Task2
    std::vector<Book> data2 = { {"Author1", "Title1", 2000}, {"Author2", "Title2", 2001}, {"Author3", "Title3", 2002} };
    saveToFile(filename, data2);
    std::vector<Book> outData2{};
    loadFromFile(filename, outData2);
    for (auto i : outData2) {
        std::cout << i.Author << " " << i.Title << " " << i.Year << std::endl;
    }

    //Task3
    Groups groups;
    groups["Group1"] = { {"Student1", 2000, {{"Math", Score::Good}, {"Physics", Score::Excellent}, {"Chemistry", Score::Satisfactorily}}},
                         {"Student2", 2001, {{"Math", Score::Excellent}, {"Physics", Score::Good}, {"Chemistry", Score::Unsatisfactorily}}},
                         {"Student3", 2002, {{"Math", Score::Satisfactorily}, {"Physics", Score::Unsatisfactorily}, {"Chemistry", Score::Good}}} };
    groups["Group2"] = { {"Student4", 2000, {{"Math", Score::Good}, {"Physics", Score::Excellent}, {"Chemistry", Score::Satisfactorily}}},
                         {"Student5", 2001, {{"Math", Score::Excellent}, {"Physics", Score::Good}, {"Chemistry", Score::Unsatisfactorily}}},
                         {"Student6", 2002, {{"Math", Score::Satisfactorily}, {"Physics", Score::Unsatisfactorily}, {"Chemistry", Score::Good}}} };
    saveToFile(filename, groups);
    Groups outGroups{};
    loadFromFile(filename, outGroups);
    for (auto i : outGroups) {
        std::cout << i.first << std::endl;
        for (auto j : i.second) {
            std::cout << j.Name << " " << j.Year << std::endl;
            for (auto k : j.RecordBook) {
                std::cout << k.first << " " << k.second << std::endl;
            }
        }
    }

    return 0;
}