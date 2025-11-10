#include <iostream>
#include <thread>
#include <chrono>
#include <semaphore>
#include <mutex>

std::binary_semaphore data_ready_signal(0);

std::mutex cout_mutex;
int shared_data = 0;

void producer()
{
    //Perform some work
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    shared_data = 42;
    
    {
        std::lock_guard<std::mutex> lock(cout_mutex);
        std::cout << "Producer finished work and shared data is " << shared_data << std::endl;
    }

    //Increments count to 1
    data_ready_signal.release();
}

void consumer()
{
    // 1. WAIT: Consumer immediately tries to acquire the semaphore.
    // Since the initial count is 0, the consumer thread BLOCKS here.
    {
        std::lock_guard<std::mutex> lock(cout_mutex);
        std::cout << "Consumer acquired semaphore \n";
    }
    data_ready_signal.acquire();

    {
        std::lock_guard<std::mutex> lock(cout_mutex);
        std::cout << "Producer sent release signal to consumer thread\n";
    }
    //Execution only continues after Producer calls release

    {
        std::lock_guard<std::mutex> lock(cout_mutex);
        std::cout << "Consumer received the signal and shared data is " << shared_data << std::endl;
    }
}

int main()
{
    std::thread p(producer);
    std::thread c(consumer);

    p.join(); c.join();
    return 0;
}
