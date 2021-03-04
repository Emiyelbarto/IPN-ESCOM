//LCD Module Connections
#define LCD_RS_PIN PIN_D1
#define LCD_RW_PIN PIN_D2
#define LCD_ENABLE_PIN PIN_D3
#define LCD_DATA4 PIN_D4
#define LCD_DATA5 PIN_D5
#define LCD_DATA6 PIN_D6
#define LCD_DATA7 PIN_D7
//End LCD Module Connections

#include <main.h>
#include <lcd.c>

#use delay (clock=8000000)

void main()
{
  int i=0;

  lcd_init();
  Delay_ms(100);

  while(TRUE)
  {
    lcd_putc('\\f');                   //Clear Display
    lcd_putc("Hello World");
    Delay_ms(2000);
    lcd_putc('\\f');                   //Clear Display
    lcd_putc("Welcome To");
    lcd_gotoxy(1,2);
    lcd_putc("LCD Library");
    Delay_ms(2000);
    lcd_putc('\\f');                   //Clear Display
    printf(lcd_putc,"Count = %d", i); //Display Count
    Delay_ms(2000);
    i++;
  }
}