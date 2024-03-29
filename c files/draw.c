
#include "stm32f30x_conf.h"
#include "30010_io.h"
#include "ansi.h"
#include "terminal.h"


void draw(uint8_t x, uint8_t y, uint8_t color){

    gotoyx(y,x);
    //bgcolor(color);
    putchar(32); //or uart_put_char
    //bgcolor(0);


}


void erase_old_draw(uint8_t oldX, uint8_t oldY, uint8_t lim, uint8_t offsetX, uint8_t offsetY){
    int8_t x1,y1,x2,i,j; //oldX/oldY = refX/refY, lim = size of loop

    x1=x2=oldX-offsetX;
    y1=oldY-offsetY;

    /*
    fgcolor(4);
    for(i=0; i<lim; i++){
        gotoyx(x1, y1+i);
        printf("l l l l l l l");
    }

*/
    for(i=0; i<lim; i++){
        for(j=0; j<lim; j++){

            draw(x1, y1, 0);
            x1++;
        }
        x1=x2;
        y1++;
    }

    fgcolor(15);
//Skal kaldes f�r refX/Y for skib/skud opdateres

}


void drawShot(uint8_t x, uint8_t y, uint8_t c_array){
   int8_t x1,y1,x2,i,j;
   x1=x2=x-2;
   y1=y-2;


   int shot1[6][6]={
        {0, 0, 0, 0, 0, 0},
        {0, 0, 4, 0, 0, 0},
        {0, 4, 6, 4, 0, 0},
        {0, 0, 4, 0, 0, 0},
        {0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0},
    };

   int shot2[6][6]={
        {0, 4, 4, 4, 4, 0},
        {4, 4, 6, 6, 4, 4},
        {4, 6, 7, 7, 6, 4},
        {4, 6, 7, 7, 6, 4},
        {4, 4, 6, 6, 4, 4},
        {0, 4, 4, 4, 4, 0},
    };


   for(i=0; i<6; i++){
            for(j=0; j<6; j++){

                if (c_array == 1){
                    if (shot1[i][j] > 0){
                            draw(x1, y1, shot1[i][j]);
                    }

                }
                if (c_array == 2){
                    if (shot2[i][j] > 0){
                            draw(x1, y1, shot2[i][j]);
                    }
                }
            x1++;
            }
        x1=x2;
        y1++;
        }

    bgcolor(0);
}


