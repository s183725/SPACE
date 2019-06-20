
#include "stm32f30x_conf.h"
#include "30010_io.h"
#include "ansi.h"
#include "terminal.h"

void draw(uint8_t x, uint8_t y, uint8_t color);

void drawShot(uint8_t x, uint8_t y, uint8_t c_array);

void drawEnemy (uint8_t x, uint8_t y, uint8_t c_array);

void drawAsteroid(uint8_t x, uint8_t y);

void drawBlackhole(uint8_t x, uint8_t y);

void drawSpaceship(uint8_t x, uint8_t y, uint8_t c_direction, uint8_t c_array);

void cSpaceship(uint8_t x, uint8_t y, uint8_t cc);

void erase_old_draw(uint8_t oldX, uint8_t oldY, uint8_t lim, uint8_t offsetX, uint8_t offsetY);

