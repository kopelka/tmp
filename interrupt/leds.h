#ifndef leds_h
#define leds_h
#include "MKL46Z4.h"  

void change1(void);
void ledsInitialize(void);

void ledsOff (void);
void ledsOn (void);
void ledGreenOff (void);
void ledGreenOn (void);

void startStopFSM(void);
void ledsService1ms(void);
void nextLedState(void);
 


unsigned char phaseA(void);
unsigned char phaseB(void);
unsigned char phaseC(void);

unsigned char phaseA3(void);
unsigned char phaseB3(void);
unsigned char phaseC3(void);

void fastSlowFSM(void);

extern unsigned char slowFSM;


#endif
