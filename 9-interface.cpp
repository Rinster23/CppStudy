#include <iostream>
#include <string>

class printable {
public:
    virtual std::string GetClassName() = 0;
};
// 接口需要在子类中被override才能实例化那个子类
class car : public printable {
public:
    virtual std::string GetName() {
        return "car";
    }
    std::string GetClassName() override {
        return "car";
    }
};

class racingCar : public car {
    std::string m_name;
public:
    racingCar(const std::string &name)
            : m_name(name) {}

    std::string GetName() override {
        return m_name;
    }
    std::string GetClassName() override {
        return "racingCar";
    }
};

void print(printable *e) {
    std::cout << e->GetClassName() << std::endl;
}

int main9() {
    car *Benz = new car();
    print(Benz);
    racingCar *p = new racingCar("F1");
    print(p);
    return 0;
}