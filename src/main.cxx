#include "include/math.hxx"
import hello;
#include <iostream>
int main(int argc, char** argv) {
    std::cout << "2 + 3 = " << add(2, 3) << std::endl;
    std::cout << "hello world!" << std::endl;
    hello1::say("Hello from the hello module!");

    return 0;
}