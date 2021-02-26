/*
 * File:   config.c
 * Author: emime
 *
 * Created on December 2, 2020, 11:30 PM
 */
#define _XTAL_FREQ 8000000 //Frecuencia a la cual ira el LCD

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

#include <xc.h>
#include <stdio.h>
#include "lcd.h"
#include "config.h"
#include <htc.h>
#include <math.h>

int ADRES;

void printMenu() {
    Lcd_Clear();
    Lcd_Set_Cursor(1, 1);
    Lcd_Write_String("Elegir opcion:");
    Lcd_Set_Cursor(2, 1);
    Lcd_Write_String("1:DC 2:AC 3:Temp");
    __delay_ms(200);
}

void seleccionarMultimetroDC() {
    Lcd_Clear();
    Lcd_Set_Cursor(1, 1);
    Lcd_Write_String("Opcion Elegida:");
    Lcd_Set_Cursor(2, 1);
    Lcd_Write_String("Multimetro DC:");
    __delay_ms(200);
}

void seleccionarMultimetroAC() {
    Lcd_Clear();
    Lcd_Set_Cursor(1, 1);
    Lcd_Write_String("Opcion Elegida:");
    Lcd_Set_Cursor(2, 1);
    Lcd_Write_String("Multimetro AC:");
    __delay_ms(200);
}

void seleccionarTemperatura() {
    Lcd_Clear();
    Lcd_Set_Cursor(1, 1);
    Lcd_Write_String("Opcion Elegida:");
    Lcd_Set_Cursor(2, 1);
    Lcd_Write_String("Multimetro AC:");
    __delay_ms(200);

}

void mostrarError() {
    Lcd_Clear();
    Lcd_Set_Cursor(1, 1);
    Lcd_Write_String("Error Seleccion");
    Lcd_Set_Cursor(2, 1);
    Lcd_Write_String("Valor: ");
    __delay_ms(200);
}

void medirVoltajeDC() {
    unsigned int val;
    val = ADCRead(2);
    //    int voltage = round(val * 0.48876);
}

void iniciarPullUp() {
    TRISA = 0xff;
    PORTA = 0x00;
    TRISB = 0xff;
    PORTB = 0x00;
    TRISD = 0x00;
    PORTD = 0x00;
    OSCCON = 0x76;
}

void ADCInit() {
    ADCON0 = 0x80; //ADC ON and Fosc/16 is selected
    ADCON1 = 0x8E; // Internal reference voltage is selected
    ADIF = 0;
    ADRESH = 1;
    ADRESL = 0;
    OPTION_REG = 0X51;
    TMR0 = 0;
}

unsigned int ADCRead(unsigned char channel) {
bucle:
    canal0(1);
    if (ADRES < 127)
        PORTB = 0x00;
    if (ADRES > 127)
        PORTB = 0x01;
    if (ADRES > 255)
        PORTB = 0x03;
    if (ADRES > 382)
        PORTB = 0x07;
    if (ADRES > 511)
        PORTB = 0x0F;
    if (ADRES > 639)
        PORTB = 0x1F;
    if (ADRES > 767)
        PORTB = 0x3F;
    if (ADRES > 894)
        PORTB = 0x7F;
    if (ADRES > 1022)
        PORTB = 0xFF;
}

void delay_ms(int time) {
    long i = 0;
retardo:
    TMR0 = 0;

mili:
    if (i <= time) {

        if (i <= 136) {
            goto mili;
            i++;
            TMR0 = 0;
            goto retardo;
        }
    }

}

void canal0(int z) {
    CHS2 = 0;
    CHS1 = 0;
    CHS0 = 0;

    ADON = 1;
    delay_ms(z);
    GO = 1;

ADCA:
    if (ADIF == 0)
        goto ADCA;

    ADON = 0;

    ADRES = (ADRESH << 8) | ADRESL;

    ADIF = 0;

}