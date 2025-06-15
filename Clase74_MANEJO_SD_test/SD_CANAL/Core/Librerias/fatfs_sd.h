// en el archivo stm32f4xx_it.h

/*
// en las variables colocar
extern uint16_t Timer1, Timer2;

// en el procedimiento SysTick_Handler(void)

if(Timer1 > 0)
			Timer1--;

		if(Timer2 > 0)
			Timer2--;


*/

/*
 en el archivo user_diskio.c
 incluir #include "fatfs_sd.h"
 hacer los cambios en

   return SD_disk_initialize(pdrv);
   return SD_disk_status(pdrv);
   return (SD_disk_read(pdrv, buff, sector, count));
   return SD_disk_write(pdrv, buff, sector, count);
   return SD_disk_ioctl(pdrv, cmd, buff);

*/
// en el main declarar las variable
/*
//variables de la memoria
FATFS memsd;
FATFS *pfs;
FIL archivo;
FRESULT fres;  // resultados de operaciones copn la memoria
uint32_t fre_clust;//
uint32_t totalSpace, freeSpace;
//char SD_BUFFER[100];// SD_SD_BUFFER usado para la memoria
char SD_BUFFER[_MAX_SS];// solo si se desea formatear;

 */

//   FORMAS DE USAR
/*


	   //retardo inicializacion
		HAL_Delay(500);
		//detecta la memoria
		if(f_mount(&memsd, "", 1) == FR_OK) uartx_write_text(&huart1, "memoria encontrada\r\n");
		else uartx_write_text(&huart1, "memoria no encontrada\r\n");

         // si desea formatear
           //if(f_mkfs("", FM_FAT32, 0, SD_BUFFER, _MAX_SS) != FR_OK)
				// uartx_write_text(&huart1, "NO FORMATEAD0\r\n");


		//Abre un archivo sino lo crea
		if(f_open(&archivo, "ARZ.txt", FA_OPEN_ALWAYS | FA_READ | FA_WRITE) != FR_OK)
		uartx_write_text(&huart1, "Archivo no creado\r\n");
		else uartx_write_text(&huart1, "Archivo creado\r\n");

		//calcula espacio libre en la memoria
		if(f_getfree("", &fre_clust, &pfs) != FR_OK);

		totalSpace = (uint32_t)((pfs->n_fatent - 2) * pfs->csize * 0.5);
		freeSpace = (uint32_t)(fre_clust * pfs->csize * 0.5);

		//mira si si es menor de 1
		if(freeSpace < 1)
       uartx_write_text(&huart1, "Memoria llena\r\n");

		//escribe algo en la memoria
		f_puts("PROBANDO\r\n", &archivo);

		f_puts("FUNCIONANDO\r\n", &archivo);
		f_puts("mas datos\r\n", &archivo);

		//cierra archivo abierto
		if(f_close(&archivo) != FR_OK)
		uartx_write_text(&huart1, "DATOS  GUARDADOS");

		//abre  un archivo para lectura
		if(f_open(&archivo, "ARZ.txt", FA_READ) != FR_OK);

		//LEE LINEA POR LINEA
		uartx_write_text(&huart1, "leido=");
		while(f_gets(SD_BUFFER, sizeof(SD_BUFFER), &archivo))
		{
			sprintf(texto,"%s", SD_BUFFER);
			uartx_write_text(&huart1, texto);
			uartx_write_text(&huart1, "\r\n");
		}

		//cierra el archivo
		if(f_close(&archivo) != FR_OK);

		//si es necesario desmonta la memoria
//		if(f_mount(NULL, "", 1) != FR_OK);


          //  crea el nuevo archivo para almacenar  los dat[s
			f_open(&archivo, "Data.txt", FA_CREATE_ALWAYS | FA_READ | FA_WRITE);
			f_close(&archivo);

			//EN EL WHILE AGREGA LOS DATOS
			 /Abre un archivo sino lo crea
	 	  f_open(&archivo, "Data.txt",FA_OPEN_APPEND | FA_READ | FA_WRITE) ;
     	    HAL_Delay(1);
	  			//escribe algo en la memoria

	  			  f_puts(texto, &archivo);

	  				//cierra archivo abierto
	  				f_close(&archivo);


	  				//SI QUIERE DESMONTAR CON SEGURIDAD
	  				 *
	     //desmonta la memoria
		  f_mount(NULL, "", 1);

 */


#include "main.h"

//definir lo necesario
#define SPI_TIMEOUT 100
extern SPI_HandleTypeDef 	hspi1;
#define HSPI_SDCARD		 	&hspi1
//#define SD_CS_Pin GPIO_PIN_4
//#define SD_CS_GPIO_Port GPIOA





#ifndef __FATFS_SD_H
#define __FATFS_SD_H

/* Definitions for MMC/SDC command */
#define CMD0     (0x40+0)     	/* GO_IDLE_STATE */
#define CMD1     (0x40+1)     	/* SEND_OP_COND */
#define CMD8     (0x40+8)     	/* SEND_IF_COND */
#define CMD9     (0x40+9)     	/* SEND_CSD */
#define CMD10    (0x40+10)    	/* SEND_CID */
#define CMD12    (0x40+12)    	/* STOP_TRANSMISSION */
#define CMD16    (0x40+16)    	/* SET_BLOCKLEN */
#define CMD17    (0x40+17)    	/* READ_SINGLE_BLOCK */
#define CMD18    (0x40+18)    	/* READ_MULTIPLE_BLOCK */
#define CMD23    (0x40+23)    	/* SET_BLOCK_COUNT */
#define CMD24    (0x40+24)    	/* WRITE_BLOCK */
#define CMD25    (0x40+25)    	/* WRITE_MULTIPLE_BLOCK */
#define CMD41    (0x40+41)    	/* SEND_OP_COND (ACMD) */
#define CMD55    (0x40+55)    	/* APP_CMD */
#define CMD58    (0x40+58)    	/* READ_OCR */

/* MMC card type flags (MMC_GET_TYPE) */
#define CT_MMC		0x01		/* MMC ver 3 */
#define CT_SD1		0x02		/* SD ver 1 */
#define CT_SD2		0x04		/* SD ver 2 */
#define CT_SDC		0x06		/* SD */
#define CT_BLOCK	0x08		/* Block addressing */

/* Functions */
DSTATUS SD_disk_initialize (BYTE pdrv);
DSTATUS SD_disk_status (BYTE pdrv);
DRESULT SD_disk_read (BYTE pdrv, BYTE* buff, DWORD sector, UINT count);
DRESULT SD_disk_write (BYTE pdrv, const BYTE* buff, DWORD sector, UINT count);
DRESULT SD_disk_ioctl (BYTE pdrv, BYTE cmd, void* buff);


#endif
