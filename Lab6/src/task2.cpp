#include "../include/lab.hpp"

std::vector<int>::iterator findInSorted(std::vector<int>::iterator first, std::vector<int>::iterator last, int el) 
{
    auto it = first + (last - first) / 2;
    if  (*it == el) 
        return it;
    if(*it > el) 
        return findInSorted(first,it,el);
    if(*it < el) 
        return findInSorted(it,last,el);
    return last;
}