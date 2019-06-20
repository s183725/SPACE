#include "inputRead.h"
#include "vectors.h"
#include "directional.h"

int32_t turnVAL(){ // A and D input register
    int32_t tVAL;
    uint8_t ch;
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

int32_t wsVAL(){  // w and s key input
    uint8_t dir = rawIN();

    switch(dir){
    case 119:     // W
        return 1;
    case 115:   // S
        return -1;
    default:
        return 0;
    }
}

/*
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
}*/


int32_t dirVAL(int32_t dVAL, int32_t tVAL){  // used for addition of input wASD

    if (tVAL == 1) {
        dVAL = dVAL + 1;
        if( dVAL > 15){ // Accounts for above radians
             dVAL = dVAL - 15;
        }
    } else if (tVAL < 0) {
         dVAL = dVAL - 1;
         if ( dVAL < 0) {
             dVAL = dVAL + 15;
         }
    } else if (tVAL == 0) {
         dVAL = dVAL + 0;
    }

    return dVAL;
}

/*
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
*/


int32_t directionVector(int32_t dVAL, int32_t *vx, int32_t *vy){    // CASE STATEMENTS FFOR directionVEctor

    if(dVAL == 0) {
        *vx = 3;
        *vy = 0;
    } else if (dVAL == 1) {
        *vx = 2;
        *vy = 1;
    } else if (dVAL == 2) {
        *vx = 2;
        *vy = 2;
    } else if (dVAL == 3) {
        *vx = 1;
        *vy = 2;
    } else if (dVAL == 4) {
        *vx = 0;
        *vy = 3;
    } else if (dVAL == 5) {
        *vx = -1;
        *vy = 2;
    } else if (dVAL == 6) {
        *vx = -2;
        *vy = 2;
    } else if (dVAL == 7) {
        *vx = -2;
        *vy = 1;
    } else if (dVAL == 8) {
        *vx = -3;
        *vy = 0;
    } else if (dVAL == 9) {
        *vx = -2;
        *vy = -1;
    } else if (dVAL == 10) {
        *vx = -2;
        *vy = -2;
    } else if (dVAL == 11) {
        *vx = -1;
        *vy = -2;
    } else if (dVAL == 12) {
        *vx = 0;
        *vy = -3;
    } else if (dVAL == 13) {
        *vx = 1;
        *vy = -2;
    } else if (dVAL == 14) {
        *vx = 2;
        *vy = -2;
    } else if (dVAL == 15) {
        *vx = 2;
        *vy = -1;
    }
    return dVAL;
}

int32_t accelVAL(int32_t spdVAL, int32_t fwdVAL){ //Velocity constant functions

    if (fwdVAL == 1) {
        if(spdVAL > 1){
            spdVAL = 2;
        } else {
            spdVAL = spdVAL + 1;
         // Accounts for above radians
        }
    }

    if (fwdVAL < 0){
        spdVAL = 0;
    }

    return spdVAL;
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
