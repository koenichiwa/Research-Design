//
// Created by Koen van Wel on 11/10/2019.
//

#include "FoldTests.h"

unsigned long FoldTests::max(unsigned long acc, unsigned in){ return (acc+in)/2; }

unsigned long FoldTests::keyMax(pair<unsigned long, unsigned long> acc, pair<unsigned long, unsigned long> in){ return (acc.first+in.first)/2; }

clock_t FoldTests::vectorFoldTest(vector<unsigned long> col) {
    auto beginTime = clock();
    reduce(col.begin(), col.end(), 0, FoldTests::max);
    return clock()-beginTime;
}

clock_t FoldTests::setFoldTest(set<unsigned long> col) {
    auto beginTime = clock();
    reduce(col.begin(), col.end(),0, FoldTests::max);
    return clock()-beginTime;
}

clock_t FoldTests::listFoldTest(list<unsigned long> col) {
    auto beginTime = clock();
    reduce(col.begin(), col.end(),0, FoldTests::max);
    return clock()-beginTime;
}

clock_t FoldTests::forwardListFoldTest(forward_list<unsigned long> col) {
    auto beginTime = clock();
    reduce(col.begin(), col.end(),0, FoldTests::max);
    return clock()-beginTime;
}

clock_t FoldTests::arrayFoldTest(unsigned long *col, int size) {
    auto beginTime = clock();
    reduce(col, col+size-1,0, FoldTests::max);
    return clock()-beginTime;
}

//clock_t FoldTests::mapFoldTest(map<unsigned long, unsigned long> col) {
//    auto beginTime = clock();
//    reduce(col.begin(), col.end(),0, FoldTests::keyMax);
//    return clock()-beginTime;
//}