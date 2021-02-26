
_Interrupt:

;Multimeter _ UITS.c,49 :: 		void Interrupt()
;Multimeter _ UITS.c,51 :: 		if (TMR1IF_bit)
	BTFSS       TMR1IF_bit+0, BitPos(TMR1IF_bit+0) 
	GOTO        L_Interrupt0
;Multimeter _ UITS.c,53 :: 		TMR1IF_bit = 0;
	BCF         TMR1IF_bit+0, BitPos(TMR1IF_bit+0) 
;Multimeter _ UITS.c,54 :: 		TMR1H = 0xFF;
	MOVLW       255
	MOVWF       TMR1H+0 
;Multimeter _ UITS.c,55 :: 		TMR1L = 0xEB;//0.01ms interrupt
	MOVLW       235
	MOVWF       TMR1L+0 
;Multimeter _ UITS.c,57 :: 		cnt_pf++;
	MOVLW       1
	ADDWF       _cnt_pf+0, 1 
	MOVLW       0
	ADDWFC      _cnt_pf+1, 1 
	ADDWFC      _cnt_pf+2, 1 
	ADDWFC      _cnt_pf+3, 1 
;Multimeter _ UITS.c,59 :: 		}
L_Interrupt0:
;Multimeter _ UITS.c,61 :: 		while(INT0IF_bit)// first zerocrossing found
	BTFSS       INT0IF_bit+0, BitPos(INT0IF_bit+0) 
	GOTO        L_Interrupt2
;Multimeter _ UITS.c,63 :: 		TMR1IE_bit = 1;// enables timer1
	BSF         TMR1IE_bit+0, BitPos(TMR1IE_bit+0) 
;Multimeter _ UITS.c,64 :: 		TMR1IF_bit = 0;// clear flag
	BCF         TMR1IF_bit+0, BitPos(TMR1IF_bit+0) 
;Multimeter _ UITS.c,65 :: 		cnt_pf = 0;
	CLRF        _cnt_pf+0 
	CLRF        _cnt_pf+1 
	CLRF        _cnt_pf+2 
	CLRF        _cnt_pf+3 
;Multimeter _ UITS.c,66 :: 		INT0IF_bit = 0;// clear flag for INT1
	BCF         INT0IF_bit+0, BitPos(INT0IF_bit+0) 
;Multimeter _ UITS.c,68 :: 		}
L_Interrupt2:
;Multimeter _ UITS.c,69 :: 		while(INT1IF_bit)// second zerocrossing found
	BTFSS       INT1IF_bit+0, BitPos(INT1IF_bit+0) 
	GOTO        L_Interrupt4
;Multimeter _ UITS.c,71 :: 		TMR1IE_bit = 0; //disable timer1
	BCF         TMR1IE_bit+0, BitPos(TMR1IE_bit+0) 
;Multimeter _ UITS.c,72 :: 		TMR1IF_bit = 0; // clear flag
	BCF         TMR1IF_bit+0, BitPos(TMR1IF_bit+0) 
;Multimeter _ UITS.c,73 :: 		INT1IF_bit = 0;//clear flag for INT0
	BCF         INT1IF_bit+0, BitPos(INT1IF_bit+0) 
;Multimeter _ UITS.c,74 :: 		i++;
	INFSNZ      _i+0, 1 
	INCF        _i+1, 1 
;Multimeter _ UITS.c,75 :: 		sample[i] = cnt_pf;
	MOVF        _i+0, 0 
	MOVWF       R0 
	MOVF        _i+1, 0 
	MOVWF       R1 
	RLCF        R0, 1 
	BCF         R0, 0 
	RLCF        R1, 1 
	MOVLW       _sample+0
	ADDWF       R0, 0 
	MOVWF       FSR1 
	MOVLW       hi_addr(_sample+0)
	ADDWFC      R1, 0 
	MOVWF       FSR1H 
	MOVF        _cnt_pf+0, 0 
	MOVWF       POSTINC1+0 
	MOVF        _cnt_pf+1, 0 
	MOVWF       POSTINC1+0 
;Multimeter _ UITS.c,76 :: 		avg_pf+=sample[i];
	MOVF        _i+0, 0 
	MOVWF       R0 
	MOVF        _i+1, 0 
	MOVWF       R1 
	RLCF        R0, 1 
	BCF         R0, 0 
	RLCF        R1, 1 
	MOVLW       _sample+0
	ADDWF       R0, 0 
	MOVWF       FSR2 
	MOVLW       hi_addr(_sample+0)
	ADDWFC      R1, 0 
	MOVWF       FSR2H 
	MOVF        POSTINC2+0, 0 
	ADDWF       _avg_pf+0, 1 
	MOVF        POSTINC2+0, 0 
	ADDWFC      _avg_pf+1, 1 
;Multimeter _ UITS.c,77 :: 		if(i>=100)
	MOVLW       0
	SUBWF       _i+1, 0 
	BTFSS       STATUS+0, 2 
	GOTO        L__Interrupt65
	MOVLW       100
	SUBWF       _i+0, 0 
L__Interrupt65:
	BTFSS       STATUS+0, 0 
	GOTO        L_Interrupt5
;Multimeter _ UITS.c,79 :: 		i = 0;
	CLRF        _i+0 
	CLRF        _i+1 
;Multimeter _ UITS.c,80 :: 		avg_pf/=100;
	MOVLW       100
	MOVWF       R4 
	MOVLW       0
	MOVWF       R5 
	MOVF        _avg_pf+0, 0 
	MOVWF       R0 
	MOVF        _avg_pf+1, 0 
	MOVWF       R1 
	CALL        _Div_16X16_U+0, 0
	MOVF        R0, 0 
	MOVWF       _avg_pf+0 
	MOVF        R1, 0 
	MOVWF       _avg_pf+1 
;Multimeter _ UITS.c,81 :: 		final_pf_cnt = avg_pf;
	MOVF        R0, 0 
	MOVWF       _final_pf_cnt+0 
	MOVF        R1, 0 
	MOVWF       _final_pf_cnt+1 
;Multimeter _ UITS.c,82 :: 		avg_pf = 0;
	CLRF        _avg_pf+0 
	CLRF        _avg_pf+1 
;Multimeter _ UITS.c,83 :: 		cnt_pf = 0;
	CLRF        _cnt_pf+0 
	CLRF        _cnt_pf+1 
	CLRF        _cnt_pf+2 
	CLRF        _cnt_pf+3 
;Multimeter _ UITS.c,84 :: 		}
L_Interrupt5:
;Multimeter _ UITS.c,86 :: 		}
L_Interrupt4:
;Multimeter _ UITS.c,87 :: 		}
L_end_Interrupt:
L__Interrupt64:
	RETFIE      1
; end of _Interrupt

_Get_Frequency:

;Multimeter _ UITS.c,96 :: 		void Get_Frequency(void)
;Multimeter _ UITS.c,98 :: 		unsigned int d=0;
;Multimeter _ UITS.c,99 :: 		TMR0L = 0;
	CLRF        TMR0L+0 
;Multimeter _ UITS.c,100 :: 		TMR0H = 0;
	CLRF        TMR0H+0 
;Multimeter _ UITS.c,101 :: 		Delay_ms(995);
	MOVLW       26
	MOVWF       R11, 0
	MOVLW       61
	MOVWF       R12, 0
	MOVLW       247
	MOVWF       R13, 0
L_Get_Frequency6:
	DECFSZ      R13, 1, 1
	BRA         L_Get_Frequency6
	DECFSZ      R12, 1, 1
	BRA         L_Get_Frequency6
	DECFSZ      R11, 1, 1
	BRA         L_Get_Frequency6
;Multimeter _ UITS.c,102 :: 		freq[2] = TMR0L/10 + 48;
	MOVLW       10
	MOVWF       R4 
	MOVF        TMR0L+0, 0 
	MOVWF       R0 
	CALL        _Div_8X8_U+0, 0
	MOVLW       48
	ADDWF       R0, 0 
	MOVWF       _freq+2 
;Multimeter _ UITS.c,103 :: 		freq[3] = TMR0L%10 + 48;
	MOVLW       10
	MOVWF       R4 
	MOVF        TMR0L+0, 0 
	MOVWF       R0 
	CALL        _Div_8X8_U+0, 0
	MOVF        R8, 0 
	MOVWF       R0 
	MOVLW       48
	ADDWF       R0, 0 
	MOVWF       _freq+3 
;Multimeter _ UITS.c,104 :: 		Lcd_Out(1,1,"                ");
	MOVLW       1
	MOVWF       FARG_Lcd_Out_row+0 
	MOVLW       1
	MOVWF       FARG_Lcd_Out_column+0 
	MOVLW       ?ICS?lstr1_Multimeter_32__32UITS+0
	MOVWF       TBLPTRL 
	MOVLW       hi_addr(?ICS?lstr1_Multimeter_32__32UITS+0)
	MOVWF       TBLPTRH 
	MOVLW       higher_addr(?ICS?lstr1_Multimeter_32__32UITS+0)
	MOVWF       TBLPTRU 
	MOVLW       ?lstr1_Multimeter_32__32UITS+0
	MOVWF       FSR1 
	MOVLW       hi_addr(?lstr1_Multimeter_32__32UITS+0)
	MOVWF       FSR1H 
	MOVLW       17
	MOVWF       R0 
	MOVLW       1
	MOVWF       R1 
	CALL        ___CC2DW+0, 0
	MOVLW       ?lstr1_Multimeter_32__32UITS+0
	MOVWF       FARG_Lcd_Out_text+0 
	MOVLW       hi_addr(?lstr1_Multimeter_32__32UITS+0)
	MOVWF       FARG_Lcd_Out_text+1 
	CALL        _Lcd_Out+0, 0
;Multimeter _ UITS.c,105 :: 		Lcd_Out(1,1,freq);
	MOVLW       1
	MOVWF       FARG_Lcd_Out_row+0 
	MOVLW       1
	MOVWF       FARG_Lcd_Out_column+0 
	MOVLW       _freq+0
	MOVWF       FARG_Lcd_Out_text+0 
	MOVLW       hi_addr(_freq+0)
	MOVWF       FARG_Lcd_Out_text+1 
	CALL        _Lcd_Out+0, 0
;Multimeter _ UITS.c,106 :: 		Delay_ms(2000);
	MOVLW       51
	MOVWF       R11, 0
	MOVLW       187
	MOVWF       R12, 0
	MOVLW       223
	MOVWF       R13, 0
L_Get_Frequency7:
	DECFSZ      R13, 1, 1
	BRA         L_Get_Frequency7
	DECFSZ      R12, 1, 1
	BRA         L_Get_Frequency7
	DECFSZ      R11, 1, 1
	BRA         L_Get_Frequency7
	NOP
	NOP
;Multimeter _ UITS.c,107 :: 		}
L_end_Get_Frequency:
	RETURN      0
; end of _Get_Frequency

_main:

;Multimeter _ UITS.c,113 :: 		void main()
;Multimeter _ UITS.c,116 :: 		TRISA = 0xFF;//all input
	MOVLW       255
	MOVWF       TRISA+0 
;Multimeter _ UITS.c,118 :: 		Lcd_Init();
	CALL        _Lcd_Init+0, 0
;Multimeter _ UITS.c,119 :: 		Lcd_Cmd(_LCD_CLEAR); // Clear display
	MOVLW       1
	MOVWF       FARG_Lcd_Cmd_out_char+0 
	CALL        _Lcd_Cmd+0, 0
