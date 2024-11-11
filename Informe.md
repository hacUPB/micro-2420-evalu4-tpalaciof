# Informe 

Lo primero que se llevó a cabo para la realización del proyecto, fue la conexión física del LCD con el microprocesador. Para esto, se siguió la gráfica proporcionada por la hoja de datos de la pantalla asignada: 
![alt text](image.png)

Para el contraste de nuestro LCD: 
![alt text](image-2.png)
donde a partir de la conexión de un potenciometro, se variaba el contraste de la pantalla 

Esto, tristemente, no resultó como se esperaba, pues aunque se logró inicialmente cambiar el contraste de la pantalla (muy brevemente, y al colocar un potenciometro de 500K ohm, no de 10k ohm como se ilustraba) luego, empezaría a echar humo el potenciometro, dando como resultado que jamás volviera a cambiar el contraste en el LCD, ni con otro potenciómetro. 

Pese a las dificultades, se continúo con la ejecución de la programación del código. 

Primero, seinicializaron los pines (todos de salida) y se nombraron y llamaron, en el archivo pin_mux, .c y .h respectivamente, ambos archivos dentro de la rama board del proyecto: 

pin_mux.c: 
![alt text](image-3.png)

pin_mux.h 
![alt text](image-4.png)

Para el código de nuestro proyecto, se implementaron 3 tipos de archivos (con su respectivo .c para crear las funciones y su .h para llamar a las funciones creadas) según el nivel de abstracción que se cumplían dentro del proyecto. Estos archivos fueron el API, HAL y LOW_LEVEL: mayor nivel, mediano nivel, y más bajo nivel de abstracción respectivamente. 

Mi archivo HAL contaba con unas de las funciones más primordiales para el funcionamiento del proyecto, estas son, especialmente: HAL_GPIO_WritePin, para escribir en los pines especificados el valor deseado (cero o uno) y el Delay. 

![alt text](image-5.png)
![alt text](image-6.png)

El delay contaba con una entrada especificada por uno mismo en nanosegundos, y su funcionamiento consistía en hacer un ciclo for en el que se ejecutara una función de assembler de "no hacer nada": asm("nop"). 
Este ciclo for dura lo que se especifíque en nanosegundos en la entrada, y para poder lograr esto, se averiguó la frecuencia del reloj del microcontrolador: 168Mhz, y se hizo una pequeña ley de 3 para convertir esta medida en nanosegundos. 
Tambien, el HAL cuenta con otras funciones, como *HAL_GPIO_OutputConfig* para configurar el pin especificado como de salida o de entrada. Y 2 funciones generales, para poner todos los pines que eran necesarios como salida o como entrada, sin la necesidad de recurrir a llamar una y otra vez esta función anterior. Estas funciones fueron: 
![alt text](image-7.png)

Mi LOW_LEVEL, contaba con 2 funciones primordiales: la de enviar datos y enviar comandos al LCD, ambas muy similares, con la única diferencia del valor del RS que se utilizaba.

![alt text](image-8.png)
![alt text](image-9.png)
Para el correcto funcionamiento de ambas funciones, su imlementación se basó acorde a lo estipulado en el diagrama de tiempos del manual del LCD

![alt text](image-10.png)

Por último, el archivo de más alto nivel, el API, donde se implementó la función de inicialización general del LCD, utilizando tanto funciones de la HAL como del LOW_LEVEL para su implementación:

```c
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

```

Esta implementación se basó estrictamente en el pseudocódigo propuesto por el manual del LCD: 
![alt text](image-11.png)

Como no se indicaban los tiempos, y fruto de muchos intentos con distintos valores, tomé la decisión arbitraria, de establecer un delay bastabte alto entre cada función, y así no pecar de que alguna necesitara más tiempo. 

