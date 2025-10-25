#include <iostream>
#include <vector>
#include <list>

void demonstrate_iterator_basics()
{
   std::vector<int> numbers = {10, 20, 30, 40, 50};
   std::list<int> numbers_in_list(numbers.begin(), numbers.end());

   std::cout << "Iterator Traversal demonstration \n";

   auto start_it = numbers.begin(); //std::vector<int>::iterator
   auto end_it = numbers.end();

   auto num_30_it = std::find(start_it, end_it, 30);

   for(auto it = start_it; it != end_it; ++it)
   {
        std::cout << *it << " ";
   }
   std::cout << "\n";

   //Modify begining of numbers
   *numbers.begin() = 15;
   *num_30_it = 25;

   std::cout << "First element modified using iterator: " << numbers.at(0) << "\n";
   std::cout << "Third element modified using iterator: " << numbers.at(2) << "\n";
   auto fourth_element_vect = start_it + 3;
   std::cout << "Fourth element in vector is " << *fourth_element_vect << "\n";

   auto start_it_list = numbers_in_list.begin();
   std::cout << "First element in list is " << *start_it_list << "\n";
   std::cout << "Second element in list is " << *(std::next(start_it_list, 1)) << "\n";
   std::cout << "Third element in list is " << *(std::next(start_it_list, 2)) << "\n";
   
   //Compilation error
   //std::cout << "Third element in list is " << *(start_it_list + 1) << "\n";
}

int main()
{
    demonstrate_iterator_basics();
    return 0;
}

