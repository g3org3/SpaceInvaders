
struct objeto {
};

void setStruct(struct objeto *o, float posx, float posy, float height, float width, float dxx, float dyy){
}

void setStructImg(struct objeto *o, ALLEGRO_BITMAP *b){
}

void setStructColor(ALLEGRO_DISPLAY *display, struct objeto *o, int c){
}

void structMove(struct objeto *o, float w){
}

void structMoveAll(struct objeto *o[], float w, int size){
}

bool checkCollition(struct objeto *o, struct objeto *b){
    return false;
}


void createBala(struct objeto *balas[], ALLEGRO_DISPLAY *display, struct objeto *nave, int size){

}

bool drawBala(struct objeto *balas[], int size, struct objeto *enemigo){
    return false;
}
bool drawBalas(struct objeto *balas[], int size, struct objeto *enemigos[], int length){

    return false;
}

void deleteBala(struct objeto *balas[], int size){
}

void createEnemies(struct objeto *o[], int size, ALLEGRO_DISPLAY *display){
}

void setEnemiesImg(struct objeto *o[], int size, ALLEGRO_BITMAP *b){
}

































