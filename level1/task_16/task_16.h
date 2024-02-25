#ifndef TASK_15
#define TASK_15

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

class SortingStrategy {
public:
    virtual void sort(std::vector<int>&) = 0;
    virtual ~SortingStrategy();
};

class BubbleSort : public SortingStrategy {
public:
    BubbleSort();
    void sort(std::vector<int>& arr) override;
    ~BubbleSort();
};

class SelectionSort : public SortingStrategy {
public:
    SelectionSort();
    void sort(std::vector<int>& arr) override;
    ~SelectionSort();
};

class FileHandler {
public:
    FileHandler();
    std::vector<int> readArrayFromFile(std::string&);
    void saveArrayToFile(std::string&, std::vector<int>);
    ~FileHandler();
};

class SortingApplication {
private:
    SortingStrategy* strategy;
    FileHandler fileHandler;

public:
    SortingApplication();
    ~SortingApplication();
    void select_sort();
    void files(std::string&, std::string&);
};

#endif

