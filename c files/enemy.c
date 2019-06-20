#include "enemy.h"

struct enemy{
    int32_t x, y; //Coordinates
    uint8_t h; //Health
};

//Kør i while loop
void spawn(uint8_t x, uint8_t y, uint8_t z){ //Spawns Enemies
    struct enemy e1;
    e1.x = x;
    e1.y = y;
    e1.h = 100;

    int i = 0;

    for(i; i <= 16 ; i++){
        if(i < 8){ //Moving up
            clrscr();
            drawEnemy (e1.x, e1.y, z);
            drawEnemy (e1.x, e1.y + 20, z);
            drawEnemy (e1.x, e1.y + 40, z);
            drawEnemy (e1.x, e1.y + 60, z);
            drawEnemy (e1.x, e1.y + 80, z);
            e1.y--;
        } else if (i > 8){ //Moving down
            clrscr();
            drawEnemy (e1.x, e1.y, z);
            drawEnemy (e1.x, e1.y + 20, z);
            drawEnemy (e1.x, e1.y + 40, z);
            drawEnemy (e1.x, e1.y + 80, z);
            e1.y++;
        }
    }
}

/*
void hitbox(uint8_t x, uint8_t y, uint8_t bullet.x, uint8_t bullet.y){ //Check if bullet hits
    struct enemy e2;
    e2.x = x;
    e2.y = y;

    if((bullet.x-5 <= e2.x <= bullet.x+5) && (bullet.y <= e2.y <= bullet.y)){ //Loose health
        e2.h--;
        printf("Mist liv");
    }

    if(e2.h <= 0){ //Dies
        printf("Slet enemy");
    }
}
*/
