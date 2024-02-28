#include <iostream>
#include "task_18.h"


int main()
{
    
    Circle<int> floatCircle(5);
    std::cout << "Circle (float): " << floatCircle.areaCalc() << std::endl;

/*    Circle<double> doubleCircle(5.0);
    std::cout << "Circle (double): " << doubleCircle.areaCalc() << std::endl;

    Rectangle<int> intRectangle(4, 5);
    std::cout << "Rectangle (int): " << intRectangle.areaCalc() << std::endl;

    Rectangle<double> doubleRectangle(4.5, 5.5);
    std::cout << "Rectangle (double): " << doubleRectangle.areaCalc() << std::endl;
*/
    return 0;
}
