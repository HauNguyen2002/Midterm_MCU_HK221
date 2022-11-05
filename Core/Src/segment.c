/*
 * segment.c
 *
 *  Created on: Nov 5, 2022
 *      Author: ASUS
 */

#include "segment.h"

int count=1;
void display7SEG(int num)
{
	int seg[10]={0xC0, 0xF9, 0xA4, 0xB0, 0x99, 0x92, 0x82, 0xF8, 0x80, 0x90};
	HAL_GPIO_WritePin(GPIOB, A_Pin,((seg[num]>>0)&0x01));
	HAL_GPIO_WritePin(GPIOB, B_Pin,((seg[num]>>1)&0x01));
	HAL_GPIO_WritePin(GPIOB, C_Pin,((seg[num]>>2)&0x01));
	HAL_GPIO_WritePin(GPIOB, D_Pin,((seg[num]>>3)&0x01));
	HAL_GPIO_WritePin(GPIOB, E_Pin,((seg[num]>>4)&0x01));
	HAL_GPIO_WritePin(GPIOB, F_Pin,((seg[num]>>5)&0x01));
	HAL_GPIO_WritePin(GPIOB, G_Pin,((seg[num]>>6)&0x01));
}
