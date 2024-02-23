#include <iostream>
#include <fstream>
#include <vector>
#include <stdexcept>

void bubble_sort(int*, size_t);
void selection_sort(int*, size_t);
void scan(int*, size_t); 
void print(int*, size_t); 

enum SortingStrategy {
    BUBBLE_SORT,
    SELECTION_SORT,
};

struct SortingOption {
    SortingStrategy ob;
    void (*f_ptr)(int*, size_t);
};

int main() {
    std::string str = "";
    std::cout << "Enter input file: ";
    std::cin >> str;
    std::ifstream in_file(str);
    if (!in_file.is_open()) {
        throw std::invalid_argument("Unable to open file: " + str);
    }

    std::vector<int> numbers;
    int x;
    while (in_file >> x) {
        numbers.push_back(x);
    }
    in_file.close();
    size_t size = numbers.size();
    int* arr = numbers.data();

    print(arr, size);

    SortingOption fp_arr[] = {
        {SortingStrategy::BUBBLE_SORT, bubble_sort},
        {SortingStrategy::SELECTION_SORT, selection_sort}
    };

    int num = 0;
    std::cout << "1. Bubble Sort " << std::endl;
    std::cout << "2. Selection Sort " << std::endl;
    std::cout << "Enter your sort: " << std::endl;
    std::cin >> num;
    
    void (*f_ptr)(int*, size_t) = nullptr;
    switch (num) {
        case 1:
            f_ptr = fp_arr[0].f_ptr;
            break;
        case 2:
            f_ptr = fp_arr[1].f_ptr;
            break;
        default:
            std::cout << "Invalid choice." << std::endl;
            return 1;
    }
    
    f_ptr(arr, size);
    print(arr, size);
    
    std::ofstream out_f("resukt.txt");
    for (int i = 0; i < size; ++i){
        out_f << arr[i] << " ";
    }
    out_f.close();
    return 0;
}

void bubble_sort(int* arr, size_t size) {
    for(size_t i = 0; i < size - 1; ++i){
        bool flag = false;
        for(size_t j = 0; j < size - 1 - i; ++j){
            if (arr[j] > arr[j + 1]){
                std::swap(arr[j], arr[j + 1]);
                flag = true;
            }
        }
        if (!flag){
            break;
        }
    }
}

void selection_sort(int* arr, size_t size) {
    for (size_t i = 0; i < size - 1; ++i) {
        size_t ind = i;
        for (size_t j = i + 1; j < size; ++j) {
            if (arr[j] < arr[ind]) {
                ind = j;
            }
        }
        std::swap(arr[i], arr[ind]);
    }
}

void scan(int* arr, size_t size) {
    for(size_t i = 0; i < size; ++i){
        arr[i] = rand()%10;
    }
}

void print(int* arr, size_t size) {
    std::cout << "Array" << std::endl;
    for(size_t i = 0; i < size; ++i){
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

