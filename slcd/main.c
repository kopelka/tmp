/*----------------------------------------------------------------------------
 *      
 *----------------------------------------------------------------------------
 *      Name:    main.c
 *      Purpose: Microprocessors Laboratory
 *----------------------------------------------------------------------------
 *      
 *---------------------------------------------------------------------------*/

#include "MKL46Z4.h"                    	/* Device header */
#include "leds.h"													/* Leds functions for FRDM46-KL46 */
#include "buttons.h"											/* Buttons of FRDM46-KL46 */
#include "slcd.h"											    /* Segment LCD of FRDM46-KL46 */
#include "extra.h"												/* Extra functions */

int main(void){
	slcdInitialize();
	//ledsInitialize();  //TASK 2.8 - enable when needed
	//buttonsInitialize();  //TASK 2.9 - enable when needed
	
	/* TASK 2.8 - place here your welcome LED sequence*/ 
	
	while(1){
		//slcdDemo(); //TASK 2.6 - enable that function to test sLCD
	  //slcdErr(1);
		//slcdSet(4,1);
		slcdDisplay(5,2);	
		Dot1(0);
			Dot2(0);
			Dot3(0);
			Col4(0);
	}
}
