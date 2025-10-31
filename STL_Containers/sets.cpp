#include <iostream>
#include <unordered_set>
#include <set>
#include <string>

//Modification of key itself is not allowed However associated value can 
//be modified Key modification requires us to erase and reinsert the key
void demonstrate_set()
{
    //Balanced binary search O(logN) sorting guranteed 
    std::set<int> unique_numbers;

    std::cout << "std::set uniqueness determination " << std::endl;
    
    unique_numbers.insert(10);
    unique_numbers.insert(20);
    unique_numbers.insert(10); //It is ignored
    unique_numbers.insert(30);
    unique_numbers.insert(20); //It is ignored

    unique_numbers.insert(5);
    unique_numbers.insert(15);

    // The size reflects only the unique items
    std::cout << "Final set size: " << unique_numbers.size() << std::endl; 

    std::cout << "Set Sorted Contents: ";
    for(auto& num : unique_numbers)
    {
        std::cout << num << " "; 
    }
    std::cout << "\n";

    if(unique_numbers.count(10))
    { 
        std::cout << "Number 10 found inside std::set " << std::endl;
    }
    else
    {
        std::cout << "Number 10 not found inside std::set " << std::endl;
    }

    if(unique_numbers.count(40))
    { 
        std::cout << "Number 40 found inside std::set " << std::endl;
    }
    else
    {
        std::cout << "Number 40 not found inside std::set " << std::endl;
    }
}

void demonstrate_unordered_set()
{
    //Hash Map O(1) speed guranteed 
    std::unordered_set<int> unique_numbers;

    std::cout << "std::unordered_set uniqueness determination " << std::endl;
    
    unique_numbers.insert(20);
    unique_numbers.insert(30);
    unique_numbers.insert(30); //It is ignored
    unique_numbers.insert(40);
    unique_numbers.insert(40); //It is ignored

    unique_numbers.insert(15);
    unique_numbers.insert(25);

    // The size reflects only the unique items
    std::cout << "Final set size: " << unique_numbers.size() << std::endl; 

    std::cout << "Unordered Set Contents: ";
    for(auto& num : unique_numbers)
    {
        std::cout << num << " "; 
    }
    std::cout << "\n";

    if(unique_numbers.count(20))
    { 
        std::cout << "Number 20 found inside std::set " << std::endl;
    }
    else
    {
        std::cout << "Number 20 not found inside std::set " << std::endl;
    }

    if(unique_numbers.count(35))
    { 
        std::cout << "Number 35 found inside std::set " << std::endl;
    }
    else
    {
        std::cout << "Number 35 not found inside std::set " << std::endl;
    }
}

void demonstrate_multiset()
{
    std::multiset<int> bid_prices;
    std::cout << "std::multiset Demonstration" << std::endl;

    bid_prices.insert(100);
    bid_prices.insert(50);
    bid_prices.insert(100);
    bid_prices.insert(200);
    bid_prices.insert(50);

    std::cout << "Final multiset size: " << bid_prices.size() << std::endl; // Size is 5

    std::cout << "Bid Prices (Sorted): ";
    for (int price : bid_prices) {
        std::cout << price << " ";
    }
    std::cout << "\n";

    std::cout << "Count for price 100 : " << bid_prices.count(100) << std::endl; //O(logN)
    std::cout << "Count for price 10 : " << bid_prices.count(10) << std::endl; //O(logN)
}

void demonstrate_unordered_multiset()
{
    std::unordered_multiset<int> bid_prices;
    std::cout << "std::unordered_multiset Demonstration" << std::endl;

    bid_prices.insert(100);
    bid_prices.insert(50);
    bid_prices.insert(100);
    bid_prices.insert(200);
    bid_prices.insert(50);

    std::cout << "Final multiset size: " << bid_prices.size() << std::endl; // Size is 5

    std::cout << "Bid Prices : ";
    for (int price : bid_prices) {
        std::cout << price << " ";
    }
    std::cout << "\n";

    std::cout << "Count for price 100 : " << bid_prices.count(100) << std::endl; //O(1)
    std::cout << "Count for price 10 : " << bid_prices.count(10) << std::endl; //O(1)
}

int main()
{
    demonstrate_set();
    demonstrate_unordered_set();
    demonstrate_multiset();
    demonstrate_unordered_multiset();
    return 0;
}