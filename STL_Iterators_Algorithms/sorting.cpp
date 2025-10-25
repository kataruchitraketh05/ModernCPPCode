#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

void demonstrate_std_sort_vect()
{
    std::vector<int> numbers = {50, 15, 45, 30, 35, 25, 20, 10, 40};
    std::vector<int> numbers_copy = numbers;
    std::cout << "std::sort Demonstration\n";
    std::cout << "Original vector ";
    for(auto& num : numbers)
    {
        std::cout << num << " ";
    }
    std::cout << "\n";

    //Sort numbers If third argument is omitted the default is ascednding order
    std::sort(numbers.begin(), numbers.end(), std::less<int>()); 
    //Quicksort or Introsort used by std::sort works perfectly with random access iterators(vector)
    std::cout << "Ascending order sort ";
    for(auto& num : numbers)
    {
        std::cout << num << " ";
    }
    std::cout << "\n";

    std::sort(numbers_copy.begin(), numbers_copy.end(), std::greater<int>());
    std::cout << "Descending order sort ";
    for(auto& num : numbers_copy)
    {
        std::cout << num << " ";
    }
    std::cout << "\n";
}

void demonstrate_sort_list()
{
    std::list<int> numbers = {50, 15, 45, 30, 35, 25, 20, 10, 40};
    std::list<int> numbers_copy = numbers;
    std::cout << "List sort Demonstration\n";
    std::cout << "Original list ";
    for(auto& num : numbers)
    {
        std::cout << num << " ";
    }
    std::cout << "\n";
      
    //It causes compilation error as list only supports bidirectional operators
    //std::sort(numbers.begin(), numbers.end(), std::less<int>());

    //Uses merge sort
    numbers.sort(std::less<int>()); //If no argument is passed default is ascending order
    std::cout << "Ascending order sort ";
    for(auto& num : numbers)
    {
        std::cout << num << " ";
    }
    std::cout << "\n";

    numbers_copy.sort(std::greater<int>());
    std::cout << "Descending order sort ";
    for(auto& num : numbers_copy)
    {
        std::cout << num << " ";
    }
    std::cout << "\n";

}

int main()
{
    demonstrate_std_sort_vect();
    demonstrate_sort_list();
    return 0;
}