void drawEnemy (uint8_t x, uint8_t y, uint8_t c_array){
   int8_t x1,y1,x2,i,j;
   x1=x2=x-5;
   y1=y-5;


    int enemy1[11][11]={
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 4, 4, 4, 0, 0, 0, 0},
        {0, 0, 0, 4, 3, 3, 3, 4, 0, 0, 0},
        {0, 0, 4, 3, 3, 3, 3, 3, 4, 0, 0},
        {0, 0, 4, 3, 1, 3, 1, 3, 4, 0, 0},
        {0, 0, 4, 3, 3, 3, 3, 3, 4, 0, 0},
        {4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4},
        {3, 4, 4, 4, 4, 4, 4, 4, 4, 4, 3},
        {0, 3, 0, 3, 0, 3, 0, 3, 0, 3, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    };

    int enemy2[11][11]={
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 5, 5, 5, 0, 0, 0, 0},
        {0, 0, 0, 5, 5, 3, 5, 5, 0, 0, 0},
        {0, 0, 5, 5, 5, 5, 5, 5, 5, 0, 0},
        {0, 5, 5, 3, 5, 3, 5, 3, 5, 5, 0},
        {0, 0, 5, 5, 5, 5, 5, 5, 5, 0, 0},
        {0, 0, 0, 5, 0, 5, 0, 5, 0, 0, 0},
        {0, 0, 5, 0, 5, 0, 5, 0, 5, 0, 0},
        {0, 2, 5, 0, 2, 0, 2, 0, 5, 2, 0},
    };

    int enemy3[11][11]={
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 5, 5, 5, 5, 0, 0, 0, 0},
        {0, 0, 5, 1, 5, 5, 1, 5, 0, 0, 0},
        {0, 0, 0, 5, 5, 5, 5, 0, 0, 0, 0},
        {0, 5, 0, 0, 5, 5, 0, 0, 5, 0, 0},
        {3, 0, 5, 5, 5, 5, 5, 5, 0, 3, 0},
        {0, 0, 5, 5, 5, 5, 5, 5, 0, 0, 0},
        {5, 5, 0, 5, 5, 5, 5, 0, 5, 5, 0},
        {0, 5, 5, 0, 5, 5, 0, 5, 5, 0, 0},
        {3, 3, 0, 0, 3, 3, 0, 0, 3, 3, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    };

    int enemy4[11][11]={
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 7, 7, 7, 0, 0, 0, 0},
        {0, 0, 0, 7, 6, 6, 6, 7, 0, 0, 0},
        {0, 0, 7, 6, 6, 6, 6, 6, 7, 0, 0},
        {7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7},
        {0, 7, 3, 7, 3, 7, 3, 7, 3, 7, 0},
        {0, 0, 7, 7, 7, 7, 7, 7, 7, 0, 0},
        {0, 7, 0, 7, 7, 7, 7, 7, 0, 7, 0},
        {7, 0, 0, 0, 0, 7, 0, 0, 0, 0, 7},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    };

    for(i=0; i<11; i++){
        for(j=0; j<11; j++){

            if (c_array == 1){
                if (enemy1[i][j] > 0){
                    draw(x1, y1, enemy1[i][j]);
                }
            }
            if (c_array == 2){
                if (enemy2[i][j] > 0){
                    draw(x1, y1, enemy2[i][j]);
                }
            }
            if (c_array == 3){
                if (enemy3[i][j] > 0){
                    draw(x1, y1, enemy3[i][j]);
                }
            }
            if (c_array == 4){
                if (enemy4[i][j] > 0){
                    draw(x1, y1, enemy4[i][j]);
                }
            }

            x1++;
        }
        x1=x2;
        y1++;
    }

}

void drawAsteroid(uint8_t x, uint8_t y){
   int8_t x1,y1,x2,i,j;
   x1=x2=x-3;
   y1=y-3;

   int asteroid[7][7]={
       {0, 0, 4, 4, 4, 0, 0},
       {0, 4, 4, 4, 4, 4, 0},
       {4, 4, 7, 4, 4, 7, 4},
       {4, 4, 4, 4, 4, 4, 4},
       {4, 4, 4, 7, 4, 4, 4},
       {0, 4, 4, 4, 4, 4, 0},
       {0, 0, 4, 4, 4, 0, 0},
    };

   for(i=0; i<7; i++){
            for(j=0; j<7; j++){

                if (asteroid[i][j] > 0){
                    draw(x1, y1, asteroid[i][j]);
                }
                x1++;
            }
        x1=x2;
        y1++;
        }

    bgcolor(0);
}


void drawBlackhole(uint8_t x, uint8_t y){
   int8_t x1,y1,x2,i,j;
   x1=x2=x-34;
   y1=y-33;

   int Blackhole[34][33]={
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0},
        {0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0},
        {0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0},
        {0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 0},
        {0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0},
        {0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0},
        {0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0},
        {0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0},
        {1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1},
        {1, 1, 3, 3, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1},
        {1, 1, 3, 3, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1},
        {1, 1, 3, 3, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 3, 3, 1, 1},
        {1, 1, 3, 3, 3, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 3, 3, 3, 1, 1},
        {1, 1, 3, 3, 3, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 3, 3, 1, 1, 1},
        {0, 1, 1, 3, 7, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 3, 3, 1, 1, 0},
        {0, 1, 1, 3, 7, 3, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 3, 3, 3, 1, 1, 0},
        {0, 0, 1, 1, 3, 7, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 3, 3, 1, 1, 0, 0},
        {0, 0, 1, 1, 3, 3, 3, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 3, 3, 3, 1, 1, 0, 0},
        {0, 0, 0, 1, 3, 3, 3, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 3, 3, 1, 1, 0, 0, 0},
        {0, 0, 0, 1, 1, 3, 3, 3, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 3, 7, 3, 1, 1, 0, 0, 0},
        {0, 0, 0, 0, 1, 1, 3, 3, 3, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 3, 7, 3, 1, 1, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 1, 1, 3, 3, 3, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 3, 7, 3, 1, 1, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 1, 1, 3, 3, 3, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 3, 7, 3, 1, 1, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 1, 1, 3, 3, 3, 3, 1, 1, 1, 1, 1, 1, 1, 3, 3, 7, 3, 1, 1, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 7, 7, 3, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    };


   for(i=0; i<34; i++){
            for(j=0; j<33; j++){

                if (Blackhole[i][j] > 0){
                    draw(x1, y1, Blackhole[i][j]);
                }
                x1++;
            }
        x1=x2;
        y1++;
        }

    bgcolor(0);
}


