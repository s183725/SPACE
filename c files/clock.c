

#include "clock.h"
#include "stm32f30x_conf.h"

//#define RCC_APB1Periph_TIM2              ((uint32_t)0x00000001


typedef struct{
    uint8_t msec, sec, minute, hour;
} watch;

volatile watch timer; //global variable

void timerINIT() {

RCC->APB1ENR |= RCC_APB1Periph_TIM2;

TIM2->CR1 = (0x0000);
TIM2->ARR = (0x0009C400);
TIM2->PSC = (0x00000000);

TIM2->DIER |= 0x0001;

NVIC_SetPriority(TIM2_IRQn, 0);
NVIC_EnableIRQ(TIM2_IRQn);

TIM2->CR1 |= (0x0001);
}

void TIM2_IRQHandler(void){
    //printf("Hello\n");
    timer.msec++;
    TIM2->SR &= ~0x0001;
}

void counter() {
    if (timer.msec > 99) {
        timer.sec++;
        timer.msec = 0;
    }

    if (timer.sec > 59) {
        timer.minute++;
        timer.sec = 0;
    }

    if (timer.minute > 59) {
        timer.hour++;
        timer.minute = 0;
    }
}

void displayTime() {
    counter();
    printf("%02d:%02d:%02d:%02d", timer.hour, timer.minute, timer.sec, timer.msec);
}