;Multimeter _ UITS.c,120 :: 		Lcd_Cmd(_LCD_CURSOR_OFF); // Cursor off
	MOVLW       12
	MOVWF       FARG_Lcd_Cmd_out_char+0 
	CALL        _Lcd_Cmd+0, 0
;Multimeter _ UITS.c,121 :: 		Lcd_Out(1,4,"Multimeter");
	MOVLW       1
	MOVWF       FARG_Lcd_Out_row+0 
	MOVLW       4
	MOVWF       FARG_Lcd_Out_column+0 
	MOVLW       77
	MOVWF       ?lstr2_Multimeter_32__32UITS+0 
	MOVLW       117
	MOVWF       ?lstr2_Multimeter_32__32UITS+1 
	MOVLW       108
	MOVWF       ?lstr2_Multimeter_32__32UITS+2 
	MOVLW       116
	MOVWF       ?lstr2_Multimeter_32__32UITS+3 
	MOVLW       105
	MOVWF       ?lstr2_Multimeter_32__32UITS+4 
	MOVLW       109
	MOVWF       ?lstr2_Multimeter_32__32UITS+5 
	MOVLW       101
	MOVWF       ?lstr2_Multimeter_32__32UITS+6 
	MOVLW       116
	MOVWF       ?lstr2_Multimeter_32__32UITS+7 
	MOVLW       101
	MOVWF       ?lstr2_Multimeter_32__32UITS+8 
	MOVLW       114
	MOVWF       ?lstr2_Multimeter_32__32UITS+9 
	CLRF        ?lstr2_Multimeter_32__32UITS+10 
	MOVLW       ?lstr2_Multimeter_32__32UITS+0
	MOVWF       FARG_Lcd_Out_text+0 
	MOVLW       hi_addr(?lstr2_Multimeter_32__32UITS+0)
	MOVWF       FARG_Lcd_Out_text+1 
	CALL        _Lcd_Out+0, 0
;Multimeter _ UITS.c,123 :: 		ADCON1 = 0x08;// AN0-AN4 only
	MOVLW       8
	MOVWF       ADCON1+0 
;Multimeter _ UITS.c,124 :: 		ADCON2 = 0x00;
	CLRF        ADCON2+0 
;Multimeter _ UITS.c,125 :: 		ADC_Init();//initialize ADC
	CALL        _ADC_Init+0, 0
;Multimeter _ UITS.c,127 :: 		T0CON = 0b11111000;//Timer 0 as counter mode
	MOVLW       248
	MOVWF       T0CON+0 
;Multimeter _ UITS.c,129 :: 		T1CON = 0x01;
	MOVLW       1
	MOVWF       T1CON+0 
;Multimeter _ UITS.c,130 :: 		TMR1IF_bit = 0;
	BCF         TMR1IF_bit+0, BitPos(TMR1IF_bit+0) 
;Multimeter _ UITS.c,131 :: 		TMR1H = 0xF8;
	MOVLW       248
	MOVWF       TMR1H+0 
;Multimeter _ UITS.c,132 :: 		TMR1L = 0x2F;
	MOVLW       47
	MOVWF       TMR1L+0 
;Multimeter _ UITS.c,133 :: 		INTCON = 0xC0;
	MOVLW       192
	MOVWF       INTCON+0 
;Multimeter _ UITS.c,135 :: 		INTEDG0_bit = 0;//interrupt on falling edge
	BCF         INTEDG0_bit+0, BitPos(INTEDG0_bit+0) 
;Multimeter _ UITS.c,136 :: 		INT0IF_bit = 0;//clear flag
	BCF         INT0IF_bit+0, BitPos(INT0IF_bit+0) 
;Multimeter _ UITS.c,138 :: 		INTEDG1_bit = 0;//interrupt on falling edge
	BCF         INTEDG1_bit+0, BitPos(INTEDG1_bit+0) 
;Multimeter _ UITS.c,139 :: 		INT1IF_bit = 0;//clear flag
	BCF         INT1IF_bit+0, BitPos(INT1IF_bit+0) 
;Multimeter _ UITS.c,140 :: 		Delay_ms(5000);
	MOVLW       127
	MOVWF       R11, 0
	MOVLW       212
	MOVWF       R12, 0
	MOVLW       49
	MOVWF       R13, 0
L_main8:
	DECFSZ      R13, 1, 1
	BRA         L_main8
	DECFSZ      R12, 1, 1
	BRA         L_main8
	DECFSZ      R11, 1, 1
	BRA         L_main8
	NOP
	NOP
;Multimeter _ UITS.c,141 :: 		Lcd_Cmd(_LCD_CLEAR); // Clear display
	MOVLW       1
	MOVWF       FARG_Lcd_Cmd_out_char+0 
	CALL        _Lcd_Cmd+0, 0
;Multimeter _ UITS.c,142 :: 		WDTCON = 0xFF;
	MOVLW       255
	MOVWF       WDTCON+0 
;Multimeter _ UITS.c,143 :: 		while(1)
L_main9:
;Multimeter _ UITS.c,146 :: 		Get_Voltage(void);
	CALL        _Get_Voltage+0, 0
;Multimeter _ UITS.c,147 :: 		Get_Current(void);
	CALL        _Get_Current+0, 0
;Multimeter _ UITS.c,148 :: 		if(voltage<10 && Current<5)
	MOVLW       0
	MOVWF       R4 
	MOVLW       0
	MOVWF       R5 
	MOVLW       32
	MOVWF       R6 
	MOVLW       130
	MOVWF       R7 
	MOVF        _voltage+0, 0 
	MOVWF       R0 
	MOVF        _voltage+1, 0 
	MOVWF       R1 
	MOVF        _voltage+2, 0 
	MOVWF       R2 
	MOVF        _voltage+3, 0 
	MOVWF       R3 
	CALL        _Compare_Double+0, 0
	MOVLW       1
	BTFSC       STATUS+0, 0 
	MOVLW       0
	MOVWF       R0 
	MOVF        R0, 1 
	BTFSC       STATUS+0, 2 
	GOTO        L_main13
	MOVLW       0
	MOVWF       R4 
	MOVLW       0
	MOVWF       R5 
	MOVLW       32
	MOVWF       R6 
	MOVLW       129
	MOVWF       R7 
	MOVF        _Current+0, 0 
	MOVWF       R0 
	MOVF        _Current+1, 0 
	MOVWF       R1 
	MOVF        _Current+2, 0 
	MOVWF       R2 
	MOVF        _Current+3, 0 
	MOVWF       R3 
	CALL        _Compare_Double+0, 0
	MOVLW       1
	BTFSC       STATUS+0, 0 
	MOVLW       0
	MOVWF       R0 
	MOVF        R0, 1 
	BTFSC       STATUS+0, 2 
	GOTO        L_main13
L__main62:
;Multimeter _ UITS.c,150 :: 		Lcd_Out(1,1,"O<=V=>O  O<=I=>O");
	MOVLW       1
	MOVWF       FARG_Lcd_Out_row+0 
	MOVLW       1
	MOVWF       FARG_Lcd_Out_column+0 
	MOVLW       ?ICS?lstr3_Multimeter_32__32UITS+0
	MOVWF       TBLPTRL 
	MOVLW       hi_addr(?ICS?lstr3_Multimeter_32__32UITS+0)
	MOVWF       TBLPTRH 
	MOVLW       higher_addr(?ICS?lstr3_Multimeter_32__32UITS+0)
	MOVWF       TBLPTRU 
	MOVLW       ?lstr3_Multimeter_32__32UITS+0
	MOVWF       FSR1 
	MOVLW       hi_addr(?lstr3_Multimeter_32__32UITS+0)
	MOVWF       FSR1H 
	MOVLW       17
	MOVWF       R0 
	MOVLW       1
	MOVWF       R1 
	CALL        ___CC2DW+0, 0
	MOVLW       ?lstr3_Multimeter_32__32UITS+0
	MOVWF       FARG_Lcd_Out_text+0 
	MOVLW       hi_addr(?lstr3_Multimeter_32__32UITS+0)
	MOVWF       FARG_Lcd_Out_text+1 
	CALL        _Lcd_Out+0, 0
;Multimeter _ UITS.c,151 :: 		}
	GOTO        L_main14
L_main13:
;Multimeter _ UITS.c,154 :: 		Disp_vac(void);
	CALL        _Disp_vac+0, 0
;Multimeter _ UITS.c,155 :: 		Disp_iac(void);
	CALL        _Disp_iac+0, 0
;Multimeter _ UITS.c,156 :: 		Delay_ms(2000);
	MOVLW       51
	MOVWF       R11, 0
	MOVLW       187
	MOVWF       R12, 0
	MOVLW       223
	MOVWF       R13, 0
L_main15:
	DECFSZ      R13, 1, 1
	BRA         L_main15
	DECFSZ      R12, 1, 1
	BRA         L_main15
	DECFSZ      R11, 1, 1
	BRA         L_main15
	NOP
	NOP
;Multimeter _ UITS.c,157 :: 		}
L_main14:
;Multimeter _ UITS.c,159 :: 		if(voltage>10 && Current>5)
	MOVF        _voltage+0, 0 
	MOVWF       R4 
	MOVF        _voltage+1, 0 
	MOVWF       R5 
	MOVF        _voltage+2, 0 
	MOVWF       R6 
	MOVF        _voltage+3, 0 
	MOVWF       R7 
	MOVLW       0
	MOVWF       R0 
	MOVLW       0
	MOVWF       R1 
	MOVLW       32
	MOVWF       R2 
	MOVLW       130
	MOVWF       R3 
	CALL        _Compare_Double+0, 0
	MOVLW       1
	BTFSC       STATUS+0, 0 
	MOVLW       0
	MOVWF       R0 
	MOVF        R0, 1 
	BTFSC       STATUS+0, 2 
	GOTO        L_main18
	MOVF        _Current+0, 0 
	MOVWF       R4 
	MOVF        _Current+1, 0 
	MOVWF       R5 
	MOVF        _Current+2, 0 
	MOVWF       R6 
	MOVF        _Current+3, 0 
	MOVWF       R7 
	MOVLW       0
	MOVWF       R0 
	MOVLW       0
	MOVWF       R1 
	MOVLW       32
	MOVWF       R2 
	MOVLW       129
	MOVWF       R3 
	CALL        _Compare_Double+0, 0
	MOVLW       1
	BTFSC       STATUS+0, 0 
	MOVLW       0
	MOVWF       R0 
	MOVF        R0, 1 
	BTFSC       STATUS+0, 2 
	GOTO        L_main18
L__main61:
;Multimeter _ UITS.c,161 :: 		Get_Frequency(void);
	CALL        _Get_Frequency+0, 0
;Multimeter _ UITS.c,162 :: 		Get_PF(void);
	CALL        _Get_PF+0, 0
;Multimeter _ UITS.c,163 :: 		AC_power(void);
	CALL        _AC_power+0, 0
;Multimeter _ UITS.c,164 :: 		}
L_main18:
;Multimeter _ UITS.c,166 :: 		Get_dc_volt(void);
	CALL        _Get_dc_volt+0, 0
;Multimeter _ UITS.c,167 :: 		Get_dc_curr(void);
	CALL        _Get_dc_curr+0, 0
;Multimeter _ UITS.c,168 :: 		if(voltdc<10 && currdc<5)
	MOVLW       0
	SUBWF       _voltdc+1, 0 
	BTFSS       STATUS+0, 2 
	GOTO        L__main68
	MOVLW       10
	SUBWF       _voltdc+0, 0 
