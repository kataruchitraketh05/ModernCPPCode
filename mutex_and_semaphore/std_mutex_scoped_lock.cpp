#include <iostream>
#include <thread>
#include <mutex>
#include <vector>
#include <chrono>

std::mutex m1, m2, cout_mutex;
int account_a = 100;
int account_b = 100;

void transfer_a_to_b_unsafe(const int& amount)
{
    {  
        std::lock_guard<std::mutex> lock(cout_mutex);
        std::cout << "Amount to transfer unsafely from A to B is " << amount << std::endl;
    }
        std::lock_guard<std::mutex> lock_m1(m1);
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
        std::lock_guard<std::mutex> lock_m2(m2);
        account_a -= amount;
        account_b += amount;
    {  
        std::lock_guard<std::mutex> lock(cout_mutex);
        std::cout << "Final balance in Account A is " << account_a << "\nFinal balance in Account B is " << account_b << std::endl;
    }
}

void transfer_b_to_a_unsafe(const int& amount)
{
    {  
        std::lock_guard<std::mutex> lock(cout_mutex);
        std::cout << "Amount to transfer unsafely from B to A is " << amount << std::endl;
    }
    std::lock_guard<std::mutex> lock_m2(m2);
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
    std::lock_guard<std::mutex> lock_m1(m1);
    account_a += amount;
    account_b -= amount;
    {  
        std::lock_guard<std::mutex> lock(cout_mutex);
        std::cout << "Final balance in Account A is " << account_a << "\nFinal balance in Account B is " << account_b << std::endl;
    }
}

void deposit_a_safe(const int& amount)
{
    {  
        std::lock_guard<std::mutex> lock(cout_mutex);
        std::cout << "Amount Safely Deposited to Account A is " << amount << std::endl;
    }

    std::lock_guard<std::mutex> lock(m1);
    account_a += amount;

    {
        std::lock_guard<std::mutex> lock(cout_mutex);
        std::cout << "Final balance in Account A after deposit is " << account_a << std::endl;
    }
}

void deposit_b_safe(const int& amount)
{
    {  
        std::lock_guard<std::mutex> lock(cout_mutex);
        std::cout << "Amount Safely Deposited to Account B is " << amount << std::endl;
    }

    std::lock_guard<std::mutex> lock(m2);
    account_b += amount;

    {
        std::lock_guard<std::mutex> lock(cout_mutex);
        std::cout << "Final balance in Account B after deposit is " << account_b << std::endl;
    }
}

void transfer_a_to_b_safe(const int& amount)
{
    {  
        std::lock_guard<std::mutex> lock(cout_mutex);
        std::cout << "Amount to transfer safely from A to B is " << amount << std::endl;
    }
    std::scoped_lock lock(m1, m2);
    account_a -= amount;
    account_b += amount;
    {  
        std::lock_guard<std::mutex> lock(cout_mutex);
        std::cout << "Final balance in Account A is " << account_a << "\nFinal balance in Account B is " << account_b << std::endl;
    }
}

void transfer_b_to_a_safe(const int& amount)
{
    {  
        std::lock_guard<std::mutex> lock(cout_mutex);
        std::cout << "Amount to transfer safely from B to A is " << amount << std::endl;
    }
    std::scoped_lock lock(m1, m2);
    account_a += amount;
    account_b -= amount;
    {  
        std::lock_guard<std::mutex> lock(cout_mutex);
        std::cout << "Final balance in Account A is " << account_a << "\nFinal balance in Account B is " << account_b << std::endl;
    }
}

void demonstrate_dead_lock()
{
    std::vector<std::thread> threads;
    for(int i = 0; i < 10; i++)
    {
        if((i % 2) == 0)
            threads.emplace_back(transfer_a_to_b_unsafe, 10);
        else
            threads.emplace_back(transfer_b_to_a_unsafe, 15);
    } 

    for(auto& thread : threads)
    {
        thread.join();
    }  
}

void demonstrate_scoped_lock()
{   
    std::vector<std::thread> threads;
    for(int i = 0; i < 12; i++)
    {
        if(i <= 2)
            threads.emplace_back(deposit_a_safe, 100);
        else if(i <= 5)
            threads.emplace_back(transfer_a_to_b_safe, 40);
        else if(i <= 8)
            threads.emplace_back(deposit_b_safe, 100);
        else
            threads.emplace_back(transfer_b_to_a_safe, 60);
    } 

    for(auto& thread : threads)
    {
        thread.join();
    }  
}

int main()
{
    //demonstrate_dead_lock();
    demonstrate_scoped_lock();
    return 0;
}