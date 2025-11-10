#include <iostream>
#include <shared_mutex>
#include <thread>
#include <chrono>

std::shared_mutex s_mutex;
int shared_value = 0;

void read_access()
{
    std::shared_lock<std::shared_mutex> lock(s_mutex);
    std::cout << "Reader Thread with ID " << std::this_thread::get_id() << " reading value is " << shared_value << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(50));
}

void write_access()
{
    std::lock_guard<std::shared_mutex> lock(s_mutex);
    shared_value++;
    std::cout << "Writer Thread with ID " << std::this_thread::get_id() << " wrote value " << shared_value << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
}

int main()
{
    std::cout << "Demonstrate Shared Mutex \n";
    std::thread r1(read_access);
    std::thread r2(read_access); // r1 and r2 can run at the same time
    std::thread w1(write_access); // w1 must wait for all readers/writers to finish
    std::thread r3(read_access); 

    r1.join(); r2.join(); w1.join(); r3.join();
    return 0;
}