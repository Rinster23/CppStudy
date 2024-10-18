#include <iostream>
#include <algorithm>
#include <vector>
#include <functional>

int main32() {
    std::vector<int> values = {3, 6, 4, 7, 9, 1};
    std::sort(values.begin(), values.end()); //默认从小到大排序
    std::sort(values.begin(), values.end(), std::greater<int>());//从大到小排序
    std::sort(values.begin(), values.end(), [](int a, int b) {
        if (a == 1) {
            return false;
        }
        if (b == 1) {
            return true;
        }
        return a < b;
    });
    //返回true,a排在b前面
    return 0;
}