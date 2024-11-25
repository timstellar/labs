#include "../include/header.hpp"

void saveToFile(const std::string& filename, const Groups& groups) {
    std::ofstream out;
    out.open(filename);
    if (out.is_open()) {
        for (auto i : groups) {
            out << i.first << std::endl;
            for (auto j : i.second) {
                out << j.Name << " " << j.Year << std::endl;
                for (auto k : j.RecordBook) {
                    out << k.first << " " << k.second << " ";
                }
                out << std::endl;
            }
        }
    }
    out.close();
}


void loadFromFile(const std::string& filename, Groups& outGroups) {
    std::ifstream in;
    in.open(filename);
    if (in.is_open()) {
        std::string line;
        std::string name;
        while (std::getline(in, line)) {
            char* word{};
            word = strtok((char*)line.c_str(), " ");
            std::vector<std::string> data;
            while (word != NULL) {
                data.emplace_back(word);
                word = strtok(NULL, " ");
            }
            if (data.size() == 1) {
                name = data[0];
                outGroups[name] = {};
            } else if (data.size() == 2) {
                std::string name2 = data[0];
                std::string year = data[1];
                outGroups[name].emplace_back(Student{ name2, std::stoi(year), {} });
            } else if (data.size() >= 3) {
                for (int i{}; i < data.size(); i += 2) {
                    outGroups[name].back().RecordBook.insert({data[i], Score(std::stoi(data[i+1]))});
                }
            }
        }
    }
    in.close();
}