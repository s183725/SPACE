#include "inputRead.h"

//Functions to expand
uint8_t ship_wasd() {
    wasdIN();
}

uint8_t ship_wep() {
    numIN();
}

uint8_t ship_shoot() {
    spaceIN();
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
