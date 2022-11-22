#include <cstdint>

class GObject
{
protected:
    int posX;
    int posY;
    uint8_t lives;

public:
    /**
     * @brief Determine if the object is colliding with another object
     * 
     */
    void collision(GObject);

    /**
     * @brief Reduce the lives number of the object
     * 
     */
    void reduceLife();

    /**
     * @brief Determine is the object has lives to continue in the game
     * 
     * @return true: object is alive (has lives)
     * @return false: object is dead (has no lives)
     */
    bool isAlive();

    /**
     * @brief Get the x-axis position (posX) attribute
     * 
     * @return int 
     */
    int getPosX();

    /**
     * @brief Get the y-axis position (posY) attribute
     * 
     * @return int 
     */
    int getPosY();

    /**
     * @brief Get the lives attribute
     * 
     * @return uint8_t
     */
    uint8_t getLives();

    /**
     * @brief Set the object lives
     * 
     * @param lives Lives number
     */
    void setLives(const uint8_t lives);

    /**
     * @brief Set the object position
     * 
     * @param x X-axis position
     * @param y Y-axis position
     */
    void setPosition(const int x, const int y);
};
