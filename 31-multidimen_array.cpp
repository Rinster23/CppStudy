#include <iostream>

int main31() {
    int *array = new int[20]; //array是一个指向有着20个整数的列表的第一个整数的指针
    auto **a2d = new float *[10]; //a2d是一个指向有着10个指针的列表的第一个指针的指针
    for (int i = 0; i < 10; i++) {
        a2d[i] = new float[20]; //a2d中有十个指针，每个指针指向有20个浮点数列表 的第一个浮点数的指针
    }

    for (int i = 0; i < 10; i++) {
        delete[] a2d[i];
    }
    delete[] a2d;
    return 0;
}