#include "software_timer.h"
#include "button.h"
#include "global.h"

int timer1_counter = 0;
int timer1_flag = 0;
int blink_counter= 0 ;
int blink_flag= 0 ;

void setTimer(int duration){
	timer1_counter = duration;
	timer1_flag = 0;
}

void timerRun(){
	if(timer1_counter > 0){
		timer1_counter--;
		//if inc button is pressed during the 10s count down,
		//immediately stop the countdown and trigger the state machine
		//with the according status
		if(inc_flag==1){
			timer1_flag=1;
			status=INC;
		}
		if(dec_flag==1){
			timer1_flag=1;
			status=DEC;
		}
		if (reset_flag==1){
			timer1_flag=1;
			status=_RESET;
		}
		if(timer1_counter == 0){
			timer1_flag = 1;
		}
	}
}


void Blink(int duration){
	blink_counter= duration;
	blink_flag=0;
}

void BlinkRun()
{
	if(blink_counter>0)
	{
		blink_counter--;
		if(blink_counter == 0){
			blink_flag = 1;
		}
	}
}


