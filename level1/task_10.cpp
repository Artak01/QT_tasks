#include <iostream>
#include <fstream>
#include <stdexcept> // Include for std::invalid_argument

int main() {
    std::ofstream f1("name_list.txt");
    if (!f1.is_open()) {
        throw std::invalid_argument("Output file didn't open!");
    }
    for (int i = 0; i < 5; ++i) {
        std::string str = "";
        std::cout << "Enter name and surname: ";
        std::getline(std::cin, str);
        f1 << str << std::endl;
    }
    f1.close();

    std::ifstream f2("name_list.txt");
    if (!f2.is_open()) {
        throw std::invalid_argument("Input file didn't open!");
    }
    std::string s;
    while (std::getline(f2, s)) {
        std::cout << s << std::endl;
    }
    std::cout << std::endl;
    f2.close();
    return 0;
}

