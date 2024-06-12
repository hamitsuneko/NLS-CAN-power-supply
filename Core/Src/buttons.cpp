/*
 * buttons.cpp
 * Кнопки для увеличения и уменьшения выходного напряжения на 0,5 В
 *
 *  Created on: Mar 12, 2024
 *      Author: PopkovaDA
 *
 *
 */

#include "main_cpp.h"

// Флаги нажатия кнопок
bool buttonFlagVPlus, buttonFlagVMinus;

// Прерывание по кнопке
void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin) {

	// Биты, которые нужно сохранить
	const uint32_t SHIFT_MASK = 0xFFFFFDF8;

	// Маска установки бита
	static uint16_t maskOn = 0x0;

	// Маска для сброса бита
	static uint16_t maskOff = 0x0;


	// Больше
	if(GPIO_Pin == KEY_P_Pin){
		buttonFlagVPlus = 1;

		if(maskOn == 0x07){
			maskOn = 0x1FF;
		}

		if(maskOn < 0x207){
			GPIOB->ODR |= ++maskOn;
			GPIOB->ODR &= (maskOn + SHIFT_MASK);
		}
	}

	// Меньше
	if(GPIO_Pin == KEY_M_Pin){
		buttonFlagVMinus = 1;
		GPIOB->ODR &= SHIFT_MASK;

		if(maskOn == 0x200){
			maskOn = 0x08;
		}
		if(maskOn > 0){
			GPIOB->ODR |= --maskOn;
		}


	}
}

