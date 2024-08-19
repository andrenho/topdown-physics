#include "world.h"

#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>

int main(int argc, char** argv)
{
    // initialize

    td_World* world = td_create();

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

        // adjust zoom and position

        const float zoom_ = 10.f;
        const float center_x = 0.f, center_y = 0.f;
        ALLEGRO_TRANSFORM t;
        al_identity_transform(&t);
        al_scale_transform(&t, zoom_, zoom_);
        al_translate_transform(&t,
                               ((float) al_get_display_width(disp_) / 2.f) - (center_x * zoom_),
                               ((float) al_get_display_height(disp_) / 2.f) - (center_y * zoom_));
        al_use_transform(&t);

        // render

        al_clear_to_color(al_map_rgb(255, 255, 255));
        static td_Shape shape[10000];
        size_t n_shapes = td_shapes(world, shape, sizeof(shape));
        for (size_t i = 0; i < n_shapes; ++i) {
            switch (shape[i].type) {
                case ST_CIRCLE:
                    al_draw_circle(shape[i].circle.x, shape[i].circle.y, shape[i].circle.radius, al_map_rgb(0, 0, 0), 0.1f);
                    break;
                case ST_POLYGON: {
                    float pts[16];
                    for (size_t j = 0; j < shape[i].polygon.n_points; ++j) {
                        pts[(j*2)] = shape[i].polygon.x[j];
                        pts[(j*2)+1] = shape[i].polygon.y[j];
                    }
                    al_draw_polygon(pts, shape[i].polygon.n_points, ALLEGRO_LINE_JOIN_ROUND, al_map_rgb(0, 0, 0), 0.1f, 0);
                    break;
                }
            }
        }
        al_flip_display();
    }

    // finalize
done:
    al_destroy_event_queue(queue_);
    al_destroy_display(disp_);
    td_destroy(world);

    return 0;
}