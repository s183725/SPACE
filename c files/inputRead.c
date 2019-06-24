#include "stdio.h"
#include "stdint.h"
#include "inputRead.h"

uint8_t rawIN(){
    volatile uint8_t ch = uart_get_char();
    return ch;
}

uint8_t wasdIN(){
    uint8_t ch = rawIN();

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
    uint8_t ch = rawIN();

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
    uint8_t ch = rawIN();

    switch(ch)
    {
    case 32:
        return ch;
    default:
        return 0;
    }
}

char directCTRL(void) {

    char inKey;

    switch (wasdIN())
    {
    case 119: // w forward
        return inKey = 'w';
    case 115: // s intended dampener
        return inKey = 's';
    case 97: // a for anti-clockwise rotation
        return inKey = 'a';
    case 100: // d for clockwise rotation
        return inKey = 'd';
    }

    switch(numIN())
    {
    case 49: // char 1
        return inKey = '1';
    case 50: // char 2
        return inKey = '2';
    case 51: // char 3
        return inKey = '3';
    case 52: // char 4
        return inKey = '4';
    }

    switch(rawIN())
    {
    case 32:
        return inKey = ' ';
    }
}

