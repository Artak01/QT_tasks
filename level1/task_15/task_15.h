#ifndef TASK_15
#define TASK_15

class SortingStrategy
{
public:
    virtual void sort(std::vector<int>&) = 0;
    virtual ~SortingStrategy();
};

class BubbleSort : public SortingStrategy
{
public:
    void sort(std::vector<int>& arr) override;
};

class SelectionSort : public SortingStrategy
{
    void sort(std::vector<int>& arr) override;
};

class FileHandler 
{
public:
    std::vector<int> readArrayFromFile(std::string&);
    void saveArrayToFile(std::string&, std::vector<int>);
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



