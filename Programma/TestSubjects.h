//
// Created by Koen van Wel on 10/10/2019.
//

#ifndef PROGRAMMA_TESTSUBJECTS_H
#define PROGRAMMA_TESTSUBJECTS_H

#include <random>
#include <algorithm>
#include <list>
#include <forward_list>
#include <map>
#include <set>
#include <iostream>

#define SUBJECT_SIZE 100000

struct TestSubjects {
    std::vector<long> vector;
    long array[SUBJECT_SIZE];
    std::list<long> doublyList;
    std::forward_list<long> singlyList;

    TestSubjects() :
        vector(getRandomVector(SUBJECT_SIZE)),
        doublyList(fillList(vector)),
        singlyList(fillForwardList(vector))
        {
            fillArray(vector);
        }

private:
    static std::vector<long> getRandomVector(unsigned int size);
    void fillArray(std::vector<long> vector);
    static std::list<long> fillList(std::vector<long> vector); //doubly linked
    static std::forward_list<long> fillForwardList(std::vector<long> vector); // singly linked
};


#endif //PROGRAMMA_TESTSUBJECTS_H
