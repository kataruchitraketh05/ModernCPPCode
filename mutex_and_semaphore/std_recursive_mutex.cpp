#include <iostream>
#include <mutex>
#include <vector>
#include <thread>

std::mutex cout_mutex;
std::recursive_mutex r_mutex;

void recursive_function(int num)
{
    std::lock_guard<std::recursive_mutex> lock(r_mutex);

    {
        std::lock_guard<std::mutex> cout_lock(cout_mutex);
        std::cout << "Thread " << std::this_thread::get_id() << " locked at " << num << std::endl;
    }

    if(num < 4)
        recursive_function(num + 1);
}

void demonstrate_recursive_mutex()
{ 
    {
        std::lock_guard<std::mutex> cout_lock(cout_mutex);
        std::cout << "Recursive mutex demonstration \n";
    }
    recursive_function(1);
}

int main()
{
    std::vector<std::thread> threads;
    for(int i = 0; i < 5; i++)
    {
        threads.emplace_back(demonstrate_recursive_mutex);
    }

    for(auto& thread : threads)
    {
        thread.join();
    }
    return 0;
}