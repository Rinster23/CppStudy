#include <iostream>

namespace file21 {
    class String {
    private:
        char *m_buffer;
        unsigned int m_size;
    public:
        String(const char *str) {
            std::cout << "Copied!" << std::endl;
            m_size = strlen(str);
            m_buffer = new char[m_size + 1];
            memcpy(m_buffer, str, m_size);
            m_buffer[m_size] = 0;
        }

        String(const String &other)
                : m_size(other.m_size) {
            m_buffer = new char[m_size + 1];
            memcpy(m_buffer, other.m_buffer, m_size + 1); //深拷贝
        }

        //String(const String &other) = delete; 不允许复制
        ~String() {
            delete[] m_buffer;
        }

        void PrintStr(const String &str) { //要加引用，否则会创建新的str对象，会打印copy！
            std::cout << str << std::endl;
        }

        char &operator[](unsigned int ind) { //加引用这样我们可以对某个地方进行修改
            return m_buffer[ind];
        }

        friend std::ostream &operator<<(std::ostream &stream, const String &str);
    };

    std::ostream &operator<<(std::ostream &stream, const String &str) {
        stream << str.m_buffer; //访问私有变量，需要定义友元
        return stream;
    }
}
using namespace file21;

int main21() {
    String name = "Cherno";
    //String second = name; 会报错因为内存中两个str对象有着相同的char*值，也就是说两个str对象的m_buffer地址是相同的，
    //但是作用域结束时析构函数被调用了两次，对同一个地址进行了两次释放内存的尝试，所以报错
    //这种复制称之为shallow copy

    String second = name;
    second[0] = 'M';
//    std::cout << name << std::endl;
//    std::cout << second << std::endl;
    return 0;
}