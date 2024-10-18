#include <iostream>
#include <vector>

namespace file23 {
    struct Vec2 {
        int x, y;

        Vec2(int x, int y)
                : x(x), y(y) {}

        Vec2(const Vec2 &v)
                : x(v.x), y(v.y) {
            std::cout << "copy!" << std::endl;
        }
    };

}
using namespace file23;

int main23() {
    std::vector<int> li;
    li.push_back(7);
    li.push_back(8);
    int len = li.size();
    for (int &v: li) {//不复制
        std::cout << v << std::endl;
    }
    li.erase(li.begin() + 1);//删除第二个元素

    std::vector<Vec2> li2;
//    li2.push_back({1,2});//main中创建，复制到列表中
//    li2.push_back({3,4});//到此复制共三次，resize array，复制了一次(1,2)到新的array中
//    li2.push_back({5,6}); //这样写复制6次
//    改进：
    li2.reserve(3);
    li2.emplace_back(1,2);
    li2.emplace_back(3,4);
    li2.emplace_back(5,6);//没有copy
    return 0;
}