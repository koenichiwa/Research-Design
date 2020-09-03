//
// Created by Koen van Wel on 11/10/2019.
//

#include "FoldTests.h"

long FoldTests::max(long acc, unsigned in){ return (acc+in)/2; }

clock_t FoldTests::vectorTest(vector<long> col) {
    auto beginTime = clock();
    reduce(col.begin().base(), col.end().base(), 0, FoldTests::max);
    return clock()-beginTime;
}

clock_t FoldTests::doublyListTest(list<long> col) {
    auto beginTime = clock();
    reduce(col.begin(), col.end(),0, FoldTests::max);
    return clock()-beginTime;
}

clock_t FoldTests::singlyListTest(forward_list<long> col) {
    auto beginTime = clock();
    reduce(col.begin(), col.end(),0, FoldTests::max);
    return clock()-beginTime;
}

clock_t FoldTests::arrayTest(long *begin, long *end) {
    auto beginTime = clock();
    reduce(begin, end,0, FoldTests::max);
    return clock()-beginTime;
}

TestResults FoldTests::test(TestSubjects subjects) {
    return TestResults (
            arrayTest(subjects.array, subjects.array+SUBJECT_SIZE-1),
            vectorTest(subjects.vector),
            singlyListTest(subjects.singlyList),
            doublyListTest(subjects.doublyList)
    );
}