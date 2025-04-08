#include "uart.h"
#include "gpio.h"

int main(){
    
    for(int i = 17; i <= 20; i++){
		GPIO->DIRSET = (1 << i);
		GPIO->OUTCLR = (1 << i);
	}

	button_init();
    

    uart_init();

    if (!(GPIO->IN & (1 << 14))){
        uart_send('A');

        if (GPIO->OUT & 0){
            for (int i = 17; i <= 20; i++){
                GPIO->OUTSET = (1 << i);
            }
        }
        else {
            for (int i = 17; i <= 20; i++){
				GPIO->OUTCLR = (1 << i);
			}
        }
        
    }

    if (!(GPIO->IN & (1 << 13))){
        uart_send('B');

        if (GPIO->OUT & 1){
            for (int i = 17; i <= 20; i++){
                GPIO->OUTSET = (1 << i);
            }
        }
        else {
            for (int i = 17; i <= 20; i++){
				GPIO->OUTCLR = (1 << i);
			}
        }
        
    }


    return 0;
}