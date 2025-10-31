#include <iostream>
#include <utility> //for std::make_pair and std::pair
#include <tuple> //for std::tuple and std::get

void demonstrate_utility_classes()
{
    std::cout << "STL Utility Classes Demonstration \n";
    std::cout << "\n 1. std::pair(Two elements):\n";

    std::pair<std::string, double> city_temp = std::make_pair("Nelluru", 30.5);

    std::cout << "City " << city_temp.first << " temparature is " << city_temp.second << std::endl;

    std::cout << "\n 2. std::tuple(Multiple elements):\n";

    //Phone name, screen size, cost
    std::tuple<std::string, double, int> product_info = std::make_tuple("Motorola G86 Power", 6.5, 15999);
    std::cout << "Smartphone " << std::get<0>(product_info) << " with screen size " << std::get<1>(product_info) 
        << " inches costs ₹" << std::get<2>(product_info) << std::endl;

}

int main()
{
    demonstrate_utility_classes();
    return 0;
}