#include "vectors.h"
#include "inputRead.h"
#include "projectiles.h"

#define BULLET_CONST 2

void initBullets(BULLET wep1[]){
    int i;
    for(i = 0; i < 10; i++){
        wep1[i].V.x = 0;
        wep1[i].V.y = 0;

        wep1[i].P.x = 0;
        wep1[i].P.y = 0;

        wep1[i].velocity = 2;
    }
}



void moveProjectile(int32_t velConstant, int32_t *vx, int32_t *vy, int32_t *px, int32_t *py){ //determintes new position of ship coordinates px and py

   //(*ship_P).x = FIX14_MULT((*ship_V).x, spdVAL) + (*ship_P).x;
   //(*ship_P).y = FIX14_MULT((*ship_V).y, spdVAL) + (*ship_P).y;

    *px = ((*vx) << velConstant) + *px;
    *py = ((*vy) << velConstant) + *py;
}

void updateProjectile(BULLET *ship_B){

    int32_t Bvx = (*ship_B).V.x;
    int32_t Bvy = (*ship_B).V.y;
    int32_t Bpx = (*ship_B).P.x;
    int32_t Bpy = (*ship_B).P.y;

    moveProjectile(2, &Bvx, &Bvy, &Bpx, &Bpy);

    if ((Bpx < 0) || (Bpy < 0) || (Bpx > 380) || (Bpy > 120)) {
        Bpx = 0;
        Bpy = 0;
    }
        (*ship_B).P.x = Bpx;
        (*ship_B).P.y = Bpy;
}




