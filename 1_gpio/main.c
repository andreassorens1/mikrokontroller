#include <stdint.h>

#define GPIO ((NRF_GPIO_REGS*)0x50000000)

typedef struct {
	volatile uint32_t RESERVED0[321];
	volatile uint32_t OUT;
	volatile uint32_t OUTSET;
	volatile uint32_t OUTCLR;
	volatile uint32_t IN;
	volatile uint32_t DIR;
	volatile uint32_t DIRSET;
	volatile uint32_t DIRCLR;
	volatile uint32_t LATCH;
	volatile uint32_t DETECTMODE;
	volatile uint32_t RESERVED1[118];
	volatile uint32_t PIN_CNF[32];
} NRF_GPIO_REGS;

void button_init(){ 
	GPIO->PIN_CNF[13] = (3 << 2);    //setter 1 på begge C i registeret (s 145 i databladet)
	GPIO->PIN_CNF[14] = (3 << 2);

	// Fill inn the configuration for the remaining buttons 
}

int main(){
	// Configure LED Matrix
	for(int i = 17; i <= 20; i++){
		GPIO->DIRSET = (1 << i);
		GPIO->OUTCLR = (1 << i);
	}

	// Configure buttons -> see button_init()
	button_init();

	int sleep = 0;
	while(1){

		 if (!(GPIO->IN & (1 << 14))) {              //Hvis knapp1 trykkes, skru på alle lysene
			for (int i = 17; i <= 20; i++){
				GPIO->OUTSET = (1 << i);
			}
			
		 }
		 if (!(GPIO->IN & (1 << 13))) {              //Hvis knapp2 trykkes, skru av alle lysene
			for (int i = 17; i <= 20; i++){
				GPIO->OUTCLR = (1 << i);
			}
		 }


		/* Check if button 1 is pressed;
		 * turn on LED matrix if it is. */

		/* Check if button 2 is pressed;
		 * turn off LED matrix if it is. */

		sleep = 10000;
		while(--sleep); // Delay
	}
	return 0;
}
