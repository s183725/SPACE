#include "inputRead.h"
#include "vectors.h"
#include "directional.h"
#include "shipcontrol.h"
#include "projectiles.h"


int32_t moveShip(int32_t spdVAL, int32_t *vx, int32_t *vy, int32_t *px, int32_t *py){ //determintes new position of ship coordinates px and py


   // (*ship_P).x = FIX14_MULT((*ship_V).x, spdVAL) + (*ship_P).x;
   // (*ship_P).y = FIX14_MULT((*ship_V).y, spdVAL) + (*ship_P).y;
    if (spdVAL == 1){
        *px = (*vx) + *px;
        *py = (*vy) + *py;
    } else if (spdVAL > 1)  {
        *px = ((*vx) << spdVAL) + *px;
        *py = ((*vy) << spdVAL) + *py;
    } else if (spdVAL < 1){
        *px = ((*vx) >> 2) + *px;
        *py = ((*vy) >> 2) + *py;
    }

    return spdVAL;
}

 int32_t wsVAL(){  // w and s key input
     int32_t fVAL;
     uint8_t dir = rawIN();

    switch(dir){
    case 119:     // W
        return fVAL = 1;
    case 115:   // S
        return fVAL = -1;
    default:
        return 0;
    }
}

 int32_t accelVAL( int32_t spdVAL, int8_t fwdVAL){ //Velocity constant functions

    if(fwdVAL == 1) {
        if(spdVAL > 1){
            spdVAL = 2;
        } else {
            spdVAL = spdVAL + 1;
         // Accounts for above radians
        }
    }

    if (fwdVAL == -1){
        spdVAL = 0;
    }

    return spdVAL;
}

int32_t shipUpdate(int32_t spdVAL, VECTOR *ship_V, REF_P *ship_P, uint8_t IN){ //updates ship position laterally
    int8_t fwdVAL = 0;

    int32_t vx = (*ship_V).x;
    int32_t vy = (*ship_V).y;

    int32_t px = (*ship_P).x;
    int32_t py = (*ship_P).y;

    if(IN == 119){
        fwdVAL = 1;
    } else if (115) {
        fwdVAL = -1;
    }
    spdVAL = accelVAL(spdVAL, fwdVAL);
    spdVAL = moveShip(spdVAL, &vx, &vy, &px, &py);

    (*ship_P).x = px;
    (*ship_P).y = py;

    return spdVAL;
}

 int32_t shipTurn(int32_t dVAL, VECTOR *ship_V, uint8_t IN){ //turns ship from A and D input around its own axis
    int8_t tVAL = 0;

    int32_t vx = (*ship_V).x;
    int32_t vy = (*ship_V).y;

    if(IN == 97){
        tVAL = 1;
    } else if(IN == 100){
        tVAL = -1;
    }
    dVAL = dirVAL(dVAL, tVAL);
    dVAL = directionVector(dVAL, &vx, &vy);

    (*ship_V).x = vx;
    (*ship_V).y = vy;

    return dVAL;
}

