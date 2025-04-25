#include "gpiote.h"
#include "ppi.h"
#include "gpio.h"

void led_init(){
    for(int i = 17; i <= 20; i++){
        GPIO->DIRSET = (1 << i);
        GPIO->OUTCLR = (1 << i);
    }
}

int main(){

    GPIO->PIN_CNF[13] = (3 << 2); //pull down
    GPIO->DIRSET = (0 << 13);   // setter til input


    led_init();
    gpiote_init();
    config_ppi();

    while(1){}

    return 0;
}