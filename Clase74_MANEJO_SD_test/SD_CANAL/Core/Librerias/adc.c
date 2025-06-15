/*
 * adc.c
 *
 *  Created on: 15/11/2021
 *      Author: Alcides Ramos
 */


#include "adc.h"

extern ADC_HandleTypeDef adc1;

uint16_t ADC_Read()
{
	HAL_ADC_Start(&adc1);
    HAL_ADC_PollForConversion(&adc1,1);
    return (HAL_ADC_GetValue(&adc1));
}

