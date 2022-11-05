#include "fsm.h"
#include "global.h"
#include "software_timer.h"
#include "segment.h"
#include "button.h"

void fsm_simple_buttons_run ()
{
	switch(status){
	case AUTO:  //auto countdown state
		if(timer1_flag==1)
		{
			if(inc_flag==1) //change to increase state right after inc button is pressed
			{
				status=INC;
				break;
			}
			if(dec_flag==1)//change to decrease state right after dec button is pressed
			{
				status=DEC;
				break;
			}
			if (reset_flag==1)//if reset button is pressed in this state, only set the 7segment to 0 and variable count to 0
			{
				display7SEG(0);
				count=0;
				reset_flag=0;
			}
			else //auto countdown each 1s and stop at 0
			{
				if(count==0)
				{
					display7SEG(0);
					count=0;
				}
				else
				{
					display7SEG(--count);
				}
				setTimer(100);
			}
		}
		break;
	case INC:
			if(inc_flag==1)
			{
			// increase value of variable count
				if(count==9) count=-1;
				display7SEG(++count);
				inc_flag=0;
			}
			if (dec_flag==1) status= DEC;//change status to DEC if dec button is pressed
			else //countdown 10s before auto counting down.
			//if any button is pressed during this 10s, the countdown process will stop and change to the according state. See more in the software_timer.c file
			{
				status=AUTO;
				setTimer(1000);
			}
		break;
	case DEC:
		if(dec_flag==1)
		{
		// decrease value of variable count
			if(count==0) count=10;
			display7SEG(--count);
			dec_flag=0;
		}
		if (inc_flag==1) status= INC; //change status to INC if inc button is pressed
		else//countdown 10s before auto counting down
		//if any button is pressed during this 10s, the countdown process will stop and change to the according state. See more in the software_timer.c file
		{
			status=AUTO;
			setTimer(1000);
		}
		break;
	case _RESET:
		if(reset_flag==1) //display 0 when reset button is pressed
		{
			display7SEG(0);
			count=0;
			reset_flag=0;
		}
		if (inc_flag==1) status= INC;//change status to INC if inc button is pressed
		if (dec_flag==1) status= DEC;//change status to DEC if dec button is pressed
		break;
	default:
		break;
	}
}

