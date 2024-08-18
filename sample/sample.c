#include "world.h"

#include <allegro5/allegro.h>

int main(int argc, char** argv)
{
    td_World* world = td_world_create();

    td_world_destroy(world);
    return 0;
}