/*
 * Teclado.c
 *
 *  Created on: 26/06/2023
 *      Author: alcid
 */

#include "main.h"
#include "Teclado.h"
#include "stdbool.h"


uint8_t state_bit=state;


uint8_t t_tecla1()
{
    HAL_GPIO_WritePin(A_GPIO_Port, A_Pin, !state_bit);//activa solo la fila 1
    HAL_GPIO_WritePin(B_GPIO_Port, B_Pin, state_bit);
    HAL_GPIO_WritePin(C_GPIO_Port, C_Pin, state_bit);
    HAL_GPIO_WritePin(D_GPIO_Port, D_Pin, state_bit);

    if (te_read0==!state_bit){
        HAL_Delay(15);
        while (te_read0==!state_bit);
        return 1;
    }
    else if (te_read1==!state_bit){
      Delay_ms(15);
      while (te_read1==!state_bit);
      return 2;
    }
    else if (te_read2==!state_bit){
      Delay_ms(15);
      while (te_read2==!state_bit);
      return 3;
    }
    else if (te_read3==!state_bit){
      Delay_ms(15);
      while (te_read3==!state_bit);
      return 4;
    }
    else return 0;
}

uint8_t t_tecla2()
{
    HAL_GPIO_WritePin(A_GPIO_Port, A_Pin, state_bit);
    HAL_GPIO_WritePin(B_GPIO_Port, B_Pin, !state_bit);//activa solo la fila 2
    HAL_GPIO_WritePin(C_GPIO_Port, C_Pin, state_bit);
    HAL_GPIO_WritePin(D_GPIO_Port, D_Pin, state_bit);

    if (te_read0==!state_bit   ){Delay_ms(15); while (te_read0==!state_bit); return 5;}
    else if (te_read1==!state_bit){Delay_ms(15); while (te_read1==!state_bit); return 6;}
    else if (te_read2==!state_bit){Delay_ms(15); while (te_read2==!state_bit); return 7;}
    else if (te_read3==!state_bit){Delay_ms(15); while (te_read3==!state_bit); return 8;}   //comentar si es 3*4
    else return 0;
}


uint8_t t_tecla3()
{
  HAL_GPIO_WritePin(A_GPIO_Port, A_Pin, state_bit);
  HAL_GPIO_WritePin(B_GPIO_Port, B_Pin, state_bit);
  HAL_GPIO_WritePin(C_GPIO_Port, C_Pin, !state_bit);//activa solo la fila 3
  HAL_GPIO_WritePin(D_GPIO_Port, D_Pin, state_bit);

  if (te_read0==!state_bit   ){Delay_ms(15); while (te_read0==!state_bit); return 9;}
  else if (te_read1==!state_bit){Delay_ms(15); while (te_read1==!state_bit); return 10;}
  else if (te_read2==!state_bit){Delay_ms(15); while (te_read2==!state_bit); return 11;}
  else if (te_read3==!state_bit){Delay_ms(15); while (te_read3==!state_bit); return 12;}   //comentar si es 3*4
  else return 0;
}


uint8_t t_tecla4()
{
  HAL_GPIO_WritePin(A_GPIO_Port, A_Pin, state_bit);
  HAL_GPIO_WritePin(B_GPIO_Port, B_Pin, state_bit);
  HAL_GPIO_WritePin(C_GPIO_Port, C_Pin, state_bit);
  HAL_GPIO_WritePin(D_GPIO_Port, D_Pin, !state_bit);//activa solo la fila 4

  if (te_read0==!state_bit   ){Delay_ms(15); while (te_read0==!state_bit); return 13;}
  else if (te_read1==!state_bit){Delay_ms(15); while (te_read1==!state_bit); return 14;}
  else if (te_read2==!state_bit){Delay_ms(15); while (te_read2==!state_bit); return 15;}
  else if (te_read3==!state_bit){Delay_ms(15); while (te_read3==!state_bit); return 16;}   //comentar si es 3*4
  else return 0;
}


//Funcion para ver si hay una tecla presionada
uint8_t tecla_presionada()
{
  uint8_t te;

  te=t_tecla1();
  if (te!=0) return (te);
  //HAL_Delay(5);
  te=t_tecla2();
  if (te!=0) return (te);
  //HAL_Delay(5);
  te=t_tecla3();
  if (te!=0) return (te);
  //HAL_Delay(5);
  te=t_tecla4();
  if (te!=0) return (te);
  return 0;
}



//Función para decodificar el teclado.
uint8_t tecla_deco()
{
//Estructura switch case para evaluar los valores_ retornados
//por la librería del teclado.
  switch( tecla_presionada () )
  {
  case 1: return '7'; break;
  case 2: return '8'; break;
  case 3: return '9'; break;
  case 4: return '%'; break;
  case 5: return '4';  break;
  case 6: return '5'; break;
  case 7: return '6'; break;
  case 8: return '*'; break;
  case 9: return '1'; break;
  case 10: return '2'; break;
  case 11: return '3'; break;
  case 12: return '-'; break;
  case 13: return 'C';  break;
  case 14: return '0';  break;
  case 15: return '=';  break;
  case 16: return '+';  break;
  default: return 0; break; //Tecla no pulsada.
  }
}
