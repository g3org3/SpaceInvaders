#include <stdio.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include "metodos.h"

void setStruct(struct objeto *o, float posx, float posy, float height, float width, float dxx, float dyy){
    o-> x = posx;
    o-> y = posy;
    o-> h = height;
    o-> w = width;
    o-> dx = dxx;
    o-> dy = dyy;
    o-> self = al_create_bitmap(width, height);
}

void setStructImg(struct objeto *o, ALLEGRO_BITMAP *b){
    o-> self = b;
}

void setStructColor(ALLEGRO_DISPLAY *display, struct objeto *o, int c){
    al_set_target_bitmap(o->self);
    switch (c) {
        case 1:
            al_clear_to_color(BLUE);
            break;
        case 2:
            al_clear_to_color(RED);
            break;
        case 3:
            al_clear_to_color(GREEN);
            break;
        default:
            al_clear_to_color(WHITE);
            break;
    }
    al_set_target_backbuffer(display);
}

void structMove(struct objeto *o, float w){
    if(o->x>=w)
        o->dx *= -1;
    if(o->x<=0)
        o->dx *= -1;
    o->x += o-> dx;
    o->y += o-> dy;
}

void structMoveAll(struct objeto *o[], float w, int size){
    for (int i=0; i<size; i++) {
        if(o[i]->x>=w)
            o[i]->dx *= -1;
        if(o[i]->x<=0)
            o[i]->dx *= -1;
        o[i]->x += o[i]-> dx;
        o[i]->y += o[i]-> dy;
    }
}

bool checkCollition(struct objeto *o, struct objeto *b){
    bool rango1 = b->x >= o->x;
    bool rango2 = b->x <= o->x + o->w;
    bool rangoX = rango1 && rango2;
    
    bool rangoA = b->y >= o->y;
    bool rangoB = b->y <= o->y + o->h;
    bool rangoY = rangoA && rangoB;
    
    return rangoX && rangoY;
}


void createBala(struct objeto *balas[], ALLEGRO_DISPLAY *display, struct objeto *nave, int size){
    for (int i=0; i<size; i++) {
        if(balas[i]==0){
            balas[i] = (struct objeto *) malloc(sizeof(struct objeto));
            setStruct(balas[i], nave->x+nave->w/2, nave->y, 20, 10, 0, BALA_SPEED);
            setStructColor(display, balas[i], 2);
            return;
        }
    }
}

bool drawBalas(struct objeto *balas[], int size, struct objeto *enemigos[], int length){
    bool choco;
    for (int i=0; i<size; i++) {
        if(balas[i]!=0){
            for (int j=0; j<length; j++) {
                choco = checkCollition(enemigos[j], balas[i]);
                if(!choco){
                    if(balas[i]->y-balas[i]->h<0){
                        free(balas[i]);
                        balas[i] = 0;
                        break;
                    } else {
                        al_draw_bitmap(balas[i]->self, balas[i]->x, balas[i]->y, 0);
                        balas[i]->y += balas[i]->dy;
                    }
                    
                } else{
                    enemigos[j]->y = -500;
                    free(balas[i]);
                    balas[i]=0;
                    break;
                }
            }
        }
    }
    for (int i=0; i<length; i++) {
        al_draw_bitmap(enemigos[i]->self, enemigos[i]->x, enemigos[i]->y, 0);
    }
    return false;
}

void createEnemies(struct objeto *o[], int size, ALLEGRO_DISPLAY *display){
    int p;
    for (int i=0; i<size; i++) {
        p = i;
        o[i] = (struct objeto *) malloc(sizeof(struct objeto));
        if(p<4){
            setStruct(o[i], 100+(200*p), 30+(80*p), 70, 100, 5+(p*2), 0);
            setStructColor(display, o[i], 3);
        } else {
            setStruct(o[i], 50*p, (80*p), 70, 100, 5+(p*2), 0);
            setStructColor(display, o[i], 3);
        }
    }
    
}

void setEnemiesImg(struct objeto *o[], int size, ALLEGRO_BITMAP *b){
    for (int i=0; i<size; i++) {
        o[i]->self = b;
    }
    
}

































