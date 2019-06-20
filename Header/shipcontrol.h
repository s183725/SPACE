#include "inputRead.h"
#include "stdbool.h"
#include "vectors.h"
#include "directional.h"

void buildShip ();

int32_t shipTurn(int32_t dVAL, VECTOR *ship_V);

int32_t moveShip(int32_t spdVAL, int32_t *vx, int32_t *vy, int32_t *px, int32_t *py);

int32_t shipUpdate(int32_t spdVAL, VECTOR *ship_V, REF_P *ship_P);
