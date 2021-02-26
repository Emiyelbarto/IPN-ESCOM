/*******************************************************************************
*           Program For "Multimeter for AC/DC load, power factor, power etc"   *
*                    Program Written By_Engr. Mithun K. Das                    *
*                       MCU: PIC18F4550; X-Tal:20MHz(Ex.)                      *
*                                 Date:03-01-16                                *
*******************************************************************************/
// LCD module connections
sbit LCD_RS at LATB4_bit;
sbit LCD_EN at LATB3_bit;
sbit LCD_D4 at LATD7_bit;
sbit LCD_D5 at LATD6_bit;
sbit LCD_D6 at LATD5_bit;
sbit LCD_D7 at LATD4_bit;

sbit LCD_RS_Direction at TRISB4_bit;
sbit LCD_EN_Direction at TRISB3_bit;
sbit LCD_D4_Direction at TRISD7_bit;
sbit LCD_D5_Direction at TRISD6_bit;
sbit LCD_D6_Direction at TRISD5_bit;
sbit LCD_D7_Direction at TRISD4_bit;
// End LCD module connections

long cnt_pf = 0;
unsigned int i;
unsigned int avg_pf = 0;
unsigned int final_pf_cnt = 0;
unsigned int sample[100];
unsigned int pf;
float power_factor = 0.00,result = 0.00;
float voltage = 0,Current=0;
long v_long,C_long,P_long,P_long1,P_long2;
long tlong=980,tlong1=980;
unsigned int temp11=0;
unsigned int maxpoint11=0;
unsigned int voltdc=0,v_longdc=0;
unsigned int k11=0;
unsigned int temp22=0;
unsigned int maxpoint22=0;
unsigned int currdc=0,c_longdc=0;
unsigned int k22=0;
void Get_PF(void);
void Get_Voltage(void);
void Get_Current(void);
void Get_dc_volt(void);
void Get_dc_curr(void);
void DC_power(void);
void AC_power(void);

void Interrupt()
{
    if (TMR1IF_bit)
    {
       TMR1IF_bit = 0;
       TMR1H = 0xFF;
       TMR1L = 0xEB;//0.01ms interrupt
       //Enter your code here
       cnt_pf++;
       //if(cnt_pf>9999)TMR1IE_bit = 0;
    }

     while(INT0IF_bit)// first zerocrossing found
     {
         TMR1IE_bit = 1;// enables timer1
         TMR1IF_bit = 0;// clear flag
         cnt_pf = 0;
         INT0IF_bit = 0;// clear flag for INT1
         break;
     }
     while(INT1IF_bit)// second zerocrossing found
     {
          TMR1IE_bit = 0; //disable timer1
          TMR1IF_bit = 0; // clear flag
          INT1IF_bit = 0;//clear flag for INT0
          i++;
          sample[i] = cnt_pf;
          avg_pf+=sample[i];
          if(i>=100)
          {
             i = 0;
             avg_pf/=100;
             final_pf_cnt = avg_pf;
             avg_pf = 0;
             cnt_pf = 0;
          }
          break;
     }
}

char massage1[]="PF:0.00 ";
char msg_ac_vlt[]="Va:000V ";
char msg_dc_vlt[]="Vd:00.0V";
char masg_ac_curr[] = "Ia:0.00A";
char masg_dc_curr[] = "I:0.00A";
char freq[]="F:00Hz";

void Get_Frequency(void)
{
   unsigned int d=0;
   TMR0L = 0;
   TMR0H = 0;
   Delay_ms(995);
   freq[2] = TMR0L/10 + 48;
   freq[3] = TMR0L%10 + 48;
   Lcd_Out(1,1,"                ");
   Lcd_Out(1,1,freq);
   Delay_ms(2000);
}

void Disp_vac(void);
void Disp_iac(void);
void Disp_vdc(void);
void Disp_idc(void);
void main()
{
   // port  settings...
   TRISA = 0xFF;//all input
   // Initialize LCD configuration...
   Lcd_Init();
   Lcd_Cmd(_LCD_CLEAR); // Clear display
   Lcd_Cmd(_LCD_CURSOR_OFF); // Cursor off
   Lcd_Out(1,4,"Multimeter");
   
   ADCON1 = 0x08;// AN0-AN4 only
   ADCON2 = 0x00;
   ADC_Init();//initialize ADC
   
   T0CON = 0b11111000;//Timer 0 as counter mode
   // Timer1 settings
   T1CON = 0x01;
   TMR1IF_bit = 0;
   TMR1H = 0xF8;
   TMR1L = 0x2F;
   INTCON = 0xC0;
   // Int0 settings...
   INTEDG0_bit = 0;//interrupt on falling edge
   INT0IF_bit = 0;//clear flag
   // INT1 settings...
   INTEDG1_bit = 0;//interrupt on falling edge
   INT1IF_bit = 0;//clear flag
   Delay_ms(5000);
   Lcd_Cmd(_LCD_CLEAR); // Clear display
   WDTCON = 0xFF;
   while(1)
   {
      
      Get_Voltage(void);
      Get_Current(void);
      if(voltage<10 && Current<5)
      {
          Lcd_Out(1,1,"O<=V=>O  O<=I=>O");
      }
      else
      {
          Disp_vac(void);
          Disp_iac(void);
          Delay_ms(2000);
      }

      if(voltage>10 && Current>5)
      {
         Get_Frequency(void);
         Get_PF(void);
         AC_power(void);
      }

      Get_dc_volt(void);
      Get_dc_curr(void);
      if(voltdc<10 && currdc<5)
      {
         Lcd_Out(2,1,"+<=V=>-  +<=I=>-");
      }
      else
      {
         Disp_vdc(void);
         Disp_idc(void);
         Delay_ms(2000);
          if(voltdc>10 && currdc>5)
          {
             DC_power(void);
          }
      }

      
   }//while(1)
}//void

