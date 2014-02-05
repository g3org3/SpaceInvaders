#include <stdio.h>
#include <allegro5/allegro.h>
#include "main.h"

#define SCREEN_W 800
#define SCREEN_H 500
#define FPS 60.00

int main(){
    ALLEGRO_DISPLAY *display;
    ALLEGRO_TIMER *timer;
    ALLEGRO_EVENT_QUEUE *event_queue;
    ALLEGRO_KEYBOARD_STATE keystate;
    
    bool done, drawbala, creating;
    int x = 4;
    drawbala = false;
    
    al_init();
    al_install_keyboard();
    
    display = al_create_display(SCREEN_W, SCREEN_H);
    event_queue = al_create_event_queue();
    timer = al_create_timer(1/FPS);
    done = false;
    
    // create space
    struct objeto nave;
    setStruct(&nave, SCREEN_W/2, SCREEN_H-30, 100, 100, 4, 0);
    setStructColor(display, &nave, 1);
    // end
    
    // create bala
    struct objeto *balas[4];
    for (int i=0; i<4; i++) {
        balas[i] = 0000000;
    }
    // end
    
    // create enemy
    struct objeto enemigo;
    setStruct(&enemigo, 200, 80, 70, 100, 5, 0);
    setStructColor(display, &enemigo, 3);
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
            if(al_key_down(&keystate, ALLEGRO_KEY_RIGHT))
                nave.x += nave.dx;
            if(al_key_down(&keystate, ALLEGRO_KEY_LEFT))
                nave.x -= nave.dx;
            
            if(al_key_down(&keystate, ALLEGRO_KEY_SPACE)){
                if(x==4){
                    printf("space%f\n", enemigo.x);
                    createBala(balas, display, &nave, 4);
                    x=0;
                }
                if(x<4)
                    x++;
            }
            
            drawBala(balas, 4, &enemigo);
            deleteBala(balas, 4);
            //printf("%p, %p, %p, %p\n", balas[0], balas[1], balas[2], balas[3]);
            //al_draw_bitmap(enemigo.self, enemigo.x, enemigo.y, 0);
            al_draw_bitmap(nave.self, nave.x, nave.y, 0);
            al_flip_display();
            al_clear_to_color(al_map_rgb(0, 0, 0));
            structMove(&enemigo, SCREEN_W);
            
        }
        
    }
    
    al_destroy_display(display);
    
    return 0;
}
