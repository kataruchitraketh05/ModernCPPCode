#include <iostream>
#include <queue>
#include <deque>
#include <string>
#include <stdexcept> //For out of range exceptions

template <typename T>
class QueueClass
{
private:
    std::deque<T> queue_container;
public:
    bool empty()
    {
        return queue_container.empty();
    }

    size_t size()
    {
        return queue_container.size();
    }

    void push(const T& value)
    {
        queue_container.emplace_back(value);
    }

    void pop()
    {
        if(empty())
        {
            throw std::out_of_range("Cannot pop from an empty queue");
        }
        queue_container.pop_front();
    }

    T& front()
    {
        if(empty())
        {
            throw std::out_of_range("Cannot pop from an empty queue");
        }
        return queue_container.front();
    }
};

void demonstrate_queue_fifo()
{
    std::queue<int> my_int_queue;
    QueueClass<std::string> my_str_queue;

    my_int_queue.push(10); 
    my_int_queue.push(5); 
    my_int_queue.push(20);
     
    my_str_queue.push("Vijayawada Junction");
    my_str_queue.push("Tenali Junction");
    my_str_queue.push("Guduru Junction");

    std::cout << "Size of int queue is " << my_int_queue.size() << std::endl;
    std::cout << "Size of string queue is " << my_str_queue.size() << std::endl;

    std::cout << "Standard Library Queue FIFO \n";
    while(!my_int_queue.empty())
    {
        std::cout << "Front element " << my_int_queue.front() << std::endl;
        my_int_queue.pop();
    }

    std::cout << "Queue Class FIFO \n";
    while(!my_str_queue.empty())
    {
        std::cout << "Front element " << my_str_queue.front() << std::endl;
        my_str_queue.pop();
    }
}

void demonstrate_priority_queue()
{
    std::priority_queue<int> my_priority_queue; //MAX HEAP
    std::cout << "std::priority_queue Demonstration\n";
    my_priority_queue.push(10);//O(logN)
    my_priority_queue.push(20);
    my_priority_queue.push(50);

    std::cout << "Priority Queue size: " << my_priority_queue.size() << "\n";

    std::cout << "Elements in priority queue \n"; 
    while(!my_priority_queue.empty())
    {
        std::cout << "Front " << my_priority_queue.top() << std::endl;
        my_priority_queue.pop(); //O(logN)
    }
}

int main()
{
    demonstrate_queue_fifo();
    demonstrate_priority_queue();
    return 0;
}