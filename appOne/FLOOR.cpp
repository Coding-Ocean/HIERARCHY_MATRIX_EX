#include "GAME.h"
#include "FLOOR.h"

FLOOR::FLOOR(GAME* game):
    OBJECT(game)
{
}

int FLOOR::setup()
{
    Data = game()->allData()->floorData;
    return 0;
}

void FLOOR::draw()
{
    for (int z = -Data.range; z <= Data.range; z++) {
        for (int x = -Data.range; x <= Data.range; x++) {
            World.identity();
            World.mulScaling(Data.scale, 1, Data.scale);
            World.mulTranslate((float)x, 0, (float)z);
            int no = (z + x) % 2 == 0 ? 0 : 1;
            Plane.draw(World, Data.color[no]);
        }
    }
}

//カメラターゲット用位置
VECTOR FLOOR::pos()
{
    return Data.pos;
}
