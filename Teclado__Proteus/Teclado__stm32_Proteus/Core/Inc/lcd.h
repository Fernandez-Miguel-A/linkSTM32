//#include <xc.h>
//#define _XTAL_FREQ 48000000

#define USE_CGRAM_LCD

#define RS(x) 		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_4, x)
#define EN(x) 		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_5, x)
#define D4(x) 		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_0, x)
#define D5(x) 		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_1, x)
#define D6(x) 		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_2, x)
#define D7(x) 		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_3, x)
/*
#define RS_DIR TRISDbits.TRISD2
#define EN_DIR TRISDbits.TRISD3
#define D4_DIR TRISDbits.TRISD4
#define D5_DIR TRISDbits.TRISD5
#define D6_DIR TRISDbits.TRISD6
#define D7_DIR TRISDbits.TRISD7
*/
void Lcd_Port(char a);
void Lcd_Cmd(char a);
void Lcd_Clear(void);
void Lcd_Set_Cursor(char a, char b);
void Lcd_Init(void);
void Lcd_Write_Char(char a);
void Lcd_Write_String(const char *a);
void Lcd_Shift_Right(void);
void Lcd_Shift_Left(void);
void Lcd_Blink(void);
void Lcd_NoBlink(void);

#ifdef USE_CGRAM_LCD
void Lcd_CGRAM_CreateChar(char add, const char* chardata);
void Lcd_CGRAM_Init(void);
void Lcd_CGRAM_Close(void);
#endif