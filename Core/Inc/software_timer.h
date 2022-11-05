#ifndef __SOFTWARE_TIMER_
#define __SOFTWARE_TIMER_

extern int timer1_flag;
extern int blink_flag;

void setTimer(int duration);
void Blink(int duration);
void timerRun();
void BlinkRun();


#endif
