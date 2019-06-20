#include "stm32f30x_conf.h"
#include "30010_io.h"

#define RCC_AHBPeriph_GPIOA               RCC_AHBENR_GPIOAEN
#define RCC_AHBPeriph_GPIOB               RCC_AHBENR_GPIOAEN
#define RCC_AHBPeriph_GPIOC               RCC_AHBENR_GPIOAEN

void setupJoyIn(){

//Port A
    RCC->AHBENR |= RCC_AHBPeriph_GPIOA;

//A4  UP
    GPIOA->MODER &= ~(0x0000003 << (4 * 2));
    GPIOA->MODER |= (0x0000000 << (4 * 2));

    GPIOA->PUPDR &= ~(0x0000003 << (4 * 2));
    GPIOA->PUPDR |= (0x0000002 << (4 * 2));



//Port B
    RCC->AHBENR |= RCC_AHBPeriph_GPIOB;

//B0  DOWN
    GPIOB->MODER &= ~(0x0000003 << (0 * 2));
    GPIOB->MODER |= (0x0000000 << (0 * 2));

    GPIOB->PUPDR &= ~(0x0000003 << (0 * 2));
    GPIOB->PUPDR |= (0x0000002 << (0 * 2));

//B5  CENTER
    GPIOB->MODER &= ~(0x0000003 << (5 * 2));
    GPIOB->MODER |= (0x0000000 << (5 * 2));

    GPIOB->PUPDR &= ~(0x0000003 << (5 * 2));
    GPIOB->PUPDR |= (0x0000002 << (5 * 2));

//Port C
    RCC->AHBENR |= RCC_AHBPeriph_GPIOC;

//C0  RIGHT
    GPIOC->MODER &= ~(0x0000003 << (0 * 2));
    GPIOC->MODER |= (0x0000000 << (0 * 2));

    GPIOC->PUPDR &= ~(0x0000003 << (0 * 2));
    GPIOC->PUPDR |= (0x0000002 << (0 * 2));

//C1  LEFT
    GPIOC->MODER &= ~(0x0000003 << (1 * 2));
    GPIOC->MODER |= (0x0000000 << (1 * 2));

    GPIOC->PUPDR &= ~(0x0000003 << (1 * 2));
    GPIOC->PUPDR |= (0x0000002 << (1 * 2));


}

void setupJoyOut(){
    RCC->AHBENR |= RCC_AHBPeriph_GPIOA;

    GPIOA->OSPEEDR &= ~(0x00000003 << (9 * 2));
    GPIOA->OSPEEDR |= (0x00000002 << (9 * 2));

    GPIOA->OTYPER &=  ~(0x0001 << (9));
    GPIOA->OTYPER |= (0x0000 << (9));

    GPIOA->MODER &= ~(0x00000003 << (9 * 2));
    GPIOA->MODER |= (0x00000001 << (9 * 2));
}

int16_t readJoy() {
uint16_t U = GPIOA->IDR & (0x0001 << 4);
uint16_t D = GPIOB->IDR & (0x0001 << 0);
uint16_t L = GPIOC->IDR & (0x0001 << 1);
uint16_t R = GPIOC->IDR & (0x0001 << 0);
uint16_t C = GPIOB->IDR & (0x0001 << 5);

if (U > 0) {
    printf("8");
}  else if  (D > 0) {
    printf("2");
}  else if  (L > 0) {
    printf("4");
}  else if  (R > 0) {
    printf("6");
}  else if  (C > 0) {
    printf("5");
} else {
    printf("0");
}
}
