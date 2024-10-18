#include <iostream>

namespace file19 {
    class entity {
    public:
        entity() {
            std::cout << "created" << std::endl;
        }

        ~entity() {
            std::cout << "destroyed" << std::endl;
        }
    };

    class ScopedPrt {
        entity *e_pot;
    public:
        ScopedPrt(entity *e)
                : e_pot(e) {}

        ~ScopedPrt() { delete e_pot; }
    };
}

//int *creatArr() { //错误写法，array是在stack上被创建的
//    int array[2];
//    array[0] = 10;
//    array[1] = 20;
//    return array;
//}

int main19() {
    {
        file19::entity e;   //超出作用域会被destroy
        //file19::entity *e2 = new file19::entity();
        file19::ScopedPrt se = new file19::entity();//隐式转换 new是创建了一个指针，所以16行要加*传入指针
    }

//    int* arr = creatArr();    //错误写法
//    std::cout << arr[0] << std::endl;
//    std::cout << arr[0] << std::endl;
//    std::cout << arr[1] << std::endl;
    return 0;
}