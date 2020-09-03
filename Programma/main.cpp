#include <iostream>
#include "TestSubjects.h"
#include "TransformTests.h"
#include "FoldTests.h"
#include "SortTests.h"
#include "FindTests.h"
#include <string>
#include <fstream>
#include <json/json.h>

#define TEST_COUNT 10000

class results {
public:
    std::vector<clock_t> sortResults;
    std::vector<clock_t> foldResults;
    std::vector<clock_t> transformResults;
    std::vector<clock_t> findResults;
};

void saveData(results arrayResults, results vectorResults, results singlyListResults, results doublyListResults){
    std::cout << "## Saving data" << std::endl;
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
        array["sort"].append(Json::Value((u_int64_t)arrayResults.sortResults[i]));
        array["fold"].append(Json::Value((u_int64_t)arrayResults.foldResults[i]));
        array["transform"].append(Json::Value((u_int64_t)arrayResults.transformResults[i]));
        array["find"].append(Json::Value((u_int64_t)arrayResults.findResults[i]));

        vector["sort"].append(Json::Value((u_int64_t)vectorResults.sortResults[i]));
        vector["fold"].append(Json::Value((u_int64_t)vectorResults.foldResults[i]));
        vector["transform"].append(Json::Value((u_int64_t)vectorResults.transformResults[i]));
        vector["find"].append(Json::Value((u_int64_t)vectorResults.findResults[i]));

        singlyList["sort"].append(Json::Value((u_int64_t)singlyListResults.sortResults[i]));
        singlyList["fold"].append(Json::Value((u_int64_t)singlyListResults.foldResults[i]));
        singlyList["transform"].append(Json::Value((u_int64_t)singlyListResults.transformResults[i]));
        singlyList["find"].append(Json::Value((u_int64_t)singlyListResults.findResults[i]));

        doublyList["sort"].append(Json::Value((u_int64_t)doublyListResults.sortResults[i]));
        doublyList["fold"].append(Json::Value((u_int64_t)doublyListResults.foldResults[i]));
        doublyList["transform"].append(Json::Value((u_int64_t)doublyListResults.transformResults[i]));
        doublyList["find"].append(Json::Value((u_int64_t)doublyListResults.findResults[i]));
    }

    Json::Value root;
    root["array"] = array;
    root["vector"] = vector;
    root["singlyList"] =  singlyList;
    root["doublyList"] = doublyList;

    std::ofstream file("results.json");
    auto writer = std::unique_ptr<Json::StreamWriter>(Json::StreamWriterBuilder().newStreamWriter());
    writer->write(root, &file);
    file.close();
}

int main() {
    auto arrayResults = results();
    auto vectorResults = results();
    auto singlyListResults = results();
    auto doublyListResults = results();
    for (int count = 0; count < TEST_COUNT; ++count) {
        std::cout << "### Testcount:" << count << std::endl;
        auto subjects = TestSubjects();
        {
            auto sortResults = SortTests::test(subjects);
            std::cout << "## Adding sort test results" << std::endl;
            arrayResults.sortResults.push_back(sortResults.arrayResult);
            vectorResults.sortResults.push_back(sortResults.vectorResult);
            singlyListResults.sortResults.push_back(sortResults.singlyListResult);
            doublyListResults.sortResults.push_back(sortResults.doublyListResult);
        }
        {
            auto foldResults = FoldTests::test(subjects);
            std::cout << "## Adding fold test results" << std::endl;
            arrayResults.foldResults.push_back(foldResults.arrayResult);
            vectorResults.foldResults.push_back(foldResults.vectorResult);
            singlyListResults.foldResults.push_back(foldResults.singlyListResult);
            doublyListResults.foldResults.push_back(foldResults.doublyListResult);
        }
        {
            auto transformResults = TransformTests::test(subjects);
            std::cout << "## Adding transform test results" << std::endl;
            arrayResults.transformResults.push_back(transformResults.arrayResult);
            vectorResults.transformResults.push_back(transformResults.vectorResult);
            singlyListResults.transformResults.push_back(transformResults.singlyListResult);
            doublyListResults.transformResults.push_back(transformResults.doublyListResult);
        }
        {
            auto findResults = FindTests::test(subjects);
            std::cout << "## Adding find test results" << std::endl;
            arrayResults.findResults.push_back(findResults.arrayResult);
            vectorResults.findResults.push_back(findResults.vectorResult);
            singlyListResults.findResults.push_back(findResults.singlyListResult);
            doublyListResults.findResults.push_back(findResults.doublyListResult);
        }
    }
    
    saveData(arrayResults, vectorResults, singlyListResults, doublyListResults);

    std::cout << "### Thank you, come again!" << std::endl;
}



