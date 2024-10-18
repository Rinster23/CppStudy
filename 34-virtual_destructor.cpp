#include <iostream>

namespace file34 {
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
}
using namespace file34;

int main34(){
    base *b = new base();
    delete b;
    std::cout << "--------------------\n";
    derived *d = new derived();
    delete d;
    std::cout << "--------------------\n";
    base *poly = new derived();
    delete poly;    //没有virtual的话少删除一个derived对象
    return 0;
}