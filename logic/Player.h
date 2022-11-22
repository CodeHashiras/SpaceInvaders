#include "Bullet.h"
#include "Constants.h"
#include "GObject.h"
#include "IMovable.h"
#include "IShootable.h"

class Player : public GObject, public IMovable, public IShootable
{
public:
    void move(const int dir) override;
    
    void shoot() override;
    Bullet *getBullet() override;

    /**
     * @brief Parameterized constructor
     * 
     * @param x X-axis position
     * @param y Y-axis position
     */
    Player(const int x, const int y);
};
