/*
 * CO_eeprom.c
 *
 *  Created on: 16 апр. 2024 г.
 *      Author: PopkovaDA
 */

#include "storage/CO_eeprom.h"
#include "stm32f1xx_hal_i2c.h"
//#include "301/crc16-ccitt.h"

#define EEPROM_CAPACITY 2048
#define EEPROM_PAGE_SIZE 16
#define EEPROM_BLOCK_SIZE 256

static size_t eepromAddrNextAuto = 0;
uint8_t I2C1_DEVICE_ADDRESS = 0x50 << 1;

bool_t CO_eeprom_init(void *storageModule){
	return 1;

}

size_t CO_eeprom_getAddr(void *storageModule, bool_t isAuto,
                         size_t len, bool_t *overflow){

	size_t address;
	address = eepromAddrNextAuto;
	eepromAddrNextAuto += len;
	if(eepromAddrNextAuto > EEPROM_CAPACITY){
		*overflow = true;
	}

	return address;
}

void CO_eeprom_readBlock(void *storageModule, uint8_t *data, size_t eepromAddr, size_t len) {
    // Адрес начала следующего блока
    uint16_t blockAddr;

    // Оставшиеся байты для чтения
    uint16_t bytesReadLeft = EEPROM_PAGE_SIZE;

    // Адрес в массиве
    uint16_t bytesRemaining = 0;

    // Буфер для чтения одного блока
    uint8_t buff[EEPROM_PAGE_SIZE];

    while (len > 0) {

    	// Сдвиг адреса устройства
    	if(eepromAddr >= 0 && eepromAddr < 256){
    		I2C1_DEVICE_ADDRESS = 0x50<<1;
    	}
    	else if(eepromAddr >= 256 && eepromAddr < 512){
    		I2C1_DEVICE_ADDRESS = 0x51<<1;
    	}
    	else if(eepromAddr >= 512 && eepromAddr < 768){
    		I2C1_DEVICE_ADDRESS = 0x52<<1;
    	}
    	else if(eepromAddr >= 768 && eepromAddr < 1024){
    		I2C1_DEVICE_ADDRESS = 0x53<<1;
    	}

        if (eepromAddr % EEPROM_PAGE_SIZE != 0 && len > bytesReadLeft) {
            blockAddr = (eepromAddr / EEPROM_PAGE_SIZE + 1) * EEPROM_PAGE_SIZE;
            bytesReadLeft = blockAddr - eepromAddr;
        }
        else if (eepromAddr % EEPROM_PAGE_SIZE == 0 && len > bytesReadLeft) {
            blockAddr = eepromAddr + EEPROM_PAGE_SIZE;
            bytesReadLeft = blockAddr - eepromAddr;
        }
        else if (len < bytesReadLeft) {
            bytesReadLeft = len;
        }

        HAL_GPIO_WritePin(I2C_WP_GPIO_Port, I2C_WP_Pin, GPIO_PIN_SET);
        while (HAL_I2C_IsDeviceReady(&hi2c1, I2C1_DEVICE_ADDRESS, 3, 5) != HAL_OK) {}

        HAL_StatusTypeDef readstatus = HAL_I2C_Mem_Read(&hi2c1, I2C1_DEVICE_ADDRESS, eepromAddr,
                                                        I2C_MEMADD_SIZE_8BIT, buff, bytesReadLeft, 100);
        if (readstatus != HAL_OK) {
            break;
        }

        memcpy(&data[bytesRemaining], buff, bytesReadLeft);

        len -= bytesReadLeft;
        eepromAddr += bytesReadLeft;
        bytesRemaining += bytesReadLeft;
        bytesReadLeft = EEPROM_PAGE_SIZE;
    }
}

bool_t CO_eeprom_writeBlock(void *storageModule, uint8_t *data,
                            size_t eepromAddr, size_t len){


	// Адрес начала следующей страницы
	uint16_t pageadr;

	// Сколько байт осталось на странице для записи
	uint16_t bytesLeft = 16;

	// Адрес в массиве
	uint16_t bytes_remaining = 0;

	// Буфер для записи одной страницы
	uint8_t buff[16];

	for(uint8_t i = 0; i<16; i++){
		buff[i] = 0;
	}

	// Если нужно произвести переход на следующую страницу (16 байт каждая)
	while(len > 0){

		// Сдвиг адреса устройства
		if(eepromAddr >= 0 && eepromAddr < 256){
			I2C1_DEVICE_ADDRESS = 0x50<<1;
		}
		else if(eepromAddr >= 256 && eepromAddr < 512){
			I2C1_DEVICE_ADDRESS = 0x51<<1;
		}
		else if(eepromAddr >= 512 && eepromAddr < 768){
			I2C1_DEVICE_ADDRESS = 0x52<<1;
		}
		else if(eepromAddr >= 768 && eepromAddr < 1024){
			I2C1_DEVICE_ADDRESS = 0x53<<1;
		}

		if (eepromAddr % EEPROM_PAGE_SIZE != 0 && len > bytesLeft){
			pageadr = (eepromAddr / EEPROM_PAGE_SIZE + 1) * EEPROM_PAGE_SIZE;
			bytesLeft = pageadr - eepromAddr;

		}
		else if (eepromAddr % EEPROM_PAGE_SIZE == 0 && len > EEPROM_PAGE_SIZE){
			pageadr = eepromAddr + EEPROM_PAGE_SIZE;
			bytesLeft = pageadr - eepromAddr;
		}
		else if (len < bytesLeft ){
			bytesLeft = len;
		}

		memcpy(&buff, &data[bytes_remaining], bytesLeft);

		HAL_GPIO_WritePin(I2C_WP_GPIO_Port, I2C_WP_Pin, GPIO_PIN_RESET);
		HAL_StatusTypeDef writestatus = HAL_I2C_Mem_Write(&hi2c1, I2C1_DEVICE_ADDRESS, eepromAddr, I2C_MEMADD_SIZE_8BIT, buff,
				bytesLeft, 100);
		while (HAL_I2C_IsDeviceReady(&hi2c1, I2C1_DEVICE_ADDRESS, 3, 5)!= HAL_OK){}
        if (writestatus != HAL_OK) {
        	return 0;
        }


		// Проверка на корректность записанных данных
		HAL_GPIO_WritePin(I2C_WP_GPIO_Port, I2C_WP_Pin, GPIO_PIN_SET);
		HAL_StatusTypeDef readstatus = HAL_I2C_Mem_Read(&hi2c1, I2C1_DEVICE_ADDRESS, eepromAddr, I2C_MEMADD_SIZE_8BIT, buff,
				bytesLeft, 100);
        if (readstatus != HAL_OK) {
        	return 0;
        }
		if(memcmp(&data[bytes_remaining], buff, bytesLeft) != 0){
			return 0;
		}

		len-=bytesLeft;
		eepromAddr+=bytesLeft;
		bytes_remaining += bytesLeft;

	}

	return 1;
}

uint16_t CO_eeprom_getCrcBlock(void *storageModule,
                               size_t eepromAddr, size_t len){
	return 0;
}

bool_t CO_eeprom_updateByte(void *storageModule, uint8_t data,
                            size_t eepromAddr){
	return 1;
}
