////////////////////////////////////////////////////////////////////////////////
// Programme d'horloge programmé avec un microncrolleur 18F4550.              //
// Ce programme est de base et permet de faire afficher l'heure dans le       //
// Format hh/mm/ss sur un afficheur LCD standard 2x20.                        //
//                                                                            //
// Copyright Dany Ferron                                    11/05/31          //
////////////////////////////////////////////////////////////////////////////////
//Incure la bibliothèque du microcontrolleur
#include <18F4550.h>
//Fuses
#fuses HSPLL,NOWDT,NOPROTECT,NODEBUG,NOBROWNOUT,USBDIV,CPUDIV1,VREGEN,PUT,NOMCLR,NOLVP
#use delay(clock=48000000)
////////////////////////////////Bootloader USB//////////////////////////////////
#build(reset=0x800, interrupt=0x808) 
#org 0, 0x7ff { }
////////////////////////////////////////////////////////////////////////////////
//Constantes définies pour les broches utilisés par l'écran LCD
#define LCD_TYPE 2  
#define LCD_ENABLE_PIN  PIN_E2
#define LCD_RW_PIN      PIN_E1
#define LCD_RS_PIN      PIN_E0
#define LCD_DATA4       PIN_D4
#define LCD_DATA5       PIN_D5
#define LCD_DATA6       PIN_D6
#define LCD_DATA7       PIN_D7
//Pilote d'affichage LCD.
#include <lcd.c> 

#include <DS18B20.c>
//RTC variables 
#define XTAL_FREQUENCY  1000 
#define TIMER1_FREQUENCY (XTAL_FREQUENCY/4)// 1 clock tick = 1 instr. cycle = crystal frequency / 4 
int32 Ticker; 
int8 Seconds=0; 
//optional: 
 int8 Month=0,Days=0,Hours=12,Minutes=0;
 int16 Year=2011;
//////////////////////////////////////////////////////////////////////////////// 
// Test whether a given year is a leap year. 
// This optimized version only works for the period 2001 - 2099 
//////////////////////////////////////////////////////////////////////////////// 
#define IS_LEAP(year) (year%4 == 0) 
//////////////////////////////////////////////////////////////////////////////// 
//    Initialize RTC 
//////////////////////////////////////////////////////////////////////////////// 
void Initialize_RTC(void) 
{
   Ticker=TIMER1_FREQUENCY;//initialize clock counter to number of clocks per second
   setup_timer_1(T1_INTERNAL|T1_DIV_BY_1);//initialize 16-bit Timer1 to interrupt
   //exactly every 65536 clock cycles
   //(about 76 times per second)
   enable_interrupts(int_TIMER1);//Start RTC
}
//////////////////////////////////////////////////////////////////////////////// 
//  -=Process Zero Drift Real Time Clock Information=- 
// 
// Most algorithms configure the timer to generate an interrupt every 100ms, and 
// then count the number of interrupts. The problem in that approach is that most 
// clock frequencies can't be divided by 256 and you don't get an exact 100ms. 
// The small errors will add up to an error of several seconds a day. 
// 
// The algorithm presented here is exact in the long run because it doesn't 
// count the number of interrupts but counts the number of clock cycles. 
//////////////////////////////////////////////////////////////////////////////// 
#int_TIMER1                                
void TIMER1_isr()                          
{
   Ticker-=65536;//Decrement ticker by clocks per interrupt
   if(Ticker<65536)//If second has expired
   {
      Ticker+=TIMER1_FREQUENCY;//Increment ticker by clocks per second
      seconds++;//Increment number of seconds
   }
   
   if(Seconds==60)
   {
      Minutes++;Seconds=0;
      if(Minutes==60)
      {
         Hours++;Minutes=0;
         if(Hours==24)
         {
            Days++;Hours=0;
            if((Days==29&&Month==2&&!IS_LEAP(Year))
            ||(Days==30&&Month==2)
            ||(Days==31&&(Month==4||Month==6||Month==9||Month==11))
            ||(Days==32))
            {
               Month++;Days=0;
            }
            if(Month==13)
            {
               Year++;Month=0;
            }
         }
      }
   }
   
}
      ////////////////////////////////////////////////////////////////////////////////
      //Example program for using the RTC
      ////////////////////////////////////////////////////////////////////////////////
      void main()
      {
         
         Initialize_RTC();
         enable_interrupts(GLOBAL);
         lcd_init();
         
         float temperature;
         //loop forever
         while(TRUE)
         {
         
            lcd_gotoxy(1,1);
            printf(lcd_putc,"Time:%2u:%02u:%02u",Hours,Minutes,Seconds);
            
            lcd_gotoxy(1,2);
            
            
            printf(lcd_putc,"%2u/%2u/%4Lu",Days,Month,Year);
         }
         
         temperature=ds1820_read();
         lcd_gotoxy(12,1);
         printf(lcd_putc,"TEMP:%3.1f ",temperature); //Afficher à l'écran.
      
      if(temperature<0)printf(lcd_putc,"TEMP:-%3.1f ",temperature); //Afficher à l'écran.
      
      lcd_putc(223); //Afficher à l'écran le symbole pour les degrés.
      lcd_putc("C "); //Afficher à l'écran le symbole pour les Celcius.
      
      }
      
