#include "vectors.h"
#include "stdint.h"
//#include "projectiles.h"

#ifndef _PROJECTILES_H_
#define _PROJECTILES_H_

typedef struct projectiles{
    VECTOR V;
    REF_P P;
    int32_t velocity;
} BULLET;

void resetBullet(BULLET ship_B);

void initBullets(BULLET wep1[]);

void moveProjectile(int32_t velConst, int32_t *Bvx, int32_t *Bvy, int32_t *Bpx, int32_t *Bpy);

void updateProjectile(BULLET *ship_B);

#endif
