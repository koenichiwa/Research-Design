//
// Created by Koen van Wel on 11/10/2019.
//

#include "sortTests.h"


clock_t sortTests::vectorSortTest(vector<unsigned long> col) {
    auto beginTime = clock();
    sort(col.begin().base(), col.end().base(), greater<long long>());
    return clock()-beginTime;
}

clock_t sortTests::listSortTest(list<unsigned long> col) {
    auto beginTime = clock();
    sort(col.begin(), col.end(), greater<long long>());
    return clock()-beginTime;
}

clock_t sortTests::forwardListSortTest(forward_list<unsigned long> col) {
    auto beginTime = clock();
    sort(col.begin(), col.end(), greater<long long>());
    return clock()-beginTime;
}

clock_t sortTests::setSortTest(set<unsigned long> col) {
    auto beginTime = clock();
    sort(col.begin(), col.end(), greater<long long>());
    return clock()-beginTime;
}

clock_t sortTests::arraySortTest(unsigned long *begin, unsigned long *end) {
    auto beginTime = clock();
    sort(begin, end, greater<long long>());
    return clock()-beginTime;
}
