#include "ansi.h"
#include "stdint.h"
#include "stdio.h"
#include "Terminal.h"

void clrscr(){
    printf("\e[2J");
}

void clreol(){
    printf("\e[K");
}

void gotoyx(uint8_t row, uint8_t column) {
    printf("\e[%d;%dH", row, column);
}

void underline(uint8_t on) {
    if(on == 1) {
        printf("\e[4m");
    } else {
        printf("\e[24m");
    }
}

void blink(uint8_t on) {
    if(on == 1) {
        printf("\e[5m");
    } else {
        printf("\e[25m");
    }
}

void inverseColor(uint8_t on) {
    if (on == 1) {
        printf("\e[7m");
    } else {
        printf("\e[27m");
    }
}

void windows(uint8_t y, uint8_t x) {
    int8_t i,j;

    gotoyx(0,0);
    for(i = 0; i < x; i++) {  // Horizontal kollone
        printf("-");
        //printf("%c", 196);
    }
}
