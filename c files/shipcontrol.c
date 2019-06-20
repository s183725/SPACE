#include "inputRead.h"
#include "vectors.h"
#include "directional.h"
#include "shipcontrol.h"

void buildShip (){ // creates a ship vector
    VECTOR ship_V;
    initVector(&ship_V, 3, 0);
}

int32_t moveShip(int32_t w, int32_t *vx, int32_t *vy, int32_t *px, int32_t *py){ //determintes new position of ship coordinates px and py


   // (*ship_P).x = FIX14_MULT((*ship_V).x, spdVAL) + (*ship_P).x;
   // (*ship_P).y = FIX14_MULT((*ship_V).y, spdVAL) + (*ship_P).y;

    *px = (*vx)*w + *px;
    *py = (*vy)*w + *py;

    return w;
}

int32_t shipUpdate(int32_t spdVAL, VECTOR *ship_V, REF_P *ship_P){ //updates ship position laterally

    int32_t vx = (*ship_V).x;
    int32_t vy = (*ship_V).y;

    int32_t px = (*ship_P).x;
    int32_t py = (*ship_P).y;

    int32_t fwdVAL = wsVAL();
    spdVAL = accelVAL(spdVAL, fwdVAL);
    spdVAL = moveShip(spdVAL, &vx, &vy, &px, &py);

    (*ship_P).x = px;
    (*ship_P).y = py;

    return spdVAL;
}

int32_t shipTurn(int32_t dVAL, VECTOR *ship_V){ //turns ship from A and D input around its own axis

    int32_t vx = (*ship_V).x;
    int32_t vy = (*ship_V).y;

    int32_t tVAL = turnVAL();
    dVAL = dirVAL(dVAL, tVAL);
    dVAL = directionVector(dVAL, &vx, &vy);

    (*ship_V).x = vx;
    (*ship_V).y = vy;

    return dVAL;
}

