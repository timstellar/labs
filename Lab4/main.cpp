#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <string>
#include <sstream>

float mean(const std::vector<float>&);
std::pair<float, float> minMax(const std::vector<float>&);
void sort(std::vector<float>&);
bool remove_first_negative_element(std::vector<int>& vec, int& removed_element) {
    auto it = std::find_if(vec.begin(), vec.end(), [](int x) { return x < 0; });
    if (it != vec.end()) {
        removed_element = *it;
        vec.erase(it);
        return true;
    }
    return false;
}
int argmax(const std::vector<float>& vec);
std::string replace(const std::string& str, const std::string& old, const std::string& new_string);
std::vector<std::string> split(const std::string&, char sep);
std::string join(const std::vector<std::string>&, const std::string& sep);

int main(int argc, char* argv[]) {
    //Task1
    std::vector<float> vec = {1.0f, 2.0f, 3.0f, 4.0f, 5.0f};
    std::cout << "Mean: " << mean(vec) << std::endl;

    //Task2
    auto [min, max] = minMax(vec);
    std::cout << "Min: " << min << ", Max: " << max << std::endl;

    // Task3
    int max_index = argmax(vec);
    std::cout << "Index of max element: " << max_index << std::endl;

    //Task4
    sort(vec);
    std::cout << "Sorted: ";
    for (auto x : vec) {
        std::cout << x << " ";
    }
    std::cout << std::endl;

    //Task5
    int zero = 0;
    std::vector<int> vec2 = {1, 2, 3, -4, 5};
    std::cout << remove_first_negative_element(vec2, zero) << std::endl;
    for (auto x : vec2) {
        std::cout << x << " ";
    }
    std::cout << std::endl;

    //Task6
    std::string str = "Hello, World!";
    std::cout << "Replace: " << replace(str, "World", "C++") << std::endl;

    //Task7
    std::string str2 = "Hello, World!";
    auto parts = split(str2, ',');
    std::cout << "Split: ";
    for (auto& part : parts) {
        std::cout << part << " ";
    }
    std::cout << std::endl;

    //Task8
    std::vector<std::string> parts2 = {"Hello", "World!"};
    std::cout << "Join: " << join(parts2, ", ") << std::endl;

    return 0;
}

float mean(const std::vector<float>& vec) {
    if (vec.empty()) return 0.0f;
    float sum = std::accumulate(vec.begin(), vec.end(), 0.0f);
    return sum / vec.size();
}

std::pair<float, float> minMax(const std::vector<float>& vec) {
    if (vec.empty()) return {0.0f, 0.0f};
    auto [min_it, max_it] = std::minmax_element(vec.begin(), vec.end());
    return {*min_it, *max_it};
}

int argmax(const std::vector<float>& vec) {
    if (vec.empty()) return -1;
    return std::distance(vec.begin(), std::max_element(vec.begin(), vec.end()));
}
void quicksort(std::vector<float>& vec, int left, int right) {
    if (left < right) {
        int i = left;
        int j = right;
        float pivot = vec[(left + right) / 2];
        while (i <= j) {
            while (vec[i] < pivot) {
                i++;
            }
            while (vec[j] > pivot) {
                j--;
            }
            if (i <= j) {
                std::swap(vec[i], vec[j]);
                i++;
                j--;
            }
        }
        quicksort(vec, left, j);
        quicksort(vec, i, right);
    }
}
void sort(std::vector<float>& vec) {
    if (!vec.empty()) {
        int left = 0;
        int right = vec.size() - 1;
        quicksort(vec, left, right);
    }
}

std::string replace(const std::string& str, const std::string& old, const std::string& new_string) {
    std::string result = str;
    size_t pos = 0;
    while ((pos = result.find(old, pos)) != std::string::npos) {
        result.replace(pos, old.length(), new_string);
        pos += new_string.length();
    }
    return result;
}

std::vector<std::string> split(const std::string& str, char sep) {
    std::vector<std::string> result;
    std::stringstream ss(str);
    std::string item;
    while (std::getline(ss, item, sep)) {
        result.push_back(item);
    }
    return result;
}

std::string join(const std::vector<std::string>& vec, const std::string& sep) {
    std::string result;
    for (size_t i = 0; i < vec.size(); ++i) {
        result += vec[i];
        if (i < vec.size() - 1) {
            result += sep;
        }
    }
    return result;
}