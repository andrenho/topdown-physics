#include "world.h"

#include <allegro5/allegro.h>

int main(int argc, char** argv)
{
    // initialize

    td_World* world = td_world_create();

    al_init();
    al_install_keyboard();

    al_set_new_display_option(ALLEGRO_SAMPLE_BUFFERS, 1, ALLEGRO_SUGGEST);
    al_set_new_display_option(ALLEGRO_SAMPLES, 8, ALLEGRO_SUGGEST);

    ALLEGRO_DISPLAY* disp_ = al_create_display(800, 600);
    ALLEGRO_EVENT_QUEUE* queue_ = al_create_event_queue();

    al_register_event_source(queue_, al_get_keyboard_event_source());
    al_register_event_source(queue_, al_get_display_event_source(disp_));

    // main loop

    while (1) {

        // events

        ALLEGRO_EVENT event;
        while (al_get_next_event(queue_, &event)) {

            switch (event.type) {
                case ALLEGRO_EVENT_DISPLAY_CLOSE:
                    goto done;

                case ALLEGRO_EVENT_KEY_CHAR:
                    switch(event.keyboard.keycode) {
                        case ALLEGRO_KEY_Q:
                            goto done;
                    }
                    break;
            }
        }

        // render

        al_clear_to_color(al_map_rgb(255, 255, 255));
        al_flip_display();
    }

    // finalize
done:
    al_destroy_event_queue(queue_);
    al_destroy_display(disp_);
    td_world_destroy(world);

    return 0;
}