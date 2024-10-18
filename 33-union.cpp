#include <iostream>

namespace file33 {
    struct vec2 {
        float x, y;
    };

    struct vec4 {
        union {
            struct {
                float x, y, z, w;
            };
            struct {
                vec2 a, b; //a和x,y共享内存，b和z,w共享内存
            };
        };
//        int x, y, z, w;
//
//        vec2 &getA() {
//            return *(vec2 *) &x; //类型双关
//        }
    };
    void printVec2(const vec2 &v){
        std::cout << v.x << "," << v.y << std::endl;
    }
}
using namespace file33;

int main33() {
//    struct Union {
//        union {
//            int a;
//            float b;
//        };
//    };
//    Union u;
//    u.a = 2.0f; //  联合体一次只能占用一个成员的内存
//    std::cout << u.a << "," << u.b << std::endl; //u.b读取了组成浮点数的内存，并且解释成一个整型
    vec4 example = {1.0, 2.0, 3.0, 4.0};
//    vec2 res = v4.getA();
//    std::cout << res.x << "," << res.y << std::endl;
    printVec2(example.a);
    example.z = 100.5;
    printVec2(example.b);
    return 0;
}