//
// Created by Koen van Wel on 11/10/2019.
//

#ifndef PROGRAMMA_FOLDTESTS_H
#define PROGRAMMA_FOLDTESTS_H

#include <vector>
#include <list>
#include <forward_list>
#include <ctime>
#include <numeric>
#include "TestResults.h"
#include "TestSubjects.h"

using namespace std;

class FoldTests {
    static long max(long acc, unsigned in);
    static clock_t vectorTest(vector<long> col);
    static clock_t doublyListTest(list<long> col);
    static clock_t singlyListTest(forward_list<long> col);
    static clock_t arrayTest(long* begin, long*  end);
public:
    static TestResults test(TestSubjects subjects);
};


#endif //PROGRAMMA_FOLDTESTS_H
