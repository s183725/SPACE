#include "sineLUT.h"
#include "stdint.h"


#ifndef _VECTORS_H_
#define _VECTORS_H_

#define FIX14_SHIFT 14

typedef struct vectorS {
    int32_t x, y;
} VECTOR;

typedef struct referencepoint {
    int32_t x, y;
} REF_P;

void scaleVector(VECTOR *v);

int32_t FIX14_MULT(int32_t a, int32_t b);
int32_t FIX14_DIV(int32_t a, int32_t b);

void printFix(int32_t i);
int32_t expand(int32_t i);
int32_t fSin(int32_t angle);
int32_t fCos(int32_t angle);
void initVector(VECTOR *v, int16_t x, int16_t y);
VECTOR buildVector();
void rotateVector(VECTOR *v, int32_t angle);
VECTOR accelVector(VECTOR *v, int32_t accelVAL);
void updateREF_P(VECTOR *v, REF_P *p);


#endif /* _VECTORS_H_ */
