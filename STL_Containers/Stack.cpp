#include <iostream>
#include <stack>
#include <deque>
#include <string>
#include <stdexcept> //For out of range exceptions

template <typename T>
class StackClass
{
private:
    std::deque<T> stack_container;
public:
    bool empty()
    {
        return stack_container.empty();
    }

    size_t size()
    {
        return stack_container.size();
    }
    
    void push(const T& value)
    {
        stack_container.emplace_back(value);
    }

    void pop()
    {
        if(empty()) 
        {
            throw std::out_of_range("Cannot pop from an empty stack.");
        }

        stack_container.pop_back();
    }

    T& top()
    {
        if(empty()) 
        {
           throw std::out_of_range("Cannot get top of an empty stack.");
        }
        return stack_container.back();
    }
};

void demonstrate_stack_lifo()
{
    std::stack<int> my_int_stack; //By default uses std::deque
    StackClass<std::string> my_str_stack;
    std::cout << "Stack LIFO implementation" << std::endl;

    my_int_stack.push(1);
    my_int_stack.push(2);
    my_int_stack.push(3);

    my_str_stack.push("Sri Potti Sri Ramulu Bus Station Nellore");
    my_str_stack.push("Pandit Nehru Bus Station Vijayawada");
    my_str_stack.push("Dwaraka Bus Station Visakhapatnam");

    std::cout << "Size of int stack is " << my_int_stack.size() << std::endl;
    std::cout << "Size of string stack is " << my_str_stack.size() << std::endl;

    std::cout << "Standard Library Stack LIFO order \n";
    while(!my_int_stack.empty())
    {
        std::cout << "Top element " << my_int_stack.top() << std::endl;
        my_int_stack.pop();
    }

    std::cout << "Stack Class LIFO order \n";
    while(!my_str_stack.empty())
    {
        std::cout << "Top element " << my_str_stack.top() << std::endl;
        my_str_stack.pop();
    }
}


int main()
{
    demonstrate_stack_lifo();
    return 0;
}