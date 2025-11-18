#include <iostream>
#include <vector>
#include <thread>
#include <chrono>
#include <semaphore>
#include <mutex>

constexpr int NUM_PRINTERS = 3;
constexpr int NUM_JOBS = 5;

std::counting_semaphore<NUM_PRINTERS> printer_pool(NUM_PRINTERS);
//<> Template argument - maximum limit of counter 
//() Constructor argument - Default Initial State
std::mutex cout_mutex;

void print_job(int job_id)
{
    //Decrements the semaphore counter
    printer_pool.acquire();

    {
        std::lock_guard<std::mutex> lock(cout_mutex);
        std::cout << "Job " << job_id << " acquired a printer Starting Job \n";
    }

    //Simulate work done
    std::this_thread::sleep_for(std::chrono::milliseconds(200));

    {
        std::lock_guard<std::mutex> lock(cout_mutex);
        std::cout << "Job " << job_id << " finished and released the printer \n";
    }

    //Increment the semaphore counter
    printer_pool.release();
}

int main()
{
    std::cout << "std counting semaphore demonstration \n";
    std::vector<std::thread> threads;
    for(int i = 0; i < NUM_JOBS; i++)
    {
        threads.emplace_back(print_job, (i+1));
    }

    for(auto& thread : threads)
    {
        thread.join();
    }
    std::cout << "All jobs are finished resource pool is free \n";
    return 0;
}