#include <iostream>
#include <thread>

void f(int i, std::string const &s)
{
    std::cout<<"i:"<<i<<"\ts:"<<s<<std::endl;
}

void oops(int some_param)
{
    char buffer[1024];
    std::cout<<"oops\n";
    sprintf(buffer,"%i", some_param);
    std::cout<<buffer<<std::endl;
    std::thread t(f, 3, buffer);
    t.join();
}

int main()
{
    oops(10);
}
