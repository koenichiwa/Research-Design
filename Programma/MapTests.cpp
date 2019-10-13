//
// Created by Koen van Wel on 10/10/2019.
//

#include <iostream>
#include "MapTests.h"

unsigned long MapTests::halve(unsigned long in){ return in/2; }

unsigned long MapTests::keyHalve(pair<unsigned long, unsigned long> in){ return in.first/2; }

clock_t MapTests::vectorHalveTest(vector<unsigned long> col) {
    auto store = vector<unsigned long>(col.size());
    auto beginTime = clock();
    transform(col.begin().base(), col.end().base(), store.begin(), MapTests::halve);
    return clock()-beginTime;
}

clock_t MapTests::setHalveTest(set<unsigned long> col) {
    auto store = vector<unsigned long>(col.size());
    auto beginTime = clock();
    transform(col.begin(), col.end(), store.begin(), MapTests::halve);
    return clock()-beginTime;
}

clock_t MapTests::listHalveTest(list<unsigned long> col) {
    auto store = vector<unsigned long>(col.size());
    auto beginTime = clock();
    transform(col.begin(), col.end(), store.begin(), MapTests::halve);
    return clock()-beginTime;
}

clock_t MapTests::forwardListHalveTest(forward_list<unsigned long> col, int size) {
    auto store = vector<unsigned long>(size);
    auto beginTime = clock();
    transform(col.begin(), col.end(), store.begin(), MapTests::halve);
    return clock()-beginTime;
}

clock_t MapTests::arrayHalveTest(unsigned long *col, int size) {
    auto store = vector<unsigned long>(size);
    auto beginTime = clock();
    transform(col, col+size-1, store.begin(), MapTests::halve);
    return clock()-beginTime;
}

clock_t MapTests::mapHalveTest(map<unsigned long, unsigned long> col) {
    auto store = vector<unsigned long>(col.size());
    auto beginTime = clock();
    transform(col.begin(), col.end(), store.begin(), MapTests::keyHalve);

    return clock()-beginTime;
}
