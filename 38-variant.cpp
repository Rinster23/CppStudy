#include <iostream>
#include <fstream>
#include <variant> //不知道返回的是什么类型

int main38() {
    std::variant<int, std::string> data;
    data = "nancy";
    data.index();//1
    std::cout << std::get<std::string>(data) << std::endl;
    data = 10;
    data.index();//0
    std::cout << std::get<int>(data) << std::endl;
    if(auto value = std::get_if<std::string>(&data)){
        //如果不匹配返回空指针，匹配就返回指向data的指针
        std::string &v= *value;
    }
    else{
        std::cout << std::get<int>(data) << std::endl;
    }
    return 0;
};