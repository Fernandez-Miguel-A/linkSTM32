/*
 * Teclado.h
 *
 *  Created on: 26/06/2023
 *      Author: alcid
 */

#ifndef LIBRERIAS_TECLADO_H_
#define LIBRERIAS_TECLADO_H_

#include "main.h"

//DEFINE SI LAS RESISTENCIAS DE LAS COLUMNAS SON PULL UP O PULL DOWM
#define res 0  //0=TIERRA    1=VDD

//PARA LA LECTURA D ELAS COLUMNAS
#define te_c1 HAL_GPIO_ReadPin(F1_GPIO_Port, F1_Pin)
#define te_c2 HAL_GPIO_ReadPin(F2_GPIO_Port, F2_Pin)
#define te_c3 HAL_GPIO_ReadPin(F3_GPIO_Port, F3_Pin)
#define te_c4 HAL_GPIO_ReadPin(F4_GPIO_Port, F4_Pin)

uint8_t tecla_presionada();//retorna el valor de la tecla leida
uint8_t tecla_deco();//decodifoca la tecla leida






#endif /* LIBRERIAS_TECLADO_H_ */
