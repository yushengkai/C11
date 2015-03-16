#include<iostream>
#include <thread>
class scoped_thread
{
    std::thread t;
    public:
    explicit scoped_thread(std::thread t_):t(std::move(t_))
    {
        if(!t.joinable())
        {
            throw std::logic_error("No thread");
        }
    }

    ~scoped_thread()
    {
        t.join();
    }

    scoped_thread(scoped_thread const&)=delete;
    scoped_thread& operator=(scoped_thread const&)=delete;
};

void func(int& data)
{
    std::cout<<data<<std::endl;
}

int main()
{
    int some_local_state;
    scoped_thread t(std::thread(func, some_local_state));
    std::cout<<"do something0"<<std::endl;

    return 0;
}



