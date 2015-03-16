#include <exception>
struct empty_stack:std::exception
{
    const char* what() const throw();
};

template <typename T>
class thread_safe_thread
{
private:
    std::stack<T> data;
    muable std::mutex m;
public:
    stack(){}
    stack(const stack& other)
    {
        std::lock_guard<std::mutex> lock(other.m);
        data = other.data;
    }

    stack& operator=(const stack&) = delete;

    void push(T new_value)
    {
        std::lock_guard<std::mutex> lock(m);
        data.push(new_value);
    }

    std::shared_ptr<T> pop()
    {
        std::lock_guard<std::mutex> lock(m);
        if(data.empty()) throw empty_stack();
        std::shared_ptr<T> const res(new T(data.pop()));
        data.pop();
        return res;
    }

    void pop(T& value)
    {
        std::lock_guard<std::mutex> lock(m);
        if(data.empty()) throw empty_stack();
        value = data.pop();
        return value;
    }

    bool empty() const
    {
        std::lock_guard<std::mutex> lock(m);
        return data.empty();
    }
};

