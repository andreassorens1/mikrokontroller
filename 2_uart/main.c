#include <stdio.h>
#include <sys/types.h>

#include "uart.h"
#include "gpio.h"

int main(){
    
    for(int i = 17; i <= 20; i++){
		GPIO->DIRSET = (1 << i);
		GPIO->OUTCLR = (1 << i);
	}

	button_init();
    uart_init();

    //iprintf("The average grade in TTK%d was in %d was: %c\n\r",4235,2022,'B');

    while(1){
        if (!(GPIO->IN & (1 << 13))){
            
            uart_send('A');

            if ((GPIO->OUT) & (1 << 17)){
                for (int i = 17; i <= 20; i++){
                    GPIO->OUTCLR = (1 << i);
                }
            }
            else {
                for (int i = 17; i <= 20; i++){
                    GPIO->OUTSET = (1 << i);
                }
            }

        }
    
        if (!(GPIO->IN & (1 << 14))){

            uart_send('B');

            if ((GPIO->OUT) & (1 << 17)){
                for (int i = 17; i <= 20; i++){
                    GPIO->OUTCLR = (1 << i);
                }
            }
            else {
                for (int i = 17; i <= 20; i++){
                    GPIO->OUTSET = (1 << i);
                }
            }

        }

        if (!(GPIO->IN & (1 << 15))){
            iprintf("The average grade in TTK%d was in %d was: %c\n\r",4235,2022,'B');
        }


    }



    return 0;
}