#include <iostream>
#include "TestSubjects.h"
#include "TransformTests.h"
#include "FoldTests.h"
#include "SortTests.h"
#include "FindTests.h"
#include <string>
#include <fstream>

#define TEST_COUNT 100000

int main() {
    for (int count = 0; count < TEST_COUNT; ++count) {
        auto subjects = TestSubjects();
        auto sortResults = SortTests::test(subjects);
        auto foldResults = FoldTests::test(subjects);
        auto transformTests = TransformTests::test(subjects);
        auto findTests = FindTests::test(subjects);
    }


}

