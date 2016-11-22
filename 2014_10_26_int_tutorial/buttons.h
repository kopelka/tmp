/*----------------------------------------------------------------------------
 *      
 *----------------------------------------------------------------------------
 *      Name:    BUTTONS.H
 *      Purpose: Microprocessors Laboratory
 *----------------------------------------------------------------------------
 *      
 *      Author: Pawel Russek AGH University of Science and Technology
 *---------------------------------------------------------------------------*/

#ifndef buttons_h
#define buttons_h

#include "MKL46Z4.h"                    // Device header

void buttonsInitialize(void);
void buttonsService(void);							//buttons' interrupt service procedure
int32_t buttonRead(void);


#endif

