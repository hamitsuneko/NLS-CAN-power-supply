/*
 * main_cpp.cpp
 *
 * @date Jan 15, 2024
 * @author PopkovaDA
 * @brief Весь код будет тут. Из-за того, что Cube создает только main.c, но не main.cpp,
 * 		  функция main на С++ будет вызываться из main.c
 *
 *
 */

#include "main_cpp.h"
#include "stm32f1xx_hal.h"
#include "storage/CO_storageEeprom.h"
#include "defines.h"

float calibV = 0.0;
float calibImin = 0.0;
float calibImax = 0.0;

float coefV = 0.0;
float coefImin = 0.0;
float coefImax = 0.0;

void mainCPP(void){

	// Ошибка перегрузки
	bool errorOverload = 0;

/*--------------------------------------- Инициализация датчика температуры ----------------------------------------------*/
	  // Датчик температуры
	  DS18B20 temperatureSensor;
	  DS18B20Init(&temperatureSensor);
/*----------------------------------------------------------------------------------------------------------------------*/
	  HAL_ADCEx_Calibration_Start(&hadc1);


	// Запуск АЦП
	HAL_ADCEx_InjectedStart_IT(&hadc1);

	// Включить выход
	HAL_GPIO_WritePin(ON_OFF_GPIO_Port, ON_OFF_Pin, GPIO_PIN_SET);

	// Выключить резисторы напряжения
	HAL_GPIO_WritePin(SP1_GPIO_Port, SP1_Pin | SP2_Pin | SP3_Pin | SP4_Pin, GPIO_PIN_RESET);

    calibV = 0.0;
    calibImin = 0.0;
    calibImax = 0.0;

    while(1) {

	  	canopen_app_process();

	  	HAL_ADCEx_InjectedStart_IT(&hadc1);

		DS18B20Read(&temperatureSensor);


/*------------------------------------------ Запись и чтение CANOpen --------------------------------------------------------------*/

	    OD_PERSIST_COMM.x3F00_temperature = (int16_t)temperatureSensor.temperature;

	    bool resistor = OD_PERSIST_COMM.x5000_resistor;
	    HAL_GPIO_WritePin(TERM_RESIST_GPIO_Port, TERM_RESIST_Pin, (GPIO_PinState)resistor);

	    float V = calculateVoltage(coefV);
	    OD_PERSIST_COMM.x3F02_voltageOut = V;

	    float I = calculateCurrent(coefImin, coefImax);
	    OD_PERSIST_COMM.x3F03_current = current;

/*------------------------------------------ Проверка перегрева и перегрузки ------------------------------------------------*/
		// Отключение нагрузки
		if((temperatureSensor.temperature > TEMP_MAX || current > CURRENT_MAX) && !errorOverload){
			errorOverload = 1;
			HAL_GPIO_WritePin(ON_OFF_GPIO_Port, ON_OFF_Pin, GPIO_PIN_RESET);
			ledOn(0);
		}

		// Ждать пока температура не придет в норму
		if (temperatureSensor.temperature <= TEMP_MAX && current <= CURRENT_MAX && errorOverload) {

			errorOverload = 0;
			HAL_GPIO_WritePin(ON_OFF_GPIO_Port, ON_OFF_Pin, GPIO_PIN_SET);
			ledOff(0);
		}
/*-------------------------------------------------------------------------------------------------------------------------*/

	  	HAL_Delay(10);

	}

}

void checkAKB(){
	GPIO_PinState pwrPinState = HAL_GPIO_ReadPin(PWR_GPIO_Port, PWR_Pin);

	// Светодиод "Аккумулятор" выключен, когда питание от сети
	HAL_GPIO_WritePin(LED_GREEN_GPIO_Port, LED_GREEN_Pin, (GPIO_PinState)(!pwrPinState));

	if(!pwrPinState && OD_PERSIST_COMM.x3F01_voltageAKB <= VOLTAGE_AKB_MIN){
		HAL_GPIO_WritePin(ON_OFF_GPIO_Port, ON_OFF_Pin, GPIO_PIN_RESET);
	}

}


float calculateVoltage(float coef){
	float V;
	V = voltageOut * coef;

	return V;
}

float calculateCurrent(float coef0, float coef1){
	float I;
	I = (current - coef0) * coef1;

	return I;
}

void calibration(){
    if(calibV != OD_PERSIST_COMM.x240E_calibrationV){
	    calibV = OD_PERSIST_COMM.x240E_calibrationV;
	    coefV = calibV / voltageOut;
    }
    if(calibImin != OD_PERSIST_COMM.x240F_calibrationImin){
    	calibImin = OD_PERSIST_COMM.x240F_calibrationImin;
    	coefImin = current;
    }
    if(calibImax != OD_PERSIST_COMM.x2410_calibratonImax){
    	calibImax = OD_PERSIST_COMM.x2410_calibratonImax;
    	coefImax = calibImin/(current - coefImax);
    }
}

void DS18B20Init(DS18B20 *temperatureSensor){
	  DS18B20_Init(temperatureSensor, &huart3);

	  DS18B20_InitializationCommand(temperatureSensor);
	  DS18B20_ReadRom(temperatureSensor);
	  DS18B20_ReadScratchpad(temperatureSensor);

	  uint8_t settings[3];
	  settings[0] = temperatureSensor->temperatureLimitHigh;
	  settings[1] = temperatureSensor->temperatureLimitLow;
	  settings[2] = DS18B20_12_BITS_CONFIG;

	  DS18B20_InitializationCommand(temperatureSensor);
	  DS18B20_SkipRom(temperatureSensor);
	  DS18B20_WriteScratchpad(temperatureSensor, settings);
}

void DS18B20Read(DS18B20 *temperatureSensor){
	DS18B20_InitializationCommand(temperatureSensor);
    DS18B20_SkipRom(temperatureSensor);
    DS18B20_ConvertT(temperatureSensor, DS18B20_DATA);

    DS18B20_InitializationCommand(temperatureSensor);
    DS18B20_SkipRom(temperatureSensor);
    DS18B20_ReadScratchpad(temperatureSensor);
}

