#include <iostream>

namespace file42 {
    class String {
    private:
        char *m_buffer;
        unsigned int m_size;
    public:
        String() = default;

        String(const char *str) {
            printf("created!\n");
            m_size = strlen(str);
            m_buffer = new char[m_size];
            memcpy(m_buffer, str, m_size);
        }

        String(const String &other)
                : m_size(other.m_size) {
            printf("copied!\n");
            m_buffer = new char[m_size];
            memcpy(m_buffer, other.m_buffer, m_size); //深拷贝
        }

        String(String &&other) { //右值引用
            printf("moved!\n");
            m_size = other.m_size;
            m_buffer = other.m_buffer;

            other.m_size = 0;
            other.m_buffer = nullptr;
        }

        ~String() {
            printf("destroyed!\n");
            delete[] m_buffer;
        }

        void PrintStr() {
            for (int i = 0; i < m_size; i++) {
                printf("%c", m_buffer[i]);
            }
            printf("\n");
        }
    };

    class entity {
        String m_name;
    public:
        entity(const String &str)
                : m_name(str) {}

        entity(String &&name)
                : m_name((String &&) name) {} //转换为临时对象
        //: m_name(std::move(name)){}
        void printName() { m_name.PrintStr(); }
    };
}
using namespace file42;

int main42() {
    entity player(String("nancy"));
    player.printName();

    String name = "nike";
    //String destination = name; //这样做是复制粘贴
    //String destination((String &&) name);等价于
    String destination(std::move(name));

    return 0;
}