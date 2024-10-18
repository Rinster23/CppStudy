#include <iostream>
#include <string>

namespace file16 {
    class sth {
        std::string m_name;
        int m_age;
    public:
        sth(const std::string &name)
                : m_name(name), m_age(-1) {}

        explicit sth(int age)
                : m_name("unknown"), m_age(age) {}
    };
}

int main16() {
    file16::sth b1 = std::string("chen"); //隐式转换
    //file16::sth b2 = 22; 加了explicit关键字就没有隐式转换了
    return 0;
}