#include <iostream>
#include <map>
#include <string>
#include <mutex>
#include <boost/thread/shared_mutex.hpp>

class dns_entry;

class dns_cache
{
    std::map<std::string, dns_entry> entries;
    boost::shared_mutex entry_mutex;

    public:
    dns_entry find_entry(std::string const& domain)
    {
        boost::shared_lock
    }
        
};

