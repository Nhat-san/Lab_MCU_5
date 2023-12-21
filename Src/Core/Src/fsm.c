/*
 * fsm.c
 *
 *  Created on: Nov 22, 2023
 *      Author: huaho
 */
#include "fsm.h"
int command_flag = 0;
char command_data[30];
int command_index = 0;
int Parser_State = 1;

extern int ADC_value;
typedef enum {
	RST,
	OK
} CommandState;
CommandState Command_0 = OK;
void clear_buffer()
{
	memset(buffer, 0, sizeof(buffer));
	index_buffer = 0;
}
void clear_data()
{
	memset(command_data, 0, sizeof(command_data));
	command_index = 0;
}
void command_parser_fsm()
{
	switch(Parser_State)
	{
		case 0:
			if (buffer[index_buffer-1] == '!')
			{
				Parser_State = 1;
			}
			clear_data();
			break;
		case 1:
			if (buffer[index_buffer-1] == '!')
			{
				command_index = 0;
				break;
			}
			if (buffer[index_buffer-1] == '#')
			{
				Parser_State = 0;
				command_flag = 1;
				break;
			}
			command_data[command_index] = buffer[index_buffer - 1];
			command_index++;
			break;
		default:
			Parser_State = 0;
			break;
	}

}

void uart_communiation_fsm()
{
	switch (command_flag){
		case 1:
			if (!strcmp(command_data,"RST"))
			{
				Command_0 = RST;
			}
			if (!strcmp(command_data,"OK"))
			{
				Command_0 = OK;
				command_flag = 0;
			}
			
			clear_data();

			break;

		case 0:
			break;
		default:
			break;
	}
	switch (Command_0)
	{
		case OK:
			SetTimer(5, 1);
		break;
		case RST:
			HAL_ADC_Start(&hadc1);
			ADC_value = HAL_ADC_GetValue(&hadc1);
			HAL_ADC_Stop(&hadc1);
			char str[30];
			if (TimerFlag[1] == 1)
			{
				HAL_UART_Transmit(&huart2, (void*)str, sprintf(str,"!ADC=%d#\r\n",ADC_value), 100);
				SetTimer(300, 1);
			}
		break;
	}

}
