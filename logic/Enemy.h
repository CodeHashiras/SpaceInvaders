#include "GObject.h"
#include "IMovable.h"
#include "IShootable.h"

class Enemy : public GObject, public IMovable, public IShootable
{
public:
    void move(const int dir) override;

    void shoot() override;
    
    /**
     * @brief Default constructor
     * 
     */
    Enemy();
};
