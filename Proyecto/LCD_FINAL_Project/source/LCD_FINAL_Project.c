#include "board.h"
#include "pin_mux.h"
#include "clock_config.h"
#include <stdio.h>
#include "API.h"
#include "HAL.h"
#include "LOW_LEVEL.h"


/***************************
 * Definitions
 **************************/
#define BOARD_LED_GPIO     BOARD_INITPINS_LED_RED_GPIO // GPIOE

// LED ---> Salida
#define BOARD_LED_GPIO_PIN BOARD_INITPINS_LED_RED_PIN  // E2
// Filas ---> Salidas
#define BOARD_FIL1_GPIO_PIN BOARD_INITPINS_FIL1_PIN    // E3
#define BOARD_FIL2_GPIO_PIN BOARD_INITPINS_FIL2_PIN    // E4
#define BOARD_FIL3_GPIO_PIN BOARD_INITPINS_FIL3_PIN    // E5
#define BOARD_FIL4_GPIO_PIN BOARD_INITPINS_FIL4_PIN    // E6

// Columnas ---> Entradas
#define BOARD_COL1_GPIO_PIN BOARD_INITPINS_COL1_PIN    // E9
#define BOARD_COL2_GPIO_PIN BOARD_INITPINS_COL2_PIN    // E10
#define BOARD_COL3_GPIO_PIN BOARD_INITPINS_COL3_PIN    // E11
#define BOARD_COL4_GPIO_PIN BOARD_INITPINS_COL4_PIN    // E12

//Estados
int col = 0, fil = 0;
int cont = 1;
int DutyCycle, Dmax,Ton,Toff;
int NUM, DEC;
int check_col1, check_col2, check_col3, check_col4;

enum Estados {INICIO, PWM, DUTYCYCLE};

/***************************
 * Variables
 **************************/

int main(void) {
    BOARD_InitPins();
    BOARD_InitBootClocks();
    lcd_init();


    while(1){

    	//lcd_send_command(1,0,1,1,1,0,0,0);
    	//lcd_send_command(0,1,0,0,0,0,0,0);
    	lcd_send_command(0,0,1,1,1,1,1,0);
    }
    /* Set systick reload value to generate interrupt */
    if (SysTick_Config(SystemCoreClock / 100000U))
    {
    	while (1){}
    }

    return 0 ;
}
