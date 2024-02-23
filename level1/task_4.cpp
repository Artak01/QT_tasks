#include <iostream>

double add(double, double);
double sub(double, double);
double mul(double, double);
double divi(double, double);

int main()
{
    int num1 = 0; 
    int num2 = 0;
    std::cout << "Enter numbers: ";
    std::cin >> num1 >> num2;
    std::cout << "Addition: " << add(num1, num2) << std::endl;
    std::cout << "Subtraction: " << sub(num1, num2) << std::endl;
    std::cout << "Multiplication: " << mul(num1, num2) << std::endl;
    std::cout << "Division: " << divi(num1, num2) << std::endl;
    return 0;
}

double add(double a, double b)
{
    return a + b;
}

double sub(double a, double b)
{
    return a - b;
}

double mul(double a, double b)
{
    return a * b;
}

double divi(double a, double b)
{
    if (b != 0){
        return a / b;
    } else {
        throw std::invalid_argument("Don't division zero!!");
    }
}
