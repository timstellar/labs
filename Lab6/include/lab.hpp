#include <iostream>
#include <vector>
#include <map>
#include <list>

std::vector<int>::iterator Find(std::vector<int>::iterator first, std::vector<int>::iterator last, int el);
std::vector<int>::iterator findInSorted(std::vector<int>::iterator first, std::vector<int>::iterator last, int el);
int wordsCounter(const std::string& str);
std::map<std::string, int> wordsMapCounter(const std::string& str);
std::vector<std::string> uniqueWords(const std::string& str);
int diffWordsCounter(const std::string& str);
std::list<int> reverseNum(std::list<int> nums);
std::vector<int> plusesDeleter(std::vector<int> nums);
std::list<int> Sort(std::list<int> nums);

