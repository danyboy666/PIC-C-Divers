//Incure la bibliothèque du microcontrolleur
#include <18F4550.h>
//Fuses
#fuses HSPLL,NOWDT,NOPROTECT,NODEBUG,NOBROWNOUT,USBDIV,PLL5,CPUDIV1,VREGEN,PUT,NOMCLR,NOLVP
#use delay(clock=48000000)
//Réserver les 800 premières case mémoire pour le bootloader.
#build(reset=0x800, interrupt=0x808) 
#org 0, 0x7ff { }
  
//Broches utilisés pour l'écran LCD
#define LCD_TYPE 2  
#define LCD_ENABLE_PIN  PIN_E2
#define LCD_RW_PIN      PIN_E1
#define LCD_RS_PIN      PIN_E0
#define LCD_DATA4       PIN_D4
#define LCD_DATA5       PIN_D5
#define LCD_DATA6       PIN_D6
#define LCD_DATA7       PIN_D7

//Bibliothèques utilisés
#include <lcd.c>//Pilote LCD.
#include <lcd_db666.h>
//Macro qui combine le port a et le port b pour la lecture du clavier.
#define INPUT_AB (((input_a()&0b00001111)*0x100)+input_b())
//Définitions des touches.
#define KP_0 0b0000111111111110
#define KP_1 0b0000111111111101
#define KP_2 0b0000111111111011
#define KP_3 0b0000111111110111
#define KP_4 0b0000111111101111
#define KP_5 0b0000111111011111
#define KP_6 0b0000111110111111
#define KP_7 0b0000111101111111
#define KP_8 0b0000111011111111
#define KP_9 0b0000110111111111
#define KP_S 0b0000101111111111
#define KP_P 0b0000011111111111
//Définition pour le buzzer.
#define BUZZER PIN_D0
//Définition pour les LEDS.
#define LEDR PIN_D1
#define LEDV PIN_D2
#define LEDY PIN_D3
//Touches étoile et carré en constante.
#define STAR_KEY 10
#define POUND_KEY 11
