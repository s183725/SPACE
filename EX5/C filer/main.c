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
#include "stdio.h"
#include "stdint.h"
#include "clock.h"
#include "Terminal.h"
#include "TrigPrint.h"

//#define RCC_APB1Periph_TIM2              ((uint32_t)0x00000001)

int main(void)
{


uart_init(115200);  //Default 9600
timerINIT();
//printf("00:00:00:00")
clrscr();

  while(1)
  {
    gotoyx(1,1);
    displayTime();
    printf("\n");
  }
}
