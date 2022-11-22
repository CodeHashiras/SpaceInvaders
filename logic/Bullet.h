#include "Constants.h"
#include "GObject.h"
#include "IMovable.h"

class Bullet : public GObject, public IMovable
{
public:
    void move(const int dir) override;

    /**
     * @brief Default constructor
     * 
     */
    Bullet();

    /**
     * @brief Parameterized constructor
     * 
     * @param x X-axis position
     * @param y Y-axis position
     */
    Bullet(const int x, const int y);

    /**
     * @brief Reset to initial state (with all lives) and change its position to the given one
     * 
     * @param x X-axis position
     * @param y Y-axis position
     */
    void reset(const int x, const int y);
};
