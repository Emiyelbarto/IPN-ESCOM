/*
 * File:   main.c
 * Author: emime
 *
 * Created on December 2, 2020, 2:07 PM
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

#include <xc.h>              // Libreria para pmlabx
#include <stdio.h>
#include <pic16f887.h>       // Libreria para el PIC
#include "lcd.h"                 /* Header File for LCD Functions */
#include "config.h"

int main(void) {
    int i = 0;
    int flag = 0;
    iniciarPullUp();
    ADCInit();
    Lcd_Init();
    Lcd_Clear();
    Lcd_Set_Cursor(1, 1);
    Lcd_Write_String("PRACTICA 2");
    delay_ms(2);
    printMenu();
    while (1) {
        if (!SWITCH_A) {
            for (int a = 0; a <= 20; a++) delay_ms(5);
            if (!SWITCH_A) {
                //Switch A abierto, por lo que es el switch seleccionado
                seleccionarMultimetroDC();
                medirVoltajeDC();
                delay_ms(20);
            }
        }
        if (!SWITCH_B) {
            for (int b = 0; b <= 20; b++) delay_ms(5);
            if (!SWITCH_B) {
                //Switch B abierto, por lo que es el switch seleccionado
                seleccionarMultimetroAC();
                delay_ms(20);
            }
        }
        if (!SWITCH_C) {
            for (int c = 0; c <= 20; c++) delay_ms(5);
            if (!SWITCH_C) {
                //Switch C abierto, por lo que es el switch seleccionado
                seleccionarTemperatura();
                delay_ms(20);
            }
        }
        mostrarError();
        printMenu();

    }
}