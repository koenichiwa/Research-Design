//
// Created by Koen van Wel on 10/10/2019.
//

#include "CollectionGenerators.h"

using namespace std;
vector<unsigned long> CollectionGenerators::getRandomVector(int size) {
    cout << "# Generating vector" << endl;
    random_device randomDevice;
    mt19937 mersenne_engine {randomDevice()};
    uniform_int_distribution<unsigned long> dist {numeric_limits<unsigned int>::min(), numeric_limits<unsigned int>::max()};

    auto gen = [&dist, &mersenne_engine]() { return dist(mersenne_engine); };
    vector<unsigned long>  vec(size);
    generate(begin(vec), end(vec), gen);
    return vec;
}

unsigned long * CollectionGenerators::getRandomArray(int size) {
    auto vector = getRandomVector(size);
    cout << "# Generating array from vector" << endl;
    unsigned long array[size];
    for(int i = 0; i<size; i++)
        array[i] = vector[i];
    return array;
}

list<unsigned long> CollectionGenerators::getRandomList(int size) {
    auto vector = getRandomVector(size);
    cout << "# Generating doubly linked list from vector" << endl;
    return {begin(vector), end(vector)};
}

forward_list<unsigned long> CollectionGenerators::getRandomForwardList(int size) {
    auto vector = getRandomVector(size);
    cout << "# Generating singly linked list from vector" << endl;
    return {begin(vector), end(vector)};
}

std::map<unsigned long, unsigned long> CollectionGenerators::getRandomMap(int size, bool sameValues) {
    map<unsigned long, unsigned long> map {};

    cout << "# Generating set" << endl;
    random_device randomDevice;
    mt19937 mersenne_engine {randomDevice()};
    uniform_int_distribution<unsigned long> dist {numeric_limits<unsigned int>::min(), numeric_limits<unsigned int>::max()};

    while(map.size()<size){
        if(sameValues){
            unsigned long val = dist(mersenne_engine);
            map[val] = val;
        } else {
            map[dist(mersenne_engine)] = dist(mersenne_engine);
        }
    }
    return map;
}

set<unsigned long> CollectionGenerators::getRandomSet(int size) {

    cout << "# Generating set" << endl;
    random_device randomDevice;
    mt19937 mersenne_engine {randomDevice()};
    uniform_int_distribution<unsigned long> dist {numeric_limits<unsigned int>::min(), numeric_limits<unsigned int>::max()};

    auto res = set<unsigned long>();
    while(res.size()<size)
        res.insert(dist(mersenne_engine));
    return res;
}
