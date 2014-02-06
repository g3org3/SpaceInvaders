#include <stdio.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include "main.h"

#define SCREEN_W 720
#define SCREEN_H 480
#define FPS 30.00

#define B_SIZE 10
#define E_SIZE 4

int main(){
    ALLEGRO_DISPLAY *display;
    ALLEGRO_TIMER *timer;
    ALLEGRO_EVENT_QUEUE *event_queue;
    ALLEGRO_KEYBOARD_STATE keystate;
    ALLEGRO_BITMAP *bg;
    
    
    bool done, drawbala;
    int x = 4;
    drawbala = false;
    
    al_init();
    al_install_keyboard();
    al_init_image_addon();
    
    
    display = al_create_display(SCREEN_W, SCREEN_H);
    event_queue = al_create_event_queue();
    timer = al_create_timer(1/FPS);
    done = false;
    
    // create space
    struct objeto nave;
    setStruct(&nave, SCREEN_W/2, SCREEN_H-50, 40, 70, 10, 0);
    setStructColor(display, &nave, 1);
    setStructImg(&nave, al_load_bitmap("ship.png"));
    // end
    
    // create bala
    struct objeto *balas[B_SIZE];
    for (int i=0; i<B_SIZE; i++) {
        balas[i] = 0000000;
    }
    // end
    
    bg = al_load_bitmap("Deep_Space.png");
    
    // create enemies
    struct objeto *enemigos[E_SIZE];
    createEnemies(enemigos, E_SIZE, display);
    setEnemiesImg(enemigos, E_SIZE, al_load_bitmap("enemigo.png"));
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
                if(nave.x+nave.w<SCREEN_W)
                    nave.x += nave.dx;
            if(al_key_down(&keystate, ALLEGRO_KEY_LEFT))
                nave.x -= nave.dx;
            
            if(al_key_down(&keystate, ALLEGRO_KEY_SPACE)){
                if(x==4){
                    createBala(balas, display, &nave, B_SIZE);
                    x=0;
                }
                if(x<4)
                    x++;
            }
            
            drawBalas(balas, B_SIZE, enemigos, E_SIZE);
            deleteBala(balas, B_SIZE);
            //printf("%p, %p, %p, %p\n", balas[0], balas[1], balas[2], balas[3]);
            //al_draw_bitmap(enemigo.self, enemigo.x, enemigo.y, 0);
            al_draw_bitmap(nave.self, nave.x, nave.y, 0);
            al_flip_display();
            al_clear_to_color(al_map_rgb(0, 0, 0));
            al_draw_bitmap(bg, 0, 0, 0);
            structMoveAll(enemigos, SCREEN_W, E_SIZE);
            
        }
        
    }
    
    al_destroy_display(display);
    
    return 0;
}
