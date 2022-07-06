/*
 * Title      : RTOS_OS
 * File Name  : RTOS_Interface.h
 * Author     : abdalla
 * Created on : Mar 25, 2022
 */

#ifndef RTOS_RTOS_INTERFACE_H_
#define RTOS_RTOS_INTERFACE_H_



void RTOS_voidStar(void);

u8 RTOS_u8CreateTask(u8 Copy_u8Priority, u16 Copy_u16Periodicity,
		void (*Copy_pvTaskFunc)(void),u16 Copy_u16FirstDelay);

void RTOS_voidSuspendTask(u8 Copy_u8Priority);
void RTOS_voidResumeTask(u8 Copy_u8Priority);

void RTOS_voidDeleteTask(u8 Copy_u8Priority);




#endif /* RTOS_RTOS_INTERFACE_H_ */
