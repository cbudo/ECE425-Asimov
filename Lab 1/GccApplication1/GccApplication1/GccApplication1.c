/*
* GccApplication1.c
*
* Created: 11/30/2014 11:58:11 AM
*  Author: budocf
*/
void forward(void);
void turn90CW(void);
void turn90CCW(void);
void SquareCW(void);
void SquareCCW(void);
void CBOT_main(void);

#include "capi324v221.h"
int main(void)
{
	CBOT_main();
}
void CBOT_main(void)
{
	LCD_open(); //allows use of the LCD
	LCD_printf("Hello, Dolly!\n"); //print to the LCD screen
	STEPPER_open();
	while(1)
	{
		for(int i=1;i<=5;i++)
		{
			SquareCW();
		}
		TMRSRVC_delay(30000);
		for(int i=1;i<=5;i++)
		{
			SquareCCW();
		}
	}
}
void SquareCW(void)
{
	for(int i=1;i<=4;i++)
	{
		STEPPER_wait_on(STEPPER_BOTH);
		forward();
		STEPPER_wait_on(STEPPER_BOTH);
		turn90CW();
	}
}
void SquareCCW(void)
{
	for(int i=1;i<=4;i++)
	{
		STEPPER_wait_on(STEPPER_BOTH);
		forward();
		STEPPER_wait_on(STEPPER_BOTH);
		turn90CCW();
	}
}
void forward(void)
{
	// Make the robot go forward two to three feet
	STEPPER_move_stwt(STEPPER_BOTH,
	STEPPER_FWD, 1000,200,400,STEPPER_BRK_OFF,
	STEPPER_FWD,1000,200,400,STEPPER_BRK_OFF);
}
void turn90CW(void)
{
	// Make the robot turn 90 degrees
	STEPPER_move_stwt( STEPPER_BOTH,
	STEPPER_FWD, 150, 200, 400, STEPPER_BRK_OFF,
	STEPPER_REV, 150, 200, 400, STEPPER_BRK_OFF );
}
void turn90CCW(void)
{
	STEPPER_move_stwt( STEPPER_BOTH,
	STEPPER_REV, 150, 200, 400, STEPPER_BRK_OFF,
	STEPPER_FWD, 150, 200, 400, STEPPER_BRK_OFF );
}