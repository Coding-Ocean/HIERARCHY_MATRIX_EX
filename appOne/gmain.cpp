#include"GAME.h"
void gmain() {
    GAME* game = new GAME;
    game->setup();
    game->run();
    delete game;
}
