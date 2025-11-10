#include <iostream>
#include <chrono>
#include <thread>
#include <mutex>

std::timed_mutex t_mutex;

void timed_access(int wait_ms)
{
    std::chrono::milliseconds timeout(500);
    
    std::unique_lock<std::timed_mutex> lock(t_mutex, std::defer_lock);
    if(lock.try_lock_for(timeout))
    {
        std::cout << "Thread " << std::this_thread::get_id() << ": Acquired lock holding for " << wait_ms << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(wait_ms));
    }
    else 
    {
        // Lock not acquired within the timeout
        std::cout << "Thread " << std::this_thread::get_id() << ": FAILED to acquire lock within 500ms timeout.\n";
    }
}

int main()
{
    std::cout << "std::timed_mutex demonstration \n";
    std::thread t1(timed_access, 1000);
    std::thread t2(timed_access, 200);

    t1.join();
    t2.join();
    return 0;
}