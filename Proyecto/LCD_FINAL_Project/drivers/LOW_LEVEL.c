#include "API.h"
#include "HAL.h"
#include "LOW_LEVEL.h"

#include <stdint.h>
#include "pin_mux.h"

//#include "clock_config.h"

/***************************
 * Code
 **************************/

void lcd_send_command(int b7, int b6, int b5, int b4, int b3, int b2, int b1, int b0) {

	HAL_GPIO_WritePin(GPIO_DATA_GPIOD,EN_PIN, 1); // E = 1

	HAL_GPIO_WritePin(GPIO_DATA_GPIOD,BOARD_INITPINS_LCD_RW, 1);  // Modo Lectura
    HAL_GPIO_WritePin(BOARD_INITPINS_GPIOC,RS_PIN, 1);  // Modo dato

    HAL_Delay(500);	//Twl
    HAL_GPIO_WritePin(GPIO_DATA_GPIOD,EN_PIN, 0); // E = 0
    HAL_Delay(500);	//Twl

    HAL_GPIO_WritePin(GPIO_DATA_GPIOD,BOARD_INITPINS_LCD_RW, 0);  // Modo Escritura
    HAL_GPIO_WritePin(BOARD_INITPINS_GPIOC,RS_PIN, 0);  // Modo comando

    HAL_Delay(200);	//Tasu
    HAL_GPIO_WritePin(GPIO_DATA_GPIOD,EN_PIN, 1); // E = 1
    HAL_Delay(500);	//TWH

    DATA_OUTPUT();
    HAL_GPIO_WritePin(GPIO_DATA_GPIOD,BOARD_INITPINS_LCD_DB0, b0);
    HAL_GPIO_WritePin(GPIO_DATA_GPIOD,BOARD_INITPINS_LCD_DB1, b1);
    HAL_GPIO_WritePin(GPIO_DATA_GPIOD,BOARD_INITPINS_LCD_DB2, b2);
    HAL_GPIO_WritePin(GPIO_DATA_GPIOD,BOARD_INITPINS_LCD_DB3, b3);
    HAL_GPIO_WritePin(GPIO_DATA_GPIOD,BOARD_INITPINS_LCD_DB4, b4);
    HAL_GPIO_WritePin(GPIO_DATA_GPIOD,BOARD_INITPINS_LCD_DB5, b5);
    HAL_GPIO_WritePin(GPIO_DATA_GPIOD,BOARD_INITPINS_LCD_DB6, b6);
    HAL_GPIO_WritePin(GPIO_DATA_GPIOD,BOARD_INITPINS_LCD_DB7, b7);

    HAL_Delay(250);	//TDSU
    HAL_GPIO_WritePin(GPIO_DATA_GPIOD,EN_PIN, 0); // E = 0
    HAL_Delay(50);  //TDHW
    HAL_GPIO_WritePin(BOARD_INITPINS_GPIOC,RS_PIN, 1);
    HAL_GPIO_WritePin(GPIO_DATA_GPIOD,BOARD_INITPINS_LCD_RW, 1);
    DATA_INPUT();
    HAL_Delay(1000); // T_CYCLE
}

void lcd_send_data(int b7, int b6, int b5, int b4, int b3, int b2, int b1, int b0) {

	HAL_GPIO_WritePin(GPIO_DATA_GPIOD,EN_PIN, 1); // E = 1

	HAL_GPIO_WritePin(GPIO_DATA_GPIOD,BOARD_INITPINS_LCD_RW, 1);  // Modo Lectura
	HAL_GPIO_WritePin(BOARD_INITPINS_GPIOC,RS_PIN, 0);  // Modo comando

	HAL_Delay(500);	//Twl


	HAL_GPIO_WritePin(GPIO_DATA_GPIOD,EN_PIN, 0); // E = 0
	HAL_Delay(500);	//Twl

	HAL_GPIO_WritePin(GPIO_DATA_GPIOD,BOARD_INITPINS_LCD_RW, 0);  // Modo Escritura
	HAL_GPIO_WritePin(BOARD_INITPINS_GPIOC,RS_PIN, 1);  // Modo dato
	HAL_Delay(200);	//Tasu

	HAL_GPIO_WritePin(GPIO_DATA_GPIOD,EN_PIN, 1); // E = 1
	HAL_Delay(500);	//TWH

	DATA_OUTPUT();
	HAL_GPIO_WritePin(GPIO_DATA_GPIOD,BOARD_INITPINS_LCD_DB0, b0);
	HAL_GPIO_WritePin(GPIO_DATA_GPIOD,BOARD_INITPINS_LCD_DB1, b1);
	HAL_GPIO_WritePin(GPIO_DATA_GPIOD,BOARD_INITPINS_LCD_DB2, b2);
	HAL_GPIO_WritePin(GPIO_DATA_GPIOD,BOARD_INITPINS_LCD_DB3, b3);
    HAL_GPIO_WritePin(GPIO_DATA_GPIOD,BOARD_INITPINS_LCD_DB4, b4);
	HAL_GPIO_WritePin(GPIO_DATA_GPIOD,BOARD_INITPINS_LCD_DB5, b5);
	HAL_GPIO_WritePin(GPIO_DATA_GPIOD,BOARD_INITPINS_LCD_DB6, b6);
	HAL_GPIO_WritePin(GPIO_DATA_GPIOD,BOARD_INITPINS_LCD_DB7, b7);

	HAL_Delay(250);	//TDSU
	HAL_GPIO_WritePin(GPIO_DATA_GPIOD,EN_PIN, 0); // E = 0
	HAL_Delay(50);  //TDHW
	HAL_GPIO_WritePin(BOARD_INITPINS_GPIOC,RS_PIN, 1);
	HAL_GPIO_WritePin(GPIO_DATA_GPIOD,BOARD_INITPINS_LCD_RW, 1);
	DATA_INPUT();
	HAL_Delay(1000); // T_CYCLE
}
