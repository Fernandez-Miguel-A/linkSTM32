/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2025 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include <stdio.h>
#include "lcd.h"
#include "keypadmodify.h"

#include "stdint.h"
#include <ctype.h>
#include "string.h"


uint8_t segment[10]={  //125
63,6,91,79,102,109,125,7,127,103
};
 
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
TIM_HandleTypeDef htim4;

/* USER CODE BEGIN PV */

char txt3[] = "Lcd4bit:";
char texto[] = "VIEJO PIC16F877A";     // Usando 'const' No muestra el texto
char Txt[20];


int res_=0;
int retardo = 500; // en 'msecs' .0-> 65535
char retardo_s[5];
char kp, tecla;
char pulsador_kp;

enum teclado_estado {E1, E2, E3, E4, Efin};
uint8_t estado_teclado= E1;

#define    LED1(x)    HAL_GPIO_WritePin(GPIOB, GPIO_PIN_0, x) // PUERTOB
#define    LED2(x)    HAL_GPIO_WritePin(GPIOB, GPIO_PIN_1, x) // PUERTOB
#define    but     		HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_10) // PUERTOA
//(x == 1) ? (GPIO_PIN_SET) : (GPIO_PIN_RESET)
//  == GPIO_PIN_SET


#define 	Delay_ms		  HAL_Delay
#define 	Retardo_ms		HAL_Delay
#define 	__delay_ms		HAL_Delay




int StrToInt(char *s)
{
    int i=0, sal=0;
    while(s[i]!=0){
        sal = sal*10 + (s[i++]-48);   
    }
    return sal;
}          
/*void Retardo_ms(int n)
{
     int i;
     for(i=0; i<n; i++){
         Delay_1ms();
     }
}*/

void __delay_us2(int32_t delay)
{
		uint16_t tickstart;
		//__HAL_TIM_SetCounter(&htim4, 0);
		tickstart = __HAL_TIM_GET_COUNTER(&htim4);
    while((__HAL_TIM_GET_COUNTER(&htim4)-tickstart) < delay);
}


void __delay_us(int32_t delay)
{
		volatile uint32_t i;
		for(i= 5*delay; i!=0; i--);
	
}

void __delay_us0(int32_t delay)
{
		HAL_Delay(1);
}

/*
void Keypad_Key_Click(void)
{
    HAL_GPIO_ReadPin(GPIOA, 
}*/


void retardo_teclado(uint32_t Delay)
{
  uint32_t tickstart = HAL_GetTick();
  uint32_t wait = Delay;

  /* Add a freq to guarantee minimum wait */
  if (wait < HAL_MAX_DELAY)
  {
    wait += (uint32_t)(uwTickFreq);
  }

  while ((HAL_GetTick() - tickstart) < wait)
  {
  }
}


