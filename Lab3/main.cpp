#include <iostream>
#include <vector>
#include <random>

void print(std::string text);
void print(std::string text, std::vector<int> nums);
void task1(std::vector<int> nums, int subtract);
void task2(std::vector<int> nums, int k[], int s[]);
void task3(std::vector<int> nums);
void task4(std::vector<int> nums);
void task5(std::string name);
void task6(std::string s1, std::string s2);
void task7(std::string s1, std::string s2, std::string s3);
void task8(std::string s1, int from, int to);
void task9(std::string str);
void task10(std::string str);
void task11(std::string word);

template<class T>
std::vector<T> generate_random_vector(std::size_t num, T min = -10, T max = 10)
{
    std::random_device rd;
    std::mt19937 e2(rd());
    std::uniform_real_distribution<> dist(min, max);

    auto lambda = [&e2, &dist] () -> T { return dist(e2); };

    std::vector<T> result(num);
    std::generate_n(result.begin(), num, lambda);
    return result;
}

int main(int argc, char* argv[]) {
    std::vector<int> nums = generate_random_vector<int>(10, -100, 50);

    task1(nums, 2);
    int k[2]{};
    std::cin >> k[0] >> k[1];
    int s[2]{};
    std::cin >> s[0] >> s[1];
    task2(nums, k, s);
    task3(nums);
    task4(nums);
    task5("Moscow");
    task6("Romanov", "Rublev");
    task7("Moscow", "New York", "Liberty City");
    task8("United States", 3, 9);
    task9("Censored");
    task10("Amazing");
    std::string word{};
    std::cin >> word;
    task11(word);

    return 0;
}

void print(std::string text) {
    std::cout << text << std::endl;
}

void print(std::string text, std::vector<int> nums) {
    std::cout << text;
    for (int i : nums) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
}

void task1(std::vector<int> nums, int subtract) {
    std::vector<int> res = nums;
    for (int i{}; i < res.size(); ++i) {
        res[i] = (res[i] * 2 - subtract) / res[0];
    }
    print("№1 Nums before calcs: ", nums);
    print("№1 Nums after calcs: ", res);
}

void task2(std::vector<int> nums, int k[], int s[]) {
    int sum{};
    for (int i : nums) {
        sum += i;
    }
    print("№2 Sum of all nums = " + std::to_string(sum));


    sum = 0;
    for (int i : nums) {
        sum += i*i;
    }
    print("№2 Sum of all squares of nums = " + std::to_string(sum));


    sum = 0;
    if (nums.size() < 6) {
        for (int i : nums) {
            sum += i;
        }
    } else {
        for (int i{}; i < 6; ++i) {
            sum += nums[i];
        }
    }
    print("№2 Sum of 6 nums = " + std::to_string(sum));


    sum = 0;
    for (int i = k[0]; i < k[1]; ++i) {
        sum += nums[i];
    }
    print("№2 Sum from " + std::to_string(k[0]) + " to " + std::to_string(k[1]) + " = " + std::to_string(sum));


    sum = 0;
    for (int i : nums) {
        sum += i;
    }
    print("№2 Average of nums = " + std::to_string((sum * 1.0f / nums.size())));


    sum = 0;
    for (int i = s[0]; i < s[1]; ++i) {
        sum += nums[i];
    }
    print("№2 Average of nums from " + std::to_string(s[0]) + " to " + std::to_string(s[1]) + " = " + std::to_string((sum * 1.0f / (s[1] - s[0]))));
}

void task3(std::vector<int> nums) {
    std::vector<int> res = nums;
    int size = res.size();
    int buffer{};
    for (int i{}; i < 3; ++i) {
        buffer = res[size - i];
        res[size - i] = res[i];
        res[i] = buffer;
    }
    print("№3 Nums before changing: ", nums);
    print("№3 Nums after changing: ", res);
}

void task4(std::vector<int> nums) {
    std::vector<int> res{};
    bool isFiltered = false;
    for (int i{}; i < nums.size(); ++i) {
        if (nums[i] < 0 && !isFiltered) {
            isFiltered = true;
            continue;
        }
        res.push_back(nums[i]);
    }
    print("№4 Nums before deleting negative: ", nums);
    print("№4 Nums after deleting negative: ", res);

    std::vector<int> res1{};
    for(int i = res.size() - 1, flag{}; i >= 0; --i){
        if(flag == 0 && res.at(i) % 2  == 0) flag = 1;
        else res1.insert(res1.begin(), res.at(i));
    }
    print("№4 Nums before deleting even: ", res);
    print("№4 Nums after deleting even: ", res1);
}

void task5 (std::string name) {
    if (name.length() % 2 == 0) {
        print("№5 Name has even amount of letters.");
    } else {
        print("№5 Name has odd amount of letters.");
    }
}

void task6(std::string s1, std::string s2) {
    std::string res{};
    if (s1.length() > s2.length())
        print("№6 First surname has more letters.");
    else if (s1.length() < s2.length())
        print("№6 Second surname has more letters.");
    else
        print("№6 Surnames have equal amount of letters.");
}

void task7(std::string s1, std::string s2, std::string s3) {
    std::vector<std::string> names;
    names.push_back(s1);
    names.push_back(s2);
    names.push_back(s3);
    std::sort(names.begin(), names.end(), []
        (const std::string& first, const std::string& second){
            return first.size() < second.size();
        });
    print("№7 The smallest amount of letters has " + names[0] + " and the smallest has " + names[2]);
}

void task8(std::string s1, int from, int to) {
    std::string result_str;
    for(int i{from}; i <= to; ++i) 
        result_str.push_back(s1.at(i));
    print("№8 String after manipulations: " + result_str);
}

void task9(std::string str){
    std::string result_str;
    for(int i{}; i < str.length(); ++i) 
        result_str.push_back('*');
    for(char i: str) 
        result_str.push_back(i);
    for(int i{}; i < str.length(); ++i) 
        result_str.push_back('*');
    print("№9 String after starrization: " + result_str);

}

void task10(std::string str){
    int i{};
    int count{};
    while(str[i++] != '\0') if(str[i-1] == 'a') 
        ++count;
    print("№10 Persantage of using 'a' in string: " + std::to_string((count * 1.0f) / str.length() * 100) + "%");
}

void task11(std::string word){
    std::string seq = "Can you can a can as a canner can can a can?";
    std::string result_str;
    for (int i{}; i < seq.size(); ++i) {
        if (seq[i] == 'c' && seq[i+1] && seq[i+2]) {
            for(char c:word) result_str.push_back(c);
            i += 2;
        } else 
            result_str.push_back(seq[i]);
    }
    print("№11 New sentence: " + result_str);
}