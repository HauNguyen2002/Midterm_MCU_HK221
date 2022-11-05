#include "fsm.h"
#include "global.h"
#include "software_timer.h"
#include "segment.h"
#include "button.h"

void fsm_simple_buttons_run ()
{
	switch(status){
	case AUTO:
		if(timer1_flag==1)
		{
			if(inc_flag==1)
			{
				status=INC;
				break;
			}
			if(dec_flag==1)
			{
				status=DEC;
				break;
			}
			if (reset_flag==1){
				display7SEG(0);
				reset_flag=0;
			}
			else
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
				if(count==9) count=-1;
				display7SEG(++count);
				inc_flag=0;
			}
			if (dec_flag==1) status= DEC;
			else
			{
				status=AUTO;
				setTimer(1000);
			}
		break;
	case DEC:
		if(dec_flag==1)
		{
			if(count==0) count=10;
			display7SEG(--count);
			dec_flag=0;
		}
		if (inc_flag==1) status= INC;
		else
		{
			status=AUTO;
			setTimer(1000);
		}
		break;
	case _RESET:
		if(reset_flag==1)
		{
			display7SEG(0);
			count=0;
			reset_flag=0;
		}
		if (inc_flag==1) status= INC;
		if (dec_flag==1) status= DEC;
		break;
	default:
		break;

	}
}

