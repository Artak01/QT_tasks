#include <iostream>

void bubble_sort(int*, size_t);
void selection_sort(int*, size_t);
void scan(int*, size_t); 
void print(int*, size_t); 

enum SortingStrategy
{
    BUBBLE_SORT,
    SELECTION_SORT,
};

struct SortingOption
{
    SortingStrategy ob;
    void (*f_ptr)(int*, size_t);
};

int main()
{
    size_t size = 0;
    std::cout << "Enter the array size: ";
    std::cin >> size;
    int* arr = new int[size];
    scan(arr, size);
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
    
    void (*f_ptr)(int*, size_t) = nullptr; // Initialize the function pointer
    switch (num) {
        case 1:
            f_ptr = fp_arr[0].f_ptr;
            break;
        case 2:
            f_ptr = fp_arr[1].f_ptr;
            break;
        default:
            std::cout << "Invalid choice." << std::endl;
            delete[] arr; // Delete allocated memory before returning
            return 1;
    }
    
    f_ptr(arr, size); // Call the selected sorting function
    print(arr, size); // Print the sorted array
    
    delete[] arr; // Delete allocated memory
    return 0; // Return 0 to indicate success
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

