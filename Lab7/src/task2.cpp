#include "../include/header.hpp"

void saveToFile(const std::string& filename, const std::vector<Book>& data) {
    std::ofstream out;
    out.open(filename);
    if (out.is_open()) {
        for (auto i : data) {
            out << i.Author << " " << i.Title << " " << i.Year << std::endl;
        }
    }
    out.close();
}

void loadFromFile(const std::string& filename, std::vector<Book>& outData) {
    std::ifstream in;
    in.open(filename);
    if (in.is_open()) {
        std::string line{};
        Book b{};
        char* word{};
        int cnt = 0;
        while (std::getline(in, line)) {
            word = strtok((char*)line.c_str(), " ");
            while (word != nullptr) {
                switch (cnt)
                {
                case 0:
                    b.Author = word;
                    cnt++;
                    break;
                case 1:
                    b.Title = word;
                    cnt++;
                    break;
                case 2:
                    b.Year = std::stoi(word);
                    cnt = 0;
                    outData.emplace_back(b);
                    break;
                }
                word = strtok(NULL, " ");
            }
        }
    }
    in.close();
}