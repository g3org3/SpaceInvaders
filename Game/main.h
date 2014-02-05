

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

bool checkCollition(struct objeto *o, struct objeto *b){
    bool rango1 = b->x >= o->x;
    bool rango2 = b->x <= o->x + o->w;
    bool rangoX = rango1 && rango2;
    
    //bool rangoA = b->y >= o->y;
    //bool rangoB = b->y <= o->y + o->h;
    //bool rangoY = rangoA && rangoB;
    
    bool rangoY = o->y+o->h == b->y;
    
    return rangoX && rangoY;
}


void createBala(struct objeto *balas[], ALLEGRO_DISPLAY *display, struct objeto *nave, int size){
    for (int i=1; i<size; i++) {
        if(balas[i]==0){
            balas[i] = (struct objeto *) malloc(sizeof(struct objeto));
            setStruct(balas[i], 0, 0, 50, 10, 0, -5);
            setStructColor(display, balas[i], 2);
            (*balas[i]).x = nave->x + nave->w/2;
            (*balas[i]).y = nave->y;
            printf("%d\n", i);
            i = size*size;
            
        }
    }
}

bool drawBala(struct objeto *balas[], int size, struct objeto *enemigo){
    bool choco;
    for (int i=1; i<size; i++) {
        if(balas[i]!=0){
            choco = checkCollition(enemigo, balas[i]);
            if(!choco){
                al_draw_bitmap(balas[i]->self, balas[i]->x, balas[i]->y, 0);
                balas[i]->y += balas[i]->dy;
                
            } else{
                enemigo->x = -512;
                balas[i]->y = -512;
            }
        }
    }
    al_draw_bitmap(enemigo->self, enemigo->x, enemigo->y, 0);
    return false;
}

void deleteBala(struct objeto *balas[], int size){
    for (int i=1; i<size; i++) {
        if(balas[i]!=0){
            if((*balas[i]).y < 0-balas[i]->h){
                free(balas[i]);
                balas[i]=0;
            }
        }
    }
}





