void Get_Voltage(void)
{
    unsigned int temp0=0;
    unsigned int maxpoint0=0;
    unsigned int k=0;
    ADCON0 = 0b00001001;// AN1 selected
    for(k=0;k<1000;k++)
    {
        if(temp0 = ADC_Read(2),temp0>maxpoint0)
        {
            maxpoint0 = temp0;
        }
    }
    maxpoint0 = abs(ceil(maxpoint0));
    voltage = (float)maxpoint0*0.655;// (5/1023)*11.00*0.707*220/12*calibration factor;
    v_long = (int)voltage;
    maxpoint0 = 0;
}
void Disp_vac(void)
{
    msg_ac_vlt[3] = (v_long/100) +48;
    msg_ac_vlt[4] = (v_long/10)%10 +48;
    msg_ac_vlt[5] =  v_long%10 +48;
    Lcd_Out(1,1, msg_ac_vlt);
    Delay_ms(20);
}
void Get_Current(void)
{
    unsigned int temp1=0;
    unsigned int maxpoint1=0;
    int kk=0;
    ADCON0 = 0b00000101;// AN1 selected
    for(kk=0;kk<1000;kk++)
    {
        if(temp1 = ADC_Read(1),temp1>maxpoint1)
        {
            maxpoint1 = temp1;
        }
    }
    Current = (float)maxpoint1*0.186;// get the load current
    C_long = (int)Current;
    maxpoint1 = 0;
}

void Disp_iac(void)
{
    masg_ac_curr[3] = C_long/100+48;
    masg_ac_curr[4] = '.';
    masg_ac_curr[5] = (C_long/10)%10 +48;
    masg_ac_curr[6] = (C_long/1)%10 +48;
    Lcd_Out(1,9,masg_ac_curr);
    Delay_ms(50);
}
void Get_PF(void)
{
    for(i=0;i<100;i++)
    {
       sample[i] = 0;
       i++;
    }
    Delay_ms(100);
    GIE_bit = 1;//Enable Interrupt
    INT0IE_bit = 1;//enable INT1
    INT1IE_bit = 1;//enable INT1
    TMR1IE_bit = 1;
    Delay_ms(2000);
    result = (float)cos((final_pf_cnt*2*3.1416)/1000);
    tlong1 = abs(ceil(result*1000));
    if(tlong>(tlong1+10))tlong-=10;
    else if(tlong<(tlong1-10))tlong+=10;
    else tlong = tlong1;
    //char massage1[]="PF:0.00 ";
    massage1[3] = tlong/1000 + 48;
    massage1[5] = (tlong/100)%10 + 48;
    massage1[6] = (tlong/10)%10 + 48;
    power_factor = (float)result;
    Lcd_Out(1,1,massage1);
    Delay_ms(20);
    GIE_bit = 0;//Disable Interrupt
    INT0IE_bit = 0;//enable INT1
    INT1IE_bit = 0;//enable INT1
    TMR1IE_bit = 0;
}

void AC_power(void)
{
   char msg_acpwr[] = "Pa:000W ";
   P_long = (int)v_long*C_long*tlong/100000;//watt
   msg_acpwr[3] = P_long/100 +48;
   msg_acpwr[4] = (P_long/10)%10 +48;
   msg_acpwr[5] = (P_long)%10 +48;
   Lcd_Out(1,9,msg_acpwr);
   Delay_ms(3000);
}


void Get_dc_volt(void)
{
    maxpoint11 = 0;
    ADCON0 = 0b00001101;// AN3 selected
    for(k11=0;k11<5;k11++)
    {
        maxpoint11+=ADC_Read(3);
        Delay_ms(20);
    }
    maxpoint11/=5;
    voltdc = (float)maxpoint11*1.27077;;
    v_longdc = (int)voltdc;
}

void Disp_vdc(void)
{
    msg_dc_vlt[3] = (v_longdc/100) +48;
    msg_dc_vlt[4] = (v_longdc/10)%10 +48;
    msg_dc_vlt[6] =  v_longdc%10 +48;
    Lcd_Out(2,1,"         ");
    Lcd_Out(2,1, msg_dc_vlt);
    Delay_ms(10);
}

void Get_dc_curr(void)
{
    maxpoint22 = 0;
    ADCON0 = 0b00010001;// AN4 selected
    for(k22=0;k22<5;k22++)
    {
        maxpoint22+=ADC_Read(4);
        Delay_ms(20);
    }
    maxpoint22/=5;
    currdc = (float)maxpoint22*0.44149;
    c_longdc = (int)currdc;
}

void Disp_idc(void)
{
    masg_dc_curr[2] = (c_longdc/100) +48;
    masg_dc_curr[4] = (c_longdc/10)%10 +48;
    masg_dc_curr[5] =  c_longdc%10 +48;
    Lcd_Out(2,9,"        ");
    Lcd_Out(2,10, masg_dc_curr);
    Delay_ms(30);
}

void DC_power(void)
{
   int pdc=0;
   char masg_pwr_dc[]="Pdc:000.00Watt";
   pdc = abs(voltdc*currdc/10);
   masg_pwr_dc[4] = pdc/10000 + 48;
   masg_pwr_dc[5] = (pdc/1000)%10 + 48;
   masg_pwr_dc[6] = (pdc/100)%10 + 48;
   masg_pwr_dc[8] = (pdc/10)%10 + 48;
   masg_pwr_dc[9] = pdc%10 + 48;
   Lcd_Out(2,1,"                ");
   Lcd_Out(2,1,masg_pwr_dc);
   Delay_ms(3000);
}

/*******************************************************************************
*                               End of the Program                             *
*******************************************************************************/