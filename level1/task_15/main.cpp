#include <iostream>
#include "task_15.h"

int main()
{
    SortingApplication ob;
    std::string in_f = "t.txt";
    std::string out_f = "resalt.txt";


    ob.select_sort();
    ob.files(in_f, out_f);

    return 0;
}
