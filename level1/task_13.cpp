#include <iostream>
#include <cmath>


class Shape
{
public:
    virtual double areaCalc() = 0;
};

class Circle : public Shape
{
public:
    Circle(double radius)
        :radius {radius}
    {}
    double areaCalc(){
        return  M_PI * pow(radius, 2); 
    }
private:
    double radius;
};

class Rectangle : public Shape
{
public:
    Rectangle(double length, double width)
        :length {length}
        ,width {width}
    {}
    double areaCalc(){
        return length * width;
    }
private:
    double length;
    double width;
};

int main()
{
    Circle ob(5);
    std::cout << "Circle: " << ob.areaCalc() << std::endl;

    Rectangle obj(4, 5);
    std::cout << "Rectangle: " << obj.areaCalc() << std::endl;


    return 0;
}



