#include <iostream>
#include "TestSubjects.h"
#include "TransformTests.h"
#include "FoldTests.h"
#include "SortTests.h"
#include "FindTests.h"
#include <string>
#include <fstream>
#include <utility>
#include <json/json.h>
#include <sys/resource.h>
#include <unistd.h>

#define TEST_COUNT 100
#define SAMPLE_COUNT 1000

struct results {
    std::vector<clock_t> sortResults;
    std::vector<clock_t> foldResults;
    std::vector<clock_t> transformResults;
    std::vector<clock_t> findResults;
};

struct means {
    std::vector<double> sortMeans;
    std::vector<double> foldMeans;
    std::vector<double> transformMeans;
    std::vector<double> findMeans;
};

std::vector<double> getAvg(results results) {
    std::vector<double> res;
    double size = TEST_COUNT;

    res.push_back(((double)std::accumulate(results.sortResults.begin(), results.sortResults.end(), 0UL)) / size);
    res.push_back(((double)std::accumulate(results.foldResults.begin(), results.foldResults.end(), 0UL))/size);
    res.push_back(((double)std::accumulate(results.transformResults.begin(), results.transformResults.end(), 0UL))/size);
    res.push_back(((double)std::accumulate(results.findResults.begin(), results.findResults.end(), 0UL))/size);

    return res;
}

void saveData(
        vector<double> calibrateMeans,
        means arrayMeans,
        means vectorMeans,
        means singlyListMeans,
        means doublyListMeans
){
    std::cout << "## Saving data" << std::endl;

    auto calibrate = Json::Value(Json::arrayValue);

    auto array = Json::Value();
    array["sort"] = Json::Value(Json::arrayValue);
    array["fold"] = Json::Value(Json::arrayValue);
    array["transform"] = Json::Value(Json::arrayValue);
    array["find"] = Json::Value(Json::arrayValue);

    auto vector = Json::Value();
    vector["sort"] = Json::Value(Json::arrayValue);
    vector["fold"] = Json::Value(Json::arrayValue);
    vector["transform"] = Json::Value(Json::arrayValue);
    vector["find"] = Json::Value(Json::arrayValue);

    auto singlyList = Json::Value();
    singlyList["sort"] = Json::Value(Json::arrayValue);
    singlyList["fold"] = Json::Value(Json::arrayValue);
    singlyList["transform"] = Json::Value(Json::arrayValue);
    singlyList["find"] = Json::Value(Json::arrayValue);

    auto doublyList = Json::Value();
    doublyList["sort"] = Json::Value(Json::arrayValue);
    doublyList["fold"] = Json::Value(Json::arrayValue);
    doublyList["transform"] = Json::Value(Json::arrayValue);
    doublyList["find"] = Json::Value(Json::arrayValue);

    for (int i = 0; i < TEST_COUNT; i++) {
        calibrate.append(calibrateMeans[i]);

        array["sort"].append(Json::Value(arrayMeans.sortMeans[i]));
        array["fold"].append(Json::Value(arrayMeans.foldMeans[i]));
        array["transform"].append(Json::Value(arrayMeans.transformMeans[i]));
        array["find"].append(Json::Value(arrayMeans.findMeans[i]));

        vector["sort"].append(Json::Value(vectorMeans.sortMeans[i]));
        vector["fold"].append(Json::Value(vectorMeans.foldMeans[i]));
        vector["transform"].append(Json::Value(vectorMeans.transformMeans[i]));
        vector["find"].append(Json::Value(vectorMeans.findMeans[i]));

        singlyList["sort"].append(Json::Value(singlyListMeans.sortMeans[i]));
        singlyList["fold"].append(Json::Value(singlyListMeans.foldMeans[i]));
        singlyList["transform"].append(Json::Value(singlyListMeans.transformMeans[i]));
        singlyList["find"].append(Json::Value(singlyListMeans.findMeans[i]));

        doublyList["sort"].append(Json::Value(doublyListMeans.sortMeans[i]));
        doublyList["fold"].append(Json::Value(doublyListMeans.foldMeans[i]));
        doublyList["transform"].append(Json::Value(doublyListMeans.transformMeans[i]));
        doublyList["find"].append(Json::Value(doublyListMeans.findMeans[i]));
    }

    Json::Value root;
    root["calibrate"] = calibrate;
    root["array"] = array;
    root["vector"] = vector;
    root["singlyList"] =  singlyList;
    root["doublyList"] = doublyList;

    std::ofstream file("results_cali.json");
    auto writer = std::unique_ptr<Json::StreamWriter>(Json::StreamWriterBuilder().newStreamWriter());
    writer->write(root, &file);
    file.close();
}

