#include "inputRead.h"
#include "stdbool.h"
#include "vectors.h"

int32_t turnVAL(){
    uint8_t ch;
    int16_t tVAL;
    ch = uart_get_char();  // skal læser input fra A og D

    switch(ch) //at dreje moduret svarer til 1
    {
    case 97:
        return tVAL = 1;
    case 100:
        return tVAL = -1;
    default:
        return tVAL = 0;
    }
}

void rotVAL(int32_t turnVAL){
    int rVAL;

    if (turnVAL == 1) {
        //rVAL = (45 >> 1);
    } else if (turnVAL == -1) {
        //rVAL = 0 - (45 >> 1);
    } else if (turnVAL == 0) {
        rVAL == 0;
    }
    return rVAL;
}
/*
turnVAL

int32_t dir = 0 + turnVAL() + dir;

if (dir < 16 || dir < - 16 )
     dir = 0
*/
int32_t dirVAL(int8_t init, int32_t dVAL, int32_t turnVAL){

    if (turnVAL == 1) {
        dVAL = dVAL + 1;
        if( dVAL > 15){ // Accounts for above radians
             dVAL = dVAL - 15;
        }
    } else if (turnVAL < 0) {
         dVAL = dVAL - 1;
         if ( dVAL < 0) {
             dVAL = dVAL + 15;
         }
    } else if (turnVAL == 0) {
         dVAL = dVAL + 0;
    }

    return dVAL;
}

void dmem(int32_t a){
    int8_t dVAL2;
}


void directionArray(int32_t turnVAL){
    VECTOR dirV[16] = {
        {3,0},
        {2,1},
        {1,1},
        {1,2},
        {0,3},
        {-1,2},
        {-1,1},
        {-2,1},
        {-3,0},
        {-2,-1},
        {-1,-1},
        {-1,-2},
        {0,-3},
        {1,-2},
        {1,-1},
        {2,-1},
    };

    uint8_t *dArray_p;

    if(turnVAL == 1){
        dArray_p++;
    } else if (turnVAL == (-1)){
        dArray_p--;
    }



    return (*dArray_p);
}


void directionVector(int32_t dVAL, VECTOR *v){

    if(dVAL == 0) {
        (*v).x = 3;
        (*v).y = 0;
    } else if (dVAL == 1) {
        (*v).x = 2;
        (*v).y = 1;
    } else if (dVAL == 2) {
        (*v).x = 2;
        (*v).y = 2;
    } else if (dVAL == 3) {
        (*v).x = 1;
        (*v).y = 2;
    } else if (dVAL == 4) {
        (*v).x = 0;
        (*v).y = 3;
    } else if (dVAL == 5) {
        (*v).x = -1;
        (*v).y = 2;
    } else if (dVAL == 6) {
        (*v).x = -2;
        (*v).y = 2;
    } else if (dVAL == 7) {
        (*v).x = -2;
        (*v).y = 1;
    } else if (dVAL == 8) {
        (*v).x = -3;
        (*v).y = 0;
    } else if (dVAL == 9) {
        (*v).x = -2;
        (*v).y = -1;
    } else if (dVAL == 10) {
        (*v).x = -2;
        (*v).y = -2;
    } else if (dVAL == 11) {
        (*v).x = -1;
        (*v).y = -2;
    } else if (dVAL == 12) {
        (*v).x = 0;
        (*v).y = -3;
    } else if (dVAL == 13) {
        (*v).x = 1;
        (*v).y = -2;
    } else if (dVAL == 14) {
        (*v).x = 2;
        (*v).y = -2;
    } else if (dVAL == 15) {
        (*v).x = 2;
        (*v).y = -1;
    }
}

void rawDirection(){

}

int32_t wsVAL(){
    uint8_t dir = rawIN();

    switch(dir){
    case 119:     // W
        return 1;
    case 115:   // S
        return 0;
    }
}



/*
void direction(VECTOR *v){
    uint8_t nDIR;
    nDIR = nDIR + turnVAL();
    if tVAL(tVAL < 16){
        tVAL = 0;
    } else {
    switch()
    case 0:
    }
}
*/
