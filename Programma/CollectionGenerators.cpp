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
    vector<unsigned long> vec1, vec2;
    int count = 0;

    while(map.size() != size) {
        count++;
        vec1 = getRandomVector(size);
        if (sameValues) {
            vec2 = vec1;
        } else {
            vec2 = getRandomVector(size);
        }

        cout << "# Generating map from vector, try " << count << endl;
        transform(
                vec1.begin(),
                vec1.end(),
                vec2.begin(),
                inserter(map, map.end()),
                make_pair<unsigned long const &, unsigned long const &>
        );
    }

    return map;
}

set<unsigned long> CollectionGenerators::getRandomSet(int size) {
    set<unsigned long> set {};
    int count = 0;
    while(set.size()!=size) { // check if set didn't ommit double values
        count++;
        auto vec = getRandomVector(size);
        cout << "# Generating set from vector, try " << count << endl;
        set = { begin(vec), end(vec) };
    }
    return set;
}
