#ifndef _TRIGPRINT_H_
#define _TRIGPRINT_H_

#include "stdint.h"
#include "stdio.h"


typedef struct vectorS {
    int16_t x, y;
} VECTOR;

int8_t power(int8_t a, int8_t exp);

void printFix(int32_t i);

int32_t expand(int32_t i);

int32_t fSin(int32_t a);

int32_t fCos(int32_t a);

int16_t d2bin(int dNum);

void initVector(VECTOR *v);

void rotateVector(VECTOR *v, int32_t angle);

#endif
