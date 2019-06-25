/*
**
**                           Main.c
**
**
**********************************************************************/
/*
   Last committed:     $Revision: 00 $
   Last changed by:    $Author: $
   Last changed date:  $Date:  $
   ID:                 $Id:  $

**********************************************************************/
#include "stm32f30x_conf.h"
#include "30010_io.h"
#include "inputRead.h"
#include "Terminal.h"
#include "ansi.h"
#include "vectors.h"
#include "directional.h"
#include "stdlib.h"
#include "shipcontrol.h"
#include "projectiles.h"


int main(void)
{
    int32_t dVAL = 0;
    int32_t spdVAL = 0;
    uint8_t clipCount = 0;
    uint8_t k;
    uint8_t IN;

    VECTOR ship_V;
    REF_P ship_P;
    BULLET ship_B[10];

    initVector(&ship_V,2,0); //Initates vector to actual values
    initREF_P(&ship_P, 0,0); //initates REF_P to point with with values other than address
    initBullets(ship_B); // initites bullets to zero across its fields w/o velocity

    uart_init(9600);
    clrscr();
    gotoyx(1,1);
    uint8_t i = 119;
    while(1)
    {

        IN = rawIN();
        if(IN == 97 || IN == 100){
            dVAL = shipTurn(dVAL, &ship_V, IN);
        } else if (IN == 119 || IN == 115){
            spdVAL = shipUpdate(spdVAL,&ship_V,&ship_P, IN);
        } else if (IN == 32){



            if (clipCount < 5){
                ship_B[clipCount].V = cpyVector(&ship_V); //fireBullet(&ship_V)
                ship_B[clipCount].P.x = ship_V.x*5;
                ship_B[clipCount].P.y = ship_V.y*5;
                clipCount++;
            }
        }
            if (clipCount != 0){
                for(k = 0; k < 5; k++){
                    updateProjectile((&ship_B[k]));
                //gotoyx(ship_B[k].P.x, ship_B[k].P.y);

                }
            }
        printf("%ld  |  BULLETS ->  (%ld ,%ld) : (%ld,%ld)  \n", dVAL, ship_B[0].P.x, ship_B[0].P.y, ship_B[1].P.x, ship_B[1].P.y);

    }

}
