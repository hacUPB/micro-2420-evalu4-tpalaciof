
#ifndef API_H
#define API_H

#include <stdint.h>

void lcd_init(void);
void Comleft(void);
void Comright(void);


void lcd_clear(void);
void lcd_set_cursor(uint8_t row, uint8_t col);
void lcd_print(const char *str);

#endif // API_H
