//
// Created by Koen van Wel on 10/10/2019.
//

#ifndef PROGRAMMA_COLLECTIONGENERATORS_H
#define PROGRAMMA_COLLECTIONGENERATORS_H

#include <random>
#include <algorithm>
#include <list>
#include <forward_list>
#include <map>
#include <set>
#include <iostream>

using namespace std;

class CollectionGenerators {
public:
    static vector<unsigned long> getRandomVector(int size);
    static unsigned long * getRandomArray(int size);
    static list<unsigned long> getRandomList(int size); //doubly linked
    static forward_list<unsigned long> getRandomForwardList(int size); // singly linked
    static map<unsigned long, unsigned long> getRandomMap(int size, bool sameValues); // if sameValues is true, both key and value are the same
    static set<unsigned long> getRandomSet(int size);
};


#endif //PROGRAMMA_COLLECTIONGENERATORS_H
