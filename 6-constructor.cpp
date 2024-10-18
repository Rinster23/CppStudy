#include <iostream>

class entity {
public:
    float x, y;

    entity() {
        x = 0.0f;
        y = 0.0f;
    }

    entity(float a, float b) {
        x = a;
        y = b;
        std::cout << "Created!" << std::endl;
    }

    ~entity() {
        std::cout << "Destroyed!" << std::endl;
    }

    void prt() {
        std::cout << x << ',' << y << std::endl;
    }
};

int main6() {
    entity e;
    e.prt();    // 若没有初始化函数，则打印此刻内存中占用的数，并不会报错
    entity e1(5.0, 10.0);
    e1.prt();
    return 0;
}