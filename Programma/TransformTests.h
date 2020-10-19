//
// Created by Koen van Wel on 10/10/2019.
//

#ifndef PROGRAMMA_TRANSFORMTESTS_H
#define PROGRAMMA_TRANSFORMTESTS_H

#include <vector>
#include <list>
#include <forward_list>
#include <ctime>
#include "TestResults.h"
#include "TestSubjects.h"

using namespace std;

class TransformTests {
    static long halve(long in);
    static long keyHalve(pair<long, long> in);
    static clock_t vectorTest(vector<long> col);
    static clock_t doublyListTest(list<long> col);
    static clock_t singlyListTest(forward_list<long> col);
    static clock_t arrayTest(long* begin, long*  end);

public:
    static TestResults test(TestSubjects subjects);

};

#endif //PROGRAMMA_TRANSFORMTESTS_H
