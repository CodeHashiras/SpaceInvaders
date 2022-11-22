#include <vector>
#include "GObject.h"

class Block : public GObject
{
private:
    std::vector<GObject> blocks;

public:
    /**
     * @brief Default constuctor
     * 
     */
    Block();
};
