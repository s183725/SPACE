
/*

#include "stm32f30x_conf.h"

void setLED(int8_t a){

/*
//PA9 (blue)
RCC->AHBENR |= RCC_AHBPeriph_GPIOA;
 // Set pin PA1 to output
 GPIOA->OSPEEDR &= ~(0x00000003 << (a * 2)); // Clear speed register
 GPIOA->OSPEEDR |= (0x00000002 << (a * 2)); // set speed register (0x01 - 10
 //MHz, 0x02 - 2 MHz, 0x03 - 50 MHz)
 GPIOA->OTYPER &= ~(0x0001 << (a)); // Clear output type register
 GPIOA->OTYPER |= (0x0000 << (a)); // Set output type register (0x00 -
 //Push pull, 0x01 - Open drain)
 GPIOA->MODER &= ~(0x00000003 << (a * 2)); // Clear mode register
 GPIOA->MODER |= (0x00000001 << (a * 2)); // Set mode register (0x00 –
 //Input, 0x01 - Output, 0x02 - Alternate Function, 0x03 - Analog in/out)

GPIOA->ODR |= (0x0000 << a); //Set pin PA1 to high
*/



/*
//PB4 (red)
RCC->AHBENR |= RCC_AHBPeriph_GPIOB;

GPIOB->OSPEEDR &= ~(0x00000003 << (a * 2)); // Clear speed register
GPIOB->OSPEEDR |= (0x00000002 << (a * 2)); // set speed register (0x01 - 10
//MHz, 0x02 - 2 MHz, 0x03 - 50 MHz)
GPIOB->OTYPER &= ~(0x0001 << (a)); // Clear output type register
GPIOB->OTYPER |= (0x0000 << (a)); // Set output type register (0x00 -
//Push pull, 0x01 - Open drain)
GPIOB->MODER &= ~(0x00000003 << (a * 2)); // Clear mode register
GPIOB->MODER |= (0x00000001 << (a * 2)); // Set mode register (0x00 –
//Input, 0x01 - Output, 0x02 - Alternate Function, 0x03 - Analog in/out)

GPIOB->ODR |= (0x0000 << a); //Set pin PA1 to high
*/



/*
//PC7 (green)
RCC->AHBENR |= RCC_AHBPeriph_GPIOC;

GPIOC->OSPEEDR &= ~(0x00000003 << (a * 2)); // Clear speed register
GPIOC->OSPEEDR |= (0x00000002 << (a * 2)); // set speed register (0x01 - 10
//MHz, 0x02 - 2 MHz, 0x03 - 50 MHz)
GPIOC->OTYPER &= ~(0x0001 << (a)); // Clear output type register
GPIOC->OTYPER |= (0x0000 << (a)); // Set output type register (0x00 -
//Push pull, 0x01 - Open drain)
GPIOC->MODER &= ~(0x00000003 << (a * 2)); // Clear mode register
GPIOC->MODER |= (0x00000001 << (a * 2)); // Set mode register (0x00 –
//Input, 0x01 - Output, 0x02 - Alternate Function, 0x03 - Analog in/out)

GPIOC->ODR |= (0x0000 << a); //Set pin PA1 to high
*/




/*
}


void turnLEDon(int8_t a){


//PA9 (blue)
//GPIOA->ODR |= (0x0000 << a); //Set pin PA1 to high

//PB4 (red)
//GPIOB->ODR |= (0x0000 << a); //Set pin PA1 to high

//PC7 (green)
GPIOC->ODR |= (0x0000 << a); //Set pin PA1 to high

}

*/
