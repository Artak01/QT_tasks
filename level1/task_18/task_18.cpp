#include <iostream>
#include <cmath>
#include "task_18.h"

template<typename T>
Circle<T>::Circle(T radius)
    :radius {radius}
{}

template<typename T>
T Circle<T>::areaCalc(){
    return  static_cast<T>(M_PI * pow(radius, 2)); 
}

template<typename T>
Rectangle<T>::Rectangle(T length, T width)
    :length {length}
    ,width {width}
{}
   
template<typename T>
T Rectangle<T>::areaCalc()
{
    return length * width;
}
