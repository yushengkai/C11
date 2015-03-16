#include <thread>
#include <iostream>

void func_1()
{
    std::cout<<"func_1"<<std::endl;
}

void func_2()
{
    std::cout<<"func_2"<<std::endl;
}

int main()
{
    std::thread t1(func_1);
    std::cout<<1<<std::endl;
    std::thread t2 = std::move(t1);
    std::cout<<2<<std::endl;
    t1=std::thread(func_2);
    std::cout<<3<<std::endl;
    std::thread t3;
    std::cout<<4<<std::endl;
    t3=std::move(t2);
    std::cout<<&t3<<std::endl;
    std::cout<<5<<std::endl;
 //   t1=std::move(t3);
    std::cout<<6<<std::endl;
    t1.join();
    std::cout<<7<<std::endl;
 //   t2.join(); 
    std::cout<<8<<std::endl;
    t3.join(); 
    std::cout<<9<<std::endl;


}

