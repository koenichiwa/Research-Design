//
// Created by Koen van Wel on 13/10/2019.
//

#include "FindTests.h"
bool FindTests::pred(const long &a) {
    return a == 1;
}

clock_t FindTests::vectorTest(vector<long> col) {
    auto beginTime = clock();
    find_if(col.begin(), col.end(), pred);
    return clock()-beginTime;
}

clock_t FindTests::doublyListTest(list<long> col) {
    auto beginTime = clock();
    find_if(begin(col), end(col), pred);
    return clock()-beginTime;
}

clock_t FindTests::singlyListTest(forward_list<long> col) {
    auto beginTime = clock();
    find_if(col.begin(), col.end(), pred);
    return clock()-beginTime;
}

clock_t FindTests::arrayTest(long *begin, long *end) {
    auto beginTime = clock();
    find_if(begin, end, pred);
    return clock()-beginTime;
}
TestResults FindTests::test(TestSubjects subjects) {
    return TestResults (
            arrayTest(subjects.array, subjects.array+SUBJECT_SIZE-1),
            vectorTest(subjects.vector),
            singlyListTest(subjects.singlyList),
            doublyListTest(subjects.doublyList)
    );
}

