#include <iostream>
#define log(x) std::cout<<x<<std::endl

void increment(int value) {
    value++;
}

void increment2_(int* value) {
    (*value)++;
}

void increment2(int *value) {
    (*value)++;
}

void increment3_(int& value) {   //这两种写法都可以
    value++;
}

void increment3(int &value) {
    value++;
}

// int a=4; int& b=a; b就是a,不会创建新内存，改变b就会改变a,相当于别名
int main2() {
    int a = 1;
    increment(a);
    log(a); // a=1
    increment2(&a);
    log(a); // a=2
    increment3(a); // a=3
    log(a);
    int m = 5;
    int &n = m;
    n = 8;
    log(n);
    return 0;
}