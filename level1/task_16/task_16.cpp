#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "task_16.h"



BubbleSort::BubbleSort() {}

SelectionSort::SelectionSort() {}

FileHandler::FileHandler() {}




SortingStrategy::~SortingStrategy() {}

BubbleSort::~BubbleSort() {}

SelectionSort::~SelectionSort() {}

FileHandler::~FileHandler() {}

SortingApplication::SortingApplication() 
    : strategy(nullptr) 
{}

SortingApplication::~SortingApplication() {
    delete strategy;
}

void BubbleSort::sort(std::vector<int>& arr) {
    size_t size = arr.size();
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

void SelectionSort::sort(std::vector<int>& arr) {
    size_t size = arr.size();
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

std::vector<int>  FileHandler::readArrayFromFile(std::string& name)
{
    std::ifstream in_f(name);
    if (!in_f.is_open()) {
        throw std::invalid_argument("Don't open file!");
    }
    std::vector<int> vec;
    int x;
    while (in_f >> x) {
        vec.push_back(x);
    }
    in_f.close();
    return vec;
}

void FileHandler::saveArrayToFile(std::string& name, std::vector<int> vec)
{
    std::ofstream out_f(name);
    if (!out_f.is_open()) {
        throw std::invalid_argument("Don't open output file!");
    }

    for (int num : vec) {
        out_f << num << " ";
    }
    out_f.close();
}

void SortingApplication::select_sort()
{
    int x;
    std::cout << "Select sort:" << std::endl;
    std::cout << "1. Bubble Sort" << std::endl;
    std::cout << "2. Selection Sort" << std::endl;
    std::cin >> x;

    if (strategy) {
        delete strategy;
    }

    switch (x) {
        case 1:
            strategy = new BubbleSort();
            break;
        case 2:
            strategy = new SelectionSort();
            break;
        default:
            std::cout << "Error";
    }
}

void SortingApplication::files(std::string& in_f, std::string& out_f) {
    std::vector<int> arr = fileHandler.readArrayFromFile(in_f);
    strategy->sort(arr);
    fileHandler.saveArrayToFile(out_f, arr);
}

