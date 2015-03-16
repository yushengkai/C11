#include <thread>
#include <iostream>
#include <mutex>

using namespace std;

class Y
{
    int some_detail;
    mutable std::mutex m;
    int get_detail()const
    {
        std::lock_guard<std::mutex> lock_a(m);
        return get_detail;
    }

    public:
    y(int sd):some_detail(sd){}
    friend bool operator==(Y const& lhs, Y const& rhs)
    {
        if(&lhs == &rhs)
            return true;
        int const lhs_value = lhs.get_detail();
        int const rhs_value = rhs.get_detail();
        return lhs_value == rhs_value;
    }
};
