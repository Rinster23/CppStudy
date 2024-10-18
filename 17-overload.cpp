#include <iostream>
#include <string>

struct Vec2 {
    float x, y;

    Vec2(float a, float b)
            : x(a), y(b) {}

    Vec2 operator+(const Vec2 &other) const {
        return Vec2(x + other.x, y + other.y);
    }

    float operator*(const Vec2 &other) const {
        return x * other.x + y * other.y;
    }

    bool operator==(const Vec2 &other) {
        return x == other.x && y == other.y;
    }
};

std::ostream &operator<<(std::ostream &stream, const Vec2 &other) {
    stream << other.x << ',' << other.y;
    return stream;
}

int main17() {
    Vec2 a(1, 2);
    Vec2 b(3, 4);
    Vec2 res = a + b;
    float res2 = a * b;
    std::cout << res << std::endl;
    std::cout << res2 << std::endl;
    return 0;
}