#ifndef _PIN_MUX_H_
#define _PIN_MUX_H_

#if defined(__cplusplus)
extern "C" {
#endif

void BOARD_InitBootPins(void);

//---------------------------------------TECLADO-----------------------------------------//
#define BOARD_INITPINS_LED_RED_GPIO GPIOE
#define BOARD_INITPINS_LED_RED_PORT PORTE

//LED
#define BOARD_INITPINS_LED_RED_PIN 2U	//E2

//FILAS ---> SALIDAS
#define BOARD_INITPINS_FIL1_PIN 3U		//E3
#define BOARD_INITPINS_FIL2_PIN 4U		//E4
#define BOARD_INITPINS_FIL3_PIN 5U
#define BOARD_INITPINS_FIL4_PIN 6U

// COLUMNAS --> ENTRADAS
#define BOARD_INITPINS_COL1_PIN 9U		//E9
#define BOARD_INITPINS_COL2_PIN 10U		//E10
#define BOARD_INITPINS_COL3_PIN 11U
#define BOARD_INITPINS_COL4_PIN 12U

//-----------------------------------------LCD-------------------------------------------//
// Pines Datos 8 bits
#define GPIO_DATA_GPIOD GPIOD
#define PORT_DATA_GPIOD PORTD

#define BOARD_INITPINS_LCD_DB0	10U //PTD10
#define BOARD_INITPINS_LCD_DB1	11U //PTD11
#define BOARD_INITPINS_LCD_DB2	12U //PTD12
#define BOARD_INITPINS_LCD_DB3	13U //PTD13
#define BOARD_INITPINS_LCD_DB4	14U //PTD14
#define BOARD_INITPINS_LCD_DB5	15U //PTD15
#define BOARD_INITPINS_LCD_DB6	16U //PTD16
#define BOARD_INITPINS_LCD_DB7	17U //PTD17

// R/W
#define BOARD_INITPINS_LCD_RW	6U //PTD6

//E
#define EN_PIN	7U //PTD7

// Pines CSX
#define BOARD_INITPINS_GPIOA GPIOA
#define BOARD_INITPINS_PORTA PORTA

#define BOARD_INITPINS_LCD_CS2	3U //PTA3
#define BOARD_INITPINS_LCD_CS1	2U //PTA2

// RST
#define BOARD_INITPINS_LCD_RST	6U //PTA6


// RS/DI
#define BOARD_INITPINS_GPIOC GPIOC
#define BOARD_INITPINS_PORTC PORTC

#define RS_PIN	15U //PTC15



void BOARD_InitPins(void);

#if defined(__cplusplus)
}
#endif
#endif
