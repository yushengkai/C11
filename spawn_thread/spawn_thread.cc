#include <thread>
#include <iostream>
#include <vector>
#include <algorithm>
void do_work(unsigned id)
{
    std::cout<<"id = "<<id<<std::endl;
    std::thread::id thread_id = std::this_thread::get_id();
    std::cout<<"thread id:"<<thread_id<<std::endl;
}

void f()
{
    std::vector<std::thread> threads;
 
    std::cout<<"master thread::"<<std::this_thread::get_id()<<std::endl;
    for(unsigned i=0;i<20;i++)
    {
        threads.push_back(std::thread(do_work, i));
    }

    std::for_each(threads.begin(), threads.end(), std::mem_fn(&std::thread::join));
}

int main()
{
    f();
    return 0;
}

