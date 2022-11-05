#ifndef INC_BUTTON_H_
#define INC_BUTTON_H_

#include "main.h"

#define NORMAL_STATE GPIO_PIN_SET
#define PRESSED_STATE GPIO_PIN_RESET

extern int dec_flag;
extern int reset_flag;
extern int inc_flag;

void getRESETInput();
void getDECInput();
void getINCInput();

#endif /* INC_BUTTON_H_ */
