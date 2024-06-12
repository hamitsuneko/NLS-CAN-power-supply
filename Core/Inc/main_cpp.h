/*
 * main_cpp.h
 *
 *  Created on: Jan 15, 2024
 *      Author: PopkovaDA
 */

#ifndef INC_MAIN_CPP_H_
#define INC_MAIN_CPP_H_

#ifdef __cplusplus
 extern "C" {
#endif


#include "main.h"
#include "CO_app_STM32.h"
#include "timers.h"
#include "OD.h"
#include "onewire.h"
#include "ds18b20.h"
#include "adc.h"
#include "buttons.h"

#include "debug.h"

// Максимально допустимое значение температуры
#define TEMP_MAX 90

 // Значение температуры, при котором включается нагрузка после перегрева
 #define TEMP_OK 85

/* *
 * Инициализация датчика температуры
 *
 * */
void DS18B20Init(DS18B20 *temperatureSensor);

/* *
 * Чтение конфигурации и температуры датчика
 *
 * */
void DS18B20Read(DS18B20 *temperatureSensor);

/* *
 * Расчет напряжения
 * Принимает: калибровочный коэффициент
 * Возвращает: значение напряжения в вольтах
 * */
float calculateVoltage(float coef);

/* *
 * Расчет напряжения
 * Принимает: калибровочные коэффициенты минимума и максимума
 * Возвращает: значение тока нагрузки в амперах
 * */
float calculateCurrent(float coef0, float coef1);

/* *
 * Калибровка тока и напряжения
 * Проверяет, было ли внесено в объект CANopen новое калибровочное значение.
 * Пересчет калибровочных коэффициентов.
 * */
void calibration();

/* *
 * Проверка напряжения на аккумуляторе. Если работа от аккумулятора,
 * то включен светодиод.
 * */
void checkAKB();

void mainCPP(void);



#ifdef __cplusplus
}
#endif


#endif /* INC_MAIN_CPP_H_ */
