//
// Created by Koen van Wel on 10/10/2019.
//

#include "TestSubjects.h"
#include <iostream>

std::vector<long> TestSubjects::getRandomVector(unsigned int size) {
    std::cout << "# Generating vector" << std::endl;
    std::random_device randomDevice;
    std::mt19937 mersenne_engine {randomDevice()};
    std::uniform_int_distribution<long> dist {
        std::numeric_limits<unsigned int>::min(), std::numeric_limits<unsigned int>::max()
    };

    auto gen = [&dist, &mersenne_engine]() { return dist(mersenne_engine); };
    std::vector<long>  vec(size);
    generate(begin(vec), end(vec), gen);
    return vec;
}

void TestSubjects::fillArray(const std::vector<long> &vec) {
    std::cout << "# Generating array from vector" << std::endl;
    auto size = vec.size();
    for(int i = 0; i<size; i++)
        array[i] = vector[i];
}

std::list<long> TestSubjects::fillList(std::vector<long> vec) {
    std::cout << "# Generating doubly linked list from vector" << std::endl;
    return {begin(vec), end(vec)};
}

std::forward_list<long> TestSubjects::fillForwardList(std::vector<long> vec) {
    std::cout << "# Generating singly linked list from vector" << std::endl;
    return {begin(vec), end(vec)};
}