void drawSpaceship(uint8_t x, uint8_t y, uint8_t c_direction, uint8_t c_array){
   int8_t x1,y1,x2,i,j;
   x1=x2=x-4;
   y1=y-4;

    bgcolor(7);

    int SS1[10][10]={
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 7, 7, 0, 0, 0, 0, 0, 0, 0},
        {1, 7, 7, 7, 7, 7, 0, 0, 0, 0},
        {1, 7, 7, 3, 3, 3, 7, 7, 0, 0},
        {0, 7, 7, 7, 7, 7, 7, 7, 7, 7},
        {0, 7, 7, 7, 7, 7, 7, 7, 7, 7},
        {1, 7, 7, 3, 3, 3, 7, 7, 0, 0},
        {1, 7, 7, 7, 7, 7, 0, 0, 0, 0},
        {0, 7, 7, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    };

    int SS2[10][10]={
        {0, 0, 0, 0, 0, 1, 7, 7, 0, 0},
        {0, 0, 0, 0, 1, 7, 7, 7, 0, 0},
        {0, 0, 0, 0, 7, 7, 7, 0, 0, 0},
        {0, 0, 0, 7, 7, 3, 7, 7, 0, 0},
        {0, 1, 7, 7, 7, 7, 3, 7, 0, 0},
        {1, 7, 7, 3, 7, 7, 7, 7, 0, 0},
        {7, 7, 7, 7, 3, 7, 7, 7, 0, 0},
        {7, 7, 0, 7, 7, 7, 7, 7, 7, 0},
        {0, 0, 0, 0, 0, 0, 0, 7, 7, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    };

    int SS3[10][10]={
        {0, 0, 0, 1, 7, 7, 7, 0, 0, 0},
        {0, 0, 1, 7, 7, 7, 7, 0, 0, 0},
        {0, 0, 7, 7, 3, 7, 0, 0, 0, 0},
        {1, 7, 7, 7, 7, 3, 7, 0, 0, 0},
        {1, 7, 7, 7, 7, 7, 3, 7, 0, 0},
        {7, 7, 7, 3, 7, 7, 7, 7, 0, 0},
        {7, 7, 7, 7, 3, 3, 3, 7, 7, 0},
        {7, 7, 0, 0, 7, 7, 7, 7, 7, 7},
        {0, 0, 0, 0, 0, 0, 0, 0, 7, 7},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    };

    int SS4[10][10]={
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 7, 7},
        {7, 7, 0, 0, 7, 7, 7, 7, 7, 7},
        {7, 7, 7, 7, 3, 3, 3, 7, 7, 0},
        {7, 7, 7, 3, 7, 7, 7, 7, 0, 0},
        {1, 7, 7, 7, 7, 7, 3, 7, 0, 0},
        {1, 7, 7, 7, 7, 3, 7, 0, 0, 0},
        {0, 0, 7, 7, 3, 7, 0, 0, 0, 0},
        {0, 0, 1, 7, 7, 7, 7, 0, 0, 0},
        {0, 0, 0, 1, 7, 7, 7, 0, 0, 0},
    };



    //Draw in position 1
    if (c_direction == 1){
        for(i=0; i<10; i++){
            for(j=0; j<10; j++){

                if (c_array == 1){
                    if (SS1[i][j] > 0){
                            draw(x1, y1, SS1[i][j]);
                    }
                }
                if (c_array == 2){
                    if (SS2[i][j] > 0){
                            draw(x1, y1, SS2[i][j]);
                    }
                }
                if (c_array == 3){
                    if (SS3[i][j] > 0){
                            draw(x1, y1, SS3[i][j]);
                    }
                }
                if (c_array == 4){
                    if (SS4[i][j] > 0){
                            draw(x1, y1, SS4[i][j]);
                    }
                }

            x1++;
            }
        x1=x2;
        y1++;
        }
    }

    //Draw in position 2
    else if (c_direction == 2){
        for(i=10; i>0; i--){
            for(j=10; j>0; j--){

                if (c_array == 1){
                    if (SS1[i-1][j-1] > 0){
                            draw(x1, y1, SS1[i-1][j-1]);
                    }
                }
                if (c_array == 2){
                    if (SS2[i-1][j-1] > 0){
                            draw(x1, y1, SS2[i-1][j-1]);
                    }
                }
                if (c_array == 3){
                    if (SS3[i-1][j-1] > 0){
                            draw(x1, y1, SS3[i-1][j-1]);
                    }
                }
                if (c_array == 4){
                    if (SS4[i-1][j-1] > 0){
                            draw(x1, y1, SS4[i-1][j-1]);
                    }
                }

            x1++;
            }
        x1=x2;
        y1++;
        }
    }

    //Draw in position 3
    else if (c_direction == 3){
        for(j=10; j>0; j--){
            for(i=0; i<10; i++){

                if (c_array == 1){
                    if (SS1[i][j-1] > 0){
                            draw(x1, y1, SS1[i][j-1]);
                    }
                }
                if (c_array == 2){
                    if (SS2[i][j-1] > 0){
                            draw(x1, y1, SS2[i][j-1]);
                    }
                }
                if (c_array == 3){
                    if (SS3[i][j-1] > 0){
                            draw(x1, y1, SS3[i][j-1]);
                    }
                }
                if (c_array == 4){
                    if (SS4[i][j-1] > 0){
                            draw(x1, y1, SS4[i][j-1]);
                    }
                }

            x1++;
            }
        x1=x2;
        y1++;
        }
    }

    //Draw in position 4
    else if (c_direction == 4){
        for(j=0; j<10; j++){
            for(i=10; i>0; i--){

                if (c_array == 1){
                    if (SS1[i-1][j] > 0){
                            draw(x1, y1, SS1[i-1][j]);
                    }
                }
                if (c_array == 2){
                    if (SS2[i-1][j] > 0){
                            draw(x1, y1, SS2[i-1][j]);
                    }
                }
                if (c_array == 3){
                    if (SS3[i-1][j] > 0){
                            draw(x1, y1, SS3[i-1][j]);
                    }
                }
                if (c_array == 4){
                    if (SS4[i-1][j] > 0){
                            draw(x1, y1, SS4[i-1][j]);
                    }
                }

            x1++;
            }
        x1=x2;
        y1++;
        }
    }

    bgcolor(0);
}


