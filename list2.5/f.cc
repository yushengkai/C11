#include <thread>
#include <iostream>

void func_1()
{
    std::cout<<"func 1"<<std::endl;
}
std::thread f()
{
    return std::thread(func_1);
}

void func_2(int i)
{
    std::cout<<"func_2:"<<i<<std::endl;
}

std::thread g()
{
    std::thread t(func_2, 42);
    return t;
}

int main()
{
   f().join();
   
    g().join();
}
