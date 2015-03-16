#include <thread>
#include <iostream>
#include <mutex>
bool flag=false;
std::mutex m;
int count = 0;
void wait_for_flag()
{
    std::unique_lock<std::mutex> lk(m);
    while(!flag)
    {
        lk.unlock();
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
        lk.lock();
        count = count + 1;
        std::cout<<count<<std::endl;
        if(count == 10)
        {
            flag = true;
        }
    }
}


int main()
{   
    wait_for_flag();
    return 0;
}
