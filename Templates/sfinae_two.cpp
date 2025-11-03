#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <string>
#include <iterator>
#include <concepts>

template <typename T>
concept GeneralContainer = requires(T container)
{
    typename T::iterator;
    { container.begin() } -> std::same_as<typename T::iterator>;
    { container.end() } -> std::same_as<typename T::iterator>;
};

template <typename T>
concept SortableContainer = GeneralContainer<T> && requires 
{
    typename std::iterator_traits<typename T::iterator>::iterator_category;
    requires std::same_as<typename std::iterator_traits<typename T::iterator>::iterator_category,std::random_access_iterator_tag>;
};


template <SortableContainer T>
void process_container(T& data)
{
    std::cout << "Sortable container(vector or deque detected) using std::sort\n";
    std::sort(data.begin(), data.end()); 
    std::cout << "Sorted elements are: ";
    for (const auto& val : data) 
    { 
        std::cout << val << " "; 
    }
    std::cout << "\n";
}

template <GeneralContainer T> requires(!SortableContainer<T>)
void process_container(T& data)
{
    std::cout << "Bidirectional container list detected using T::sort\n";
    data.sort();
    std::cout << "Sorted elements are: ";
    for (const auto& val : data) 
    { 
        std::cout << val << " "; 
    }
    std::cout << "\n";
}

template <typename T> requires(!GeneralContainer<T>)
void process_container(T& data)
{
    std::cout << "Scalar detected.** Cannot process; value is: " << data << "\n";
}

int main()
{
    std::cout << "C++20 Concept Dispatch: Sorting \n";
    std::vector<int> v = {9, 1, 5, 3};
    std::list<int> l = {8, 2, 6, 4};
    int i = 42;

    process_container(v); //std::vector

    process_container(l); //std::list

    process_container(i); //scalar

    return 0;
}
