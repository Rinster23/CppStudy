#include <iostream>
#include <string>

class entity {
public:
    virtual std::string GetName() {
        return "entity";
    }
};

class player : public entity {
    std::string m_name;
public:
    player(const std::string &name)
            : m_name(name) {}

    std::string GetName() override {
        return m_name;
    }

};

void printName(entity *e) {
    std::cout << e->GetName() << std::endl;
}

int main8() {
    entity *e = new entity();
    printName(e);
    player *p = new player("mike");
    printName(p);
    return 0;
}

class Base {
public:
    virtual ~Base() { std::cout << "Base Destructor\n"; }
};

class Derived : public Base {
public:
    ~Derived() { std::cout << "Derived Destructor\n"; }
};

int main() {
    Derived* basePtr = new Derived();
    delete basePtr; // Correct behavior!
    // Derived Destructor
    //Base Destructor
}
