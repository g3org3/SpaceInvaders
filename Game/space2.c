


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
}

void setStructColor(ALLEGRO_DISPLAY *display, struct objeto *o, int c){
    al_set_target_bitmap(o->self);
    al_clear_to_color(BLUE);
    al_set_target_backbuffer(display);
}

void structMove(struct objeto *o, float w){
}

void structMoveAll(struct objeto *o[], float w, int size){
}

bool checkCollition(struct objeto *o, struct objeto *b){
    return false;
}


void createBala(struct objeto *balas[], ALLEGRO_DISPLAY *display, struct objeto *nave, int size){
    
    for (int i=0; i<size; i++) {
        if(balas[i]==0){
            balas[i] = (struct objeto *)malloc(sizeof(struct objeto));
            setStruct(balas[i], nave->x+nave->w/2, nave->y, 20, 10, 0, -10);
            setStructColor(display, balas[i], 2);
            i = size;
        }
    }
    
}

bool drawBala(struct objeto *balas[], int size, struct objeto *enemigo){
    return false;
}
bool drawBalas(struct objeto *balas[], int size, struct objeto *enemigos[], int length){
    for (int i=0; i<size; i++) {
        if(balas[i]!=0){
            al_draw_bitmap(balas[i]->self, balas[i]->x, balas[i]->y, 0);
            balas[i]->y += balas[i]-> dy;
        }
    }
    return false;
}

void deleteBala(struct objeto *balas[], int size){
    for (int i=0; i<size; i++) {
        if(balas[i]!=0){
            if(balas[i]->y < 0){
                free(balas[i]);
                balas[i] = 0;
            }
        }
    }
}

void createEnemies(struct objeto *o[], int size, ALLEGRO_DISPLAY *display){
}

void setEnemiesImg(struct objeto *o[], int size, ALLEGRO_BITMAP *b){
}

































