#include <stdio.h>
#include <allegro5/allegro.h>

#define SCREEN_W 720
#define SCREEN_H 480
#define FPS 30.00

#define B_SIZE 1
#define E_SIZE 4

int main(){
    ALLEGRO_DISPLAY *display;
    ALLEGRO_TIMER *timer;
    ALLEGRO_EVENT_QUEUE *event_queue;
    ALLEGRO_KEYBOARD_STATE keystate;
    
    
    bool done, drawbala;
    int x = 4;
    drawbala = false;
    
    al_init();
    al_install_keyboard();
    
    
    display = al_create_display(SCREEN_W, SCREEN_H);
    event_queue = al_create_event_queue();
    timer = al_create_timer(1/FPS);
    done = false;
    
    // create space
    // end
    
    // create bala
    // end
    
    // create enemies
    // end
    
    al_register_event_source(event_queue, al_get_keyboard_event_source());
    al_register_event_source(event_queue, al_get_timer_event_source(timer));
    
    al_start_timer(timer);
    
    while (!done) {
        ALLEGRO_EVENT events;
        al_wait_for_event(event_queue, &events);
        al_get_keyboard_state(&keystate);
        
        if(events.type == ALLEGRO_EVENT_KEY_DOWN){
            switch(events.keyboard.keycode){
                case ALLEGRO_KEY_ESCAPE:
                    done = true;
                    break;
            }
        }
        if(events.type == ALLEGRO_EVENT_TIMER){
            

            al_flip_display();
            al_clear_to_color(al_map_rgb(0, 0, 0));
        }
        
    }
    
    al_destroy_display(display);
    
    return 0;
}
