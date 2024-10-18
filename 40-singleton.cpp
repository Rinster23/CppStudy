#include <iostream>
//  这个类只允许有一个实例

namespace file40 {
    class random {
    private:
        random() = default;;
        float random_floatNumber = 0.33;//假定这是个随机数

        float I_get_random() const { return random_floatNumber; }

    public:
        random(const random &) = delete; //删除拷贝构造函数
        static random &Get() {
            static random instance;
            return instance;
        }

        static float get_random() { return Get().I_get_random(); }
    };
}
using namespace file40;

int main40() {
    float m = random::get_random();
    std::cout << m << std::endl;
    return 0;
}