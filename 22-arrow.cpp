#include <iostream>

namespace file22 {
    class entity {
    public:
        int x;

        void print() {
            std::cout << "Hello" << std::endl;
        }

    };

    class ScopedPrt {
        entity *e_pot;
    public:
        ScopedPrt(entity *e)
                : e_pot(e) {}

        ~ScopedPrt() { delete e_pot; }

        entity* operator->(){
            return e_pot;
        }
    };
}
using namespace file22;
int main22(){
    ScopedPrt e1 = new entity();
    e1->print();
    return 0;
}

