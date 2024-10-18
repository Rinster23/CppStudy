#include <iostream>
#include <memory>

namespace file20 {
    class entity {
    public:
        entity() {
            std::cout << "created" << std::endl;
        }

        ~entity() {
            std::cout << "destroyed" << std::endl;
        }

        void print() {}
    };
}

int main20() {
//    {
//        std::unique_ptr<file20::entity> en(new file20::entity());
//        std::unique_ptr<file20::entity> en2 = std::make_unique<file20::entity>();
//        en->print(); //作用域结束时自动销毁
//    }
    {
        std::shared_ptr<file20::entity> e0;
        {
            std::shared_ptr<file20::entity> sharedEntity = std::make_shared<file20::entity>();
            e0 = sharedEntity; //可以复制，此时ref=2
        }//到这里entity不会被destroy, ref = 1
    }//在这里被destroy, ref = 0
    {
        std::weak_ptr<file20::entity> e1;
        {
            std::shared_ptr<file20::entity> sharedEntity = std::make_shared<file20::entity>();
            e1 = sharedEntity; //可以复制，但不会增加引用，此时ref=1
        }//到这里entity会被destroy, ref = 0
    }
    return 0;
}