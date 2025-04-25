#include "gpio.h"

void button_init(){ 
	GPIO->PIN_CNF[13] = (3 << 2);    //setter 1 på begge C i registeret (s 145 i databladet)
	GPIO->PIN_CNF[14] = (3 << 2);
	GPIO->PIN_CNF[15] = (3 << 2);

	// Fill inn the configuration for the remaining buttons 
}