#include <exception>
class No_Balance_Exception : public std::exception
{
public:
    No_Balance_Exception(/* args */) noexcept = default;
    ~No_Balance_Exception() = default;
    virtual const char* what() const noexcept
    {
        return "Insufficient balance for withdrawal";
    }
};
