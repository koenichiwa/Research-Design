//
// Created by Koen van Wel on 11/10/2019.
//

#ifndef PROGRAMMA_FOLDTESTS_H
#define PROGRAMMA_FOLDTESTS_H

#include <vector>
#include <map>
#include <list>
#include <forward_list>
#include <set>
#include <ctime>
#include <numeric>
using namespace std;

class FoldTests {
    static unsigned long max(unsigned long acc, unsigned in);
    static unsigned long keyMax(pair<unsigned long, unsigned long> acc, pair<unsigned long, unsigned long> in);

public:
    static clock_t vectorFoldTest(vector<unsigned long> col);
    static clock_t listFoldTest(list<unsigned long> col);
    static clock_t forwardListFoldTest(forward_list<unsigned long> col);
    static clock_t setFoldTest(set<unsigned long> col);
    static clock_t arrayFoldTest(unsigned long * col, int size);

    //static clock_t mapFoldTest(map<unsigned long, unsigned long> col);
};


#endif //PROGRAMMA_FOLDTESTS_H
