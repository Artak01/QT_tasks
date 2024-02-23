#include <iostream>

int main()
{
    int num = 0;
    std::cout << "Enter the Number: ";
    std::cin >> num;
    bool b = false;
    if (num < 0){
        std::cout << "Number is negative!" << std::endl;
    } else if (num == 0){
        std::cout << "Number is zero!" << std::endl;
    } else {
        std::cout << "Number is positive!" << std::endl;
        if (num <= 100){
            char grade;
            switch(num) {
                case 90 ... 100:
                    grade = 'A';
                    break;
                case 80 ... 89:
                    grade = 'B';
                    break;
                case 70 ... 79:
                    grade = 'C';
                    break;
                case 60 ... 69:
                    grade = 'C';
                    break;
                default:
                    grade = 'F';
            }
            b = true;
            std::cout << "Grade: " << grade << std::endl;
        }
    }
    if (!b){
        std::cout << "Grade: - " << std::endl;
    }

    std::cout << "Numbers from 1 to 10:" << std::endl; 
    for (int i = 1; i <= 10; ++i) { 
        std::cout << i << " "; 
    } 
    std::cout << std::endl; 

    return 0;
}


