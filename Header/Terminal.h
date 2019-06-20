#include "ansi.h"
#include "stdint.h"
#include "stdio.h"

void clrscr();

void clreol();

void gotoyx(uint8_t row, uint8_t column);

void underline(uint8_t on);

void blink(uint8_t on);

void inverseColor(uint8_t on);

void windows(uint8_t y, uint8_t x);
