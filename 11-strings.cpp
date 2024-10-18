#include <iostream>
#include <string>

void printString(const std::string &str) {
    std::cout << str << std::endl;
}

int main11() {
    std::string name = "nancy";// + "hello"报错
    name[0] = 'N';
    name += "hello";    //+=被override了
    bool contain = name.find("he") != std::string::npos; //npos就是找不到
    int po = name.find("he");
    std::cout << po << std::endl;
    char name2[6] = {'N', 'a', 'n', 'c', 'y', 0};
    std::cout << name2 << std::endl;

    printString("str");
    return 0;
}

