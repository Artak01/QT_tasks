#include <iostream>
#include <stdexcept>
#include <cmath>


class Shape
{
public:
    virtual double areaCalc() = 0;
};

class Circle : public Shape
{
public:
    Circle(double rad)
        :radius {rad}
    {
        if (rad <= 0){
            throw std::invalid_argument("Redius is negative!");
        }
    }
    double areaCalc(){
        return  M_PI * pow(radius, 2); 
    }
private:
    double radius;
};

class Rectangle : public Shape
{
public:
    Rectangle(double l, double w)
        :length {l}
        ,width {w}
    {
        if (l <= 0 || w <= 0){
            throw std::invalid_argument("Sides is negative!");
        }
    }
    double areaCalc(){
        return length * width;
    }
private:
    double length;
    double width;
};

int main()
{
    try{
        Circle ob(-5);
        std::cout << "Circle: " << ob.areaCalc() << std::endl;
    } catch (...){
        std::cout << "Error Circle" << std::endl;
    }

    try{
        Rectangle obj(4, 5);
        std::cout << "Rectangle: " << obj.areaCalc() << std::endl;
    } catch (...) {
        std::cout << "Error Rectangle!" << std::endl; 
    }

    return 0;
}