L__main68:
	BTFSC       STATUS+0, 0 
	GOTO        L_main21
	MOVLW       0
	SUBWF       _currdc+1, 0 
	BTFSS       STATUS+0, 2 
	GOTO        L__main69
	MOVLW       5
	SUBWF       _currdc+0, 0 
L__main69:
	BTFSC       STATUS+0, 0 
	GOTO        L_main21
L__main60:
;Multimeter _ UITS.c,170 :: 		Lcd_Out(2,1,"+<=V=>-  +<=I=>-");
	MOVLW       2
	MOVWF       FARG_Lcd_Out_row+0 
	MOVLW       1
	MOVWF       FARG_Lcd_Out_column+0 
	MOVLW       ?ICS?lstr4_Multimeter_32__32UITS+0
	MOVWF       TBLPTRL 
	MOVLW       hi_addr(?ICS?lstr4_Multimeter_32__32UITS+0)
	MOVWF       TBLPTRH 
	MOVLW       higher_addr(?ICS?lstr4_Multimeter_32__32UITS+0)
	MOVWF       TBLPTRU 
	MOVLW       ?lstr4_Multimeter_32__32UITS+0
	MOVWF       FSR1 
	MOVLW       hi_addr(?lstr4_Multimeter_32__32UITS+0)
	MOVWF       FSR1H 
	MOVLW       17
	MOVWF       R0 
	MOVLW       1
	MOVWF       R1 
	CALL        ___CC2DW+0, 0
	MOVLW       ?lstr4_Multimeter_32__32UITS+0
	MOVWF       FARG_Lcd_Out_text+0 
	MOVLW       hi_addr(?lstr4_Multimeter_32__32UITS+0)
	MOVWF       FARG_Lcd_Out_text+1 
	CALL        _Lcd_Out+0, 0
;Multimeter _ UITS.c,171 :: 		}
	GOTO        L_main22
L_main21:
;Multimeter _ UITS.c,174 :: 		Disp_vdc(void);
	CALL        _Disp_vdc+0, 0
;Multimeter _ UITS.c,175 :: 		Disp_idc(void);
	CALL        _Disp_idc+0, 0
;Multimeter _ UITS.c,176 :: 		Delay_ms(2000);
	MOVLW       51
	MOVWF       R11, 0
	MOVLW       187
	MOVWF       R12, 0
	MOVLW       223
	MOVWF       R13, 0
L_main23:
	DECFSZ      R13, 1, 1
	BRA         L_main23
	DECFSZ      R12, 1, 1
	BRA         L_main23
	DECFSZ      R11, 1, 1
	BRA         L_main23
	NOP
	NOP
;Multimeter _ UITS.c,177 :: 		if(voltdc>10 && currdc>5)
	MOVLW       0
	MOVWF       R0 
	MOVF        _voltdc+1, 0 
	SUBWF       R0, 0 
	BTFSS       STATUS+0, 2 
	GOTO        L__main70
	MOVF        _voltdc+0, 0 
	SUBLW       10
L__main70:
	BTFSC       STATUS+0, 0 
	GOTO        L_main26
	MOVLW       0
	MOVWF       R0 
	MOVF        _currdc+1, 0 
	SUBWF       R0, 0 
	BTFSS       STATUS+0, 2 
	GOTO        L__main71
	MOVF        _currdc+0, 0 
	SUBLW       5
L__main71:
	BTFSC       STATUS+0, 0 
	GOTO        L_main26
L__main59:
;Multimeter _ UITS.c,179 :: 		DC_power(void);
	CALL        _DC_power+0, 0
;Multimeter _ UITS.c,180 :: 		}
L_main26:
;Multimeter _ UITS.c,181 :: 		}
L_main22:
;Multimeter _ UITS.c,184 :: 		}//while(1)
	GOTO        L_main9
;Multimeter _ UITS.c,185 :: 		}//void
L_end_main:
	GOTO        $+0
; end of _main

_Get_Voltage:

;Multimeter _ UITS.c,187 :: 		void Get_Voltage(void)
;Multimeter _ UITS.c,189 :: 		unsigned int temp0=0;
	CLRF        Get_Voltage_temp0_L0+0 
	CLRF        Get_Voltage_temp0_L0+1 
	CLRF        Get_Voltage_maxpoint0_L0+0 
	CLRF        Get_Voltage_maxpoint0_L0+1 
	CLRF        Get_Voltage_k_L0+0 
	CLRF        Get_Voltage_k_L0+1 
;Multimeter _ UITS.c,192 :: 		ADCON0 = 0b00001001;// AN1 selected
	MOVLW       9
	MOVWF       ADCON0+0 
;Multimeter _ UITS.c,193 :: 		for(k=0;k<1000;k++)
	CLRF        Get_Voltage_k_L0+0 
	CLRF        Get_Voltage_k_L0+1 
L_Get_Voltage27:
	MOVLW       3
	SUBWF       Get_Voltage_k_L0+1, 0 
	BTFSS       STATUS+0, 2 
	GOTO        L__Get_Voltage73
	MOVLW       232
	SUBWF       Get_Voltage_k_L0+0, 0 
L__Get_Voltage73:
	BTFSC       STATUS+0, 0 
	GOTO        L_Get_Voltage28
;Multimeter _ UITS.c,195 :: 		if(temp0 = ADC_Read(2),temp0>maxpoint0)
	MOVLW       2
	MOVWF       FARG_ADC_Read_channel+0 
	CALL        _ADC_Read+0, 0
	MOVF        R0, 0 
	MOVWF       Get_Voltage_temp0_L0+0 
	MOVF        R1, 0 
	MOVWF       Get_Voltage_temp0_L0+1 
	MOVF        R1, 0 
	SUBWF       Get_Voltage_maxpoint0_L0+1, 0 
	BTFSS       STATUS+0, 2 
	GOTO        L__Get_Voltage74
	MOVF        R0, 0 
	SUBWF       Get_Voltage_maxpoint0_L0+0, 0 
L__Get_Voltage74:
	BTFSC       STATUS+0, 0 
	GOTO        L_Get_Voltage30
;Multimeter _ UITS.c,197 :: 		maxpoint0 = temp0;
	MOVF        Get_Voltage_temp0_L0+0, 0 
	MOVWF       Get_Voltage_maxpoint0_L0+0 
	MOVF        Get_Voltage_temp0_L0+1, 0 
	MOVWF       Get_Voltage_maxpoint0_L0+1 
;Multimeter _ UITS.c,198 :: 		}
L_Get_Voltage30:
;Multimeter _ UITS.c,193 :: 		for(k=0;k<1000;k++)
	INFSNZ      Get_Voltage_k_L0+0, 1 
	INCF        Get_Voltage_k_L0+1, 1 
;Multimeter _ UITS.c,199 :: 		}
	GOTO        L_Get_Voltage27
L_Get_Voltage28:
;Multimeter _ UITS.c,200 :: 		maxpoint0 = abs(ceil(maxpoint0));
	MOVF        Get_Voltage_maxpoint0_L0+0, 0 
	MOVWF       R0 
	MOVF        Get_Voltage_maxpoint0_L0+1, 0 
	MOVWF       R1 
	CALL        _word2double+0, 0
	MOVF        R0, 0 
	MOVWF       FARG_ceil_x+0 
	MOVF        R1, 0 
	MOVWF       FARG_ceil_x+1 
	MOVF        R2, 0 
	MOVWF       FARG_ceil_x+2 
	MOVF        R3, 0 
	MOVWF       FARG_ceil_x+3 
	CALL        _ceil+0, 0
	CALL        _double2int+0, 0
	MOVF        R0, 0 
	MOVWF       FARG_abs_a+0 
	MOVF        R1, 0 
	MOVWF       FARG_abs_a+1 
	CALL        _abs+0, 0
	MOVF        R0, 0 
	MOVWF       Get_Voltage_maxpoint0_L0+0 
	MOVF        R1, 0 
	MOVWF       Get_Voltage_maxpoint0_L0+1 
;Multimeter _ UITS.c,201 :: 		voltage = (float)maxpoint0*0.655;// (5/1023)*11.00*0.707*220/12*calibration factor;
	CALL        _word2double+0, 0
	MOVLW       20
	MOVWF       R4 
	MOVLW       174
	MOVWF       R5 
	MOVLW       39
	MOVWF       R6 
	MOVLW       126
	MOVWF       R7 
	CALL        _Mul_32x32_FP+0, 0
	MOVF        R0, 0 
	MOVWF       _voltage+0 
	MOVF        R1, 0 
	MOVWF       _voltage+1 
	MOVF        R2, 0 
	MOVWF       _voltage+2 
	MOVF        R3, 0 
	MOVWF       _voltage+3 
;Multimeter _ UITS.c,202 :: 		v_long = (int)voltage;
	CALL        _double2int+0, 0
	MOVF        R0, 0 
	MOVWF       _v_long+0 
	MOVF        R1, 0 
	MOVWF       _v_long+1 
	MOVLW       0
	BTFSC       R1, 7 
	MOVLW       255
	MOVWF       _v_long+2 
	MOVWF       _v_long+3 
;Multimeter _ UITS.c,203 :: 		maxpoint0 = 0;
	CLRF        Get_Voltage_maxpoint0_L0+0 
	CLRF        Get_Voltage_maxpoint0_L0+1 
;Multimeter _ UITS.c,204 :: 		}
L_end_Get_Voltage:
	RETURN      0
; end of _Get_Voltage

_Disp_vac:

;Multimeter _ UITS.c,205 :: 		void Disp_vac(void)
;Multimeter _ UITS.c,207 :: 		msg_ac_vlt[3] = (v_long/100) +48;
	MOVLW       100
	MOVWF       R4 
	MOVLW       0
	MOVWF       R5 
	MOVWF       R6 
	MOVWF       R7 
	MOVF        _v_long+0, 0 
	MOVWF       R0 
	MOVF        _v_long+1, 0 
	MOVWF       R1 
	MOVF        _v_long+2, 0 
	MOVWF       R2 
	MOVF        _v_long+3, 0 
	MOVWF       R3 
	CALL        _Div_32x32_S+0, 0
	MOVLW       48
	ADDWF       R0, 0 
	MOVWF       _msg_ac_vlt+3 
;Multimeter _ UITS.c,208 :: 		msg_ac_vlt[4] = (v_long/10)%10 +48;
	MOVLW       10
	MOVWF       R4 
	MOVLW       0
	MOVWF       R5 
	MOVWF       R6 
	MOVWF       R7 
	MOVF        _v_long+0, 0 
	MOVWF       R0 
	MOVF        _v_long+1, 0 
	MOVWF       R1 
	MOVF        _v_long+2, 0 
	MOVWF       R2 
	MOVF        _v_long+3, 0 
	MOVWF       R3 
	CALL        _Div_32x32_S+0, 0
	MOVLW       10
	MOVWF       R4 
	MOVLW       0
	MOVWF       R5 
	MOVWF       R6 
	MOVWF       R7 
	CALL        _Div_32x32_S+0, 0
	MOVF        R8, 0 
	MOVWF       R0 
	MOVF        R9, 0 
	MOVWF       R1 
	MOVF        R10, 0 
	MOVWF       R2 
	MOVF        R11, 0 
	MOVWF       R3 
	MOVLW       48
	ADDWF       R0, 0 
	MOVWF       _msg_ac_vlt+4 
