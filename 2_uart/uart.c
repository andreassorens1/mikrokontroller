#include "uart.h"
#include "gpio.h"

void uart_init(){
    GPIO->PIN_CNF[6] = (1);     // TXD output
    GPIO->PIN_CNF[8] = (0);     // RXD input

    UART->PSELTXD = 6;
    UART->PSELRXD = 8;

    UART->BAUDRATE = 0x00275000;

    UART->PSELTRS = 0xFFFFFFFF;
    UART->PSELCTS = 0xFFFFFFFF;

    UART->ENABLE = 4;

    UART->TASKS_STARTRX = 1;    
}


void uart_send(char letter){
    
}