// 在类与结构体外使用static,那该变量或者函数只能在所处的翻译单元内使用，即不能跨.cpp文件使用
// 在类与结构体内使用static,那在所有实例中这个变量的值都是一样的
// local static
#include <iostream>

struct entity {
    static int x, y;

    void Prt() {
        std::cout << x << ',' << y << std::endl;
    }
};

int entity::x;
int entity::y;

//int main() {
//    entity e1;
//    e1.x = 3;
//    e1.y = 5;
//
//    entity e2;
//    e2.x = 1;
//    e2.y = 2;
//
//    e1.Prt();
//    e2.Prt();
//}

struct Vec {
    static int dim;
    int x, y;

    void Prt() {
        std::cout << x << ',' << y << std::endl;
    }

    static void prtDim() {
        // std::cout << x << ',' << y << std::endl; //静态方法不能访问非静态变量
        std::cout << dim << std::endl;
    }
};

int Vec::dim;
//int main() {
//    Vec::dim = 5;   //static不需要类实例
//    Vec::prtDim();
//}

void func() {
    static int i = 0;
    i++;
    std::cout << i << std::endl;
}

//int main() {
//    func();//1
//    func();//2
//    func();//3
//}

