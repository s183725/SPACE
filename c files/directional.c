#include "inputRead.h"
#include "stdbool.h"
#include "vectors.h"

int32_t initial = 1;

int32_t turnVAL(){
    uint8_t ch;
    int16_t tVAL;
    //ch = uart_get_char();  // skal læser input fra A og D

    ch = 97;
    char character = ch;

    switch(ch) //at dreje moduret svarer til 1
    {
    case 97:
        return tVAL = 1;
    case 100:
        return tVAL = -1;
    default:
        return tVAL = 0;
    }
}

void rotVAL(int32_t turnVAL){
    uint32_t rVAL, initVAL;
    //uint8_t *dirArray[16] = {(0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15 )};
    //if(turnVAL() == )
    if (initVAL != 0){
        initVAL = 0;
        rVAL = 0;
    } else {
        initVAL = 1;
    }

    if (turnVAL == 1) {
        //rVAL = (45 >> 1);
    } else if (turnVAL == -1) {
        //rVAL = 0 - (45 >> 1);
    } else if (turnVAL == 0) {
        rVAL == 0;
    }
    return rVAL;
}

int32_t dirVAL(int32_t turnVAL){
    int32_t dVAL;
    int8_t active;

    if (initial > 0) {
        initial = 0;
        dVAL = 0;
    }

        if (turnVAL == 1) {
            dVAL += 1;
        } else if (turnVAL == -1) {
            dVAL -= 1;
        } else if (turnVAL == 0) {
            dVAL = 0;
        }

        if(dVAL > 15){ // Accounts for above radians
            dVAL -= 15;
        } else if (dVAL < 0) {
            dVAL += 15;
        }

    return dVAL;
}

void dmem(int32_t a){
    int8_t dVAL2;
}


void directionArray(int32_t turnVAL){
    VECTOR dirV[16] = {
        {3,0},
        {2,1},
        {1,1},
        {1,2},
        {0,3},
        {-1,2},
        {-1,1},
        {-2,1},
        {-3,0},
        {-2,-1},
        {-1,-1},
        {-1,-2},
        {0,-3},
        {1,-2},
        {1,-1},
        {2,-1},
    };

    uint8_t *dArray_p;

    if(turnVAL == 1){
        dArray_p++;
    } else if (turnVAL == (-1)){
        dArray_p--;
    }



    return (*dArray_p);
}


void directionVector(int32_t dVAL, VECTOR *v){

    switch(dVAL){
    case 0:
        (*v).x = 3;
        (*v).y = 0;
    case 1:
        (*v).x = 2;
        (*v).y = 1;
    case 2:
        (*v).x = 1;
        (*v).y = 1;
    case 3:
        (*v).x = 1;
        (*v).y = 2;
    case 4:
        (*v).x = 0;
        (*v).y = 3;
    case 5:
        (*v).x = -1;
        (*v).y = 2;
    case 6:
        (*v).x = -1;
        (*v).y = 1;
    case 7:
        (*v).x = -2;
        (*v).y = 1;
    case 8:
        (*v).x = -3;
        (*v).y = 0;
    case 9:
        (*v).x = -2;
        (*v).y = -1;
    case 10:
        (*v).x = -1;
        (*v).y = -1;
    case 11:
        (*v).x = -1;
        (*v).y = -2;
    case 12:
        (*v).x = 0;
        (*v).y = -3;
    case 13:
        (*v).x = 1;
        (*v).y = -2;
    case 14:
        (*v).x = 1;
        (*v).y = -1;
    case 15:
        (*v).x = 2;
        (*v).y = -1;
    }
}

void rawDirection(){

}

/*
void direction(VECTOR *v){
    uint8_t nDIR;
    nDIR = nDIR + turnVAL();
    if tVAL(tVAL < 16){
        tVAL = 0;
    } else {
    switch()
    case 0:
    }
}
*/
