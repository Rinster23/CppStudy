#include <iostream>

enum Example{
    A, B, C //默认第一个是0然后递增1
};

int main5(){
    Example a = B;  //a 取值只能取A,B,C中的一个
    return 0;
}