#include "gpiote.h"

void gpiote_init(){
    GPIOTE->CONFIG[0] |= 1;
    GPIOTE->CONFIG[0] |= (13 << 8);
    GPIOTE->CONFIG[0] |= (2 << 16);

    for (int i = 1: i < 5; i++){
        GPIOTE->CONFIG[i] |= 3;
        GPIOTE->CONFIG[i] |= ((16+i) << 8);
        GPIOTE->CONFIG[i] |= (3 << 16);
        GPIOTE->CONFIG[i] &= ~(1 << 20);
    }
}
