#include <iostream>
#include "CollectionGenerators.h"
#include "MapTests.h"
#include "FoldTests.h"
#include <string>


int main() {
    const int size = 100000; //100_000
    const int count = 1000;
    map<string, unsigned long> resMap;
    resMap["vector"] = 0;
    resMap["list"] = 0;
    resMap["forward list"] = 0;
    resMap["set"] = 0;
    resMap["array"] = 0;
    resMap["map"] = 0;
    map<string, unsigned long> resFold;
    resFold["vector"] = 0;
    resFold["list"] = 0;
    resFold["forward list"] = 0;
    resFold["set"] = 0;
    resFold["array"] = 0;
    resFold["map"] = 0;
    for(int i = 0; i<count; i++) {
        clock_t clock;
        auto vector = CollectionGenerators::getRandomVector(size);
        clock = MapTests::vectorHalveTest(vector);
        resMap["vector"]+=clock;
        clock = FoldTests::vectorFoldTest(vector);
        resFold["vector"]+=clock;

        auto list = CollectionGenerators::getRandomList(size);
        clock = MapTests::listHalveTest(list);
        resMap["list"]+=clock;
        clock = FoldTests::listFoldTest(list);
        resFold["list"]+=clock;

        auto set = CollectionGenerators::getRandomSet(size);
        clock = MapTests::setHalveTest(set);
        resMap["set"]+=clock;
        clock = FoldTests::setFoldTest(set);
        resFold["set"]+=clock;

        auto forwardList = CollectionGenerators::getRandomForwardList(size);
        clock = MapTests::forwardListHalveTest(forwardList, size);
        resMap["forward list"]+= clock;
        clock = FoldTests::forwardListFoldTest(forwardList);
        resFold["forward list"]+=clock;

        auto array = CollectionGenerators::getRandomArray(size);
        clock = MapTests::arrayHalveTest(array, size);
        resMap["array"]+= clock;
        clock = FoldTests::arrayFoldTest(array, size);
        resFold["array"]+=clock;
//
//        auto map = CollectionGenerators::getRandomMap(size, true);
//        clock = MapTests::mapHalveTest(map);
//        resMap["map"]+= clock;
    }

    string json = "map: {\n";

    auto stringMap = vector<string>(size*2);
    transform(resMap.begin(), resMap.end(), stringMap.begin(), [](const std::pair<string, unsigned long>& p){
        return p.first + " = " + to_string((long double)p.second/count) + "\n";
    });

    auto stringFold = vector<string>(size*2);
    transform(resFold.begin(), resFold.end(), stringFold.begin(), [](const std::pair<string, unsigned long>& p){
        return p.first + " = " + std::to_string((long double)p.second/count) + "\n";
    });

    for(auto& s: stringMap){
        json += s;
    }

    json+= "}\nfold:{\n";
    for(auto& s: stringFold){
        json += s;
    }

    json+="}";
    cout << json;
    return 0;
}

