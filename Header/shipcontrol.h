#include "inputRead.h"
#include "vectors.h"
#include "directional.h"
#include "projectiles.h"


typedef struct player{
    VECTOR V;
    REF_P P;
    BULLET B;
    uint8_t hlth;
    uint8_t ammo;
} SHIP;

int32_t wsVAL();

void buildShip();

int32_t shipTurn(int32_t dVAL, VECTOR *ship_V, uint8_t IN);

int32_t moveShip(int32_t spdVAL, int32_t *vx, int32_t *vy, int32_t *px, int32_t *py);

int32_t shipUpdate(int32_t spdVAL, VECTOR *ship_V, REF_P *ship_P, uint8_t IN);

int32_t accelVAL( int32_t spdVAL, int8_t fwdVAL);
