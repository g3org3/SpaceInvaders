

#define BLUE al_map_rgb(90, 150, 220)
#define RED al_map_rgb(220, 88, 88)
#define GREEN al_map_rgb(70, 180, 95)
#define WHITE al_map_rgb(255, 255, 255)

struct objeto {
    float x;
    float y;
    float h;
    float w;
    float dx;
    float dy;
    ALLEGRO_BITMAP *self;
};

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
    
    //bool rangoY = o->y+o->h == b->y;
    
    return rangoX && rangoY;
}


void createBala(struct objeto *balas[], ALLEGRO_DISPLAY *display, struct objeto *nave, int size){
    for (int i=0; i<size; i++) {
        if(balas[i]==0){
            balas[i] = (struct objeto *) malloc(sizeof(struct objeto));
            setStruct(balas[i], 0, 0, 10, 10, 0, -6);
            setStructColor(display, balas[i], 2);
            (*balas[i]).x = nave->x + nave->w/2;
            (*balas[i]).y = nave->y;
            //printf("%d\n", i);
            i = size*size;
            
        }
    }
}

bool drawBala(struct objeto *balas[], int size, struct objeto *enemigo){
    bool choco;
    for (int i=0; i<size; i++) {
        if(balas[i]!=0){
            choco = checkCollition(enemigo, balas[i]);
            if(!choco){
                al_draw_bitmap(balas[i]->self, balas[i]->x, balas[i]->y, 0);
                balas[i]->y += balas[i]->dy;
                //printf("choco");
                
            } else{
                enemigo->x = -512;
                balas[i]->y = -512;
            }
        }
    }
    al_draw_bitmap(enemigo->self, enemigo->x, enemigo->y, 0);
    return false;
}
bool drawBalas(struct objeto *balas[], int size, struct objeto *enemigos[], int length){
    bool choco;
    for (int i=0; i<size; i++) {
        if(balas[i]!=0){
            for (int j=0; j<length; j++) {
                choco = checkCollition(enemigos[j], balas[i]);
                if(!choco){
                    al_draw_bitmap(balas[i]->self, balas[i]->x, balas[i]->y, 0);
                    balas[i]->y += balas[i]->dy;
                    
                } else{
                    enemigos[j]->y = -512;
                    balas[i]->x = -512;
                }
                //printf("%d", choco);
            }
        }
    }
    for (int i=0; i<length; i++) {
        al_draw_bitmap(enemigos[i]->self, enemigos[i]->x, enemigos[i]->y, 0);
    }
    return false;
}

void deleteBala(struct objeto *balas[], int size){
    for (int i=0; i<size; i++) {
        if(balas[i]!=0){
            if((*balas[i]).y < 0-balas[i]->h){
                free(balas[i]);
                balas[i]=0;
            }
        }
    }
}

void createEnemies(struct objeto *o[], int size, ALLEGRO_DISPLAY *display){
    for (int i=0; i<size; i++) {
        o[i] = (struct objeto *) malloc(sizeof(struct objeto));
        setStruct(o[i], 100+(200*i), 30+(80*i), 70, 100, 5+(i*2), 0);
        setStructColor(display, o[i], 3);
    }

}

void setEnemiesImg(struct objeto *o[], int size, ALLEGRO_BITMAP *b){
    for (int i=0; i<size; i++) {
        o[i]->self = b;
    }
    
}

































