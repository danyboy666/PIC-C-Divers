//Incure la bibliothèque du microcontrolleur
#include <18F4550.h>
//Fuses
#fuses HSPLL,NOWDT,NOPROTECT,NODEBUG,NOBROWNOUT,USBDIV,PLL5,CPUDIV1,VREGEN,PUT,NOMCLR,NOLVP
#use delay(clock=48000000)
//Réserver les 800 premières case mémoire pour le bootloader.
#build(reset=0x800, interrupt=0x808) 
#org 0, 0x7ff { }
//Constantes définies pour les broches utilisés par l'écran LCD
#define LCD_TYPE 2  
#define LCD_ENABLE_PIN  PIN_E2
#define LCD_RW_PIN      PIN_E1
#define LCD_RS_PIN      PIN_E0
#define LCD_DATA4       PIN_D4
#define LCD_DATA5       PIN_D5
#define LCD_DATA6       PIN_D6
#define LCD_DATA7       PIN_D7

//Constantes définies pour les broches utilisés pour l'ajustement du temps.
#define TIMESET PIN_B0  
#define HRSET PIN_B1
#define MINSET PIN_B2
#define AMPM PIN_D1
 


