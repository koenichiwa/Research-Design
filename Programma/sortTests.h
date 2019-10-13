//
// Created by Koen van Wel on 11/10/2019.
//

#ifndef PROGRAMMA_SORTTESTS_H
#define PROGRAMMA_SORTTESTS_H


#include <vector>
#include <list>
#include <forward_list>
#include <set>
#include <ctime>

using namespace std;
class sortTests {
public:
    static clock_t vectorSortTest(vector<unsigned long> col);
    static clock_t listSortTest(list<unsigned long> col);
    static clock_t forwardListSortTest(forward_list<unsigned long> col);
    static clock_t setSortTest(set<unsigned long> col);
    static clock_t arraySortTest(unsigned long* begin, unsigned long*  end);
};


#endif //PROGRAMMA_SORTTESTS_H
