#include <iostream>
#include <cstdlib>
#include <ctime>

void bubble_sort(int*, size_t);
void selection_sort(int*, size_t);
void scan(int*, size_t);
void print(int*, size_t);

int main() {
    srand(time(NULL));
    size_t size = 0;
    std::cout << "Enter the array size: ";
    std::cin >> size;
    int* arr = new int[size];
    scan(arr, size);
    print(arr, size);
    void (*f_ptr)(int*, size_t) = nullptr;
    std::cout << "Select sort algorithm" <<  std::endl;
    std::cout << "1) Bubble Sort" << std::endl << "2) Selection Sort" << std::endl;
    int num = 0;
    std::cin >> num;
    switch(num) {
        case 1:
            f_ptr = bubble_sort;
            break;
        case 2:
            f_ptr = selection_sort;
            break;
    }
    f_ptr(arr, size);
    std::cout << "Sorted array!" << std::endl;
    print(arr, size);
    delete[] arr;
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

