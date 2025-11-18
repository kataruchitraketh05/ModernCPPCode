#include <iostream>
#include <thread>
#include <mutex>
#include <vector>

std::mutex cout_mutex, resource_mutex;
int shared_data = 0;

void flexible_increment()
{
    //Create an unique lock object without locking
    std::unique_lock<std::mutex>lock(resource_mutex, std::defer_lock); 

    {
        std::lock_guard<std::mutex>lock(cout_mutex);
        std::cout << "Thread " << std::this_thread::get_id() << ": Lock object is created but mutex is not locked yet \n";
    }
    lock.lock();
    {
        std::lock_guard<std::mutex>lock(cout_mutex);
        std::cout << "Thread " << std::this_thread::get_id() << ": mutex is locked \n";
    }

    shared_data ++;
    {
        std::lock_guard<std::mutex>lock(cout_mutex);
        std::cout << "Thread " << std::this_thread::get_id() << ": data updated to " << shared_data << ".\n";
    }

    lock.unlock();
}

void demonstrate_flexible_mutual_exclusion()
{
    std::cout << "Demonstrate Flexible Mutual Exclusion \n";
    std::vector<std::thread> threads;

    for(int i = 0; i < 10; i++)
    {
        threads.emplace_back(flexible_increment);
    }

    for(auto& thread : threads)
    {
        thread.join();
    }
}

int main()
{
    demonstrate_flexible_mutual_exclusion();
    return 0;
}