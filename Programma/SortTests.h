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
#include "TestResults.h"
#include "TestSubjects.h"

using namespace std;
class SortTests {
    static clock_t vectorTest(vector<long> col);
    static clock_t doublyListTest(list<long> col);
    static clock_t singlyListTest(forward_list<long> col);
    static clock_t arrayTest(long* begin, long*  end);
public:
    static TestResults test(TestSubjects subjects);
};


#endif //PROGRAMMA_SORTTESTS_H
