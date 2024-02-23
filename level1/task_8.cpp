#include <iostream>
#include <ctime>

enum Day {
    Sunday = 1,
    Monday,
    Tuesday,
    Wednesday,
    Thursday,
    Friday,
    Saturday
};

struct Date {
    int day;
    int month;
    int year;
};

void getCurrentDate(Date& date);

int main() {
    srand(time(NULL));
    Date ob;
    getCurrentDate(ob);
    int x = rand()%6 + 1;
    switch(x){
        case 1:
        std::cout << "Monday";
        break;
        case 2:
        std::cout << "Tuesday";
        break;
        case 3:
        std::cout << "Wednesday";
        break;
        case 4:
        std::cout << "Thursday";
        break;
        case 5:
        std::cout << "Friday";
        break;
        case 6:
        std::cout << "Saturday";
        break;
        case 7:
        std::cout << "Sunday";
        break;
        default:
        std::cout << "Invalid day";
        break;
    }
    std::cout << std::endl;
    std::cout << ob.day << ". " << ob.month << ". " << ob.year << std::endl;
    return 0;
}

void getCurrentDate(Date& date) {
    time_t now = time(nullptr);
    tm* currentTime = localtime(&now);

    date.day = currentTime->tm_mday;
    date.month = currentTime->tm_mon + 1;
    date.year = currentTime->tm_year + 1900; 
}

