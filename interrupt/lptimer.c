/*----------------------------------------------------------------------------
 *      
 *----------------------------------------------------------------------------
 *      Name:    lptimer.c
 *      Purpose: Microprocessors Laboratory
 *----------------------------------------------------------------------------
 *      
 *      Author: Pawel Russek AGH University of Science and Technology
 *---------------------------------------------------------------------------*/

#include "MKL46Z4.h"
#include "lptimer.h"
#include "leds.h"
 
#define LPTMR_DELAY_MS 												/* ToDo 6.3 */										
#define LPTMR_ALARM_INT_NBR (IRQn_Type) -1	/* ToDo 6.1: Determine the proper IRQ number for LPTRM timer. Refer to K46Z user manual - NVIC section */


unsigned int fastFlag=0; 

/*----------------------------------------------------------------------------
	Function initializes LPTMR
 *----------------------------------------------------------------------------*/
void lpTimerInitialize(void){

	SIM->SCGC5 |= SIM_SCGC5_LPTMR_MASK; 	/*Turn on ADC Low Power Timer (LPTMR) registers clock gate*/
		 	 
	//LPTMR0->PSR = 	LPTMR_PSR_PCS(1) 			/* Set LPO clock source */
	//							| LPTMR_PSR_XXX_MASK; 	/* ToDo 6.2:  Set PBYP bit to bypass prescaler. No prescaler selected */
	 
	//LPTMR0->CMR = LPTMR_CMR_XXX(LPTMR_DELAY_MS); /* ToDo 6.3: Set the compare value in CMR register to interrupt every 600ms */
	 
	/** Configure LPTMR as timer in 'clear CNR in compare' mode*/ 
	//LPTMR0->CSR = ( !LPTMR_CSR_XXX_MASK |  	/* ToDo 6.4: Set Timer Free-Running Counter bit zero i.e. select to clear CNT on compare mode */
	//								!LPTMR_CSR_XXX_MASK |  	/* ToDo 6.5: Set Timer Mode Select bit zero to select timer mode */
	//								LPTMR_CSR_XXX_MASK |    /* ToDo 6.6: Clear any pending interrupt */
	//								LPTMR_CSR_XXX_MASK);  	/* ToDo 6.7: LPTMR0 interrupt enabled */
	
	  
	/** Enable alarm interrupt*/
	NVIC_ClearPendingIRQ(LPTMR_ALARM_INT_NBR); 	/* Clear any pending interrupt */
	NVIC_EnableIRQ(LPTMR_ALARM_INT_NBR);				/* Notify Nested Vector Interrupt Controller */
	//NVIC_SetPriority (LPTMR_ALARM_INT_NBR, 3);	/* ToDo 7.2b Enable NVIC interrupts source for lptimer module */ /* ToDo 7.3: Increase lptimer interrupt priority level  */

	//LPTMR0->CSR |= LPTMR_CSR_XXX_MASK;	/* ToDo 6.8: Turn on LPTMR and start counting */
	return;
}

/*----------------------------------------------------------------------------
	Interrupt service routine
 *----------------------------------------------------------------------------*/ 
 void put_LPTR_irq_handler_name(void){			/* ToDo 6.9: Put a proper name of LPTMR Interrupt service routine ISR. See system_MKL46Z4.s file for function name */ 		
			
		LPTMR0->CSR &= ~LPTMR_CSR_TEN_MASK;			/* Disable timer to clear timer register*/
		
		nextLedState ();
	
		LPTMR0->CSR |=  LPTMR_CSR_TCF_MASK;   	/* write 1 to TCF to clear the LPTMR timer compare flag */
		LPTMR0->CSR =  LPTMR_CSR_TEN_MASK | LPTMR_CSR_TIE_MASK; /* Enable LPTMR timer and interupt */
		return;
 }


