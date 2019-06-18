#include "stdio.h"
#include "stdint.h"
#include "inputRead.h"

uint8_t rawIN(){
    uint8_t ch;
    ch = uart_get_char();
    return ch;
}

uint8_t wasdIN(){
    int8_t ch;

    ch = rawIN();

    switch(ch)
    {
    case 119: // w forward
        return ch;
    case 115: // s intended dampener
        return ch;
    case 97: // a for anti-clockwise rotation
        return ch;
    case 100: // d for clockwise rotation
        return ch;
    default:
        return 0;
    }
}

uint8_t numIN(){
    int8_t ch;
    ch = rawIN();

    switch(ch)
    {
    case 49: // char 1
        return ch;
    case 50: // char 2
        return ch;
    case 51: // char 3
        return ch;
    case 52: // char 4
        return ch;
    default:
        return 0;
    }
}

uint8_t spaceIN(){
    int8_t ch;
    ch = rawIN();

    switch(ch)
    {
    case 32:
        return ch;
    default:
        return 0;
    }
}


