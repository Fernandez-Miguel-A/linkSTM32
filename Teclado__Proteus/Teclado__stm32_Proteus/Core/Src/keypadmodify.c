#include "main.h"
//#include "key_jorge.h"
/*
C1->GPIOA[0](GPIO_PULLUP)
C2->GPIOA[1](GPIO_PULLUP)
C3->GPIOA[2](GPIO_PULLUP)
C4->GPIOA[3](GPIO_PULLUP)

R1->GPIOA[4]
R2->GPIOA[5]
R3->GPIOA[6]
R4->GPIOA[7]
*/

char val_key;
const char keys[4][4] = {{'7','8','9','%'},
                         {'4','5','6','*'},
                         {'1','2','3','-'},
                         {'C','0','=','+'}};

char Keypad_Get_Char_stm32(void)
{
    GPIO_TypeDef* F_PORTS[4] = {F1_GPIO_Port, F2_GPIO_Port, F3_GPIO_Port, F4_GPIO_Port};
    uint16_t F_PINS[4] = {F1_Pin, F2_Pin, F3_Pin, F4_Pin};
    GPIO_TypeDef* let_PORTS[4] = {A_GPIO_Port, B_GPIO_Port, C_GPIO_Port, D_GPIO_Port};
    uint16_t let_PINS[4] = {A_Pin, B_Pin, C_Pin, D_Pin};


    for (int r = 0; r < 4; r++) {
    	HAL_GPIO_WritePin(let_PORTS[r], let_PINS[r], GPIO_PIN_SET);
    }

    val_key = 0; // debe retornar 0 en caso de que no pulse una tecla.

    for (int r = 0; r < 4; r++) {
        HAL_GPIO_WritePin(let_PORTS[r], let_PINS[r], GPIO_PIN_RESET);
        for (int c = 0; c < 4; c++) {
            if (!(HAL_GPIO_ReadPin(F_PORTS[c], F_PINS[c]))) {
                //HAL_Delay(4);
                //while (!(HAL_GPIO_ReadPin(F_PORTS[c], F_PINS[c]))); //cuelge inesperado.
                //HAL_Delay(4);
                val_key = keys[r][c];
            }
        }
        HAL_GPIO_WritePin(let_PORTS[r], let_PINS[r], GPIO_PIN_SET);
    }

    return val_key;
}
