//
// Created by Koen van Wel on 13/10/2019.
//

#ifndef PROGRAMMA_FINDTESTS_H
#define PROGRAMMA_FINDTESTS_H

#include <vector>
#include <list>
#include <forward_list>
#include <set>
#include <ctime>

using namespace std;
class FindTests {
    static bool pred(const unsigned long &a, const unsigned long &b);

public:
    static clock_t vectorFindTest(vector<unsigned long> col);
    static clock_t listFindTest(list<unsigned long> col);
    static clock_t forwardListFindTest(forward_list<unsigned long> col);
    static clock_t setFindTest(set<unsigned long> col);
    static clock_t arrayFindTest(unsigned long* begin, unsigned long*  end);
};


#endif //PROGRAMMA_FINDTESTS_H
