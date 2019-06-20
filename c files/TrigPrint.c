#include "stdint.h"
#include "stdio.h"
#include "sineLUT.h"
#include "TrigPrint.h"

#define FIX14_SHIFT 14
#define FIXU_SHIFT 16
#define FIX14_MULT(a, b)  ( (a) * (b) >> FIX14_SHIFT )

/*typedef struct vectorS {
    int16_t x, y;
} VECTOR; */

int8_t power(int8_t base, int8_t exp){
    int8_t i, r = base;

    for (i = 1; i < exp; i++) {
        r *= base;
    }
    return(r);
}

int16_t d2bin(int dNum) //decimal til binær funktion
{
    int16_t binNum = 0;
    int16_t rem, temp = 1;

    while (dNum!=0)
    {
        rem = dNum % 2;
        dNum = dNum / 2;
        binNum = binNum + rem*temp;
        temp = temp * 10;
    }
    return binNum;
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

void initVector(VECTOR *v) {
    (*v).x = -4;
    (*v).y = -4;
}

void rotateVector(VECTOR *v, int32_t angle) {
    int32_t x, y;
    x = (*v).x;
    y = (*v).y;
    int32_t cosV = fCos(angle);
    int32_t sinV = fSin(angle);

    //x = (x << );
    //y = (y << 16);

    int32_t a = x*cosV - y*sinV;
    int32_t b = x*sinV + y*cosV;
    //x = FIX14_MULT(x, cosV) - FIX14_MULT(y, sinV);  //x = v.x * cosV - v.y * sinV;
    //y = FIX14_MULT(x, sinV) + FIX14_MULT(y, cosV);  //y = v.x * sinV + v.y * cosV;
    printf("\n");
    printFix(expand(a));
    printf("\n");
    printFix(expand(b));




}
