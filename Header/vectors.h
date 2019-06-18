#include "sineLUT.h"
#include "stdint.h"

typedef struct vectorS {
    int16_t x, y;
} VECTOR;

typedef struct referencepoint {
    int16_t x, y;
} REFP;

void printFix(int32_t i);
int32_t expand(int32_t i);
int32_t fSin(int32_t angle);
int32_t fCos(int32_t angle);
void initVector(VECTOR *v);
void rotateVector(VECTOR *v, int32_t angle);
