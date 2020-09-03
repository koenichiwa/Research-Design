//
// Created by Koen van Wel on 02/09/2020.
//

#ifndef PROGRAMMA_TESTRESULTS_H
#define PROGRAMMA_TESTRESULTS_H


#include <ctime>

class TestResults {
public:
    TestResults(
            clock_t array,
            clock_t vector,
            clock_t singlyList,
            clock_t doublyList
            ) : arrayResult(array),
            vectorResult(vector),
            singlyListResult(singlyList),
            doublyListResult(doublyList)
            {};
    clock_t arrayResult;
    clock_t vectorResult;
    clock_t singlyListResult;
    clock_t doublyListResult;
};


#endif //PROGRAMMA_TESTRESULTS_H
