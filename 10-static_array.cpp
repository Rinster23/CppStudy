#include <iostream>
#include <array>
#include <string>

#define log(x) std::cout<<x<<std::endl
namespace file10 {
    class entity {
    public:
        //int arr1[3];
        int *arr2 = new int[3];

        entity() {
            for (int i = 0; i < 3; i++) {
                //arr1[i] = i;
                arr2[i] = 10 + i;
            }
        }

        ~entity() {
            delete arr2;
        }
    };
}

int main10() {
    int arr[5]; // stack
    for (int i = 0; i < 5; i++) {
        arr[i] = 1;
    }
    for (int &i: arr) {
        i = 1;
    }
    int *prt = arr;
    *(prt + 2) = 10; //arr[2]=10
    int *prt2 = &arr[0]; //等于上面的
//    log(prt);
//    log(prt2);

    int *anotherArr = new int[5];   // heap
    delete[] anotherArr;

    std::array<int, 5> array{1, 2, 3}; //包含边界检查
    file10::entity e1;
    log(*(e1.arr2));//10
    log(*(e1.arr2 + 1));//11
    return 0;
}