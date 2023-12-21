#ifndef INC_FSM_H_
#define INC_FSM_H_


#include "softwaretimer.h"
#include "main.h"
#define MAX_BUFFER_SIZE  30

extern uint8_t buffer[MAX_BUFFER_SIZE];
extern uint8_t index_buffer;
extern uint8_t temp;
extern int ADC_value;
extern UART_HandleTypeDef huart2;
extern ADC_HandleTypeDef hadc1;

void clear_buffer();
void command_parser_fsm();
void uart_communiation_fsm();

#endif /* INC_FSM_H_ */
