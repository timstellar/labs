#include <iostream>
#include <lab.hpp>

int main(){
    std::string song_text = R"( Lorem ipsum dolor sit amet, consectetur adipiscing elit. Donec vehicula dictum convallis. Donec pretium ornare magna, eget suscipit tortor imperdiet ac. In sit amet ante molestie, tempus leo nec, facilisis eros. Quisque vestibulum nibh sem, sed blandit orci sodales sit amet. Nulla feugiat, metus ut congue malesuada, eros nunc commodo elit, at laoreet tellus purus sed libero. Cras bibendum ante diam, eu mattis purus blandit rutrum.)";

    { //task1
        std::vector<int> vt = {1,2,3,4,5};
        auto it = Find(vt.begin(),vt.end(),2);
        std::cout << *it << std::endl;
    }
    { //task2
        std::vector<int> v = {1, 2, 3, 4, 5};
        std::vector<int>::iterator it = findInSorted(v.begin(), v.end(), 2);
        std::cout << *it << std::endl;
    }
    { //task3
        int words = wordsCounter("Hello World");
        std::cout << words << std::endl;
    }
    { //tasks4-6
        auto words_map = wordsMapCounter(song_text);
        for(auto [key, val] : words_map){
            std::cout << key << ": " << val << std::endl;
        }
        for(auto word : uniqueWords(song_text)){
            std::cout << word << std::endl;
        }
        std::cout << diffWordsCounter(song_text) << std::endl;
    }
    { //tasks7-9
        std::list<int> nums = {1, 5, 4, -3};
        reverseNum(nums);
        for(auto i : nums){
            std::cout << i << " ";
        }
        std::cout << std::endl;

        std::vector vec(nums.begin(),nums.end());
        plusesDeleter(vec);
        for(auto i : vec){
            std::cout << i << " ";
        }
        std::cout << std::endl;

        Sort(nums);
        for(auto i : nums){
            std::cout << i << " ";
        }
        std::cout << std::endl;
    }
    
}