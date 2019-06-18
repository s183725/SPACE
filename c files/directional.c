#include "shipcontrol.h"
#include "vectors.h"

uint8_t turnVAL(){
    uint8_t ch, tVAL;
    ch = wasdIN();  //læser input fra A og D

    switch(ch) //at dreje moduret svare til at plusse med 1
    {
    case 97:
        return tVAL = 1;
    case 100:
        return tVAL = -1;
    default:
        return tVAL = 0;
    }
}

void directionVAL(){
    uint8_t dirVAL;
    dirVAL = dirVAL + turnVAL();


    //switch()

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
