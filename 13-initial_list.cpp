#include <iostream>
#include <string>

namespace file13 {
    class example {
    public:
        example() {
            std::cout << "example created with no para" << std::endl;
        }

        example(int a) {
            std::cout << "example created with int" << a << std::endl;
        }
    };

    class sth {
        std::string m_name;
        int score;
        example ex;
    public:
        sth()
                //: m_name("Unknown"), score(0), ex(example(7))
                {
             m_name = "unknown";
             ex = example(8); //在这里初始化会创建两个example，而在成员列表中初始化只会创建一个
        }

        sth(const std::string &str)
                : m_name(str) {
            //m_name = str;
        }

        const std::string &getName() {
            return m_name;
        }
    };
}

int main13() {
    file13::sth e0;
//    std::cout << e0.getName() << std::endl;
//    file13::sth e1("Mike");
//    std::cout << e1.getName() << std::endl;
    return 0;
}