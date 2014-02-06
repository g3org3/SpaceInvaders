

#define BLUE al_map_rgb(90, 150, 220)
#define RED al_map_rgb(220, 88, 88)
#define GREEN al_map_rgb(70, 180, 95)
#define WHITE al_map_rgb(255, 255, 255)
#define BALA_SPEED -4


struct objeto {
    float x;
    float y;
    float h;
    float w;
    float dx;
    float dy;
    ALLEGRO_BITMAP *self;
};

void setStruct(struct objeto *o, float posx, float posy, float height, float width, float dxx, float dyy);
void setStructImg(struct objeto *o, ALLEGRO_BITMAP *b);
void setStructColor(ALLEGRO_DISPLAY *display, struct objeto *o, int c);
void structMove(struct objeto *o, float w);
void structMoveAll(struct objeto *o[], float w, int size);
bool checkCollition(struct objeto *o, struct objeto *b);
void createBala(struct objeto *balas[], ALLEGRO_DISPLAY *display, struct objeto *nave, int size);
bool drawBala(struct objeto *balas[], int size, struct objeto *enemigo);
bool drawBalas(struct objeto *balas[], int size, struct objeto *enemigos[], int length);
void deleteBala(struct objeto *balas[], int size);
void createEnemies(struct objeto *o[], int size, ALLEGRO_DISPLAY *display);
void setEnemiesImg(struct objeto *o[], int size, ALLEGRO_BITMAP *b);