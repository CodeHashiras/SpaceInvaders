#include <cstdint>

const uint8_t MAX_BULLET_LIVES = 1;
const uint8_t MAX_PLAYER_LIVES = 3;

const uint8_t ENEMIES_PER_ROW = 11;
const uint8_t ENEMIES_PER_COLUMN = 5;
const uint8_t TOTAL_ENEMIES = ENEMIES_PER_ROW * ENEMIES_PER_COLUMN;

enum class Direction {Up = -1, Down = 1, Left = -1, Right = 1};
