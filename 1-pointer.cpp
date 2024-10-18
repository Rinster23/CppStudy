#include <iostream>
//void prt(const char*);
#define log(x)
int main1() {
    //prt("hello");
    int var = 8;
    int* pot; //声明整数型指针，存储整数型变量的地址
    pot = &var;
    // log(pot);  // var的内存地址
    *pot = 10;
    log(var);
    int** prt = &pot; // 双指针
    return 0;
}