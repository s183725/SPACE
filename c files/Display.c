#include "Display.h"

void lcd_write_string(char *text, uint8_t* buffer){

    uint8_t i, j, l, a, symbol, t;
    uint16_t z = 0; //z = the number of a specific column 0..512

    l = strlen(text);

    for(i = 0; i < l; i++){
        symbol = text[i];
        t = symbol - 0x20; //0x20=32

        for(j = 0; j < 5; j++){

            a = character_data[t][j];
            memset(buffer + z, a, 1);
            z++;
        }
    }
}

void lcd_write_string1(uint8_t h, uint8_t* buffer){

    uint16_t r = 128; //Second row
    uint8_t hp; //Health
    uint8_t k = 0;

    if (h == 1){
        k++;
    }

    //Heart
    memset(buffer + r, 12, 1);
    memset(buffer + 1 + r, 30, 1);
    memset(buffer + 2 + r, 63, 1);
    memset(buffer + 3 + r, 127, 1);
    memset(buffer + 4 + r, 254, 1);
    memset(buffer + 5 + r, 127, 1);
    memset(buffer + 6 + r, 63, 1);
    memset(buffer + 7 + r, 30, 1);
    memset(buffer + 8 + r, 12, 1);

    for(hp = 18; hp < 58 - k; hp = hp + 2){
        memset(buffer + hp + r, 85, 1);
    }

    for(hp = 19; hp < 58 - k; hp = hp + 2){
        memset(buffer + hp + r, 42, 1);
    }
}

void lcd_write_string2(uint8_t* buffer){

    uint16_t r = 256; //Third row
    uint8_t b; //Boost

    //Boost sign
    memset(buffer + r, 127, 1);
    memset(buffer + r + 1, 65, 1);
    memset(buffer + r + 2, 34, 1);
    memset(buffer + r + 3, 20, 1);
    memset(buffer + r + 4, 8, 1);
    memset(buffer + r + 5, 127, 1);
    memset(buffer + r + 6, 65, 1);
    memset(buffer + r + 7, 34, 1);
    memset(buffer + r + 8, 20, 1);
    memset(buffer + r + 9, 8, 1);

    for(b = 18; b < 58; b = b + 2){
        memset(buffer + b + r, 85, 1);
    }

    for(b = 19; b < 58; b = b + 2){
        memset(buffer + b + r, 42, 1);
    }
}

void lcd_write_string3(uint8_t p, uint8_t *buffer){

    uint16_t r = 384; //Fourth row
    uint8_t s = 11;

    if (p == 1){
        //Missile
        memset(buffer + r, 53, 1);
        memset(buffer + 1 + r, 126, 1);
        memset(buffer + 2 + r, 126, 1);
        memset(buffer + 3 + r, 30, 1);
        memset(buffer + 4 + r, 46, 1);
        memset(buffer + 5 + r, 30, 1);
        memset(buffer + 6 + r, 14, 1);
        memset(buffer + 7 + r, 15, 1);

        memset(buffer + 1 + s + r, 255, 1);
        memset(buffer + 2 + s + r, 227, 1);
        memset(buffer + 3 + s + r, 128, 1);
        memset(buffer + 4 + s + r, 193, 1);
        memset(buffer + 5 + s + r, 227, 1);
        memset(buffer + 6 + s + r, 227, 1);
        memset(buffer + 7 + s + r, 227, 1);
        memset(buffer + 8 + s + r, 227, 1);
        memset(buffer + 9 + s + r, 247, 1);
        memset(buffer + 10 + s + r, 255, 1);

    } else if (p == 0){
        //Gun
        memset(buffer + r, 255, 1);
        memset(buffer + 1 + r, 202, 1);
        memset(buffer + 2 + r, 129, 1);
        memset(buffer + 3 + r, 129, 1);
        memset(buffer + 4 + r, 225, 1);
        memset(buffer + 5 + r, 209, 1);
        memset(buffer + 6 + r, 225, 1);
        memset(buffer + 7 + r, 241, 1);
        memset(buffer + 8 + r, 240, 1);
        memset(buffer + 9 + r, 255, 1);

        memset(buffer + s + r, 28, 1);
        memset(buffer + 1 + s + r, 127, 1);
        memset(buffer + 2 + s + r, 62, 1);
        memset(buffer + 3 + s + r, 28, 1);
        memset(buffer + 4 + s + r, 28, 1);
        memset(buffer + 5 + s + r, 28, 1);
        memset(buffer + 6 + s + r, 28, 1);
        memset(buffer + 7 + s + r, 8, 1);
    }
}
