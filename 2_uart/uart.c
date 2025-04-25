#include <stdio.h>
#include <sys/types.h>

#include "uart.h"
#include "gpio.h"

void uart_init(){
    GPIO->PIN_CNF[6] = 1;     // TXD output
    GPIO->PIN_CNF[8] = 0;     // RXD input

    UART->PSELTXD = 6;
    UART->PSELRXD = 8;

    UART->BAUDRATE = 0x00275000;

    UART->PSELRTS = 0xFFFFFFFF;
    UART->PSELCTS = 0xFFFFFFFF;

    UART->ENABLE = 4;

    UART->TASKS_STARTRX = 1;    
}


void uart_send(char letter){
    UART->TASKS_STARTTX = 1;

    UART->TXD = letter;

    while (!UART->EVENTS_TXDRDY){}

    UART->TASKS_STOPTX = 1;

    UART->EVENTS_TXDRDY = 0;

}


char uart_read(){
    if ((UART->EVENTS_RXDRDY)){
        char letter = UART->RXD;
        UART->EVENTS_RXDRDY = 0;
        return letter;
    }
    return '\0';
}


void uart_send_str(char ** str){
    UART->TASKS_STARTTX = 1;
    char * letter_ptr = *str;
    while(*letter_ptr != '\0'){
        UART->TXD = *letter_ptr;
        while(!UART->EVENTS_TXDRDY){
            UART->EVENTS_TXDRDY = 0;
            letter_ptr++;
        }
    }
}

ssize_t _write(int fd, const void *buf, size_t count){
    char * letter = (char *)(buf);
    for(int i = 0; i < count; i++){
        uart_send(*letter);
        letter++;
    }
    return count;
}