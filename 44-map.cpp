#include <map>
#include <string>
#include <iostream>

using namespace std;

int main44() {
    map<int, string> mapStudent;
    //数据的插入--第一种：用insert函数插入pair数据
    mapStudent.insert(pair<int, string>(1, "student_one"));
    mapStudent.insert(pair<int, string>(2, "student_two"));
    mapStudent.insert(pair<int, string>(3, "student_three"));
    map<int, string>::iterator iter;
    for (iter = mapStudent.begin(); iter != mapStudent.end(); iter++) {
        cout << iter->first << ' ' << iter->second << endl;
    }
    //第二种：用insert函数插入value_type数据，下面举例说明
    mapStudent.insert(map<int, string>::value_type (1, "student_one"));
    mapStudent.insert(map<int, string>::value_type (2, "student_two"));
    mapStudent.insert(map<int, string>::value_type (3, "student_three"));
    //第三种：用数组方式插入数据，下面举例说明
    mapStudent[1] = "student_one";
    mapStudent[2] = "student_two";
    mapStudent[3] = "student_three";

    int nSize = mapStudent.size();
    iter = mapStudent.find(1);
    if(iter != mapStudent.end())
        cout<<"Find, the value is "<<iter->second<<endl;
    else
        cout<<"Do not Find"<<endl;

    //如果要删除1,用迭代器删除
    mapStudent.erase(iter);
    //如果要删除1，用关键字删除
    int n = mapStudent.erase(1);//如果删除了会返回1，否则返回0
    //用迭代器，成片的删除
    //把整个map清空
    mapStudent.erase( mapStudent.begin(), mapStudent.end() );
    //成片删除要注意的是，也是STL的特性，删除区间是一个前闭后开的集合
    return 0;
}
