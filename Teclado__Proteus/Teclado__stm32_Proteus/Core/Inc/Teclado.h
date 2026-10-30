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


//entradas
#ifdef    TC1_GPIO_Port
# define   F1_GPIO_Port     TC1_GPIO_Port 
# define   F2_GPIO_Port     TC2_GPIO_Port
# define   F3_GPIO_Port     TC3_GPIO_Port
# define   F4_GPIO_Port     TC4_GPIO_Port

# define   F1_Pin           TC1_Pin          
# define   F2_Pin           TC2_Pin
# define   F3_Pin           TC3_Pin
# define   F4_Pin           TC4_Pin
#endif
//

//salidas
#ifdef    TF1_GPIO_Port
# define   A_GPIO_Port      TF1_GPIO_Port
# define   B_GPIO_Port      TF2_GPIO_Port
# define   C_GPIO_Port      TF3_GPIO_Port
# define   D_GPIO_Port      TF4_GPIO_Port

# define   A_Pin            TF1_Pin
# define   B_Pin            TF2_Pin
# define   C_Pin            TF3_Pin
# define   D_Pin            TF4_Pin
#endif
//




//PARA LA LECTURA D ELAS COLUMNAS
#define te_c1 HAL_GPIO_ReadPin(F1_GPIO_Port, F1_Pin)
#define te_c2 HAL_GPIO_ReadPin(F2_GPIO_Port, F2_Pin)
#define te_c3 HAL_GPIO_ReadPin(F3_GPIO_Port, F3_Pin)
#define te_c4 HAL_GPIO_ReadPin(F4_GPIO_Port, F4_Pin)

uint8_t tecla_presionada();//retorna el valor de la tecla leida
uint8_t tecla_deco();//decodifoca la tecla leida






#endif /* LIBRERIAS_TECLADO_H_ */