;Multimeter _ UITS.c,209 :: 		msg_ac_vlt[5] =  v_long%10 +48;
	MOVLW       10
	MOVWF       R4 
	MOVLW       0
	MOVWF       R5 
	MOVWF       R6 
	MOVWF       R7 
	MOVF        _v_long+0, 0 
	MOVWF       R0 
	MOVF        _v_long+1, 0 
	MOVWF       R1 
	MOVF        _v_long+2, 0 
	MOVWF       R2 
	MOVF        _v_long+3, 0 
	MOVWF       R3 
	CALL        _Div_32x32_S+0, 0
	MOVF        R8, 0 
	MOVWF       R0 
	MOVF        R9, 0 
	MOVWF       R1 
	MOVF        R10, 0 
	MOVWF       R2 
	MOVF        R11, 0 
	MOVWF       R3 
	MOVLW       48
	ADDWF       R0, 0 
	MOVWF       _msg_ac_vlt+5 
;Multimeter _ UITS.c,210 :: 		Lcd_Out(1,1, msg_ac_vlt);
	MOVLW       1
	MOVWF       FARG_Lcd_Out_row+0 
	MOVLW       1
	MOVWF       FARG_Lcd_Out_column+0 
	MOVLW       _msg_ac_vlt+0
	MOVWF       FARG_Lcd_Out_text+0 
	MOVLW       hi_addr(_msg_ac_vlt+0)
	MOVWF       FARG_Lcd_Out_text+1 
	CALL        _Lcd_Out+0, 0
;Multimeter _ UITS.c,211 :: 		Delay_ms(20);
	MOVLW       130
	MOVWF       R12, 0
	MOVLW       221
	MOVWF       R13, 0
L_Disp_vac31:
	DECFSZ      R13, 1, 1
	BRA         L_Disp_vac31
	DECFSZ      R12, 1, 1
	BRA         L_Disp_vac31
	NOP
	NOP
;Multimeter _ UITS.c,212 :: 		}
L_end_Disp_vac:
	RETURN      0
; end of _Disp_vac

_Get_Current:

;Multimeter _ UITS.c,213 :: 		void Get_Current(void)
;Multimeter _ UITS.c,215 :: 		unsigned int temp1=0;
	CLRF        Get_Current_temp1_L0+0 
	CLRF        Get_Current_temp1_L0+1 
	CLRF        Get_Current_maxpoint1_L0+0 
	CLRF        Get_Current_maxpoint1_L0+1 
	CLRF        Get_Current_kk_L0+0 
	CLRF        Get_Current_kk_L0+1 
;Multimeter _ UITS.c,218 :: 		ADCON0 = 0b00000101;// AN1 selected
	MOVLW       5
	MOVWF       ADCON0+0 
;Multimeter _ UITS.c,219 :: 		for(kk=0;kk<1000;kk++)
	CLRF        Get_Current_kk_L0+0 
	CLRF        Get_Current_kk_L0+1 
L_Get_Current32:
	MOVLW       128
	XORWF       Get_Current_kk_L0+1, 0 
	MOVWF       R0 
	MOVLW       128
	XORLW       3
	SUBWF       R0, 0 
	BTFSS       STATUS+0, 2 
	GOTO        L__Get_Current77
	MOVLW       232
	SUBWF       Get_Current_kk_L0+0, 0 
L__Get_Current77:
	BTFSC       STATUS+0, 0 
	GOTO        L_Get_Current33
;Multimeter _ UITS.c,221 :: 		if(temp1 = ADC_Read(1),temp1>maxpoint1)
	MOVLW       1
	MOVWF       FARG_ADC_Read_channel+0 
	CALL        _ADC_Read+0, 0
	MOVF        R0, 0 
	MOVWF       Get_Current_temp1_L0+0 
	MOVF        R1, 0 
	MOVWF       Get_Current_temp1_L0+1 
	MOVF        R1, 0 
	SUBWF       Get_Current_maxpoint1_L0+1, 0 
	BTFSS       STATUS+0, 2 
	GOTO        L__Get_Current78
	MOVF        R0, 0 
	SUBWF       Get_Current_maxpoint1_L0+0, 0 
L__Get_Current78:
	BTFSC       STATUS+0, 0 
	GOTO        L_Get_Current35
;Multimeter _ UITS.c,223 :: 		maxpoint1 = temp1;
	MOVF        Get_Current_temp1_L0+0, 0 
	MOVWF       Get_Current_maxpoint1_L0+0 
	MOVF        Get_Current_temp1_L0+1, 0 
	MOVWF       Get_Current_maxpoint1_L0+1 
;Multimeter _ UITS.c,224 :: 		}
L_Get_Current35:
;Multimeter _ UITS.c,219 :: 		for(kk=0;kk<1000;kk++)
	INFSNZ      Get_Current_kk_L0+0, 1 
	INCF        Get_Current_kk_L0+1, 1 
;Multimeter _ UITS.c,225 :: 		}
	GOTO        L_Get_Current32
L_Get_Current33:
;Multimeter _ UITS.c,226 :: 		Current = (float)maxpoint1*0.186;// get the load current
	MOVF        Get_Current_maxpoint1_L0+0, 0 
	MOVWF       R0 
	MOVF        Get_Current_maxpoint1_L0+1, 0 
	MOVWF       R1 
	CALL        _word2double+0, 0
	MOVLW       201
	MOVWF       R4 
	MOVLW       118
	MOVWF       R5 
	MOVLW       62
	MOVWF       R6 
	MOVLW       124
	MOVWF       R7 
	CALL        _Mul_32x32_FP+0, 0
	MOVF        R0, 0 
	MOVWF       _Current+0 
	MOVF        R1, 0 
	MOVWF       _Current+1 
	MOVF        R2, 0 
	MOVWF       _Current+2 
	MOVF        R3, 0 
	MOVWF       _Current+3 
;Multimeter _ UITS.c,227 :: 		C_long = (int)Current;
	CALL        _double2int+0, 0
	MOVF        R0, 0 
	MOVWF       _C_long+0 
	MOVF        R1, 0 
	MOVWF       _C_long+1 
	MOVLW       0
	BTFSC       R1, 7 
	MOVLW       255
	MOVWF       _C_long+2 
	MOVWF       _C_long+3 
;Multimeter _ UITS.c,228 :: 		maxpoint1 = 0;
	CLRF        Get_Current_maxpoint1_L0+0 
	CLRF        Get_Current_maxpoint1_L0+1 
;Multimeter _ UITS.c,229 :: 		}
L_end_Get_Current:
	RETURN      0
; end of _Get_Current

_Disp_iac:

;Multimeter _ UITS.c,231 :: 		void Disp_iac(void)
;Multimeter _ UITS.c,233 :: 		masg_ac_curr[3] = C_long/100+48;
	MOVLW       100
	MOVWF       R4 
	MOVLW       0
	MOVWF       R5 
	MOVWF       R6 
	MOVWF       R7 
	MOVF        _C_long+0, 0 
	MOVWF       R0 
	MOVF        _C_long+1, 0 
	MOVWF       R1 
	MOVF        _C_long+2, 0 
	MOVWF       R2 
	MOVF        _C_long+3, 0 
	MOVWF       R3 
	CALL        _Div_32x32_S+0, 0
	MOVLW       48
	ADDWF       R0, 0 
	MOVWF       _masg_ac_curr+3 
;Multimeter _ UITS.c,234 :: 		masg_ac_curr[4] = '.';
	MOVLW       46
	MOVWF       _masg_ac_curr+4 
;Multimeter _ UITS.c,235 :: 		masg_ac_curr[5] = (C_long/10)%10 +48;
	MOVLW       10
	MOVWF       R4 
	MOVLW       0
	MOVWF       R5 
	MOVWF       R6 
	MOVWF       R7 
	MOVF        _C_long+0, 0 
	MOVWF       R0 
	MOVF        _C_long+1, 0 
	MOVWF       R1 
	MOVF        _C_long+2, 0 
	MOVWF       R2 
	MOVF        _C_long+3, 0 
	MOVWF       R3 
	CALL        _Div_32x32_S+0, 0
	MOVLW       10
	MOVWF       R4 
	MOVLW       0
	MOVWF       R5 
	MOVWF       R6 
	MOVWF       R7 
	CALL        _Div_32x32_S+0, 0
	MOVF        R8, 0 
	MOVWF       R0 
	MOVF        R9, 0 
	MOVWF       R1 
	MOVF        R10, 0 
	MOVWF       R2 
	MOVF        R11, 0 
	MOVWF       R3 
	MOVLW       48
	ADDWF       R0, 0 
	MOVWF       _masg_ac_curr+5 
;Multimeter _ UITS.c,236 :: 		masg_ac_curr[6] = (C_long/1)%10 +48;
	MOVLW       10
	MOVWF       R4 
	MOVLW       0
	MOVWF       R5 
	MOVWF       R6 
	MOVWF       R7 
	MOVF        _C_long+0, 0 
	MOVWF       R0 
	MOVF        _C_long+1, 0 
	MOVWF       R1 
	MOVF        _C_long+2, 0 
	MOVWF       R2 
	MOVF        _C_long+3, 0 
	MOVWF       R3 
	CALL        _Div_32x32_S+0, 0
	MOVF        R8, 0 
	MOVWF       R0 
	MOVF        R9, 0 
	MOVWF       R1 
	MOVF        R10, 0 
	MOVWF       R2 
	MOVF        R11, 0 
	MOVWF       R3 
	MOVLW       48
	ADDWF       R0, 0 
	MOVWF       _masg_ac_curr+6 
;Multimeter _ UITS.c,237 :: 		Lcd_Out(1,9,masg_ac_curr);
	MOVLW       1
	MOVWF       FARG_Lcd_Out_row+0 
	MOVLW       9
	MOVWF       FARG_Lcd_Out_column+0 
	MOVLW       _masg_ac_curr+0
	MOVWF       FARG_Lcd_Out_text+0 
	MOVLW       hi_addr(_masg_ac_curr+0)
	MOVWF       FARG_Lcd_Out_text+1 
	CALL        _Lcd_Out+0, 0
;Multimeter _ UITS.c,238 :: 		Delay_ms(50);
	MOVLW       2
	MOVWF       R11, 0
	MOVLW       69
	MOVWF       R12, 0
	MOVLW       169
	MOVWF       R13, 0
L_Disp_iac36:
	DECFSZ      R13, 1, 1
	BRA         L_Disp_iac36
	DECFSZ      R12, 1, 1
	BRA         L_Disp_iac36
	DECFSZ      R11, 1, 1
	BRA         L_Disp_iac36
	NOP
	NOP
;Multimeter _ UITS.c,239 :: 		}
L_end_Disp_iac:
	RETURN      0
; end of _Disp_iac

_Get_PF:

;Multimeter _ UITS.c,240 :: 		void Get_PF(void)
;Multimeter _ UITS.c,242 :: 		for(i=0;i<100;i++)
	CLRF        _i+0 
	CLRF        _i+1 
L_Get_PF37:
	MOVLW       0
	SUBWF       _i+1, 0 
	BTFSS       STATUS+0, 2 
	GOTO        L__Get_PF81
	MOVLW       100
	SUBWF       _i+0, 0 
L__Get_PF81:
	BTFSC       STATUS+0, 0 
	GOTO        L_Get_PF38
;Multimeter _ UITS.c,244 :: 		sample[i] = 0;
	MOVF        _i+0, 0 
	MOVWF       R0 
	MOVF        _i+1, 0 
	MOVWF       R1 
	RLCF        R0, 1 
	BCF         R0, 0 
	RLCF        R1, 1 
	MOVLW       _sample+0
	ADDWF       R0, 0 
	MOVWF       FSR1 
	MOVLW       hi_addr(_sample+0)
	ADDWFC      R1, 0 
	MOVWF       FSR1H 
	CLRF        POSTINC1+0 
	CLRF        POSTINC1+0 
