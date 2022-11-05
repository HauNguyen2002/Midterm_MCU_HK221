
#include "button.h"
int KeyReg0 = NORMAL_STATE;
int KeyReg1 = NORMAL_STATE;
int KeyReg2 = NORMAL_STATE;
int KeyReg3 = NORMAL_STATE;
int KeyReg4 = NORMAL_STATE;
int KeyReg5 = NORMAL_STATE;
int KeyReg6 = NORMAL_STATE;
int KeyReg7 = NORMAL_STATE;
int KeyReg8 = NORMAL_STATE;
int KeyReg9 = NORMAL_STATE;
int KeyReg10 = NORMAL_STATE;
int KeyReg11 = NORMAL_STATE;

int TimeOutForRESETPress =  500;
int TimeOutForINCPress =  500;
int TimeOutForDECPress =  500;

int reset_flag = 0;
int inc_flag = 0;
int dec_flag = 0;

void subRESETProcess(){
	reset_flag = 1;
}

void subINCProcess(){
	inc_flag = 1;
}

void subDECProcess(){
	dec_flag = 1;
}

void getRESETInput(){
  KeyReg2 = KeyReg1;
  KeyReg1 = KeyReg0;
  KeyReg0 = HAL_GPIO_ReadPin(RESET_GPIO_Port, RESET_Pin);
  if ((KeyReg1 == KeyReg0) && (KeyReg1 == KeyReg2)){
    if (KeyReg2 != KeyReg3)
    {
      KeyReg3 = KeyReg2;

      if (KeyReg3 == PRESSED_STATE)
      {
    	  subRESETProcess();
      }
    }
  }
}

void getINCInput(){ //function for inc button
  KeyReg6 = KeyReg5;
  KeyReg5 = KeyReg4;
  KeyReg4 = HAL_GPIO_ReadPin(INC_GPIO_Port, INC_Pin);
  if ((KeyReg5 == KeyReg4) && (KeyReg5 == KeyReg6)){
    if (KeyReg6 != KeyReg7)
    {
      KeyReg7 = KeyReg6;

      if (KeyReg7 == PRESSED_STATE)
      {
        subINCProcess();
        TimeOutForINCPress =  300; //set time out duration to 3s
      }
    }
    else
    {
       TimeOutForINCPress --;
        if (TimeOutForINCPress == 0)
        {
            if (KeyReg7 == PRESSED_STATE) //if after 3s the inc button is still pressed, start increasing the count value by 1 for every 1s
            {
              subINCProcess();
              TimeOutForINCPress =  100;
            }
            else
            {
                KeyReg7 = NORMAL_STATE;
                TimeOutForINCPress = 500;
            }
        }
    }
  }
}
void getDECInput(){
  KeyReg10 = KeyReg9;
  KeyReg9 = KeyReg8;
  KeyReg8 = HAL_GPIO_ReadPin(DEC_GPIO_Port, DEC_Pin);
  if ((KeyReg9 == KeyReg8) && (KeyReg9 == KeyReg10)){
    if (KeyReg10 != KeyReg11)
    {
      KeyReg11 = KeyReg10;

      if (KeyReg11 == PRESSED_STATE)
      {
    	  subDECProcess();
        TimeOutForDECPress =  300;//set time out duration to 3s
      }
    }
    else
    {
    	TimeOutForDECPress --;
        if (TimeOutForDECPress == 0){
            if (KeyReg11 == PRESSED_STATE)//if after 3s the dec button is still pressed, start decreasing the count value by 1 for every 1s
            {
            	subDECProcess();
              TimeOutForDECPress =  100;
            }
            else
            {
                KeyReg11 = NORMAL_STATE;
                TimeOutForDECPress = 500;
            }
        }
    }
  }
}
