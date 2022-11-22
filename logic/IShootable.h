#include "Bullet.h"

class IShootable
{
protected:
    Bullet *bullet;

    /**
     * @brief Get the bullet attribute
     * 
     * @return Bullet* 
     */
    virtual Bullet *getBullet() = 0;

public:
    /**
     * @brief Create a new Bullet object
     * 
     * @note This method does not create a new Bullet object each time, 
     * but restores the position of the bullet attribute
     */
    virtual void shoot() = 0;
};