;Multimeter _ UITS.c,245 :: 		i++;
	INFSNZ      _i+0, 1 
	INCF        _i+1, 1 
;Multimeter _ UITS.c,242 :: 		for(i=0;i<100;i++)
	INFSNZ      _i+0, 1 
	INCF        _i+1, 1 
;Multimeter _ UITS.c,246 :: 		}
	GOTO        L_Get_PF37
L_Get_PF38:
;Multimeter _ UITS.c,247 :: 		Delay_ms(100);
	MOVLW       3
	MOVWF       R11, 0
	MOVLW       138
	MOVWF       R12, 0
	MOVLW       85
	MOVWF       R13, 0
L_Get_PF40:
	DECFSZ      R13, 1, 1
	BRA         L_Get_PF40
	DECFSZ      R12, 1, 1
	BRA         L_Get_PF40
	DECFSZ      R11, 1, 1
	BRA         L_Get_PF40
	NOP
	NOP
;Multimeter _ UITS.c,248 :: 		GIE_bit = 1;//Enable Interrupt
	BSF         GIE_bit+0, BitPos(GIE_bit+0) 
;Multimeter _ UITS.c,249 :: 		INT0IE_bit = 1;//enable INT1
	BSF         INT0IE_bit+0, BitPos(INT0IE_bit+0) 
;Multimeter _ UITS.c,250 :: 		INT1IE_bit = 1;//enable INT1
	BSF         INT1IE_bit+0, BitPos(INT1IE_bit+0) 
;Multimeter _ UITS.c,251 :: 		TMR1IE_bit = 1;
	BSF         TMR1IE_bit+0, BitPos(TMR1IE_bit+0) 
;Multimeter _ UITS.c,252 :: 		Delay_ms(2000);
	MOVLW       51
	MOVWF       R11, 0
	MOVLW       187
	MOVWF       R12, 0
	MOVLW       223
	MOVWF       R13, 0
L_Get_PF41:
	DECFSZ      R13, 1, 1
	BRA         L_Get_PF41
	DECFSZ      R12, 1, 1
	BRA         L_Get_PF41
	DECFSZ      R11, 1, 1
	BRA         L_Get_PF41
	NOP
	NOP
;Multimeter _ UITS.c,253 :: 		result = (float)cos((final_pf_cnt*2*3.1416)/1000);
	MOVF        _final_pf_cnt+0, 0 
	MOVWF       R0 
	MOVF        _final_pf_cnt+1, 0 
	MOVWF       R1 
	RLCF        R0, 1 
	BCF         R0, 0 
	RLCF        R1, 1 
	CALL        _word2double+0, 0
	MOVLW       249
	MOVWF       R4 
	MOVLW       15
	MOVWF       R5 
	MOVLW       73
	MOVWF       R6 
	MOVLW       128
	MOVWF       R7 
	CALL        _Mul_32x32_FP+0, 0
	MOVLW       0
	MOVWF       R4 
	MOVLW       0
	MOVWF       R5 
	MOVLW       122
	MOVWF       R6 
	MOVLW       136
	MOVWF       R7 
	CALL        _Div_32x32_FP+0, 0
	MOVF        R0, 0 
	MOVWF       FARG_cos_f+0 
	MOVF        R1, 0 
	MOVWF       FARG_cos_f+1 
	MOVF        R2, 0 
	MOVWF       FARG_cos_f+2 
	MOVF        R3, 0 
	MOVWF       FARG_cos_f+3 
	CALL        _cos+0, 0
	MOVF        R0, 0 
	MOVWF       _result+0 
	MOVF        R1, 0 
	MOVWF       _result+1 
	MOVF        R2, 0 
	MOVWF       _result+2 
	MOVF        R3, 0 
	MOVWF       _result+3 
;Multimeter _ UITS.c,254 :: 		tlong1 = abs(ceil(result*1000));
	MOVLW       0
	MOVWF       R4 
	MOVLW       0
	MOVWF       R5 
	MOVLW       122
	MOVWF       R6 
	MOVLW       136
	MOVWF       R7 
	CALL        _Mul_32x32_FP+0, 0
	MOVF        R0, 0 
	MOVWF       FARG_ceil_x+0 
	MOVF        R1, 0 
	MOVWF       FARG_ceil_x+1 
	MOVF        R2, 0 
	MOVWF       FARG_ceil_x+2 
	MOVF        R3, 0 
	MOVWF       FARG_ceil_x+3 
	CALL        _ceil+0, 0
	CALL        _double2int+0, 0
	MOVF        R0, 0 
	MOVWF       FARG_abs_a+0 
	MOVF        R1, 0 
	MOVWF       FARG_abs_a+1 
	CALL        _abs+0, 0
	MOVF        R0, 0 
	MOVWF       _tlong1+0 
	MOVF        R1, 0 
	MOVWF       _tlong1+1 
	MOVLW       0
	BTFSC       R1, 7 
	MOVLW       255
	MOVWF       _tlong1+2 
	MOVWF       _tlong1+3 
;Multimeter _ UITS.c,255 :: 		if(tlong>(tlong1+10))tlong-=10;
	MOVLW       10
	ADDWF       _tlong1+0, 0 
	MOVWF       R1 
	MOVLW       0
	ADDWFC      _tlong1+1, 0 
	MOVWF       R2 
	MOVLW       0
	ADDWFC      _tlong1+2, 0 
	MOVWF       R3 
	MOVLW       0
	ADDWFC      _tlong1+3, 0 
	MOVWF       R4 
	MOVLW       128
	XORWF       R4, 0 
	MOVWF       R0 
	MOVLW       128
	XORWF       _tlong+3, 0 
	SUBWF       R0, 0 
	BTFSS       STATUS+0, 2 
	GOTO        L__Get_PF82
	MOVF        _tlong+2, 0 
	SUBWF       R3, 0 
	BTFSS       STATUS+0, 2 
	GOTO        L__Get_PF82
	MOVF        _tlong+1, 0 
	SUBWF       R2, 0 
	BTFSS       STATUS+0, 2 
	GOTO        L__Get_PF82
	MOVF        _tlong+0, 0 
	SUBWF       R1, 0 
L__Get_PF82:
	BTFSC       STATUS+0, 0 
	GOTO        L_Get_PF42
	MOVLW       10
	SUBWF       _tlong+0, 1 
	MOVLW       0
	SUBWFB      _tlong+1, 1 
	SUBWFB      _tlong+2, 1 
	SUBWFB      _tlong+3, 1 
	GOTO        L_Get_PF43
L_Get_PF42:
;Multimeter _ UITS.c,256 :: 		else if(tlong<(tlong1-10))tlong+=10;
	MOVF        _tlong1+0, 0 
	MOVWF       R1 
	MOVF        _tlong1+1, 0 
	MOVWF       R2 
	MOVF        _tlong1+2, 0 
	MOVWF       R3 
	MOVF        _tlong1+3, 0 
	MOVWF       R4 
	MOVLW       10
	SUBWF       R1, 1 
	MOVLW       0
	SUBWFB      R2, 1 
	SUBWFB      R3, 1 
	SUBWFB      R4, 1 
	MOVLW       128
	XORWF       _tlong+3, 0 
	MOVWF       R0 
	MOVLW       128
	XORWF       R4, 0 
	SUBWF       R0, 0 
	BTFSS       STATUS+0, 2 
	GOTO        L__Get_PF83
	MOVF        R3, 0 
	SUBWF       _tlong+2, 0 
	BTFSS       STATUS+0, 2 
	GOTO        L__Get_PF83
	MOVF        R2, 0 
	SUBWF       _tlong+1, 0 
	BTFSS       STATUS+0, 2 
	GOTO        L__Get_PF83
	MOVF        R1, 0 
	SUBWF       _tlong+0, 0 
L__Get_PF83:
	BTFSC       STATUS+0, 0 
	GOTO        L_Get_PF44
	MOVLW       10
	ADDWF       _tlong+0, 1 
	MOVLW       0
	ADDWFC      _tlong+1, 1 
	ADDWFC      _tlong+2, 1 
	ADDWFC      _tlong+3, 1 
	GOTO        L_Get_PF45
L_Get_PF44:
;Multimeter _ UITS.c,257 :: 		else tlong = tlong1;
	MOVF        _tlong1+0, 0 
	MOVWF       _tlong+0 
	MOVF        _tlong1+1, 0 
	MOVWF       _tlong+1 
	MOVF        _tlong1+2, 0 
	MOVWF       _tlong+2 
	MOVF        _tlong1+3, 0 
	MOVWF       _tlong+3 
L_Get_PF45:
L_Get_PF43:
;Multimeter _ UITS.c,259 :: 		massage1[3] = tlong/1000 + 48;
	MOVLW       232
	MOVWF       R4 
	MOVLW       3
	MOVWF       R5 
	MOVLW       0
	MOVWF       R6 
	MOVWF       R7 
	MOVF        _tlong+0, 0 
	MOVWF       R0 
	MOVF        _tlong+1, 0 
	MOVWF       R1 
	MOVF        _tlong+2, 0 
	MOVWF       R2 
	MOVF        _tlong+3, 0 
	MOVWF       R3 
	CALL        _Div_32x32_S+0, 0
	MOVLW       48
	ADDWF       R0, 0 
	MOVWF       _massage1+3 
;Multimeter _ UITS.c,260 :: 		massage1[5] = (tlong/100)%10 + 48;
	MOVLW       100
	MOVWF       R4 
	MOVLW       0
	MOVWF       R5 
	MOVWF       R6 
	MOVWF       R7 
	MOVF        _tlong+0, 0 
	MOVWF       R0 
	MOVF        _tlong+1, 0 
	MOVWF       R1 
	MOVF        _tlong+2, 0 
	MOVWF       R2 
	MOVF        _tlong+3, 0 
	MOVWF       R3 
	CALL        _Div_32x32_S+0, 0
	MOVLW       10
	MOVWF       R4 
	MOVLW       0
	MOVWF       R5 
	MOVWF       R6 
	MOVWF       R7 
	CALL        _Div_32x32_S+0, 0
	MOVF        R8, 0 
	MOVWF       R0 
	MOVF        R9, 0 
	MOVWF       R1 
	MOVF        R10, 0 
	MOVWF       R2 
	MOVF        R11, 0 
	MOVWF       R3 
	MOVLW       48
	ADDWF       R0, 0 
	MOVWF       _massage1+5 
;Multimeter _ UITS.c,261 :: 		massage1[6] = (tlong/10)%10 + 48;
	MOVLW       10
	MOVWF       R4 
	MOVLW       0
	MOVWF       R5 
	MOVWF       R6 
	MOVWF       R7 
	MOVF        _tlong+0, 0 
	MOVWF       R0 
	MOVF        _tlong+1, 0 
	MOVWF       R1 
	MOVF        _tlong+2, 0 
	MOVWF       R2 
	MOVF        _tlong+3, 0 
	MOVWF       R3 
	CALL        _Div_32x32_S+0, 0
	MOVLW       10
	MOVWF       R4 
	MOVLW       0
	MOVWF       R5 
	MOVWF       R6 
	MOVWF       R7 
	CALL        _Div_32x32_S+0, 0
	MOVF        R8, 0 
	MOVWF       R0 
	MOVF        R9, 0 
	MOVWF       R1 
	MOVF        R10, 0 
	MOVWF       R2 
	MOVF        R11, 0 
	MOVWF       R3 
	MOVLW       48
	ADDWF       R0, 0 
	MOVWF       _massage1+6 
