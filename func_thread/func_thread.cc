#include <iostream>
#include <thread>
    
class func
{
public:
   int& i;
    func(int& i_):i(i_){}
    void operator()()
    {
        std::cout<<i<<std::endl;
    }

};

void oops()
{
    int some_local_state = 0;
    std::thread my_thread((func(some_local_state)));

    try
    {
        std::cout<<"current thread"<<std::endl;
    }
    catch(...)
    {
        my_thread.join();
        throw;
    }
    my_thread.join();
}

void f()
{
   
}

int main()
{
    oops();
}
