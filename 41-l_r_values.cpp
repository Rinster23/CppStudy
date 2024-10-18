#include <iostream>

namespace file41 {
    //int getValue(){
//    return 20;
//}
    int &getValue() {    //左值引用
        static int value = 10;
        return value;
    }

    void setValue(int value) {}

    void printName(const std::string &name) {
        std::cout << name << std::endl;
    }

    void printName2(std::string &&name) { //右值引用，只接受临时对象
        std::cout << name << std::endl;
    }
    //可以直接让上面两个函数同名进行重载
}

using namespace file41;

int main41() {
    int a = 10; //a是左值，10是右值
    //int a = getValue(); //将临时值存到左值中
    getValue() = 20;//左值引用
    setValue(a);//传入左值
    setValue(10);//传入右值，但实际上这个右值会被用来创造一个左值

    //int &va = 100; //报错，因为右值不能给左值引用
    const int &va = 100; //这样可以，实际上是int temp = 100, int &a = temp;

    std::string first = "David";
    std::string last = "Copperfield";
    std::string full = first + last;
    printName(full);
    //printName(first + last);//报错，因为first + last是右值，临时值
    //但是14行加上const就可以了，即可以接受左值也可以接受右值

    //printName2(full); //报错
    printName2(first + last);
    return 0;
}