#include <pthread>
#include <iostream>

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

    -scoped_thread()
    {
        t.join
    }
};
