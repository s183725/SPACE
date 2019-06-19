#include "stdint.h"
#include "stdio.h"
#include "stdlib.h"
#include "sineLUT.h"
#include  "vectors.h"

/*typedef struct vectorS {
    int16_t x, y;
} VECTOR;

typedef struct referencepoint {
    int16_t x, y;
} REFP;*/

void scaleVector(VECTOR *v){
    if(abs((*v).x) < 3 || abs((*v).y) < 3  ){
        //(*v).x = FIX14_MULT();
        //(*v).y = FIX14_MULT();
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

VECTOR buildVector(){
    VECTOR v;

    v.x = 0;
    v.y = 0;
    return v;
}

void cpyVector(VECTOR *v){

}

void accelVector(VECTOR *v, int32_t accelVAL){

}

void rotateVector(VECTOR *v, int32_t angle) {

    int32_t x, y, cosV, sinV, a, b;
    x = (*v).x;
    y = (*v).y;
    cosV = fCos(angle);
    sinV = fSin(angle);

    (*v).x = FIX14_MULT(x,cosV) - FIX14_MULT(y,sinV);
    (*v).y = FIX14_MULT(y,cosV) + (FIX14_MULT(x,sinV));
}

int32_t adjustAngle (int32_t angle){

}


void vectorTurn(VECTOR *v, char dir){

}

