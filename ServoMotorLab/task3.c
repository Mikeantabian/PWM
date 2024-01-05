/*--------------------------INCLUDE HEADER FILES---------------------*/
#include "TM4C123GH6PM.h"
#define Load 62500.00

/*--------------------------USER FUNCTION DECLARATIONS---------------*/
/*Function 1: Delay in milliseconds (50 MHz CPU Clock)*/
void delayMs(int ms);
/* Function 2: Sets up the Duty cycle in PWM1 */
void FindDutyCycle(double cycle);

/*--------------------------MAIN FUNCTION-----------------------------*/
int main(void){
	/*------------------------INITIALIZE /CONFIGURE PERIPHERALS ----------*/
	/*Such as GPIO, UARTs, ADC, Timer, Interrupt, etc*/
	
	/* task 1*/
	
	/* Configure the PWM */
	
	/* enable clock to PWM1 */
	SYSCTL->RCGCPWM |=0x02;
	
	SYSCTL->RCC |= 0x00100000; /* enable clock divider for PWM */
	SYSCTL->RCC &= ~0x000E0000;	/* clear clock divider for PWM */
	SYSCTL->RCC |= 0x00060000;	/* set clock divide to 16*/ /* 50MHz/16 = 3.125MHz */
	
	delayMs(1);  /* wait for clock to stabilize */
	
	PWM1->_3_CTL = 0;	/* disable PWM1_2 during configuration */
	PWM1->_3_GENB = 0x0000080C;	/* output high when load and low when match */
	PWM1->_3_LOAD = 62500 - 1;	/* Set LOAD depending on desired frequency */
	PWM1->_3_CMPB = 59375 - 1;	/* Compare value for duty cycle */
	PWM1->_3_CTL = 1;	/* enable PWM1_2, set counter mode to count down */
	PWM1->ENABLE |= 0x80;	/* enable PWM1 */
	
	SYSCTL->RCGCGPIO |= 0x20;	/* 1-enable clock to PORTF */
	GPIOF->DEN |= 0x08;	/* 2-enable digital functionality for PF2 */
	GPIOF->DIR |= 0x08;	/* 3-set PF2 as output pin */
	GPIOF->AFSEL |= 0x08;		/* Enable alternate function for PF2 */
	GPIOF->PCTL &= ~0x0000F000;	/* clear PORTF 2 alternate function */
	GPIOF->PCTL |= 0x00005000;	/* set PORTF 2 alternate function to PWM by writing 5 to PWCM2*/
	
	SYSCTL->RCGCGPIO |= 0x08;	/* 1-enable clock to PORTD */
	GPIOD->DEN |= 0x0F;	/* 2-enable digital functionality for PD3-PD0 */
	GPIOD->DIR |= 0x0F;	/* 3-set PD3-PD0 as output pin */
	GPIOD->AMSEL &= ~0x0F;	/* Disable Analog Functionality for PD3-PD0 */
	
	

	/*--------------------------Main Tasks----------------------*/
	/*To keep the program running*/
	/*Main logic of the program goes inside the loop */
	
	int pw;

	
	for(;;){
			for(pw = 54500; pw < 59375; pw +=50){
				PWM1->_3_CMPB = pw;
				delayMs(20);
			}	
			for(pw = 59375; pw > 54500; pw-=50){
				PWM1->_3_CMPB = pw;
				delayMs(20);
			}
	}
											
}


/*-------------------USER FUNCTION DEFINITIONS---------------------------*/
/*Function 1: Delay in milliseconds (50 MHz CPU Clock)*/
void delayMs(int ms) {
	int i, j;
	for(i = 0 ; i < ms; i++)
		for(j = 0; j < 2850; j++)
			{}   /* do nothing for 1 ms */
}


