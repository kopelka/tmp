/*----------------------------------------------------------------------------
 *      
 *----------------------------------------------------------------------------
 *      Name:    main.c
 *      Purpose: Microprocessors Laboratory
 *----------------------------------------------------------------------------
 *      
 *      Author: Pawel Russek AGH University of Science and Technology
 *---------------------------------------------------------------------------*/

#include "MKL46Z4.h"                    	/* Device header */
#include "leds.h"													/* leds functions for FRDM46-KL46 */
#include "buttons.h"											/* Buttons of FRDM46-KL46 */
#include "lptimer.h"											/* Kinetis KL46 Low Power Timer (LPTMR) */ 
#include "lowpower.h"											/* KL46 Low Leakage Stop (LSS) mode */

/*----------------------------------------------------------------------------
  SysTick_Handler  function is an interrupt service routine 
	for ARM core Sys_Tick interrupt
 *----------------------------------------------------------------------------*/
void SysTick_Handler(void) { 							/* TBD_4.1:  Put the name of SysTick handler */	
	ledsService1ms();												
}

/*----------------------------------------------------------------------------
      Application main procedure 
 *---------------------------------------------------------------------------*/
int main (void) {

	ledsInitialize();       	/* Initialize LEDs */
	buttonsInitialize();	  /* ToDo 5.7 Initialize buttons */
	lpTimerInitialize();		/* ToDo 6.10a Initialize LPTMR  */
	//lowPowerInitialize();
	
	SystemCoreClockUpdate();	/** Updates the SystemCoreClock variable. */
														/*  Evaluates the clock register settings and calculates */
	
	//SysTick_Config(SystemCoreClock / 1000);	/** TBD 4.2: Configure and anable SysTick interrupt to generate an interrupt every millisecond */
																						/* The function initializes the System Timer and its interrupt, and starts the System Tick Timer. */
																						/* Counter is in free running mode to generate periodic interrupts. */
																						/* Function parameter is a umber of ticks between two interrupts */
																						/* ToDo 6.10b */
	
	while(1){	
		enterLLSMode();			/* ToDo 7.1 Periodically enter LLS mode. The function returns on interrupt wake-up events */ 
	}
}

