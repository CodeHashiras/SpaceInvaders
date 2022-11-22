#include <cstdint>

class IMovable
{
protected:
    uint8_t speed;

public:
    /**
     * @brief Change the object position
     * 
     * @param dir Movement direction (-1 = Up | Left, 1 = Down | Right)
     */
    virtual void move(const int dir) = 0;
};
