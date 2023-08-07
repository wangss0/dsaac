


#ifndef __MY_EXCEPTION__H__
#define __MY_EXCEPTION__H__

#include <stdexcept>
#include <string>
#include <sstream> 

class illegalIndex : public std::runtime_error
{
public:
    explicit illegalIndex(const std::string& message)
        : std::runtime_error(message)
    {
    }
};

class illegalParameter : public std::runtime_error
{
public:
    explicit illegalParameter(const std::string& message)
        : std::runtime_error(message)
    {
    }
};


#endif // !__MY_EXCEPTION__H__
