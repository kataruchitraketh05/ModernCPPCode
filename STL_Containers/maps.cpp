#include <iostream>
#include <map>
#include <unordered_map>

//Modification of key itself is not allowed However associated value can 
//be modified Key modification requires us to erase and reinsert the key
int main()
{
    std::unordered_map<std::string, int> my_unordered_map;
    my_unordered_map["Chirala"] = 3;
    my_unordered_map["Anakaapalli"] = 1;
    my_unordered_map["Balabhadraapuram"] = 2;

    std::map<std::string, int> my_map;
    my_map["Chirala"] = 3;
    my_map["Anakaapalli"] = 1;
    my_map["Balabhadraapuram"] = 2;

    //Hash map faster lookups O(1)
    std::cout << "Unordered Map Contents are \n";
    for(const auto& item : my_unordered_map)
    {
        std::cout << item.first << " : " << item.second << std::endl;
    }
    //Sorting is guranteed in ordered map lookup O(logN) balanced binary tree
    std::cout << "\n Ordered Map Contents are \n";
    for(const auto& item : my_map)
    {
        std::cout << item.first << " : " << item.second << std::endl;
    }
    return 0;
}