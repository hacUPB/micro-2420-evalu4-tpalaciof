/*
 * Copyright (c) 2016, Freescale Semiconductor, Inc.
 * Copyright 2016-2018 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef _BOARD_H_
#define _BOARD_H_

#include "clock_config.h"
#include "fsl_gpio.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/*! @brief The board name */
#define BOARD_NAME "HVP-KE18F"

/*! @brief The UART to use for debug messages. */
#define BOARD_USE_UART
#define BOARD_DEBUG_UART_TYPE     kSerialPort_Uart
#define BOARD_DEBUG_UART_BASEADDR (uint32_t) LPUART2
#define BOARD_DEBUG_UART_INSTANCE 2U
#define BOARD_DEBUG_UART_CLKSRC   kCLOCK_ScgSysPllAsyncDiv2Clk
#define BOARD_DEBUG_UART_CLK_FREQ CLOCK_GetIpFreq(kCLOCK_Lpuart2)

#ifndef BOARD_DEBUG_UART_BAUDRATE
#define BOARD_DEBUG_UART_BAUDRATE 115200
#endif /* BOARD_DEBUG_UART_BAUDRATE */

/* Board led color mapping */
#define LOGIC_LED_ON  0U
#define LOGIC_LED_OFF 1U
#ifndef BOARD_LED_RED_GPIO
#define BOARD_LED_RED_GPIO GPIOE
#endif
#define BOARD_LED_RED_GPIO_PORT PORTE
#ifndef BOARD_LED_RED_GPIO_PIN
#define BOARD_LED_RED_GPIO_PIN 9U
#endif
#ifndef BOARD_LED_GREEN_GPIO
#define BOARD_LED_GREEN_GPIO GPIOE
#endif
#define BOARD_LED_GREEN_GPIO_PORT PORTE
#ifndef BOARD_LED_GREEN_GPIO_PIN
#define BOARD_LED_GREEN_GPIO_PIN 6U
#endif

#define LED_RED_INIT(output)                                           \
    GPIO_PinWrite(BOARD_LED_RED_GPIO, BOARD_LED_RED_GPIO_PIN, output); \
    BOARD_LED_RED_GPIO->PDDR |= (1U << BOARD_LED_RED_GPIO_PIN)                         /*!< Enable target LED_RED */
#define LED_RED_ON()  GPIO_PortClear(BOARD_LED_RED_GPIO, 1U << BOARD_LED_RED_GPIO_PIN) /*!< Turn on target LED_RED */
#define LED_RED_OFF() GPIO_PortSet(BOARD_LED_RED_GPIO, 1U << BOARD_LED_RED_GPIO_PIN)   /*!< Turn off target LED_RED */
#define LED_RED_TOGGLE() \
    GPIO_PortToggle(BOARD_LED_RED_GPIO, 1U << BOARD_LED_RED_GPIO_PIN) /*!< Toggle on target LED_RED */

#define LED_GREEN_INIT(output)                                             \
    GPIO_PinWrite(BOARD_LED_GREEN_GPIO, BOARD_LED_GREEN_GPIO_PIN, output); \
    BOARD_LED_GREEN_GPIO->PDDR |= (1U << BOARD_LED_GREEN_GPIO_PIN) /*!< Enable target LED_GREEN */
#define LED_GREEN_ON() \
    GPIO_PortClear(BOARD_LED_GREEN_GPIO, 1U << BOARD_LED_GREEN_GPIO_PIN) /*!< Turn on target LED_GREEN */
#define LED_GREEN_OFF() \
    GPIO_PortSet(BOARD_LED_GREEN_GPIO, 1U << BOARD_LED_GREEN_GPIO_PIN) /*!< Turn off target LED_GREEN */
#define LED_GREEN_TOGGLE() \
    GPIO_PortToggle(BOARD_LED_GREEN_GPIO, 1U << BOARD_LED_GREEN_GPIO_PIN) /*!< Toggle on target LED_GREEN */

#if defined(__cplusplus)
extern "C" {
#endif /* __cplusplus */

/*******************************************************************************
 * API
 ******************************************************************************/

void BOARD_InitDebugConsole(void);

#if defined(__cplusplus)
}
#endif /* __cplusplus */

#endif /* _BOARD_H_ */
