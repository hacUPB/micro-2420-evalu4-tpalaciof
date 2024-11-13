#include "API.h"
#include "HAL.h"
#include "LOW_LEVEL.h"

#include "pin_mux.h"
#include <stdint.h>
#include "fsl_gpio.h"
#include "fsl_common.h"

/*
void lcd_init(void)

{
	HAL_Delay(3e+7); //Delay de inicialización
	lcd_send_command(0,0,1,1,0,0,0,0);

	HAL_Delay(1e+7);
	lcd_send_command(0,0,1,1,0,0,0,0);

	HAL_Delay(300000);
	lcd_send_command(0,0,1,1,0,0,0,0);

	lcd_send_command(0,0,1,1,1,0,0,0);

	lcd_send_command(0,0,0,0,1,0,0,0);

	lcd_send_command(0,0,0,0,0,0,0,1);

	lcd_send_command(0,0,0,0,0,1,1,0);


	HAL_Delay(100000);

	lcd_clear();

}

void lcd_clear(void) {
	lcd_send_command(0,0,0,0,0,0,0,1);
    HAL_Delay(2);
}

void lcd_set_cursor(uint8_t row, uint8_t col) {
    //uint8_t address = (row == 0) ? col : (0x40 + col);
    //lcd_send_command(0x80 | address);
}

void lcd_print(const char *str) {	//Imprime cadena
    while (*str) {
        //lcd_send_data(*str++);
    }
}
*/

void lcd_init(void) {
    // Inicialización
    // P3.2 = 0	--> 0 en RST
    HAL_GPIO_WritePin(GPIO_DATA_GPIOD,BOARD_INITPINS_LCD_RST, 0);
    HAL_Delay(1000);
    // P3.2 = 1 --> 1 en RST
    HAL_GPIO_WritePin(GPIO_DATA_GPIOD,BOARD_INITPINS_LCD_RST, 1);
    HAL_Delay(1000);
    // P3.4 = 0 --> 0 en Enable
    HAL_GPIO_WritePin(GPIO_DATA_GPIOD,EN_PIN, 0);
    HAL_Delay(1000);
    // P3.0 = 0 --> 0 en RS/DI
    HAL_GPIO_WritePin(BOARD_INITPINS_GPIOC,RS_PIN, 0);
    HAL_Delay(1000);
    // P3.7 = 0 --> 0 en RW
    HAL_GPIO_WritePin(GPIO_DATA_GPIOD,BOARD_INITPINS_LCD_RW, 0);
    HAL_Delay(1000);
    // P3.6 = 0 --> 0 en CS2
    HAL_GPIO_WritePin(BOARD_INITPINS_GPIOA,BOARD_INITPINS_LCD_CS2, 0);
    HAL_Delay(1000);
    // P3.1 = 0 --> 0 en CS1
    HAL_GPIO_WritePin(BOARD_INITPINS_GPIOA,BOARD_INITPINS_LCD_CS1, 0);
    HAL_Delay(1000);


    Comleft();      // display on
    Comright();     // display on
}

void Comleft(void) {
	lcd_send_command(0,0,1,1,1,1,1,1);
	HAL_Delay(1000);
    //Set P3.6 --> 1 en CS2
    HAL_GPIO_WritePin(BOARD_INITPINS_GPIOA,BOARD_INITPINS_LCD_CS2, 1);
    HAL_Delay(1000);
    // P3.0 = 0 --> 0 en RS/DI
    HAL_GPIO_WritePin(BOARD_INITPINS_GPIOC,RS_PIN, 0);
    HAL_Delay(1000);
    // P3.4 = 1 --> 1 en E
    HAL_GPIO_WritePin(GPIO_DATA_GPIOD,EN_PIN, 1);
    HAL_Delay(1000);
    // P3.4 = 0 --> 0 en E
    HAL_GPIO_WritePin(GPIO_DATA_GPIOD,EN_PIN, 0);
    HAL_Delay(1000);
    //Reset P3.6 --> 0 en CS2
    HAL_GPIO_WritePin(BOARD_INITPINS_GPIOA,BOARD_INITPINS_LCD_CS2, 0);
    HAL_Delay(1000);
}

void Comright(void) {
	lcd_send_command(0,0,1,1,1,1,1,1);
	HAL_Delay(1000);
	//Set P3.1 --> 1 en CS1
	HAL_GPIO_WritePin(BOARD_INITPINS_GPIOA,BOARD_INITPINS_LCD_CS1, 1);
	HAL_Delay(1000);
    // P3.0 = 0 --> 0 en RS/DI
	HAL_GPIO_WritePin(BOARD_INITPINS_GPIOC,RS_PIN, 0);
	HAL_Delay(1000);
	// P3.4 = 1 --> 1 en E
	HAL_GPIO_WritePin(GPIO_DATA_GPIOD,EN_PIN, 1);
	HAL_Delay(1000);
	// P3.4 = 0 --> 0 en E
	HAL_GPIO_WritePin(GPIO_DATA_GPIOD,EN_PIN, 0);
	HAL_Delay(1000);
	//Reset P3.1 --> 0 en CS1
	HAL_GPIO_WritePin(BOARD_INITPINS_GPIOA,BOARD_INITPINS_LCD_CS1, 0);
	HAL_Delay(1000);
}


