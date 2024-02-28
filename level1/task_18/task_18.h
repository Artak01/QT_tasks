#ifndef TASK_18
#define TASK_18


template<typename T>
class Shape
{
public:
    virtual T areaCalc() = 0;
};

template<typename T>
class Circle : public Shape<T>
{
public:
    Circle(T radius);
    T areaCalc() override;
private:
    T radius;
};


template<typename T>
class Rectangle : public Shape<T>
{
public:
    Rectangle(T length, T width);
    T areaCalc() override;
private:
    T length;
    T width;
};

#endif //TASK_19