/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_TIM4_Init(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{

  /* USER CODE BEGIN 1 */
    char c;
  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */
      
  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_TIM4_Init();
  /* USER CODE BEGIN 2 */
	  HAL_TIM_Base_Start(&htim4);
		
		
    //Keypad_Init();										// PUERTOA
    
    Lcd_Init();                        // Initialize Lcd
    Delay_ms(15);
	
	
    Lcd_Clear(); //Lcd_Cmd(_LCD_CLEAR);               // Clear display
    Lcd_NoBlink(); //Lcd_Cmd(_LCD_CURSOR_OFF);          // Cursor off
    
    
    Lcd_Set_Cursor(1,1);
    Lcd_Write_String(txt3);                 // Write text in first row 
		Lcd_Set_Cursor(2,1);
    Lcd_Write_String("PIC  es la onda!");                 // Write text in first row
    c = '0';
	
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
		
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
		
		do {  
				kp = Keypad_Get_Char();
				if(!isdigit(c)){// && (atoi(c)>9)){
						 c = '0'; 
				}
				Lcd_Set_Cursor(1, 15);
				Lcd_Write_Char(kp);
				Lcd_Set_Cursor(1, 16);
				Lcd_Write_Char(c++);


				if (but == 0){// ENTRA aca  SIN Pulsar  el boton.
					 Lcd_Set_Cursor(2,1);
					 Lcd_Write_String("                ");
					 sprintf(Txt, "%i", retardo);
					 Lcd_Set_Cursor(2, 1);
					 Lcd_Write_String(Txt);
				} 
        LED1(1);
        Retardo_ms(retardo);     //retardo
        LED1(0);         
        Retardo_ms(retardo);     //retardo
		} while(!kp);
         
    LED2(1);
		Delay_ms(500);     //retardo
		LED2(0);           
		Delay_ms(500);     //retardo
        
		tecla = kp;
		
		//Lcd_Chr(1,9,tecla);
		if(tecla == '='){
				if(retardo_s[0] != 0)
						retardo = StrToInt(retardo_s);
						
		}
		if(!isdigit(tecla)){
				estado_teclado = Efin;
		}
											
		switch(estado_teclado){
				case E1: retardo_s[0] = tecla;
								 retardo_s[1] = 0;
								 Lcd_Set_Cursor(1,11);
								 Lcd_Write_Char(tecla);
								 estado_teclado = E2;
								 Delay_ms(400);
								 break;          
				case E2: retardo_s[1] = tecla; 
								 retardo_s[2] = 0;
								 Lcd_Set_Cursor(1,12);
								 Lcd_Write_Char(tecla); 
								 estado_teclado = E3;
								 Delay_ms(400); 
								 break;
				case E3: retardo_s[2] = tecla;
								 retardo_s[3] = 0;
								 Lcd_Set_Cursor(1,13);
								 Lcd_Write_Char(tecla); 
								 estado_teclado = E4;
								 Delay_ms(400);
								 break;
				case E4: retardo_s[3] = tecla;
								 retardo_s[4] = 0;
								 Lcd_Set_Cursor(1,14);
								 Lcd_Write_Char(tecla);
								 estado_teclado = Efin;
								 Delay_ms(400);
								 break;
				case Efin:
								 Lcd_Set_Cursor(1,11);
								 Lcd_Write_String("    ");
								 //retardo = StrToInt(retardo_s); 
								 retardo_s[0] = 0;
								 Delay_ms(600);
								 estado_teclado = E1;
								 break;
		}
        
//    Lcd_Out(2, 9, retardo_s);   
     
		
		
  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_NONE;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_HSI;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief TIM4 Initialization Function
  * @param None
  * @retval None
  */
static void MX_TIM4_Init(void)
{

  /* USER CODE BEGIN TIM4_Init 0 */

  /* USER CODE END TIM4_Init 0 */

  TIM_ClockConfigTypeDef sClockSourceConfig = {0};
  TIM_MasterConfigTypeDef sMasterConfig = {0};

  /* USER CODE BEGIN TIM4_Init 1 */

  /* USER CODE END TIM4_Init 1 */
  htim4.Instance = TIM4;
  htim4.Init.Prescaler = 8-1;
  htim4.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim4.Init.Period = 0xffff-1;
  htim4.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  htim4.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
  if (HAL_TIM_Base_Init(&htim4) != HAL_OK)
  {
    Error_Handler();
  }
  sClockSourceConfig.ClockSource = TIM_CLOCKSOURCE_INTERNAL;
  if (HAL_TIM_ConfigClockSource(&htim4, &sClockSourceConfig) != HAL_OK)
  {
    Error_Handler();
  }
  sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
  if (HAL_TIMEx_MasterConfigSynchronization(&htim4, &sMasterConfig) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN TIM4_Init 2 */

  /* USER CODE END TIM4_Init 2 */

}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};
  /* USER CODE BEGIN MX_GPIO_Init_1 */

  /* USER CODE END MX_GPIO_Init_1 */

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOC_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOA, R1_Pin|R2_Pin|R3_Pin|R4_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOB, LED1_Pin|LED2_Pin|D4_Pin|D5_Pin
                          |D6_Pin|D7_Pin|RS_Pin|EN_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pins : C1_Pin C2_Pin C3_Pin C4_Pin */
  GPIO_InitStruct.Pin = C1_Pin|C2_Pin|C3_Pin|C4_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_PULLUP;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pins : R1_Pin R2_Pin R3_Pin R4_Pin */
  GPIO_InitStruct.Pin = R1_Pin|R2_Pin|R3_Pin|R4_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pins : LED1_Pin LED2_Pin D4_Pin D5_Pin
                           D6_Pin D7_Pin RS_Pin EN_Pin */
  GPIO_InitStruct.Pin = LED1_Pin|LED2_Pin|D4_Pin|D5_Pin
                          |D6_Pin|D7_Pin|RS_Pin|EN_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

  /*Configure GPIO pin : BOTON_Pin */
  GPIO_InitStruct.Pin = BOTON_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(BOTON_GPIO_Port, &GPIO_InitStruct);

  /* USER CODE BEGIN MX_GPIO_Init_2 */

  /* USER CODE END MX_GPIO_Init_2 */
}

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
