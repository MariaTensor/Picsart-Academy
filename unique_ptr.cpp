#include <iostream>
#include "unique_ptr.hpp"

int main() {
    unique_ptr<int> ptr1(new int(42));
    std::cout<< *ptr1 << std::endl;

    unique_ptr<int> ptr2(std::move(ptr1));
    std::cout <<*ptr2 << std::endl;

    ptr2.reset(new int(100));
    std::cout<< *ptr2 << std::endl;

    int* rawPtr = ptr2.release();
    std::cout << *rawPtr << std::endl;
    delete rawPtr;

    return 0;
}
