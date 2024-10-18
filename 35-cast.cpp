#include <iostream>

namespace file35 {
    class base {
    public:
        base() { std::cout << "base constructed\n"; }

        virtual ~base() { std::cout << "base destroyed\n"; }
        //这里virtual不是代表在子类中可能被覆写，而是说明可能还有一个析构函数需要调用
    };

    class derived : public base {
    public:
        derived() { std::cout << "derived constructed\n"; }

        ~derived() { std::cout << "derived destroyed\n"; }
    };

    class anotherClass : public base {
    public:
        anotherClass() { std::cout << "anotherClass constructed\n"; }

        ~anotherClass() { std::cout << "anotherClass destroyed\n"; }
    };
}
using namespace file35;

int main35() {
    double a = 5.6;
    double b = (int) a + 4.4; //C style
    double s = static_cast<int>(a) + 4.4; //C++ style

    auto another = reinterpret_cast<derived *>(&a);

    derived *de = new derived();
    base *ba = de;
    anotherClass *ac = dynamic_cast<anotherClass*>(ba); //会检查，若转换不成功ac为空指针
    //dynamic_cast沿继承层次的强制类型转换
    return 0;
}