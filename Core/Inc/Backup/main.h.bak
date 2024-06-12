/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2024 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f1xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */
extern ADC_HandleTypeDef hadc1;
extern CAN_HandleTypeDef hcan;
extern I2C_HandleTypeDef hi2c1;
extern UART_HandleTypeDef huart3;
extern TIM_HandleTypeDef htim3;

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define LED_GREEN_Pin GPIO_PIN_13
#define LED_GREEN_GPIO_Port GPIOC
#define LED_RED_Pin GPIO_PIN_14
#define LED_RED_GPIO_Port GPIOC
#define KEY_P_Pin GPIO_PIN_0
#define KEY_P_GPIO_Port GPIOA
#define KEY_P_EXTI_IRQn EXTI0_IRQn
#define KEY_M_Pin GPIO_PIN_1
#define KEY_M_GPIO_Port GPIOA
#define KEY_M_EXTI_IRQn EXTI1_IRQn
#define INIT_Pin GPIO_PIN_2
#define INIT_GPIO_Port GPIOA
#define PWR_Pin GPIO_PIN_3
#define PWR_GPIO_Port GPIOA
#define ADC_V_AKB_Pin GPIO_PIN_4
#define ADC_V_AKB_GPIO_Port GPIOA
#define ADC_V_OUT_Pin GPIO_PIN_5
#define ADC_V_OUT_GPIO_Port GPIOA
#define ADC_I_Pin GPIO_PIN_6
#define ADC_I_GPIO_Port GPIOA
#define SP1_Pin GPIO_PIN_0
#define SP1_GPIO_Port GPIOB
#define SP2_Pin GPIO_PIN_1
#define SP2_GPIO_Port GPIOB
#define SP3_Pin GPIO_PIN_2
#define SP3_GPIO_Port GPIOB
#define ON_OFF_Pin GPIO_PIN_12
#define ON_OFF_GPIO_Port GPIOB
#define USART1_LATCH_Pin GPIO_PIN_8
#define USART1_LATCH_GPIO_Port GPIOA
#define TERM_RESIST_Pin GPIO_PIN_15
#define TERM_RESIST_GPIO_Port GPIOA
#define I2C_WP_Pin GPIO_PIN_5
#define I2C_WP_GPIO_Port GPIOB
#define SP4_Pin GPIO_PIN_9
#define SP4_GPIO_Port GPIOB
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