void addMeans(results results, means* means){
    auto mean = getAvg(std::move(results));
    means->sortMeans.push_back(mean[0]);
    means->foldMeans.push_back(mean[1]);
    means->transformMeans.push_back(mean[2]);
    means->findMeans.push_back(mean[3]);
}

int main() {
    means arrayMeans;
    means vectorMeans;
    means singlyListMeans;
    means doublyListMeans;
    vector<double> calibrateMeans;

    setpriority(PRIO_PROCESS, getpid(), INT32_MIN);

    for (int sampleN = 0; sampleN < SAMPLE_COUNT; ++sampleN) {
        std::cout << "### Sample count:" << sampleN << std::endl;
        results arrayResults;
        results vectorResults;
        results singlyListResults;
        results doublyListResults;
        std::vector<clock_t> calibrateResults;

        for (int count = 0; count < TEST_COUNT; ++count) {
            std::cout << "## Test count:" << count << std::endl;

            auto beginTime = clock();

            auto subjects = TestSubjects();
            {
                auto sortResults = SortTests::test(subjects);
                std::cout << "# Adding sort test results" << std::endl;
                arrayResults.sortResults.push_back(sortResults.arrayResult);
                vectorResults.sortResults.push_back(sortResults.vectorResult);
                singlyListResults.sortResults.push_back(sortResults.singlyListResult);
                doublyListResults.sortResults.push_back(sortResults.doublyListResult);
            }
            {
                auto foldResults = FoldTests::test(subjects);
                std::cout << "# Adding fold test results" << std::endl;
                arrayResults.foldResults.push_back(foldResults.arrayResult);
                vectorResults.foldResults.push_back(foldResults.vectorResult);
                singlyListResults.foldResults.push_back(foldResults.singlyListResult);
                doublyListResults.foldResults.push_back(foldResults.doublyListResult);
            }
            {
                auto transformResults = TransformTests::test(subjects);
                std::cout << "# Adding transform test results" << std::endl;
                arrayResults.transformResults.push_back(transformResults.arrayResult);
                vectorResults.transformResults.push_back(transformResults.vectorResult);
                singlyListResults.transformResults.push_back(transformResults.singlyListResult);
                doublyListResults.transformResults.push_back(transformResults.doublyListResult);
            }
            {
                auto findResults = FindTests::test(subjects);
                std::cout << "# Adding find test results" << std::endl;
                arrayResults.findResults.push_back(findResults.arrayResult);
                vectorResults.findResults.push_back(findResults.vectorResult);
                singlyListResults.findResults.push_back(findResults.singlyListResult);
                doublyListResults.findResults.push_back(findResults.doublyListResult);
            }

            calibrateResults.push_back(clock()-beginTime);
        }
        calibrateMeans.push_back((
                (double) std::accumulate(
                    calibrateResults.begin(),
                    calibrateResults.end(),
                    0UL)
            ) / calibrateResults.size()
        );
        addMeans(arrayResults, &arrayMeans);
        addMeans(vectorResults, &vectorMeans);
        addMeans(singlyListResults, &singlyListMeans);
        addMeans(doublyListResults, &doublyListMeans);
    }

    saveData(calibrateMeans, arrayMeans, vectorMeans, singlyListMeans, doublyListMeans);

    std::cout << "### Thank you, come again!" << std::endl;
}



