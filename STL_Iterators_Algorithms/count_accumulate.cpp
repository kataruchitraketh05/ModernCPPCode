#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <numeric>

void demonstrate_count_and_accumulate()
{
    std::vector<int> vector_data = {10, 30, 15, 30, 45, 20, 30};
    std::list<int> list_data = {15, 35, 20, 35, 50, 25, 35};
    int target_value_vect = 30;
    int target_value_list = 35;

    std::cout << "Count and summing demonstration" << std::endl;

    std::cout << "\nVector data set ";
    for(auto& num : vector_data)
    {
        std::cout << num << " ";
    }
    std::cout << "\n";

    auto count_vect = std::count(vector_data.begin(), vector_data.end(), target_value_vect);
    std::cout << "The target " << target_value_vect << " appears " << count_vect << " times in the vector \n";

    auto sum_vect = std::accumulate(vector_data.begin(), vector_data.end(), 0); //Initial sum is 0
    std::cout << "The sum of all elements in the vector is " << sum_vect << std::endl;

    std::cout << "\nList data set ";
    for(auto& num : list_data)
    {
        std::cout << num << " ";
    }
    std::cout << "\n";

    auto count_list = std::count(list_data.begin(), list_data.end(), target_value_list);
    std::cout << "The target " << target_value_list << " appears " << count_list << " times in the list \n";

    auto sum_list = std::accumulate(list_data.begin(), list_data.end(), 0); //Initial sum is 0
    std::cout << "The sum of all elements in the list is " << sum_list << std::endl;
}

int main()
{
    demonstrate_count_and_accumulate();
    return 0;
}