;Multimeter _ UITS.c,262 :: 		power_factor = (float)result;
	MOVF        _result+0, 0 
	MOVWF       _power_factor+0 
	MOVF        _result+1, 0 
	MOVWF       _power_factor+1 
	MOVF        _result+2, 0 
	MOVWF       _power_factor+2 
	MOVF        _result+3, 0 
	MOVWF       _power_factor+3 
;Multimeter _ UITS.c,263 :: 		Lcd_Out(1,1,massage1);
	MOVLW       1
	MOVWF       FARG_Lcd_Out_row+0 
	MOVLW       1
	MOVWF       FARG_Lcd_Out_column+0 
	MOVLW       _massage1+0
	MOVWF       FARG_Lcd_Out_text+0 
	MOVLW       hi_addr(_massage1+0)
	MOVWF       FARG_Lcd_Out_text+1 
	CALL        _Lcd_Out+0, 0
;Multimeter _ UITS.c,264 :: 		Delay_ms(20);
	MOVLW       130
	MOVWF       R12, 0
	MOVLW       221
	MOVWF       R13, 0
L_Get_PF46:
	DECFSZ      R13, 1, 1
	BRA         L_Get_PF46
	DECFSZ      R12, 1, 1
	BRA         L_Get_PF46
	NOP
	NOP
;Multimeter _ UITS.c,265 :: 		GIE_bit = 0;//Disable Interrupt
	BCF         GIE_bit+0, BitPos(GIE_bit+0) 
;Multimeter _ UITS.c,266 :: 		INT0IE_bit = 0;//enable INT1
	BCF         INT0IE_bit+0, BitPos(INT0IE_bit+0) 
;Multimeter _ UITS.c,267 :: 		INT1IE_bit = 0;//enable INT1
	BCF         INT1IE_bit+0, BitPos(INT1IE_bit+0) 
;Multimeter _ UITS.c,268 :: 		TMR1IE_bit = 0;
	BCF         TMR1IE_bit+0, BitPos(TMR1IE_bit+0) 
;Multimeter _ UITS.c,269 :: 		}
L_end_Get_PF:
	RETURN      0
; end of _Get_PF

_AC_power:

;Multimeter _ UITS.c,271 :: 		void AC_power(void)
;Multimeter _ UITS.c,273 :: 		char msg_acpwr[] = "Pa:000W ";
	MOVLW       80
	MOVWF       AC_power_msg_acpwr_L0+0 
	MOVLW       97
	MOVWF       AC_power_msg_acpwr_L0+1 
	MOVLW       58
	MOVWF       AC_power_msg_acpwr_L0+2 
	MOVLW       48
	MOVWF       AC_power_msg_acpwr_L0+3 
	MOVLW       48
	MOVWF       AC_power_msg_acpwr_L0+4 
	MOVLW       48
	MOVWF       AC_power_msg_acpwr_L0+5 
	MOVLW       87
	MOVWF       AC_power_msg_acpwr_L0+6 
	MOVLW       32
	MOVWF       AC_power_msg_acpwr_L0+7 
	CLRF        AC_power_msg_acpwr_L0+8 
;Multimeter _ UITS.c,274 :: 		P_long = (int)v_long*C_long*tlong/100000;//watt
	MOVF        _v_long+0, 0 
	MOVWF       R0 
	MOVF        _v_long+1, 0 
	MOVWF       R1 
	MOVLW       0
	BTFSC       _v_long+1, 7 
	MOVLW       255
	MOVWF       R2 
	MOVWF       R3 
	MOVF        _C_long+0, 0 
	MOVWF       R4 
	MOVF        _C_long+1, 0 
	MOVWF       R5 
	MOVF        _C_long+2, 0 
	MOVWF       R6 
	MOVF        _C_long+3, 0 
	MOVWF       R7 
	CALL        _Mul_32x32_U+0, 0
	MOVF        _tlong+0, 0 
	MOVWF       R4 
	MOVF        _tlong+1, 0 
	MOVWF       R5 
	MOVF        _tlong+2, 0 
	MOVWF       R6 
	MOVF        _tlong+3, 0 
	MOVWF       R7 
	CALL        _Mul_32x32_U+0, 0
	MOVLW       160
	MOVWF       R4 
	MOVLW       134
	MOVWF       R5 
	MOVLW       1
	MOVWF       R6 
	MOVLW       0
	MOVWF       R7 
	CALL        _Div_32x32_S+0, 0
	MOVF        R0, 0 
	MOVWF       FLOC__AC_power+0 
	MOVF        R1, 0 
	MOVWF       FLOC__AC_power+1 
	MOVF        R2, 0 
	MOVWF       FLOC__AC_power+2 
	MOVF        R3, 0 
	MOVWF       FLOC__AC_power+3 
	MOVF        FLOC__AC_power+0, 0 
	MOVWF       _P_long+0 
	MOVF        FLOC__AC_power+1, 0 
	MOVWF       _P_long+1 
	MOVF        FLOC__AC_power+2, 0 
	MOVWF       _P_long+2 
	MOVF        FLOC__AC_power+3, 0 
	MOVWF       _P_long+3 
;Multimeter _ UITS.c,275 :: 		msg_acpwr[3] = P_long/100 +48;
	MOVLW       100
	MOVWF       R4 
	MOVLW       0
	MOVWF       R5 
	MOVWF       R6 
	MOVWF       R7 
	MOVF        FLOC__AC_power+0, 0 
	MOVWF       R0 
	MOVF        FLOC__AC_power+1, 0 
	MOVWF       R1 
	MOVF        FLOC__AC_power+2, 0 
	MOVWF       R2 
	MOVF        FLOC__AC_power+3, 0 
	MOVWF       R3 
	CALL        _Div_32x32_S+0, 0
	MOVLW       48
	ADDWF       R0, 0 
	MOVWF       AC_power_msg_acpwr_L0+3 
;Multimeter _ UITS.c,276 :: 		msg_acpwr[4] = (P_long/10)%10 +48;
	MOVLW       10
	MOVWF       R4 
	MOVLW       0
	MOVWF       R5 
	MOVWF       R6 
	MOVWF       R7 
	MOVF        FLOC__AC_power+0, 0 
	MOVWF       R0 
	MOVF        FLOC__AC_power+1, 0 
	MOVWF       R1 
	MOVF        FLOC__AC_power+2, 0 
	MOVWF       R2 
	MOVF        FLOC__AC_power+3, 0 
	MOVWF       R3 
	CALL        _Div_32x32_S+0, 0
	MOVLW       10
	MOVWF       R4 
	MOVLW       0
	MOVWF       R5 
	MOVWF       R6 
	MOVWF       R7 
	CALL        _Div_32x32_S+0, 0
	MOVF        R8, 0 
	MOVWF       R0 
	MOVF        R9, 0 
	MOVWF       R1 
	MOVF        R10, 0 
	MOVWF       R2 
	MOVF        R11, 0 
	MOVWF       R3 
	MOVLW       48
	ADDWF       R0, 0 
	MOVWF       AC_power_msg_acpwr_L0+4 
;Multimeter _ UITS.c,277 :: 		msg_acpwr[5] = (P_long)%10 +48;
	MOVLW       10
	MOVWF       R4 
	MOVLW       0
	MOVWF       R5 
	MOVWF       R6 
	MOVWF       R7 
	MOVF        FLOC__AC_power+0, 0 
	MOVWF       R0 
	MOVF        FLOC__AC_power+1, 0 
	MOVWF       R1 
	MOVF        FLOC__AC_power+2, 0 
	MOVWF       R2 
	MOVF        FLOC__AC_power+3, 0 
	MOVWF       R3 
	CALL        _Div_32x32_S+0, 0
	MOVF        R8, 0 
	MOVWF       R0 
	MOVF        R9, 0 
	MOVWF       R1 
	MOVF        R10, 0 
	MOVWF       R2 
	MOVF        R11, 0 
	MOVWF       R3 
	MOVLW       48
	ADDWF       R0, 0 
	MOVWF       AC_power_msg_acpwr_L0+5 
;Multimeter _ UITS.c,278 :: 		Lcd_Out(1,9,msg_acpwr);
	MOVLW       1
	MOVWF       FARG_Lcd_Out_row+0 
	MOVLW       9
	MOVWF       FARG_Lcd_Out_column+0 
	MOVLW       AC_power_msg_acpwr_L0+0
	MOVWF       FARG_Lcd_Out_text+0 
	MOVLW       hi_addr(AC_power_msg_acpwr_L0+0)
	MOVWF       FARG_Lcd_Out_text+1 
	CALL        _Lcd_Out+0, 0
;Multimeter _ UITS.c,279 :: 		Delay_ms(3000);
	MOVLW       77
	MOVWF       R11, 0
	MOVLW       25
	MOVWF       R12, 0
	MOVLW       79
	MOVWF       R13, 0
L_AC_power47:
	DECFSZ      R13, 1, 1
	BRA         L_AC_power47
	DECFSZ      R12, 1, 1
	BRA         L_AC_power47
	DECFSZ      R11, 1, 1
	BRA         L_AC_power47
	NOP
	NOP
;Multimeter _ UITS.c,280 :: 		}
L_end_AC_power:
	RETURN      0
; end of _AC_power

_Get_dc_volt:

;Multimeter _ UITS.c,283 :: 		void Get_dc_volt(void)
;Multimeter _ UITS.c,285 :: 		maxpoint11 = 0;
	CLRF        _maxpoint11+0 
	CLRF        _maxpoint11+1 
;Multimeter _ UITS.c,286 :: 		ADCON0 = 0b00001101;// AN3 selected
	MOVLW       13
	MOVWF       ADCON0+0 
;Multimeter _ UITS.c,287 :: 		for(k11=0;k11<5;k11++)
	CLRF        _k11+0 
	CLRF        _k11+1 
L_Get_dc_volt48:
	MOVLW       0
	SUBWF       _k11+1, 0 
	BTFSS       STATUS+0, 2 
	GOTO        L__Get_dc_volt86
	MOVLW       5
	SUBWF       _k11+0, 0 
L__Get_dc_volt86:
	BTFSC       STATUS+0, 0 
	GOTO        L_Get_dc_volt49
;Multimeter _ UITS.c,289 :: 		maxpoint11+=ADC_Read(3);
	MOVLW       3
	MOVWF       FARG_ADC_Read_channel+0 
	CALL        _ADC_Read+0, 0
	MOVF        R0, 0 
	ADDWF       _maxpoint11+0, 1 
	MOVF        R1, 0 
	ADDWFC      _maxpoint11+1, 1 
;Multimeter _ UITS.c,290 :: 		Delay_ms(20);
	MOVLW       130
	MOVWF       R12, 0
	MOVLW       221
	MOVWF       R13, 0
L_Get_dc_volt51:
	DECFSZ      R13, 1, 1
	BRA         L_Get_dc_volt51
	DECFSZ      R12, 1, 1
	BRA         L_Get_dc_volt51
	NOP
	NOP
;Multimeter _ UITS.c,287 :: 		for(k11=0;k11<5;k11++)
	INFSNZ      _k11+0, 1 
	INCF        _k11+1, 1 
;Multimeter _ UITS.c,291 :: 		}
	GOTO        L_Get_dc_volt48
