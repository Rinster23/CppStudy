#include <iostream>
#include <string>

namespace file25 {
    template<typename T>
    void print(T value) {
        std::cout << value << std::endl;
    }

    template<typename T, int A>
    class Array {
    private:
        T m_array[A];
    public:
        int getSize() const { return A; }
    };

}
using namespace file25;

int main25() {
//    print(2);
//    print<int>(10);
//    print("hello");
//    print(5.5);
    Array<int, 5> arr;
    std::cout << arr.getSize() << std::endl;
    return 0;
}
