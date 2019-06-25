#include "inputRead.h"
#include "vectors.h"
#include "directional.h"
#include "shipcontrol.h"
#include "projectiles.h"


int32_t moveShip(int32_t spdVAL, int32_t *vx, int32_t *vy, int32_t *px, int32_t *py){ //determintes new position of ship coordinates px and py

    if (spdVAL == 1){
        *px = (*vx) + *px;
        *py = (*vy) + *py;
    } else if (spdVAL > 1)  {
        *px = ((*vx) << spdVAL) + *px;
        *py = ((*vy) << spdVAL) + *py;
    } else if (spdVAL == 0){
        *px = *px;
        *py = *py;
    }

    return spdVAL;
}


 int32_t accelVAL( int32_t spdVAL, int8_t fwdVAL){ //Velocity constant functions

    if(fwdVAL > 0) {
        if(spdVAL > 1){
            spdVAL = 2;
        } else {
            spdVAL = spdVAL + 1;
         // Accounts for above radians
        }
    }

    if (fwdVAL < 0){
        spdVAL = 0;
    } else if(fwdVAL == 0){
        spdVAL = spdVAL;
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
    } else if (IN == 115) {
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

