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

// GLOBAL PARAMETER
uint8_t red_led = red;
uint8_t green_led = green;
uint8_t blue_led = blue;

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

/* LED1 toggle thread */
static void vLEDTask(void *pvParameters) {

	uint8_t LED = *((uint8_t*) pvParameters); // LED Color Parameter
		if (LED == green)
		{
			//block for 2sec
			vTaskDelay(2*configTICK_RATE_HZ );
		}

		if (LED == blue)
		{
			// Block for 4 sec 
			vTaskDelay(4*configTICK_RATE_HZ);
		}

	while (1) {
		Board_LED_Set(LED, true); // led ON
		vTaskDelay(configTICK_RATE_HZ );//1sec delay
		Board_LED_Set(LED, false);// led OFF
		vTaskDelay(5*configTICK_RATE_HZ );//5sec delay


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
	xTaskCreate(vLEDTask, (signed char *) "vTaskLed1",
				configMINIMAL_STACK_SIZE, (void *)&red_led, (tskIDLE_PRIORITY + 3UL), // highest priority 
				(xTaskHandle *) NULL);

	/* LED2 toggle thread */
	xTaskCreate(vLEDTask, (signed char *) "vTaskLed2",
				configMINIMAL_STACK_SIZE, (void *)&green_led, (tskIDLE_PRIORITY + 2UL), // second highest priority
				(xTaskHandle *) NULL);
	/* LED3 toggle thread */
	xTaskCreate(vLEDTask, (signed char *) "vTaskLed3",
					configMINIMAL_STACK_SIZE, (void *)&blue_led, (tskIDLE_PRIORITY + 1UL), //last priority 
					(xTaskHandle *) NULL);

	/* Start the scheduler */
	vTaskStartScheduler();

	/* Should never arrive here */
	return 1;
}

/**
 * @}
 */
