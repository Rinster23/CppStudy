#include <iostream>
#include <array>
#include <string>
#include <vector>

void printValue(int a) {
    std::cout << "Value:" << a << std::endl;
}

void forEach(const std::vector<int> &vec, void(*fun)(int)) {
    for (int value: vec) {
        fun(value);
    }
}

int main28() {
    typedef void(*fun)(int);
    fun function = printValue;
    function(7);

    auto haha = printValue;
    haha(10);

    std::vector<int> ar = {1, 2, 3, 4, 5};
    forEach(ar, printValue);
    forEach(ar, [](int a){std::cout << "Value:" << a << std::endl;}); //匿名函数
    return 0;
}