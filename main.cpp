#include <iostream>
struct A{
    A(){std::cout<<"StructA default initialization\n";}
    A(int) { std::cout<<"StructA direct-initialization select A::A(int)\n";}
    A(int, int) {std::cout<<"StructA direct list initialization A::A(int,int)\n";}
};

struct B{
    explicit B() {}
    explicit B(int) {}
    explicit B(int, int) {}
};
int main() {
// A constructor that is not declared with specifier explicit. Converting Constructor.
    A a1 = 1;
    A a2(2);
    A a3{4,5};
    A a4 = {4,5};
    A a5 = (A) 1;

//    B b1 = 1; //copy-initializtion does not consider B::B(int).
    B b2(2);
    B b3 {4,5};

//    B b4 = {4,5}; error: converting to 'B' from initializer list would use explicit constructor 'B::B(int, int)'

    B b5 = (B) 1;

    B b6;
    B b7 {};
    return 0;
}
