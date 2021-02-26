/* 
 * File:   config.h
 * Author: emime
 *
 * Created on December 2, 2020, 11:30 PM
 */

#ifndef CONFIG_H
#define	CONFIG_H

#ifdef	__cplusplus
extern "C" {
#endif




#ifdef	__cplusplus
}
#endif

#endif	/* CONFIG_H */
void printMenu();
void seleccionarMultimetroDC();
void seleccionarMultimetroAC();
void seleccionarTemperatura();
void mostrarError();
void medirVoltajeDC();
void iniciarPullUp();
void ADCInit();
unsigned int ADCRead(unsigned char ch);
void delay_ms(int time);
void canal0(int z);