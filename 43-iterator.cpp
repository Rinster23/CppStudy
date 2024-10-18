#include <iostream>
#include <vector>
#include <unordered_map>

int main43() {
    std::vector<int> arr = {1, 2, 3, 4, 5, 6};
    for (int value: arr) {
        std::cout << value << std::endl;
    }

    using scoreMap = std::unordered_map<std::string, int>;
    scoreMap myMap;
    myMap["mike"] = 4;
    myMap["nancy"] = 20;
    for (scoreMap::const_iterator it = myMap.begin(); it != myMap.end();
         it++) {
        auto &key = it->first;
        auto &value = it->second;
    }
    for (auto kv: myMap) {
        auto &key = kv.first;
        auto &value = kv.second;
    }
    for (auto [key, value]: myMap) {
        std::cout << key << value << std::endl;
    }
    return 0;
}