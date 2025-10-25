#include <iostream>
#include <vector>
#include <algorithm>

class GreaterIntThreshold
{
private:
    int threshold;
public:
    GreaterIntThreshold(int thres) : threshold(thres) {}

    bool operator() (int n) const { return n > threshold; }
};

void demonstrate_find_if_lambda_functor()
{
    std::cout << "std find if with lambda find first even number \n";
    std::vector<int> numbers = {11, 23, 16, 41, 58, 30};
    GreaterIntThreshold predicate_object(25);
    std::cout << "Data: ";
    for (auto &n : numbers) {
        std::cout << n << " ";
    }
    std::cout << "\n";

    auto iterator1 = std::find_if(numbers.begin(), numbers.end(), [](int&n) { return (n%2 == 0); });

    auto iterator2 = std::find_if(numbers.begin(), numbers.end(), predicate_object);

    if (iterator1 != numbers.end()) 
    {
        std::cout << "Found the first even number: " << *iterator1 << " at index " << std::distance(numbers.begin(), iterator1) << "\n";
    } 
    else 
    {
        std::cout << "No even number found.\n";
    }

    std::cout << "std find if with functor find first number > 25 \n";

    if(iterator2 != numbers.end())
    {
        std::cout << "Found the first number greater than 25 is " << *iterator2 << " at index " << std::distance(numbers.begin(), iterator2) << "\n";
    }
    else
    {
        std::cout << "No number greater than 25 found \n";
    }
}

int main()
{
    demonstrate_find_if_lambda_functor();
    return 0;
}