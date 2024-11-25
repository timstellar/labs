#include "../include/header.hpp"

void saveToFile(const std::string& filename, const std::vector<std::string>& data) {
    std::ofstream out;
    out.open(filename);
    if (out.is_open()) {
        for (auto i : data) {
            out << i << std::endl;
        }
    }
    out.close();
}

void loadFromFile(const std::string& filename, std::vector<std::string>& outData) {
    std::ifstream in;
    in.open(filename);
    if (in.is_open()) {
        std::string line{};
        char* word{};
        while (std::getline(in, line)) {
            word = strtok((char*)line.c_str(), " ");
            while (word != NULL) {
                outData.emplace_back(word);
                word = strtok(NULL, " ");
            }
        }
    }
    in.close();
}