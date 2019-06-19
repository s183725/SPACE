#include "stdio.h"
#include "30010_io.h"

#define RCC_AHBPeriph_GPIOA               RCC_AHBENR_GPIOAEN  //blue
#define RCC_AHBPeriph_GPIOB               RCC_AHBENR_GPIOBEN  //red
#define RCC_AHBPeriph_GPIOC               RCC_AHBENR_GPIOCEN  //green

void setLED(int8_t a);
void turnLEDon(int8_t a);
void color(int8_t a, int8_t b, int8_t c);