L_Get_dc_volt49:
;Multimeter _ UITS.c,292 :: 		maxpoint11/=5;
	MOVLW       5
	MOVWF       R4 
	MOVLW       0
	MOVWF       R5 
	MOVF        _maxpoint11+0, 0 
	MOVWF       R0 
	MOVF        _maxpoint11+1, 0 
	MOVWF       R1 
	CALL        _Div_16X16_U+0, 0
	MOVF        R0, 0 
	MOVWF       _maxpoint11+0 
	MOVF        R1, 0 
	MOVWF       _maxpoint11+1 
;Multimeter _ UITS.c,293 :: 		voltdc = (float)maxpoint11*1.27077;;
	CALL        _word2double+0, 0
	MOVLW       151
	MOVWF       R4 
	MOVLW       168
	MOVWF       R5 
	MOVLW       34
	MOVWF       R6 
	MOVLW       127
	MOVWF       R7 
	CALL        _Mul_32x32_FP+0, 0
	CALL        _double2word+0, 0
	MOVF        R0, 0 
	MOVWF       _voltdc+0 
	MOVF        R1, 0 
	MOVWF       _voltdc+1 
;Multimeter _ UITS.c,294 :: 		v_longdc = (int)voltdc;
	MOVF        R0, 0 
	MOVWF       _v_longdc+0 
	MOVF        R1, 0 
	MOVWF       _v_longdc+1 
;Multimeter _ UITS.c,295 :: 		}
L_end_Get_dc_volt:
	RETURN      0
; end of _Get_dc_volt

_Disp_vdc:

;Multimeter _ UITS.c,297 :: 		void Disp_vdc(void)
;Multimeter _ UITS.c,299 :: 		msg_dc_vlt[3] = (v_longdc/100) +48;
	MOVLW       100
	MOVWF       R4 
	MOVLW       0
	MOVWF       R5 
	MOVF        _v_longdc+0, 0 
	MOVWF       R0 
	MOVF        _v_longdc+1, 0 
	MOVWF       R1 
	CALL        _Div_16X16_U+0, 0
	MOVLW       48
	ADDWF       R0, 0 
	MOVWF       _msg_dc_vlt+3 
;Multimeter _ UITS.c,300 :: 		msg_dc_vlt[4] = (v_longdc/10)%10 +48;
	MOVLW       10
	MOVWF       R4 
	MOVLW       0
	MOVWF       R5 
	MOVF        _v_longdc+0, 0 
	MOVWF       R0 
	MOVF        _v_longdc+1, 0 
	MOVWF       R1 
	CALL        _Div_16X16_U+0, 0
	MOVLW       10
	MOVWF       R4 
	MOVLW       0
	MOVWF       R5 
	CALL        _Div_16X16_U+0, 0
	MOVF        R8, 0 
	MOVWF       R0 
	MOVF        R9, 0 
	MOVWF       R1 
	MOVLW       48
	ADDWF       R0, 0 
	MOVWF       _msg_dc_vlt+4 
;Multimeter _ UITS.c,301 :: 		msg_dc_vlt[6] =  v_longdc%10 +48;
	MOVLW       10
	MOVWF       R4 
	MOVLW       0
	MOVWF       R5 
	MOVF        _v_longdc+0, 0 
	MOVWF       R0 
	MOVF        _v_longdc+1, 0 
	MOVWF       R1 
	CALL        _Div_16X16_U+0, 0
	MOVF        R8, 0 
	MOVWF       R0 
	MOVF        R9, 0 
	MOVWF       R1 
	MOVLW       48
	ADDWF       R0, 0 
	MOVWF       _msg_dc_vlt+6 
;Multimeter _ UITS.c,302 :: 		Lcd_Out(2,1,"         ");
	MOVLW       2
	MOVWF       FARG_Lcd_Out_row+0 
	MOVLW       1
	MOVWF       FARG_Lcd_Out_column+0 
	MOVLW       32
	MOVWF       ?lstr5_Multimeter_32__32UITS+0 
	MOVLW       32
	MOVWF       ?lstr5_Multimeter_32__32UITS+1 
	MOVLW       32
	MOVWF       ?lstr5_Multimeter_32__32UITS+2 
	MOVLW       32
	MOVWF       ?lstr5_Multimeter_32__32UITS+3 
	MOVLW       32
	MOVWF       ?lstr5_Multimeter_32__32UITS+4 
	MOVLW       32
	MOVWF       ?lstr5_Multimeter_32__32UITS+5 
	MOVLW       32
	MOVWF       ?lstr5_Multimeter_32__32UITS+6 
	MOVLW       32
	MOVWF       ?lstr5_Multimeter_32__32UITS+7 
	MOVLW       32
	MOVWF       ?lstr5_Multimeter_32__32UITS+8 
	CLRF        ?lstr5_Multimeter_32__32UITS+9 
	MOVLW       ?lstr5_Multimeter_32__32UITS+0
	MOVWF       FARG_Lcd_Out_text+0 
	MOVLW       hi_addr(?lstr5_Multimeter_32__32UITS+0)
	MOVWF       FARG_Lcd_Out_text+1 
	CALL        _Lcd_Out+0, 0
;Multimeter _ UITS.c,303 :: 		Lcd_Out(2,1, msg_dc_vlt);
	MOVLW       2
	MOVWF       FARG_Lcd_Out_row+0 
	MOVLW       1
	MOVWF       FARG_Lcd_Out_column+0 
	MOVLW       _msg_dc_vlt+0
	MOVWF       FARG_Lcd_Out_text+0 
	MOVLW       hi_addr(_msg_dc_vlt+0)
	MOVWF       FARG_Lcd_Out_text+1 
	CALL        _Lcd_Out+0, 0
;Multimeter _ UITS.c,304 :: 		Delay_ms(10);
	MOVLW       65
	MOVWF       R12, 0
	MOVLW       238
	MOVWF       R13, 0
L_Disp_vdc52:
	DECFSZ      R13, 1, 1
	BRA         L_Disp_vdc52
	DECFSZ      R12, 1, 1
	BRA         L_Disp_vdc52
	NOP
;Multimeter _ UITS.c,305 :: 		}
L_end_Disp_vdc:
	RETURN      0
; end of _Disp_vdc

_Get_dc_curr:

;Multimeter _ UITS.c,307 :: 		void Get_dc_curr(void)
;Multimeter _ UITS.c,309 :: 		maxpoint22 = 0;
	CLRF        _maxpoint22+0 
	CLRF        _maxpoint22+1 
;Multimeter _ UITS.c,310 :: 		ADCON0 = 0b00010001;// AN4 selected
	MOVLW       17
	MOVWF       ADCON0+0 
;Multimeter _ UITS.c,311 :: 		for(k22=0;k22<5;k22++)
	CLRF        _k22+0 
	CLRF        _k22+1 
L_Get_dc_curr53:
	MOVLW       0
	SUBWF       _k22+1, 0 
	BTFSS       STATUS+0, 2 
	GOTO        L__Get_dc_curr89
	MOVLW       5
	SUBWF       _k22+0, 0 
L__Get_dc_curr89:
	BTFSC       STATUS+0, 0 
	GOTO        L_Get_dc_curr54
;Multimeter _ UITS.c,313 :: 		maxpoint22+=ADC_Read(4);
	MOVLW       4
	MOVWF       FARG_ADC_Read_channel+0 
	CALL        _ADC_Read+0, 0
	MOVF        R0, 0 
	ADDWF       _maxpoint22+0, 1 
	MOVF        R1, 0 
	ADDWFC      _maxpoint22+1, 1 
;Multimeter _ UITS.c,314 :: 		Delay_ms(20);
	MOVLW       130
	MOVWF       R12, 0
	MOVLW       221
	MOVWF       R13, 0
L_Get_dc_curr56:
	DECFSZ      R13, 1, 1
	BRA         L_Get_dc_curr56
	DECFSZ      R12, 1, 1
	BRA         L_Get_dc_curr56
	NOP
	NOP
;Multimeter _ UITS.c,311 :: 		for(k22=0;k22<5;k22++)
	INFSNZ      _k22+0, 1 
	INCF        _k22+1, 1 
;Multimeter _ UITS.c,315 :: 		}
	GOTO        L_Get_dc_curr53
L_Get_dc_curr54:
;Multimeter _ UITS.c,316 :: 		maxpoint22/=5;
	MOVLW       5
	MOVWF       R4 
	MOVLW       0
	MOVWF       R5 
	MOVF        _maxpoint22+0, 0 
	MOVWF       R0 
	MOVF        _maxpoint22+1, 0 
	MOVWF       R1 
	CALL        _Div_16X16_U+0, 0
	MOVF        R0, 0 
	MOVWF       _maxpoint22+0 
	MOVF        R1, 0 
	MOVWF       _maxpoint22+1 
;Multimeter _ UITS.c,317 :: 		currdc = (float)maxpoint22*0.44149;
	CALL        _word2double+0, 0
	MOVLW       250
	MOVWF       R4 
	MOVLW       10
	MOVWF       R5 
	MOVLW       98
	MOVWF       R6 
	MOVLW       125
	MOVWF       R7 
	CALL        _Mul_32x32_FP+0, 0
	CALL        _double2word+0, 0
	MOVF        R0, 0 
	MOVWF       _currdc+0 
	MOVF        R1, 0 
	MOVWF       _currdc+1 
;Multimeter _ UITS.c,318 :: 		c_longdc = (int)currdc;
	MOVF        R0, 0 
	MOVWF       _c_longdc+0 
	MOVF        R1, 0 
	MOVWF       _c_longdc+1 
;Multimeter _ UITS.c,319 :: 		}
L_end_Get_dc_curr:
	RETURN      0
; end of _Get_dc_curr

_Disp_idc:

;Multimeter _ UITS.c,321 :: 		void Disp_idc(void)
;Multimeter _ UITS.c,323 :: 		masg_dc_curr[2] = (c_longdc/100) +48;
	MOVLW       100
	MOVWF       R4 
	MOVLW       0
	MOVWF       R5 
	MOVF        _c_longdc+0, 0 
	MOVWF       R0 
	MOVF        _c_longdc+1, 0 
	MOVWF       R1 
	CALL        _Div_16X16_U+0, 0
	MOVLW       48
	ADDWF       R0, 0 
	MOVWF       _masg_dc_curr+2 
;Multimeter _ UITS.c,324 :: 		masg_dc_curr[4] = (c_longdc/10)%10 +48;
	MOVLW       10
	MOVWF       R4 
	MOVLW       0
	MOVWF       R5 
	MOVF        _c_longdc+0, 0 
	MOVWF       R0 
	MOVF        _c_longdc+1, 0 
	MOVWF       R1 
	CALL        _Div_16X16_U+0, 0
	MOVLW       10
	MOVWF       R4 
	MOVLW       0
	MOVWF       R5 
	CALL        _Div_16X16_U+0, 0
	MOVF        R8, 0 
	MOVWF       R0 
	MOVF        R9, 0 
	MOVWF       R1 
	MOVLW       48
	ADDWF       R0, 0 
	MOVWF       _masg_dc_curr+4 
;Multimeter _ UITS.c,325 :: 		masg_dc_curr[5] =  c_longdc%10 +48;
	MOVLW       10
	MOVWF       R4 
	MOVLW       0
	MOVWF       R5 
	MOVF        _c_longdc+0, 0 
	MOVWF       R0 
	MOVF        _c_longdc+1, 0 
	MOVWF       R1 
	CALL        _Div_16X16_U+0, 0
	MOVF        R8, 0 
	MOVWF       R0 
	MOVF        R9, 0 
	MOVWF       R1 
	MOVLW       48
	ADDWF       R0, 0 
	MOVWF       _masg_dc_curr+5 
