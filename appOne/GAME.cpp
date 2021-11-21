#include "GAME.h"

GAME::GAME()
    :Objects(static_cast<int>(OBJ_ID::NUM_OBJECTS), nullptr)
{
}

GAME::~GAME()
{
    for (OBJECT* object : Objects)SAFE_DELETE(object);
}

int GAME::setup()
{
    setAllData(AllData);

    window(AllData.w, AllData.h, AllData.fullScreenFlag);
    if (AllData.fullScreenFlag)hideCursor();
    
    addObject(OBJ_ID::CAMERA, new CAMERA(this));
    addObject(OBJ_ID::PROJECTOR, new PROJECTOR(this));
    addObject(OBJ_ID::LIGHT, new LIGHT(this));
    addObject(OBJ_ID::FLOOR, new FLOOR(this));

    for (OBJECT* object : Objects)object->setup();

    return 0;
}

void GAME::run()
{
    while (notQuit) {
        clear(0, 0, 40);
        for (OBJECT* object : Objects)object->update();
        for (OBJECT* object : Objects)object->draw();
    }
}

int GAME::addObject(OBJ_ID id, OBJECT* object)
{
    Objects[static_cast<int>(id)] = object;
    return static_cast<int>(id);
}

const ALL_DATA* GAME::allData()
{
    return &AllData;
}

OBJECT* GAME::object(OBJ_ID id)
{
    return Objects[static_cast<int>(id)];
}
