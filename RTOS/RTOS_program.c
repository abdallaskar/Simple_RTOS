/*
 * Title      : RTOS_OS
 * File Name  : RTOS_Program.c
 * Author     : abdalla
 * Created on : Mar 25, 2022
 */

#include "../LIB/STD_TYPES.h"

#include "../GIE/GIE_interface.h"
#include "../TIMER0/TIMER0_interface.h"

#include "RTOS_config.h"
#include "RTOS_interface.h"
#include "RTOS_private.h"


TASK_TYPE SystemTask[TASK_NUMBER] = {{NULL}};

/** start timer to generate interrupt every one milli second ***/

void RTOS_voidStar(void) {

	TIMER0_OCMP_SetCallBack(&RTOS_voidScheduler);
	TIMER0_Init(TIMER0_CTC_MODE, TIMER0_SCALER_64, OC0_DISCONNECTED);
	TIMER0_Output_Compare_Interrupt_Eable();
	GIE_voidEnableGlobleInterrupt();

}


/********* Create a new task using priority and aperiodicity *******/

u8 RTOS_u8CreateTask(u8 Copy_u8Priority, u16 Copy_u16Periodicity,
		void (*Copy_pvTaskFunc)(void),u16 Copy_u16FirstDelay) {

	u8 Local_u8ErrorState=TRUE;

	/*** Check priority is not received ***/

		SystemTask[Copy_u8Priority].Priodisty = Copy_u16Periodicity;
		SystemTask[Copy_u8Priority].pvTaskFunc = Copy_pvTaskFunc;
		SystemTask[Copy_u8Priority].State =TASK_RESUMED;
		SystemTask[Copy_u8Priority].FirstDelay=Copy_u16FirstDelay;



	return Local_u8ErrorState;
}



static void RTOS_voidScheduler(void)
{


	u8 Local_u8TaskCounter;
    /*Loop on all Task to check periodisty*/
	for (Local_u8TaskCounter = 0; Local_u8TaskCounter < TASK_NUMBER;Local_u8TaskCounter++)
	{
		/* Check if the task is suspend or not */

        if(SystemTask[Local_u8TaskCounter].State==TASK_RESUMED)
        {
        	/* Check if the first delay equal zero*/

        	if (SystemTask[Local_u8TaskCounter].FirstDelay == 0)
        	{

				if (SystemTask[Local_u8TaskCounter].pvTaskFunc != NULL)
				{
					SystemTask[Local_u8TaskCounter].pvTaskFunc();
					/*Assign first delay parameter to the periodisty */
					SystemTask[Local_u8TaskCounter].FirstDelay=SystemTask[Local_u8TaskCounter].Priodisty-1;
				}
				else
				{
					/* Counter refer to null pointer Do noting*/
				}

        	}
        	else
        	{
        		/*if first delay not equal zero decrement first delay */
        		SystemTask[Local_u8TaskCounter].FirstDelay--;
        	}
        }
        else
        {
        	/* Task is suspend do nothing */
        }

	}

}




void RTOS_voidSuspendTask(u8 Copy_u8Priority)
{
	SystemTask[Copy_u8Priority].State=TASK_SUSPEND;
}
void RTOS_voidResumeTask(u8 Copy_u8Priority)
{
	SystemTask[Copy_u8Priority].State=TASK_RESUMED;
}
void RTOS_voidDeleteTask(u8 Copy_u8Priority)
{
	SystemTask[Copy_u8Priority].pvTaskFunc= NULL;
}


