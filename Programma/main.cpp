#include <iostream>
#include "CollectionGenerators.h"
#include "MapTests.h"

int main() {
    int size = 100000; //100_000
    int count = 1000;
    map<string, unsigned long> resMap;
    resMap["vector"] = 0;
    resMap["list"] = 0;
    resMap["forward list"] = 0;
    resMap["set"] = 0;
    resMap["array"] = 0;
    resMap["map"] = 0;
    for(int i = 0; i<count; i++) {
        clock_t clock;
        auto vector = CollectionGenerators::getRandomVector(size);
        clock = MapTests::vectorHalveTest(vector);
        resMap["vector"]+=clock;

        auto list = CollectionGenerators::getRandomList(size);
        clock = MapTests::listHalveTest(list);
        resMap["list"]+=clock;

        auto set = CollectionGenerators::getRandomSet(size);
        clock = MapTests::setHalveTest(set);
        resMap["set"]+=clock;

        auto forwardList = CollectionGenerators::getRandomForwardList(size);
        clock = MapTests::forwardListHalveTest(forwardList, size);
        resMap["forward list"]+= clock;

        auto array = CollectionGenerators::getRandomArray(size);
        clock = MapTests::arrayHalveTest(array, size);
        resMap["array"]+= clock;

        auto map = CollectionGenerators::getRandomMap(size, true);
        clock = MapTests::mapHalveTest(map);
        resMap["map"]+= clock;
    }

    for_each(resMap.begin(), resMap.end(), [](const std::pair<string, unsigned long>& p)
    {
        cout << p.first << ": " << ((long double)p.second/1000) << endl;
    });
    return 0;
}

