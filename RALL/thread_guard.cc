#include <iostream>
#include <thread>

class thread_guard
{
    std::thread& t;
public:
    explicit thread_guard(std::thread& t_):t(t_){}
    thread_guard()
    {
        if(t.joinable())
        {
            t.join();
        }
    }
    thread_guard(thread_guard const&) = delete;
    thread_guard& operator=(thread_guard const&) = delete;
};

void func(int&){};

int main()
{
    int some_local_state;
    std::thread t(func(some_local_state));
    thread_guard g(t);

    std::cout<<"do something in current thread"<<std::endl;
    return 0;
}
