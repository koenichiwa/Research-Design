//
// Created by Koen van Wel on 10/10/2019.
//

#include <iostream>
#include "TransformTests.h"

long TransformTests::halve(long in){ return in / 2; }

long TransformTests::keyHalve(pair<long, long> in){ return in.first / 2; }

clock_t TransformTests::vectorTest(vector<long> col) {
    auto store = vector<long>(col.size());
    auto beginTime = clock();
    transform(col.begin().base(), col.end().base(), store.begin(), TransformTests::halve);
    return clock()-beginTime;
}

clock_t TransformTests::doublyListTest(list<long> col) {
    auto store = vector<long>(col.size());
    auto beginTime = clock();
    transform(col.begin(), col.end(), store.begin(), TransformTests::halve);
    return clock()-beginTime;
}

clock_t TransformTests::singlyListTest(forward_list<long> col) {
    long store[SUBJECT_SIZE];
    auto beginTime = clock();
    transform(col.begin(), col.end(), store, TransformTests::halve);
    return clock()-beginTime;
}

clock_t TransformTests::arrayTest(long *begin, long *end) {
    long store[SUBJECT_SIZE];
    auto beginTime = clock();
    transform(begin, end, store, TransformTests::halve);
    return clock()-beginTime;
}



TestResults TransformTests::test(TestSubjects subjects) {
    return TestResults (
            arrayTest(subjects.array, subjects.array+SUBJECT_SIZE-1),
            vectorTest(subjects.vector),
            singlyListTest(subjects.singlyList),
            doublyListTest(subjects.doublyList)
    );
}