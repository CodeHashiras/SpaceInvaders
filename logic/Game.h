#include <vector>
#include "Block.h"
#include "Bullet.h"
#include "Enemy.h"
#include "Player.h"

class Game
{
private:
    Player *player;
    std::vector<GObject> *enemies;
    std::vector<GObject> *blocks;

    /**
     * @brief Initialize all the elements that make up the game
     * 
     */
    void initObjects();

    /**
     * @brief Initialize all enemies in the game
     * 
     */
    void initEnemies();

    /**
     * @brief Initialize all blocks in the game
     * 
     */
    void initBlocks();

public:
    /**
     * @brief Default constructor
     * 
     */
    Game();
};
