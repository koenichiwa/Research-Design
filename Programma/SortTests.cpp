//
// Created by Koen van Wel on 11/10/2019.
//

#include "SortTests.h"


clock_t SortTests::vectorTest(vector<long> col) {
    auto beginTime = clock();
    sort(begin(col), end(col));
    return clock()-beginTime;
}

clock_t SortTests::doublyListTest(list<long> col) {
    auto beginTime = clock();
    col.sort();
    return clock()-beginTime;
}

clock_t SortTests::singlyListTest(forward_list<long> col) {
    auto beginTime = clock();
    col.sort();
    return clock()-beginTime;
}

clock_t SortTests::arrayTest(long *begin, long *end) {
    auto beginTime = clock();
    sort(begin, end);
    return clock()-beginTime;
}

TestResults SortTests::test(TestSubjects subjects) {
    return TestResults (
        arrayTest(subjects.array, subjects.array+SUBJECT_SIZE-1),
        vectorTest(subjects.vector),
        singlyListTest(subjects.singlyList),
        doublyListTest(subjects.doublyList)
    );
}