#include <iostream>

class entity {
public:
    float x, y, speed;

    entity() {
        x = 0.0f;
        y = 0.0f;
    }

    entity(float a, float b, float spe) {
        x = a;
        y = b;
        speed = spe;
        std::cout << "Created!" << std::endl;
    }
    void Move(int xa, int ya) {
        x += xa * speed;
        y += ya * speed;
    }
};

class player : public entity{
public:
    const char* name;
    void prtName(){
        std::cout << name << std::endl;
    }
};