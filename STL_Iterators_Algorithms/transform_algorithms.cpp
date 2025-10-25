#include <iostream>
#include <vector>
#include <algorithm>

void demonstrate_transform_algorithms()
{
    std::vector<int> original_data = {1,2,3,4,5};

    std::cout << "STL Transform Algorithms \n";

    std::cout << "Original Data: ";
    for(auto& num : original_data)
    {
        std::cout << num << " ";
    }
    std::cout << "\n\n";

    std::cout << "Algorithm std::for_each for doubling\n";

    std::for_each(original_data.begin(), original_data.end(), [](int &n) { n*=2; });

    std::cout << "Data after doubling: ";
    for(auto& num : original_data)
    {
        std::cout << num << " ";
    }
    std::cout << "\n\n";

    std::cout << "Algorithm std::transform for squaring\n";

    std::vector<int> sqaured_numbers;
    sqaured_numbers.reserve(original_data.size()); //Reserve capacity

    //Return value of opeartion is stored in output range
    std::transform(original_data.begin(), original_data.end(), std::back_inserter(sqaured_numbers), [](int n) { return n*n; });

    std::cout << "New Vector (Squared values): ";
    for (auto& num : sqaured_numbers) {
        std::cout << num << " ";
    }
    std::cout << "\n";
}

int main()
{
    demonstrate_transform_algorithms();
    return 0;
}