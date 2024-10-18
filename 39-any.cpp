#include <iostream>
#include <any> //可以将它设为任何类型

int main39() {
    std::any data;
    data = 2;
    data = "like";
    data = std::string("hello");
    std::string &string = std::any_cast<std::string &>(data);
    return 0;
}