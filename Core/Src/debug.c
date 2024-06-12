/*
 * debug.c
 *
 *  Created on: 18 янв. 2024 г.
 *      Author: PopkovaDA
 */


#include "main_cpp.h"


// Отключить светодиод
// 0 - красный
// 1 - зеленый
 void ledOff(uint8_t led){
	 switch (led) {
		case 0:
			HAL_GPIO_WritePin(LED_RED_GPIO_Port, LED_RED_Pin, GPIO_PIN_RESET);
			break;
		case 1:
			HAL_GPIO_WritePin(LED_GREEN_GPIO_Port, LED_GREEN_Pin, GPIO_PIN_RESET);
			break;
		default:
			break;
	}
}

 // Включить светодиод
 // 0 - красный
 // 1 - зеленый
 void ledOn(uint8_t led){
	 switch (led) {
	 		case 0:
	 			HAL_GPIO_WritePin(LED_RED_GPIO_Port, LED_RED_Pin, GPIO_PIN_SET);
	 			break;
	 		case 1:
	 			HAL_GPIO_WritePin(LED_GREEN_GPIO_Port, LED_GREEN_Pin, GPIO_PIN_SET);
	 			break;
	 		default:
	 			break;
	 }
 }

 // Задержка в мс
 void delay(uint32_t delay){
	 HAL_Delay(delay);
 }
