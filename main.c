/*
 * Title      : RTOS_OS
 * File Name  : main.c
 * Author     : abdalla
 * Created on : Mar 25, 2022
 */

#include "LIB/STD_TYPES.h"
#include "LIB/BIT_MATH.h"

#include "RTOS/RTOS_interface.h"
#include "DIO/DIO_interface.h"

#include "util/delay.h"


void LED1(void);
void LED2(void);
void LED3(void);


int main() {

	DIO_SetPortDirection(DIO_PORTA,0xff);

	RTOS_u8CreateTask(0, 1000, LED1,1000);
	RTOS_u8CreateTask(1, 2000, LED2,0);
	RTOS_u8CreateTask(2, 3000, LED3,0);
	RTOS_voidStar();



	while (1) {


	}

	return 0;
}


void LED1(void){
	DIO_TogglePin(DIO_PORTA,0);
}
void LED2(void){
	DIO_TogglePin(DIO_PORTA,1);
}
void LED3(void){
	DIO_TogglePin(DIO_PORTA,2);
}


