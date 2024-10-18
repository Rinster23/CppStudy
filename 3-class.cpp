#include <iostream>

#define log(x) std::cout<<x<<std::endl

class player {
public:
    int x, y;
    int speed;

    void Move(int xa, int ya) {
        x += xa * speed;
        y += ya * speed;
    }

};
// struct 和 class 的区别为若不特殊指定，class的变量均为私有，而struct均为公有。
struct gamer {
    int x, y;
    int speed;

    void Move(int xa, int ya) {
        x += xa * speed;
        y += ya * speed;
    }

};

int main3() {
    gamer mike;
    mike.x = 10;
    mike.y = 20;
    mike.speed = 2;
    mike.Move(1, 1);
    log(mike.x);
    return 0;
}