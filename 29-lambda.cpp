#include <iostream>
#include <algorithm>
#include <vector>
#include <functional>

void forEach(const std::vector<int> &vec, const std::function<void(int)> &fun) {
    for (int value: vec) {
        fun(value);
    }
}

int main29() {
    std::vector<int> ar = {1, 2, 3, 4, 5};
    int a = 5;
    auto lambda = [&](int value) {
        a = 1;
        std::cout << "Value:" << a << std::endl;
    };
    //[=]复制[&]引用
//    auto lambda = [=](int value) mutable{
//        a = 1;
//        std::cout << "Value:" << a << std::endl;
//    };
    forEach(ar, lambda);

    auto iterator = std::find_if(ar.begin(), ar.end(), [](int value) { return value > 3; });
    std::cout << *iterator << std::endl;
    return 0;
}