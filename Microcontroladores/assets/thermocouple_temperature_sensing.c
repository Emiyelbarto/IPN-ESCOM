/*
   Thermocouple Interfacing with PIC18F4550
   http://www.electronicwings.com
 */ 

#include <pic18f4550.h>
#include <string.h>
#include <stdio.h>
#include "LCD_16x2_8-bit_Header_File.h"
#include "PIC18F4550_ADC_Header_File.h"

void main(void)
{
    OSCCON =0x72;
	LCD_Init();		/* initialize LCD16x2 */
	LCD_Clear();	/* clear LCD */
	ADC_Init();		/* initialize ADC */
	char Temperature_buffer[10];
	int Analog_Input;
	float Temperature;
	LCD_String_xy(0, 0, "Temperature");    
    while(1)
	{
		Analog_Input = ADC_Read(0);	/* store the analog data on a variable */
		
        /* convert analog voltage into ºC and substract the offset voltage */	
 		Temperature = ((Analog_Input * 4.88)-0.0027)/10.0;	
		sprintf(Temperature_buffer,"%d%cC  ",(int)Temperature,0xdf);  /* convert integer to ASCII string */
        LCD_String_xy(1, 2, Temperature_buffer);
		MSdelay(1000);	/* wait for 1 second */
	}
}