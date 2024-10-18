#include <iostream>
#include <tuple>
#include <string>
//1.可以自定义结构体，然后函数返回结构体
//2.返回可以储存多个值的数据结构，如pair,tuple,vector等

using namespace std;
//
//
//tuple<int,string> func()
//{
//    tuple<int, string> result = make_tuple(2, "hello");
//    return result;
//}
//
//int main()
//{
//    tuple<int, string> res = func();
//    cout << get<0>(res) << endl;     //2
//    cout << get<1>(res) << endl;     //hello
//    return 0;
//}


struct returnValue {
    double x;
    string s;

    //定义构造函数方便初始化，否则无法通过构造函数初始化。
    returnValue() = default;

    returnValue(double x_, string s_)
            : x(x_), s(s_) {}
};

returnValue func() {
    returnValue res(2, "hello");
    return res;
}

int main24() {
    returnValue result = func();
    cout << result.x << endl;    //2
    cout << result.s << endl;    //hello
    return 0;
}
