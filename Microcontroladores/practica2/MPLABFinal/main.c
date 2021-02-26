/*
 * File:   main.c
 * Author: emime
 *
 * Created on December 2, 2020, 2:07 PM
 */

// Conexiones para multimetro
#define DC_INPUT RA0
#define AC_INPUT RA1
#define TEMP_INPUT RA2
// Conexiones para multimetro
// Conexiones para switches
#define SWITCH_A RB0
#define SWITCH_B RB1
#define SWITCH_C RB2
// Conexiones para switches

#include <xc.h>              // Libreria para pmlabx
#include <stdio.h>
#include <string.h> 
#include <pic16f887.h>       // Libreria para el PIC
#include "lcd.h"                 /* Header File for LCD Functions */
//#include "config.h"          /* Archivo de configuracion */
//#include "pic.h"

int main()
{
  unsigned int a;
  TRISD = 0x00;
  Lcd_Init();
  while(1)
  {
    Lcd_Clear();
    Lcd_Set_Cursor(1,1);
    Lcd_Write_String("LCD Library for");
    Lcd_Set_Cursor(2,1);
    Lcd_Write_String("MPLAB XC8");
    __delay_ms(2000);
    Lcd_Clear();
    Lcd_Set_Cursor(1,1);
    Lcd_Write_String("Developed By");
    Lcd_Set_Cursor(2,1);
    Lcd_Write_String("electroSome");
    __delay_ms(2000);
    Lcd_Clear();
    Lcd_Set_Cursor(1,1);
    Lcd_Write_String("www.electroSome.com");

    for(a=0;a<15;a++)
    {
        __delay_ms(300);
        Lcd_Shift_Left();
    }

    for(a=0;a<15;a++)
    {
        __delay_ms(300);
        Lcd_Shift_Right();
    }

    Lcd_Clear();
    Lcd_Set_Cursor(2,1);
    Lcd_Write_Char('e');
    Lcd_Write_Char('S');
    __delay_ms(2000);
  }
  return 0;
}