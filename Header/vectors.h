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

int32_t cpyVectorX(VECTOR *v);

int32_t cpyVectorY(VECTOR *v);

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
void accelVector(int32_t spdVAL, VECTOR *v, VECTOR *ship_SPD);
void updateREF_P(VECTOR *v, REF_P *p);
int32_t vectorlength(VECTOR *v);
int32_t cpyVectorX(VECTOR *v);
int32_t cpyVectorY(VECTOR *v);
VECTOR cpyVector(VECTOR *v);

#endif /* _VECTORS_H_ */



