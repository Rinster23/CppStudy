#include <iostream>
#include <string>
#include <tuple>

std::tuple<std::string, int> createPerson() {
    return {"Mike", 24};
}

int main36() {
    auto [name, age] = createPerson();
    std::cout << name << age << std::endl;
    return 0; //recall episode 24 multi returns
}