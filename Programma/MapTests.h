//
// Created by Koen van Wel on 10/10/2019.
//

#ifndef PROGRAMMA_MAPTESTS_H
#define PROGRAMMA_MAPTESTS_H

#include <vector>
#include <map>
#include <list>
#include <forward_list>
#include <set>
#include <ctime>
using namespace std;

class MapTests {
public:
    static unsigned long halve(unsigned long in);
    static unsigned long keyHalve(pair<unsigned long, unsigned long> in);

    static clock_t vectorHalveTest(vector<unsigned long> col);
    static clock_t listHalveTest(list<unsigned long> col);
    static clock_t forwardListHalveTest(forward_list<unsigned long> col, int size);
    static clock_t setHalveTest(set<unsigned long> col);
    static clock_t arrayHalveTest(unsigned long * col, int size);

    static clock_t mapHalveTest(map<unsigned long, unsigned long> col);
};

#endif //PROGRAMMA_MAPTESTS_H
