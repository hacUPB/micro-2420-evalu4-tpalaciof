#include <stdint.h>

#ifndef LOW_H
#define LOW_H

void lcd_send_command(int b7, int b6, int b5, int b4, int b3, int b2, int b1, int b0);
void lcd_send_data(int b7, int b6, int b5, int b4, int b3, int b2, int b1, int b0);

#endif // LOW_H
