/*
 * Title      : RTOS_OS
 * File Name  : RTOS_Private.h
 * Author     : abdalla
 * Created on : Mar 25, 2022
 */


#ifndef RTOS_RTOS_PRIVATE_H_
#define RTOS_RTOS_PRIVATE_H_

typedef struct {
	u16  Priodisty;
	void(*pvTaskFunc)(void);
	u8  State;
	u16 FirstDelay;

} TASK_TYPE;


#define TASK_RESUMED    1
#define TASK_SUSPEND    0



static void RTOS_voidScheduler(void);


#endif /* RTOS_RTOS_PRIVATE_H_ */
