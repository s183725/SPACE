#include "stdint.h"
#include "stdio.h"
#include "sineLUT.h"

typedef struct vectorS {
    int16_t x, y;
} VECTOR;

typedef struct referencepoint {
    int16_t x, y;
} REFP;


void printFix(int32_t i) {
    //Prints a signed 16,16 fixed point number
    if((i & 0x80000000) != 0) { //Handle negative numbers
        printf("-");
        i = ~i + 1;
    }
    printf("%ld.%04ld", i >> 16, 10000 * (uint32_t)(i & 0xFFFF) >> 16);
    //Print a aximum of 4 decimal digits to avoid overflow
}

int32_t expand(int32_t i) {
    //Converterer 18.14 til 16.16
    return i << 2;
}

int32_t fSin(int32_t angle) {
    int32_t sinV, a;

    while(angle < 0) {  //Tests if angle is minus
        angle = 360 + angle;
    }

    a = (angle*512)/360; //Converts angle into 512 table (a)

    while(a > 512) {
        a = a - 512;
    }

    sinV = SIN[a];

    return sinV;
}

int32_t fCos(int32_t angle) {
    int32_t cosV;
    cosV = fSin(angle + 90);
    return cosV;
}

void initVector(VECTOR *v, int16_t x, int16_t y) {
    (*v).x = x;
    (*v).y = y;
}

void buildVector(){
    VECTOR v;

    v.x = 0;
    v.y = 0;

    return v:
}

void rotateVector(VECTOR *v, int32_t angle) {
    int32_t x, y, a, b, cosV, sinV;
    x = (*v).x;
    y = (*v).y;
    cosV = fCos(angle);
    sinV = fSin(angle);

    (*v).x= x*cosV - y*sinV;
    (*v).y = x*sinV + y*cosV;

    /*
    printf("\n");
    printFix(expand(a));
    printf("\n");
    printFix(expand(b));
    */

    return ;
}

VECTOR vectorDIR(VECTOR *v, int32_t angle){

    return v;
}

void vectorTurn(VECTOR *v, char dir){



}



