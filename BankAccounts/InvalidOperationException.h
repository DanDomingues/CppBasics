#include <exception>
#include <string>
class Invalid_Operation_Exception : public std::exception
{
private:
    std::string message;
public:
    Invalid_Operation_Exception(std::string message) noexcept :
    exception(), message{message}
    {
    }
    ~Invalid_Operation_Exception() = default;
    virtual const char* what() const noexcept
    {
        const char* ptr {message.c_str()};
        return ptr;
    }
};
