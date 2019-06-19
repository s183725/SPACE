#include "30010_io.h"
#include "charset.h"
#include <string.h>

void lcd_write_string(char *text, uint8_t* buffer);
void lcd_write_string1(uint8_t h, uint8_t* buffer);
void lcd_write_string2(uint8_t* buffer);
void lcd_write_string3(uint8_t p,uint8_t *buffer);
