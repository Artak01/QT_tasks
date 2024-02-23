#include <iostream>

int main()
{
    int num = 0;
    std::cout << "Number: " << num << std::endl;
    int* ptr = &num;
    *ptr = 10;
    std::cout << "Number: " << num << std::endl;
    int& ref = num;
    ref = 20;
    std::cout << "Number: " << num << std::endl;
}
