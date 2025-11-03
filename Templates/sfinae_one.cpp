//Substituion failure is not an error
#include <iostream>
#include <type_traits> //Required for std::enable_if and std::is_integral 

template <typename T>
typename std::enable_if<std::is_integral<T>::value, void>::type
print(T val)
{
    std::cout << "Integer " << val << " (Internal size : " << sizeof(T) << " bytes)\n";
}

template <typename T>
typename std::enable_if<std::is_floating_point<T>::value, void>::type
print(T val)
{
    std::cout << "Float " << val << " (Internal size : " << sizeof(T) << " bytes)\n";
}

template <typename T>
void print_value_modern(T val)
{
    if constexpr (std::is_integral_v<T>)
    {
        std::cout << "Modern Integer: " << val << " (Internal size: " << sizeof(T) << " bytes)\n";
    }
    else if constexpr (std::is_floating_point_v<T>)
    {
        std::cout << "Modern Float: " << val << " (Internal size: " << sizeof(T) << " bytes)\n";
    }
    else
    {
        std::cout << "Modern Other Type: Cannot process " << typeid(T).name() << ".\n";
    }
}

void demonstrate_enable_if()
{
    std::cout << "std::enable_if Demonstration\n";
    print(10); //Function 1
    print(3.14); //Function 2
    print('B'); //Function 1
    //print(std::string("Abcd")); //Compilation error
}

void demonstrate_if_constexpr()
{
    std::cout << "C++17 if constexpr Demonstration\n";
    print_value_modern(100);
    print_value_modern(45.67);
    print_value_modern('Z');
    print_value_modern("Hello");
}

int main()
{
    demonstrate_enable_if();
    demonstrate_if_constexpr();
    return 0;
}