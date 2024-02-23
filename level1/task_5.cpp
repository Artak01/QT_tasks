#include <iostream>
#include <string>

void scan(int*, size_t);
void print(int*, size_t);
int max(int*, size_t);
int min(int*, size_t);
int avg(int*, size_t);
size_t len(const char*);
std::string con(std::string, std::string);

int main()
{
    srand(time(NULL));
    size_t n = 0;
    std::cout << "Enter the array size: ";
    std::cin >> n;
    int* arr = new int[n];
    scan(arr, n);
    print(arr, n);
    std::cout << "Maximum: " << max(arr, n) << std::endl;
    std::cout << "Minimum: " << min(arr, n) << std::endl;
    std::cout << "Everage: " << avg(arr, n) << std::endl;

    std::cout << "\n\n" << "Strings!!" << std::endl << std::endl;
    std::string str = "Hello World!";
    std::cout << "Size string: " << len(str.c_str()) << std::endl;
    std::string str1 = "Hello ";
    std::string str2 = "World!";
    std::cout << "concatenation str1 and str2: " << con(str1, str2) << std::endl; 
    return 0;
}


void scan(int* arr, size_t n)
{
    for(int i = 0; i < n; ++i){
        arr[i] = rand()%10;
    }
}

void print(int* arr, size_t n)
{   
    std::cout << "Array" << std::endl;
    for(int i = 0; i < n; ++i){
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

int max(int* arr, size_t n)
{
    int Max = arr[0];
    for(int i = 1; i < n; ++i){
        if (arr[i] > Max){
            Max = arr[i];
        }
    }
    return Max;
}

int min(int* arr, size_t n)
{
    int Min = arr[0];
    for(int i = 1; i < n; ++i){
        if (arr[i] < Min){
            Min = arr[i];
        }
    }
    return Min;
}

int avg(int* arr, size_t n)
{
    int sum = 0;
    for(int i = 1; i < n; ++i){
        sum += arr[i];
    }
    return sum / n;
}

size_t len(const char* str){
    if (*str == '\0'){
        return 0;
    }
    return 1 + len(str + 1);
}

std::string con(std::string str1, std::string str2)
{
    return str1 + str2;
}