void cSpaceship(uint8_t x, uint8_t y, int32_t cc){

       if (cc == 0){
          drawSpaceship(x,y,1,1);
       }

       else if (cc == 15){
          drawSpaceship(x,y,1,4);
       }

       else if (cc == 14){
          drawSpaceship(x,y,3,2);
       }

       else if (cc == 13){
          drawSpaceship(x,y,3,3);
       }

       else if (cc == 12){
          drawSpaceship(x,y,3,1);
       }


       else if (cc == 11){
          drawSpaceship(x,y,2,3);
       }


       else if (cc == 10){
          drawSpaceship(x,y,2,2);
       }


       else if (cc == 9){
          drawSpaceship(x,y,3,4);
       }


       else if (cc == 8){
          drawSpaceship(x,y,2,1);
       }


       else if (cc == 7){
          drawSpaceship(x,y,2,4);
       }

       else if (cc == 6){
          drawSpaceship(x,y,4,2);
       }


       else if (cc == 5){
          drawSpaceship(x,y,4,3);
       }


       else if (cc == 4){
          drawSpaceship(x,y,4,1);
       }


       else if (cc == 3){
          drawSpaceship(x,y,1,3);
       }


       else if (cc == 2){
          drawSpaceship(x,y,1,2);
       }


       else if (cc == 1){
          drawSpaceship(x,y,4,4);
       }

}



