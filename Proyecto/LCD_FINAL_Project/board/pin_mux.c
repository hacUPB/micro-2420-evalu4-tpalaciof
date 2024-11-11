#include "fsl_common.h"
#include "fsl_port.h"
#include "fsl_gpio.h"
#include "pin_mux.h"

void BOARD_InitPins(void)
{
	/*--------------------------------------- CLOCKS --------------------------------------*/
    CLOCK_EnableClock(kCLOCK_PortA);
    CLOCK_EnableClock(kCLOCK_PortE);
    CLOCK_EnableClock(kCLOCK_PortD);
    CLOCK_EnableClock(kCLOCK_PortC);

    /*--------------------------------------- GPIO --------------------------------------*/
    gpio_pin_config_t Salida_config = {
        .pinDirection = kGPIO_DigitalOutput,
        .outputLogic = 0U
    };

    gpio_pin_config_t Entrada_config = {
         .pinDirection = kGPIO_DigitalInput,
		 .outputLogic = 0U
    };

    /********************** TECLADO *******************/
    // Initialize GPIO LED
    GPIO_PinInit(BOARD_INITPINS_LED_RED_GPIO, BOARD_INITPINS_LED_RED_PIN, &Salida_config);

    // GPIO Filas ---> Salidas
    GPIO_PinInit(BOARD_INITPINS_LED_RED_GPIO, BOARD_INITPINS_FIL1_PIN, &Salida_config);
    GPIO_PinInit(BOARD_INITPINS_LED_RED_GPIO, BOARD_INITPINS_FIL2_PIN, &Salida_config);
    GPIO_PinInit(BOARD_INITPINS_LED_RED_GPIO, BOARD_INITPINS_FIL3_PIN, &Salida_config);
    GPIO_PinInit(BOARD_INITPINS_LED_RED_GPIO, BOARD_INITPINS_FIL4_PIN, &Salida_config);

    // GPIO Columnas ---> Entradas
    GPIO_PinInit(BOARD_INITPINS_LED_RED_GPIO, BOARD_INITPINS_COL1_PIN, &Entrada_config);
    GPIO_PinInit(BOARD_INITPINS_LED_RED_GPIO, BOARD_INITPINS_COL2_PIN, &Entrada_config);
    GPIO_PinInit(BOARD_INITPINS_LED_RED_GPIO, BOARD_INITPINS_COL3_PIN, &Entrada_config);
    GPIO_PinInit(BOARD_INITPINS_LED_RED_GPIO, BOARD_INITPINS_COL4_PIN, &Entrada_config);

    /********************** LCD *******************/
    // GPIO DATOS
    GPIO_PinInit(GPIO_DATA_GPIOD, BOARD_INITPINS_LCD_DB0, &Salida_config);
    GPIO_PinInit(GPIO_DATA_GPIOD, BOARD_INITPINS_LCD_DB1, &Salida_config);
    GPIO_PinInit(GPIO_DATA_GPIOD, BOARD_INITPINS_LCD_DB2, &Salida_config);
    GPIO_PinInit(GPIO_DATA_GPIOD, BOARD_INITPINS_LCD_DB3, &Salida_config);
    GPIO_PinInit(GPIO_DATA_GPIOD, BOARD_INITPINS_LCD_DB4, &Salida_config);
    GPIO_PinInit(GPIO_DATA_GPIOD, BOARD_INITPINS_LCD_DB5, &Salida_config);
    GPIO_PinInit(GPIO_DATA_GPIOD, BOARD_INITPINS_LCD_DB6, &Salida_config);
    GPIO_PinInit(GPIO_DATA_GPIOD, BOARD_INITPINS_LCD_DB7, &Salida_config);

    // GPIO R/W
    GPIO_PinInit(GPIO_DATA_GPIOD, BOARD_INITPINS_LCD_RW, &Salida_config);

    // GPIO E
    GPIO_PinInit(GPIO_DATA_GPIOD, EN_PIN, &Salida_config);

    // GPIO CSX
    GPIO_PinInit(BOARD_INITPINS_GPIOA, BOARD_INITPINS_LCD_CS2, &Salida_config);
    GPIO_PinInit(BOARD_INITPINS_GPIOA, BOARD_INITPINS_LCD_CS1, &Salida_config);

    // GPIO RST
    GPIO_PinInit(BOARD_INITPINS_GPIOA, BOARD_INITPINS_LCD_RST, &Salida_config);

    // GPIO RS
    GPIO_PinInit(BOARD_INITPINS_GPIOC, RS_PIN, &Salida_config);

    /*--------------------------------------- MUX --------------------------------------*/
    /********************** TECLADO *******************/
    // MUX LED
    PORT_SetPinMux(BOARD_INITPINS_LED_RED_PORT, BOARD_INITPINS_LED_RED_PIN, kPORT_MuxAsGpio);

    // MUX Filas
    PORT_SetPinMux(BOARD_INITPINS_LED_RED_PORT, BOARD_INITPINS_FIL1_PIN, kPORT_MuxAsGpio);
    PORT_SetPinMux(BOARD_INITPINS_LED_RED_PORT, BOARD_INITPINS_FIL2_PIN, kPORT_MuxAsGpio);
    PORT_SetPinMux(BOARD_INITPINS_LED_RED_PORT, BOARD_INITPINS_FIL3_PIN, kPORT_MuxAsGpio);
    PORT_SetPinMux(BOARD_INITPINS_LED_RED_PORT, BOARD_INITPINS_FIL4_PIN, kPORT_MuxAsGpio);

    // MUX Columnas
    PORT_SetPinMux(BOARD_INITPINS_LED_RED_PORT, BOARD_INITPINS_COL1_PIN, kPORT_MuxAsGpio);
    PORT_SetPinMux(BOARD_INITPINS_LED_RED_PORT, BOARD_INITPINS_COL2_PIN, kPORT_MuxAsGpio);
    PORT_SetPinMux(BOARD_INITPINS_LED_RED_PORT, BOARD_INITPINS_COL3_PIN, kPORT_MuxAsGpio);
    PORT_SetPinMux(BOARD_INITPINS_LED_RED_PORT, BOARD_INITPINS_COL4_PIN, kPORT_MuxAsGpio);

    /********************** LCD *******************/
    //MUX DATOS
    PORT_SetPinMux(PORT_DATA_GPIOD, BOARD_INITPINS_LCD_DB0, kPORT_MuxAsGpio);
    PORT_SetPinMux(PORT_DATA_GPIOD, BOARD_INITPINS_LCD_DB1, kPORT_MuxAsGpio);
    PORT_SetPinMux(PORT_DATA_GPIOD, BOARD_INITPINS_LCD_DB2, kPORT_MuxAsGpio);
    PORT_SetPinMux(PORT_DATA_GPIOD, BOARD_INITPINS_LCD_DB3, kPORT_MuxAsGpio);
    PORT_SetPinMux(PORT_DATA_GPIOD, BOARD_INITPINS_LCD_DB4, kPORT_MuxAsGpio);
    PORT_SetPinMux(PORT_DATA_GPIOD, BOARD_INITPINS_LCD_DB5, kPORT_MuxAsGpio);
    PORT_SetPinMux(PORT_DATA_GPIOD, BOARD_INITPINS_LCD_DB6, kPORT_MuxAsGpio);
    PORT_SetPinMux(PORT_DATA_GPIOD, BOARD_INITPINS_LCD_DB7, kPORT_MuxAsGpio);

    //MUX R/W
    PORT_SetPinMux(PORT_DATA_GPIOD, BOARD_INITPINS_LCD_RW, kPORT_MuxAsGpio);

    //MUX E
    PORT_SetPinMux(PORT_DATA_GPIOD, EN_PIN, kPORT_MuxAsGpio);

    //MUX CSX
    PORT_SetPinMux(BOARD_INITPINS_PORTA, BOARD_INITPINS_LCD_CS2, kPORT_MuxAsGpio);
    PORT_SetPinMux(BOARD_INITPINS_PORTA, BOARD_INITPINS_LCD_CS1, kPORT_MuxAsGpio);

    //MUX RST
    PORT_SetPinMux(BOARD_INITPINS_PORTA, BOARD_INITPINS_LCD_RST, kPORT_MuxAsGpio);

    //MUX RS
    PORT_SetPinMux(BOARD_INITPINS_PORTC, RS_PIN, kPORT_MuxAsGpio);

    /*----------------------------------- PULL-UP --------------------------------------*/
    PORTE->PCR[9] = ((PORTE->PCR[9] &
                           /* Mask bits to zero which are setting */
                           (~(PORT_PCR_PS_MASK | PORT_PCR_PE_MASK | PORT_PCR_ISF_MASK)))

                          /* Pull Select: Internal pulldown resistor is enabled on the corresponding pin, if the
                           * corresponding PE field is set. */
                          | PORT_PCR_PS(kPORT_PullUp)

                          /* Pull Enable: Internal pullup or pulldown resistor is not enabled on the corresponding
                           * pin. */
						  | PORT_PCR_PE(kPORT_PullUp  ));



    PORTE->PCR[10] = ((PORTE->PCR[10] &
                               /* Mask bits to zero which are setting */
                               (~(PORT_PCR_PS_MASK | PORT_PCR_PE_MASK | PORT_PCR_ISF_MASK)))

                              /* Pull Select: Internal pulldown resistor is enabled on the corresponding pin, if the
                               * corresponding PE field is set. */
                              | PORT_PCR_PS(kPORT_PullUp)

                              /* Pull Enable: Internal pullup or pulldown resistor is not enabled on the corresponding
                               * pin. */
							  | PORT_PCR_PE(kPORT_PullUp  ));

    PORTE->PCR[11] = ((PORTE->PCR[11] &
                                   /* Mask bits to zero which are setting */
                                   (~(PORT_PCR_PS_MASK | PORT_PCR_PE_MASK | PORT_PCR_ISF_MASK)))

                                  /* Pull Select: Internal pulldown resistor is enabled on the corresponding pin, if the
                                   * corresponding PE field is set. */
                                  | PORT_PCR_PS(kPORT_PullUp)

                                  /* Pull Enable: Internal pullup or pulldown resistor is not enabled on the corresponding
                                   * pin. */
								  | PORT_PCR_PE(kPORT_PullUp  ));


    PORTE->PCR[12] = ((PORTE->PCR[12] &
                                   /* Mask bits to zero which are setting */
                                   (~(PORT_PCR_PS_MASK | PORT_PCR_PE_MASK | PORT_PCR_ISF_MASK)))

                                  /* Pull Select: Internal pulldown resistor is enabled on the corresponding pin, if the
                                   * corresponding PE field is set. */
                                  | PORT_PCR_PS(kPORT_PullUp)

                                  /* Pull Enable: Internal pullup or pulldown resistor is not enabled on the corresponding
                                   * pin. */
                                  | PORT_PCR_PE(kPORT_PullUp  ));
}
