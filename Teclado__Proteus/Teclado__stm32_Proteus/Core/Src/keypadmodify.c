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

char Keypad_Get_Char(void)
{
    val_key = 0;
    GPIO_TypeDef* R_PORTS[4] = {R1_GPIO_Port, R2_GPIO_Port, R3_GPIO_Port, R4_GPIO_Port};
    uint16_t R_PINS[4] = {R1_Pin, R2_Pin, R3_Pin, R4_Pin};
    GPIO_TypeDef* C_PORTS[4] = {C1_GPIO_Port, C2_GPIO_Port, C3_GPIO_Port, C4_GPIO_Port};
    uint16_t C_PINS[4] = {C1_Pin, C2_Pin, C3_Pin, C4_Pin};

    for (int r = 0; r < 4; r++) {
        HAL_GPIO_WritePin(R_PORTS[r], R_PINS[r], GPIO_PIN_RESET);
        for (int c = 0; c < 4; c++) {
            if (!(HAL_GPIO_ReadPin(C_PORTS[c], C_PINS[c]))) {
                HAL_Delay(4);
                while (!(HAL_GPIO_ReadPin(C_PORTS[c], C_PINS[c])));
                HAL_Delay(4);
                val_key = keys[r][c];
            }
        }
        HAL_GPIO_WritePin(R_PORTS[r], R_PINS[r], GPIO_PIN_SET);
    }

    return val_key;
}