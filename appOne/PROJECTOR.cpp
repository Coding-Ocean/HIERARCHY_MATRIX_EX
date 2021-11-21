#include "GAME.h"
#include "MODEL.h"
#include "PROJECTOR.h"

PROJECTOR::PROJECTOR(class GAME* game)
    :OBJECT(game)
{
}

int PROJECTOR::setup()
{
    Data = game()->allData()->projectorData;
    MODEL::proj.pers(Data.fov, Data.aspect, Data.near_, Data.far_);
    return 0;
}

