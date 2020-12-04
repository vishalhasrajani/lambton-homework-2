/*
 * @brief FreeRTOS Blinky example
 *
 * @note
 * Copyright(C) NXP Semiconductors, 2014
 * All rights reserved.
 *
 * @par
 * Software that is described herein is for illustrative purposes only
 * which provides customers with programming information regarding the
 * LPC products.  This software is supplied "AS IS" without any warranties of
 * any kind, and NXP Semiconductors and its licensor disclaim any and
 * all warranties, express or implied, including all implied warranties of
 * merchantability, fitness for a particular purpose and non-infringement of
 * intellectual property rights.  NXP Semiconductors assumes no responsibility
 * or liability for the use of the software, conveys no license or rights under any
 * patent, copyright, mask work right, or any other intellectual property rights in
 * or to any products. NXP Semiconductors reserves the right to make changes
 * in the software without notification. NXP Semiconductors also makes no
 * representation or warranty that such application will be suitable for the
 * specified use without further testing or modification.
 *
 * @par
 * Permission to use, copy, modify, and distribute this software and its
 * documentation is hereby granted, under NXP Semiconductors' and its
 * licensor's relevant copyrights in the software, without fee, provided that it
 * is used in conjunction with NXP Semiconductors microcontrollers.  This
 * copyright, permission, and disclaimer notice must appear in all copies of
 * this code.
 */

#include "board.h"
#include "FreeRTOS.h"
#include "task.h"

/*****************************************************************************
 * Private types/enumerations/variables
 ****************************************************************************/

/*****************************************************************************
 * Public types/enumerations/variables
 ****************************************************************************/

/*****************************************************************************
 * Private functions
 ****************************************************************************/

/* Sets up system hardware */
static void prvSetupHardware(void)
{
	SystemCoreClockUpdate();
	Board_Init();

	/* Initial red LED,green LED and blue LED states are off */
	Board_LED_Set(red, false);
	Board_LED_Set(green, false);
	Board_LED_Set(blue, false);
}

portTickType xLastWakeTime1;
portTickType xLastWakeTime2;
portTickType xLastWakeTime3;
portTickType xLastWakeTime4;
portTickType xLastWakeTime5;
portTickType xLastWakeTime6;
/* LED1 toggle thread */
static void vLEDTask1(void *pvParameters) {
	 xLastWakeTime1 = xTaskGetTickCount ();

	while (1) {
		Board_LED_Set(red, true); //red led ON
		vTaskDelayUntil( &xLastWakeTime1, 1000 );//1sec delay
		Board_LED_Set(red, false);//red led OFF
		vTaskDelayUntil( &xLastWakeTime1, 11000 );//5sec delay


	}
}

/* LED2 toggle thread */
static void vLEDTask2(void *pvParameters) {

	xLastWakeTime2 = xTaskGetTickCount ();
	vTaskDelayUntil( &xLastWakeTime2, 2000 );//2sec delay
	while (1) {

		Board_LED_Set(green, true); //green led ON
		 vTaskDelayUntil( &xLastWakeTime2, 1000 );//1sec delay
		Board_LED_Set(green, false); //green led OFF
		 vTaskDelayUntil( &xLastWakeTime2, 11000);//5sec delay


	}
}

static void vLEDTask3(void *pvParameters) {
	xLastWakeTime3 = xTaskGetTickCount ();
	vTaskDelayUntil( &xLastWakeTime3, 4000 );//4sec delay
	while (1) {

		Board_LED_Set(blue,true); //blue led ON
		 vTaskDelayUntil( &xLastWakeTime3, 1000 ); //1sec delay
		Board_LED_Set(blue,false);//blue led OFF
		 vTaskDelayUntil( &xLastWakeTime3, 11000);//5sec delay



	}
}

static void vLEDTask4(void *pvParameters) {
	xLastWakeTime4 = xTaskGetTickCount ();
	vTaskDelayUntil( &xLastWakeTime4, 6000 );//4sec delay
	while (1) {

		Board_LED_Set(blue,true); //blue led ON
		Board_LED_Set(green,true); //blue led ON
		 vTaskDelayUntil( &xLastWakeTime4, 1000 ); //1sec delay
		Board_LED_Set(blue,false);//blue led OFF
		Board_LED_Set(green,false);//blue led OFF
		 vTaskDelayUntil( &xLastWakeTime4, 11000);//5sec delay



	}
}

static void vLEDTask5(void *pvParameters) {
	xLastWakeTime5 = xTaskGetTickCount ();
	vTaskDelayUntil( &xLastWakeTime5, 8000 );//4sec delay
	while (1) {

		Board_LED_Set(red,true); //blue led ON
		Board_LED_Set(green,true); //blue led ON
		 vTaskDelayUntil( &xLastWakeTime5, 1000 ); //1sec delay
		Board_LED_Set(red,false);//blue led OFF
		Board_LED_Set(green,false);//blue led OFF
		 vTaskDelayUntil( &xLastWakeTime5, 11000);//5sec delay



	}
}

static void vLEDTask6(void *pvParameters) {
	xLastWakeTime6 = xTaskGetTickCount ();
	vTaskDelayUntil( &xLastWakeTime6, 10000 );//4sec delay
	while (1) {

		Board_LED_Set(red,true); //blue led ON
		Board_LED_Set(blue,true); //blue led ON
		 vTaskDelayUntil( &xLastWakeTime6, 1000 ); //1sec delay
		Board_LED_Set(red,false);//blue led OFF
		Board_LED_Set(blue,false);//blue led OFF
		 vTaskDelayUntil( &xLastWakeTime6, 11000);//5sec delay



	}
}

/* UART (or output) thread */


/*****************************************************************************
 * Public functions
 ****************************************************************************/

/**
 * @brief	main routine for FreeRTOS blinky example
 * @return	Nothing, function should not exit
 */
int main(void)
{
	prvSetupHardware();

	/* LED1 toggle thread */
	xTaskCreate(vLEDTask1, (signed char *) "vTaskLed1",
				configMINIMAL_STACK_SIZE, NULL, (tskIDLE_PRIORITY + 3UL),
				(xTaskHandle *) NULL);

	/* LED2 toggle thread */
	xTaskCreate(vLEDTask2, (signed char *) "vTaskLed2",
				configMINIMAL_STACK_SIZE, NULL, (tskIDLE_PRIORITY + 2UL),
				(xTaskHandle *) NULL);
	/* LED3 toggle thread */
	xTaskCreate(vLEDTask3, (signed char *) "vTaskLed3",
					configMINIMAL_STACK_SIZE, NULL, (tskIDLE_PRIORITY + 1UL),
					(xTaskHandle *) NULL);

	xTaskCreate(vLEDTask4, (signed char *) "vTaskLed4",
						configMINIMAL_STACK_SIZE, NULL, (tskIDLE_PRIORITY + 4UL),
						(xTaskHandle *) NULL);

	xTaskCreate(vLEDTask5, (signed char *) "vTaskLed5",
							configMINIMAL_STACK_SIZE, NULL, (tskIDLE_PRIORITY + 5UL),
							(xTaskHandle *) NULL);

	xTaskCreate(vLEDTask6, (signed char *) "vTaskLed6",
								configMINIMAL_STACK_SIZE, NULL, (tskIDLE_PRIORITY + 6UL),
								(xTaskHandle *) NULL);




	/* Start the scheduler */
	vTaskStartScheduler();

	/* Should never arrive here */
	return 1;
}

/**
 * @}
 */

