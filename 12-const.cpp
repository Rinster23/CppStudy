#include <iostream>
#include <string>

namespace file12 {
    class sth {
    public:
        int x, y;
        //int *p_x, *p_y; //这样写是定义两个指针
        mutable char m;
        int getX() const {   //const表示不能修改类
            m = 'A'; //但是constant中可以改变mutable的
            return x;
        }
    };

    void printX(const sth &s) { //上面的getX必须加const
        std::cout << s.getX() << std::endl;
    }

}


int main12() {
    const int max_age = 90;
    int *a = new int;
    *a = 2;
    a = (int *) &max_age;
    std::cout << *a << std::endl; // 90

    const int *b = new int;
    //*b =2; //报错，const 指针不能改变指向的内容
    b = &max_age; // 但可以改变指针的指向

    int *const c = new int; //与上面相反，可以改变指向的内容，但不可以改变指向
    *c = 20;
    //c = &max_age;

    int const *m = new int; // 和const int *b效果一样
    const int *const n = nullptr; //不能改变指向也不能改变指向的内容

    return 0;
}