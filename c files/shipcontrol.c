#include "inputRead.h"
#include "stdbool.h"
#include "vectors.h"
#include "directional.h"

void buildShip (){
    VECTOR ship_V;
    initVector(&ship_V, 3, 0);
}

void updateShip(VECTOR *v, REF_P *p){

    (*p).x = ((*v).x) + ((*p).x);
    (*p).y = ((*v).y) + ((*p).y);
}

void directShip(int32_t init, int32_t dVAL, VECTOR ship_V, REF_P ship_P){

    int32_t tVAL = turnVAL();
    dVAL = dirVAL(init, dVAL, tVAL);
    directionVector(dVAL, &ship_V);
    updateShip(&ship_V, &ship_P);
}


void controlShip(int32_t init, VECTOR ship_V, REF_P ship_P){

    int32_t tVAL = turnVAL();

    if (tVAL == 1){
        rotateVector(&ship_V, 45);
    } else if(tVAL == -1) {
        rotateVector(&ship_V, -45);
    }
    //scaleVector();
    //int32_t accelVAL = wsVAL();
    //accelVector(ship_V, accelVAL);




       // directionArray(turnVAL);
       // directionVector(tVAL);

}

