#include <iostream>
struct MyStruct
{
    int a;
    float b;
};

int
main(int argc, char *argv[])
{
    struct MyStruct e = {
      .a = 10,
      .b = 10.0,
    };
    std::cout << e.a << e.b << std::endl;
    return 0;
}
