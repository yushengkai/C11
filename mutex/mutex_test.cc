#include <list>
#include <mutex>
#include <algorithm>
#include <iostream>
std::list<int> some_list;
std::mutex some_mutex;

void add_to_list(int new_value)
{
    std::lock_guard<std::mutex> guard(some_mutex);
    some_list.push_back(new_value);
}

bool list_contains(int value_to_find)
{
    std::lock_guard<std::mutex> guard(some_mutex);
    return std::find(some_list.begin(), some_list.end(), value_to_find)!=some_list.end();
}

class some_data
{
    public:
    void do_something()
    {
        std::cout<<"I am some data"<<std::endl;
    }
};

class data_wrapper
{
private:
    some_data data;
    std::mutex m;
public:
    template <typename Function>
    void process_data(Function func)
    {
        std::lock_guard<std::mutex> l(m);
        func(data);
    }
};

some_data *unprotected;

void malicious_function(some_data& protected_data)
{
    unprotected = &protected_data;
}

data_wrapper x;

void foo()
{
    x.process_data(malicious_function);
    unprotected->do_something();
}


int main()
{
    foo();
    return 0;
}
