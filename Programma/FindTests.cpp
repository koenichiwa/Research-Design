//
// Created by Koen van Wel on 13/10/2019.
//

#include "FindTests.h"



clock_t FindTests::vectorFindTest(vector<unsigned long> col) {
    auto beginTime = clock();
    find_if(col.begin(), col.end(), pred);
    return clock()-beginTime;
}

bool FindTests::pred(const unsigned long &a, const unsigned long &b) {
    return false;
}

clock_t FindTests::listFindTest(list<unsigned long> col) {
    auto beginTime = clock();
    find_if(col.begin(), col.end(), pred);
    return clock()-beginTime;
}

clock_t FindTests::forwardListFindTest(forward_list<unsigned long> col) {
    auto beginTime = clock();
    find_if(col.begin(), col.end(), pred);
    return clock()-beginTime;
}

clock_t FindTests::setFindTest(set<unsigned long> col) {
    auto beginTime = clock();
    find_if(col.begin(), col.end(), pred);
    return clock()-beginTime;
}

clock_t FindTests::arrayFindTest(unsigned long *begin, unsigned long *end) {
    auto beginTime = clock();
    find_if(begin, end, pred);
    return clock()-beginTime;
}
