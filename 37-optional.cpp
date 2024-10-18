#include <iostream>
#include <fstream>
#include <optional> //不知道有没有返回

namespace file37 {
    std::optional<std::string> readFile(const std::string &filePath) {
        std::ifstream stream(filePath);
        if (stream) {
            std::string res;
            //read file
            stream.close();
            return res;
        }
        return {};
    }
}
using namespace file37;
int main37() {
    auto data = readFile("data.txt");
    std::string value = data.value_or("data not present");//若没有读取到东西，设置默认值
    if (data.has_value()) {
        std::cout << "read successfully" << std::endl;
    } else {
        std::cout << "file cannot open" << std::endl;
    }
    return 0;
}