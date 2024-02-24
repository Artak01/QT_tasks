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

void print(Shape* ob)
{
    std::cout << "Area: " << ob->areaCalc() << std::endl;
}

int main()
{
    Circle ob(5);
    print(&ob);
    Rectangle obj(4, 5);
    print(&obj);


    return 0;
}

