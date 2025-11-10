#include <iostream>
#include <thread>
#include <mutex>
#include <vector>

std::mutex unsafe_increment_mutex, safe_increment_mutex;
int unsafe_increment_mutex_data = 0;
int safe_increment_mutex_data = 0;

void unsafe_increment()
{
    //Lock the mutex manually
    unsafe_increment_mutex.lock();

    unsafe_increment_mutex_data++;

    std::cout << "Unsafe increment mutex shared data is " << unsafe_increment_mutex_data << std::endl;
    //Added a hypotetical unsafe condition
    if(unsafe_increment_mutex_data == 5)
    {
        return;
    }

    //Unlock mutex manually
    unsafe_increment_mutex.unlock();
}

//Inspite of return statement the thread completes it's execution without any deadlock
void safe_increment()
{
    std::lock_guard<std::mutex> lock(safe_increment_mutex);

    safe_increment_mutex_data ++;
    std::cout << "Safe increment mutex shared data is " << safe_increment_mutex_data << std::endl;

    //Added a hypotetical unsafe condition
    if(unsafe_increment_mutex_data == 5)
    {
        return;
    }
}

void demonstrate_unsafe_mutual_exclusion()
{
    std::cout << "Demonstrate Unsafe Mutual Exclusion \n";
    std::vector<std::thread> threads;

    for(int i = 0; i < 10; i++)
    {
        threads.emplace_back(unsafe_increment);
    }

    for(auto& thread : threads)
    {
        thread.join();
    }
}

void demonstrate_safe_mutual_exclusion()
{
    std::cout << "Demonstrate Safe Mutual Exclusion \n";
    std::vector<std::thread> threads;

    for(int i = 0; i < 10; i++)
    {
        threads.emplace_back(safe_increment);
    }

    for(auto& thread : threads)
    {
        thread.join();
    }
}

int main()
{
    //demonstrate_unsafe_mutual_exclusion();
    demonstrate_safe_mutual_exclusion();
    return 0;
}