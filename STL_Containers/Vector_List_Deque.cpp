#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <algorithm>

void demonstrate_containers()
{
    std::cout << "Demonstrate containers" << std::endl;
    //Vector is an dynamic array
    std::vector<int> my_vector = {1,2,3,4,5,6,7,8,9,10};
    //List is a doubly linked list
    std::list<int> my_list(my_vector.begin(), my_vector.end());

    std::cout << "Initial Vector size: " << my_vector.size() << std::endl;
    std::cout << "Initial List size: " << my_list.size() << std::endl;

    //Now access the 5th element in the array
    std::cout << "5th element in the array is " << my_vector.at(4) << std::endl;
    //The above cannot be done with a list

    int new_value = 20;

    //Insert at beginning of list O(1)
    my_list.push_front(new_value);

    //Insert at end of vector O(1)
    my_vector.emplace_back(new_value);

    std::cout << "New List: ";
    for (auto& n : my_list) 
    {
        std::cout << n << " ";
    }
    std::cout << "\n";

    std::cout << "New Vector: ";
    for (auto& n : my_vector) 
    { 
        std::cout << n << " ";
    }
    std::cout << "\n";
}

void demonstrate_list_insertion()
{
    std::cout << "Demonstrate list insertion" << std::endl;
    std::list<int> my_list = {10,20,30,40,50};
    std::cout << "Original List: ";
    for (auto& n : my_list) {
        std::cout << n << " ";
    }
    std::cout << "\n";
    std::cout << "Original list size: " << my_list.size() << std::endl;

    //O(1) way to add at end of list
    my_list.emplace_back(60);

    //Insertion in middle Step 1: Find position O(N)
    auto it = std::find(my_list.begin(), my_list.end(), 30);

    //Insertion at middle given the position is O(1)
    if(it != my_list.end())
    {
        my_list.insert(std::next(it), 35);
    }

    std::cout << "Final List after inserting 35 and 60: ";
    for (auto& n : my_list) {
        std::cout << n << " ";
    }
    std::cout << "\n";
    std::cout << "New list size: " << my_list.size() << std::endl;
}

void demonstrate_deque() //Double ended queue
{
    //A deque is implemented as a sequence of non-contiguous, fixed-size blocks of memory 
    //(like an array of arrays) plus a central map that keeps track of these blocks.

    std::cout << "Demonstrate deque" << std::endl;
    std::deque<std::string> my_deque;

    //Push back O(1) amortized
    my_deque.emplace_back("Task B");
    my_deque.emplace_back("Task C");
    my_deque.emplace_back("Task D");

    //Insert a front O(1)
    my_deque.emplace_front("Task A");

    //Access middle element
    std::cout << "Middle element at index 1(position 2) is " << my_deque.at(1) << std::endl;

    std::cout << "Deque size is " << my_deque.size() << std::endl;

    std::cout << "My Deque is ";
    for (auto& n : my_deque) {
        std::cout << n << " ";
    }
    std::cout << "\n";
}

int main()
{
    demonstrate_containers();
    demonstrate_list_insertion();
    demonstrate_deque();
    return 0;
}