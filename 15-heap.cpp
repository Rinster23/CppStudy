#include <iostream>
#include <string>

namespace file15 {
    class sth {
        std::string m_name;
    public:
        sth()
                : m_name("Unknown") {
        }

        sth(std::string str)
                : m_name(std::move(str)) {
        }

        const std::string &getName() {
            return m_name;
        }
    };
}

int main15() {
    int a = 1;
    int b = 2;
    file15::sth *pot;
    file15::sth *pot2;

    while (a < b) {
        file15::sth item("stack!");
        pot = &item;
        file15::sth *item2 = new file15::sth("heap!");
        pot2 = item2;
        a++;
    }
    std::cout << (*pot).getName() << std::endl;
    std::cout << pot2->getName() << std::endl;
    delete pot2;
    return 0;

//  std::cout << (*item2).getName() << std::endl;
//  same as
//  std::cout << item2->getName() << std::endl;

}