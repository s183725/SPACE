#include "stdint.h"
#include "stdio.h"
#include "stdlib.h"
#include "sineLUT.h"
#include  "vectors.h"




/*
typedef struct vectorS {
    int16_t x, y;
} VECTOR;

typedef struct referencepoint {
    int16_t x, y;
} REF_P;*/


int8_t power(int32_t base, int32_t exp){  // power function for multiple uses
    int8_t i, r = base;

    for (i = 1; i < exp; i++) {
        r *= base;
    }
    return(r);
}

void scaleMovingVector(VECTOR *v){
    if(abs((*v).x) < 3){
        (*v).x = FIX14_MULT((*v).x,2);
    }

    if(abs((*v).y) < 3){
        (*v).y = FIX14_MULT((*v).y,2);
    }
}



int32_t FIX14_MULT(int32_t a, int32_t b){
    return ((a)*(b)) >> FIX14_SHIFT;
}

int32_t FIX14_DIV(int32_t a, int32_t b){
    return (((a) << FIX14_SHIFT) / b);
}

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

int32_t fSin(int32_t angle) { //
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

int32_t fCos(int32_t angle) { //Cosine function piggybacking off of Sine
    int32_t cosV;
    cosV = fSin(angle + 90);
    return cosV;
}

void initVector(VECTOR *v, int16_t x, int16_t y) { //enables pre-initialized vector
    (*v).x = x;
    (*v).y = y;
}

void initREF_P(REF_P *p, int16_t x, int16_t y) { //ables creation of initial starting point
    (*p).x = x;
    (*p).y = y;
}

VECTOR buildVector(){ //builds null vector for utility
    VECTOR v;

    v.x = 0;
    v.y = 0;
    return v;
}

void cpyVector(VECTOR *v){

}
/*
int32_t accelVector(int32_t spdVAL, VECTOR *v, VECTOR *ship_SPD){  //returns vector and keeping direction vector intact
    //(*v).x = FIX14_MULT(((*v).x),accelVAL);
    //(*v).x = FIX14_MULT(((*v).y),accelVAL);

    (*ship_SPD).x = ((*v).x)*spdVAL;
    (*ship_SPD).y = ((*v).y)*spdVAL;

    return spdVAL;
}
*/
void rotateVector(VECTOR *v, int32_t angle) { //rotates a vector

    int32_t x, y, cosV, sinV;
    x = (*v).x;
    y = (*v).y;
    cosV = fCos(angle);
    sinV = fSin(angle);

    (*v).x = FIX14_MULT(x,cosV) - FIX14_MULT(y,sinV);
    (*v).y = FIX14_MULT(y,cosV) + (FIX14_MULT(x,sinV));
}


void vectorTurn(VECTOR *v, char dir){

}

void vectorlength (){

}

void updateREF_P(VECTOR *v, REF_P *p){  // update updates point p by adding vector v

    (*p).x = (*p).x + (*v).x;
    (*p).y = (*p).y + (*v).y;

}