;Multimeter _ UITS.c,326 :: 		Lcd_Out(2,9,"        ");
	MOVLW       2
	MOVWF       FARG_Lcd_Out_row+0 
	MOVLW       9
	MOVWF       FARG_Lcd_Out_column+0 
	MOVLW       32
	MOVWF       ?lstr6_Multimeter_32__32UITS+0 
	MOVLW       32
	MOVWF       ?lstr6_Multimeter_32__32UITS+1 
	MOVLW       32
	MOVWF       ?lstr6_Multimeter_32__32UITS+2 
	MOVLW       32
	MOVWF       ?lstr6_Multimeter_32__32UITS+3 
	MOVLW       32
	MOVWF       ?lstr6_Multimeter_32__32UITS+4 
	MOVLW       32
	MOVWF       ?lstr6_Multimeter_32__32UITS+5 
	MOVLW       32
	MOVWF       ?lstr6_Multimeter_32__32UITS+6 
	MOVLW       32
	MOVWF       ?lstr6_Multimeter_32__32UITS+7 
	CLRF        ?lstr6_Multimeter_32__32UITS+8 
	MOVLW       ?lstr6_Multimeter_32__32UITS+0
	MOVWF       FARG_Lcd_Out_text+0 
	MOVLW       hi_addr(?lstr6_Multimeter_32__32UITS+0)
	MOVWF       FARG_Lcd_Out_text+1 
	CALL        _Lcd_Out+0, 0
;Multimeter _ UITS.c,327 :: 		Lcd_Out(2,10, masg_dc_curr);
	MOVLW       2
	MOVWF       FARG_Lcd_Out_row+0 
	MOVLW       10
	MOVWF       FARG_Lcd_Out_column+0 
	MOVLW       _masg_dc_curr+0
	MOVWF       FARG_Lcd_Out_text+0 
	MOVLW       hi_addr(_masg_dc_curr+0)
	MOVWF       FARG_Lcd_Out_text+1 
	CALL        _Lcd_Out+0, 0
;Multimeter _ UITS.c,328 :: 		Delay_ms(30);
	MOVLW       195
	MOVWF       R12, 0
	MOVLW       205
	MOVWF       R13, 0
L_Disp_idc57:
	DECFSZ      R13, 1, 1
	BRA         L_Disp_idc57
	DECFSZ      R12, 1, 1
	BRA         L_Disp_idc57
;Multimeter _ UITS.c,329 :: 		}
L_end_Disp_idc:
	RETURN      0
; end of _Disp_idc

_DC_power:

;Multimeter _ UITS.c,331 :: 		void DC_power(void)
;Multimeter _ UITS.c,333 :: 		int pdc=0;
;Multimeter _ UITS.c,334 :: 		char masg_pwr_dc[]="Pdc:000.00Watt";
	MOVLW       80
	MOVWF       DC_power_masg_pwr_dc_L0+0 
	MOVLW       100
	MOVWF       DC_power_masg_pwr_dc_L0+1 
	MOVLW       99
	MOVWF       DC_power_masg_pwr_dc_L0+2 
	MOVLW       58
	MOVWF       DC_power_masg_pwr_dc_L0+3 
	MOVLW       48
	MOVWF       DC_power_masg_pwr_dc_L0+4 
	MOVLW       48
	MOVWF       DC_power_masg_pwr_dc_L0+5 
	MOVLW       48
	MOVWF       DC_power_masg_pwr_dc_L0+6 
	MOVLW       46
	MOVWF       DC_power_masg_pwr_dc_L0+7 
	MOVLW       48
	MOVWF       DC_power_masg_pwr_dc_L0+8 
	MOVLW       48
	MOVWF       DC_power_masg_pwr_dc_L0+9 
	MOVLW       87
	MOVWF       DC_power_masg_pwr_dc_L0+10 
	MOVLW       97
	MOVWF       DC_power_masg_pwr_dc_L0+11 
	MOVLW       116
	MOVWF       DC_power_masg_pwr_dc_L0+12 
	MOVLW       116
	MOVWF       DC_power_masg_pwr_dc_L0+13 
	CLRF        DC_power_masg_pwr_dc_L0+14 
;Multimeter _ UITS.c,335 :: 		pdc = abs(voltdc*currdc/10);
	MOVF        _voltdc+0, 0 
	MOVWF       R0 
	MOVF        _voltdc+1, 0 
	MOVWF       R1 
	MOVF        _currdc+0, 0 
	MOVWF       R4 
	MOVF        _currdc+1, 0 
	MOVWF       R5 
	CALL        _Mul_16X16_U+0, 0
	MOVLW       10
	MOVWF       R4 
	MOVLW       0
	MOVWF       R5 
	CALL        _Div_16X16_U+0, 0
	MOVF        R0, 0 
	MOVWF       FARG_abs_a+0 
	MOVF        R1, 0 
	MOVWF       FARG_abs_a+1 
	CALL        _abs+0, 0
	MOVF        R0, 0 
	MOVWF       FLOC__DC_power+0 
	MOVF        R1, 0 
	MOVWF       FLOC__DC_power+1 
	MOVLW       16
	MOVWF       R4 
	MOVLW       39
	MOVWF       R5 
	MOVF        FLOC__DC_power+0, 0 
	MOVWF       R0 
	MOVF        FLOC__DC_power+1, 0 
	MOVWF       R1 
	CALL        _Div_16x16_S+0, 0
;Multimeter _ UITS.c,336 :: 		masg_pwr_dc[4] = pdc/10000 + 48;
	MOVLW       48
	ADDWF       R0, 0 
	MOVWF       DC_power_masg_pwr_dc_L0+4 
;Multimeter _ UITS.c,337 :: 		masg_pwr_dc[5] = (pdc/1000)%10 + 48;
	MOVLW       232
	MOVWF       R4 
	MOVLW       3
	MOVWF       R5 
	MOVF        FLOC__DC_power+0, 0 
	MOVWF       R0 
	MOVF        FLOC__DC_power+1, 0 
	MOVWF       R1 
	CALL        _Div_16x16_S+0, 0
	MOVLW       10
	MOVWF       R4 
	MOVLW       0
	MOVWF       R5 
	CALL        _Div_16x16_S+0, 0
	MOVF        R8, 0 
	MOVWF       R0 
	MOVF        R9, 0 
	MOVWF       R1 
	MOVLW       48
	ADDWF       R0, 0 
	MOVWF       DC_power_masg_pwr_dc_L0+5 
;Multimeter _ UITS.c,338 :: 		masg_pwr_dc[6] = (pdc/100)%10 + 48;
	MOVLW       100
	MOVWF       R4 
	MOVLW       0
	MOVWF       R5 
	MOVF        FLOC__DC_power+0, 0 
	MOVWF       R0 
	MOVF        FLOC__DC_power+1, 0 
	MOVWF       R1 
	CALL        _Div_16x16_S+0, 0
	MOVLW       10
	MOVWF       R4 
	MOVLW       0
	MOVWF       R5 
	CALL        _Div_16x16_S+0, 0
	MOVF        R8, 0 
	MOVWF       R0 
	MOVF        R9, 0 
	MOVWF       R1 
	MOVLW       48
	ADDWF       R0, 0 
	MOVWF       DC_power_masg_pwr_dc_L0+6 
;Multimeter _ UITS.c,339 :: 		masg_pwr_dc[8] = (pdc/10)%10 + 48;
	MOVLW       10
	MOVWF       R4 
	MOVLW       0
	MOVWF       R5 
	MOVF        FLOC__DC_power+0, 0 
	MOVWF       R0 
	MOVF        FLOC__DC_power+1, 0 
	MOVWF       R1 
	CALL        _Div_16x16_S+0, 0
	MOVLW       10
	MOVWF       R4 
	MOVLW       0
	MOVWF       R5 
	CALL        _Div_16x16_S+0, 0
	MOVF        R8, 0 
	MOVWF       R0 
	MOVF        R9, 0 
	MOVWF       R1 
	MOVLW       48
	ADDWF       R0, 0 
	MOVWF       DC_power_masg_pwr_dc_L0+8 
;Multimeter _ UITS.c,340 :: 		masg_pwr_dc[9] = pdc%10 + 48;
	MOVLW       10
	MOVWF       R4 
	MOVLW       0
	MOVWF       R5 
	MOVF        FLOC__DC_power+0, 0 
	MOVWF       R0 
	MOVF        FLOC__DC_power+1, 0 
	MOVWF       R1 
	CALL        _Div_16x16_S+0, 0
	MOVF        R8, 0 
	MOVWF       R0 
	MOVF        R9, 0 
	MOVWF       R1 
	MOVLW       48
	ADDWF       R0, 0 
	MOVWF       DC_power_masg_pwr_dc_L0+9 
;Multimeter _ UITS.c,341 :: 		Lcd_Out(2,1,"                ");
	MOVLW       2
	MOVWF       FARG_Lcd_Out_row+0 
	MOVLW       1
	MOVWF       FARG_Lcd_Out_column+0 
	MOVLW       ?ICS?lstr7_Multimeter_32__32UITS+0
	MOVWF       TBLPTRL 
	MOVLW       hi_addr(?ICS?lstr7_Multimeter_32__32UITS+0)
	MOVWF       TBLPTRH 
	MOVLW       higher_addr(?ICS?lstr7_Multimeter_32__32UITS+0)
	MOVWF       TBLPTRU 
	MOVLW       ?lstr7_Multimeter_32__32UITS+0
	MOVWF       FSR1 
	MOVLW       hi_addr(?lstr7_Multimeter_32__32UITS+0)
	MOVWF       FSR1H 
	MOVLW       17
	MOVWF       R0 
	MOVLW       1
	MOVWF       R1 
	CALL        ___CC2DW+0, 0
	MOVLW       ?lstr7_Multimeter_32__32UITS+0
	MOVWF       FARG_Lcd_Out_text+0 
	MOVLW       hi_addr(?lstr7_Multimeter_32__32UITS+0)
	MOVWF       FARG_Lcd_Out_text+1 
	CALL        _Lcd_Out+0, 0
;Multimeter _ UITS.c,342 :: 		Lcd_Out(2,1,masg_pwr_dc);
	MOVLW       2
	MOVWF       FARG_Lcd_Out_row+0 
	MOVLW       1
	MOVWF       FARG_Lcd_Out_column+0 
	MOVLW       DC_power_masg_pwr_dc_L0+0
	MOVWF       FARG_Lcd_Out_text+0 
	MOVLW       hi_addr(DC_power_masg_pwr_dc_L0+0)
	MOVWF       FARG_Lcd_Out_text+1 
	CALL        _Lcd_Out+0, 0
;Multimeter _ UITS.c,343 :: 		Delay_ms(3000);
	MOVLW       77
	MOVWF       R11, 0
	MOVLW       25
	MOVWF       R12, 0
	MOVLW       79
	MOVWF       R13, 0
L_DC_power58:
	DECFSZ      R13, 1, 1
	BRA         L_DC_power58
	DECFSZ      R12, 1, 1
	BRA         L_DC_power58
	DECFSZ      R11, 1, 1
	BRA         L_DC_power58
	NOP
	NOP
;Multimeter _ UITS.c,344 :: 		}
L_end_DC_power:
	RETURN      0
; end of _DC_power
