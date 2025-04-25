#include "ppi.h"
#include "gpiote.h"

void config_ppi(){
    for (int i=1; i<5; i++){
        PPI->CHEN |= (1 << i);
        PPI->PPI_CH[i].EEP = (uint32_t)&(GPIOTE->EVENTS_IN[0]);
        PPI->PPI_CH[i].TEP = (uint32_t)&(GPIOTE->TASKS_OUT[i]);
    }
}