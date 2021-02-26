
/* 
   Header File For PIC18F4550 ADC 
   http://www.electronicwings.com
 */


// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef ADC_Header_File
#define	ADC_Header_File

#include <pic18f4550.h> 
#include "Configuration_Header_File.h"
void ADC_Init();
int ADC_Read(int);

#endif	/* ADC_Header_File */

