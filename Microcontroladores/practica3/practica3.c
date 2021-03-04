
// CONFIG
#pragma config FOSC = HS   // Oscillator Selection bits (HS oscillator)
#pragma config WDTE = OFF  // Watchdog Timer Enable bit (WDT disabled)
#pragma config PWRTE = OFF // Power-up Timer Enable bit (PWRT enabled)
#pragma config BOREN = OFF // Brown-out Reset Enable bit (BOR enabled)
#pragma config LVP = OFF   // Low-Voltage (Single-Supply) In-Circuit Serial Programming Enable bit (RB3 is digital I/O, HV on MCLR must be used FOR programming)
#pragma config CPD = OFF   // Data EEPROM Memory Code Protection bit (Data EEPROM code protection off)
#pragma config WRT = OFF   // Flash Program Memory Write Enable bits (Write protection off; all program memory may be written to by EECON control)
#pragma config CP = OFF    // Flash Program Memory Code Protection bit (Code protection off)

//End of CONFIG registers
/*
 * Interfacing PIC16F877A microcontroller with 1602 LCD and
 * LM335 analog temperature sensor.
 * C Code FOR CCS C compiler.
 * This is a free software with NO WARRANTY.
 * https://simple - circuit.com /
 */
// LCD module connections
#define LCD_RS_PIN PIN_D0
#define LCD_RW_PIN PIN_D1
#define LCD_ENABLE_PIN PIN_D2
#define LCD_DATA4 PIN_D3
#define LCD_DATA5 PIN_D4
#define LCD_DATA6 PIN_D5
#define LCD_DATA7 PIN_D6

// End LCD module connections
#include <16F877A.h>
#include <lcd.c>
#fuses HS, NOWDT, NOPROTECT, NOLVP
#define ADC = 10
#use delay(clock = 8MHz)
#define _XTAL_FREQ 20000000

signed INT16 Kelvin, Celsius;

//******Initialize Bluetooth using USART********//
void Initialize_Bluetooth()
{
   //Set the pins of RX and TX//
   TRISC6 = 1;
   TRISC7 = 1;

   //Set the baud rate using the look up table in datasheet (pg114) //
   BRGH = 1; //Always use high speed baud rate with Bluetooth ELSE it wont work
   SPBRG = 129;

   //Turn on Asyc. Serial Port//
   SYNC = 0;
   SPEN = 1;

   //Set 8 - bit reception and transmission
   RX9 = 0;
   TX9 = 0;

   //Enable transmission and reception//
   TXEN = 1;
   CREN = 1;

   //Enable global and ph. interrupts//
   GIE = 1;
   PEIE = 1;

   //Enable interrupts FOR Tx. and Rx.//
   RCIE = 1;
   TXIE = 1;
}

//___________BT initialized_____________//
//Function to load the Bluetooth Rx. buffer with one CHAR.//
void BT_load_CHAR(char byte)
{
   TXREG = byte;

   WHILE (!TXIF)
      ;

   WHILE (!TRMT)
      ;
}

//End of function//
//Function to Load Bluetooth Rx. buffer with string//
void BT_load_string(CHAR *string)
{
   WHILE (*string)
      BT_load_CHAR ( * string++) ;
}

//End of function//
//Function to broadcast data from RX. buffer//
void broadcast_BT()
{
   TXREG = 13;
   __delay_ms (500) ;
}

//End of function//
//Function to get a CHAR from Rx.buffer of BT//
char BT_get_char(VOID)
{
   IF (OERR) // check for over run error
   {
      CREN = 0;
      CREN = 1; //Reset CREN
   }

   if (RCIF == 1) //if the user has sent a char RETURN the char (ASCII value)
   {
      WHILE (!RCIF)
         ;

      RETURN RCREG;
   }

   else //if user has sent no message RETURN 0
   RETURN 0;
}

//End of function/
void main(VOID)
{
   //Scope variable declarations//
   INT get_value;

   //End of variable declaration//
   //I / O Declarations//
   TRISB3 = 0;

   //End of I / O declaration//
   Initialize_Bluetooth (); //lets get our bluetooth ready FOR action
   //Show some introductory message once on power up//
   BT_load_string ("Bluetooth Initialized and Ready") ;
   broadcast_BT () ;
   BT_load_string ("Press 1 to turn ON LM35") ;
   broadcast_BT () ;
   BT_load_string ("Press 0 to turn OFF LM35") ;
   broadcast_BT () ;

   //End of message//
   WHILE (1) //The infinite lop
   {
      setup_adc (ADC_CLOCK_INTERNAL); // ADC Module uses its internal oscillator
      setup_adc_ports (AN0);  // Configure AN0 pin as analog
      set_adc_channel (0);   // Select channel 0 (AN0)
      lcd_init ();     // Initialize LCD module
      lcd_putc ('\f');    // Clear LCD
      WHILE (TRUE)
      {
         delay_ms (1000) ;
         Kelvin = read_adc () * 0.489; // Read analog voltage and convert it to Kelvin (0.489 = 500 / 1023)
         Celsius = Kelvin - 273; // Convert Kelvin to degree Celsius
         IF (Celsius > 80)
         {
            //Señal de respuesta es 1, se prende ventilador
            RB3 = 1;
            BT_load_string ("Ventilador turned ON") ;

            //Se envia mensaje
            broadcast_BT () ;
         }

         ELSE
         {
            //Señal de respuesta es 0, se apaga ventilador
            RB3 = 0;
            BT_load_string ("Ventilador turned OFF") ;

            //Se envia mensaje
            broadcast_BT () ;
         }
      }
   }

