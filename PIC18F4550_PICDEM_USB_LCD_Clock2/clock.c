////////////////////////////////////////////////////////////////////////////////
// Programme d'horloge programm� avec un microncrolleur 18F4550.              //
// Ce programme est de base et permet de faire afficher l'heure dans le       //
// Format hh/mm/ss sur un afficheur LCD standard 2x20.                        //
//                                                                            //
// Copyright Dany Ferron                                    11/05/31          //
////////////////////////////////////////////////////////////////////////////////
//Incure la biblioth�que du microcontrolleur
#include <18F4550.h>
//Fuses
#fuses HSPLL,NOWDT,NOPROTECT,NODEBUG,NOBROWNOUT,USBDIV,PLL5,CPUDIV1,VREGEN,PUT,NOMCLR,NOLVP
#use delay(clock=48000000)
////////////////////////////////Bootloader USB//////////////////////////////////
#build(reset=0x800, interrupt=0x808) 
#org 0, 0x7ff { }
////////////////////////////////////////////////////////////////////////////////
//Constantes d�finies pour les broches utilis�s par l'�cran LCD
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
//Constantes d�finies pour les broches utilis�s pour l'ajustement du temps.
#define TIMESET PIN_B0  
#define HRSET PIN_B1
#define MINSET PIN_B2
//Variables globales.
int8 seconds=00;
int8 minutes=00;
int8 hours=12;
BOOLEAN ampm=0;
/////////////////////////D�claration des sous-fonctions////////////////////////
void Display_time(int8 hours,int8 minutes,int8 seconds);
void EcouleTemps();
void MinsRoutine();
void HrsRoutine();
void TimeAdjust();
///////////////////////////Programme principal.////////////////////////////////
void main()
{
   lcd_init();//Initialisation du pilote d'affichage LCD.
   //D�but de la boucle infinie.
   do
   {
      Display_time(hours,minutes,seconds);//Fonction pour faire afficher l'heure � l'�cran.
      //Appel de la fonction ajustement du temps si le boutton d'ajustement est appuy�.
      if(input(TIMESET)==0)
      {
         seconds=0;//Remettre les secondes a z�ro.
         delay_ms(250);//Ajustement avec delai rapide.
         TimeAdjust();//Appel de la fonction ajustement du temps.
      }
      //Sinon �coulement du temps normal.
      else
      {
         delay_ms(1000);//Temps normal.
         EcouleTemps();//Appel de la fonction �coulement du temps.
      }
   }
   while(true);
}
     
////////////////////////D�finition des sous-fonctions./////////////////////////

///////////////////////Fonction d'ajustement des minutes.//////////////////////
void MinsRoutine()
{
   minutes++;
   if(minutes>=60)minutes=00;
}
///////////////////////Fonction d'ajustement des heures.///////////////////////
   void HrsRoutine()
   {
      hours++;
      //Faire afficher AM ou PM au passage de 12 heures.
      if(hours==13)
      {
         hours=1;
         ampm=~ampm;
      }
   }
//////////////////////////Fonction ajustement du temps.////////////////////////
   void TimeAdjust()
   {
      //Si appui du boutton des heures,faire monter les heures.
      if(input(HRSET)==0)HrsRoutine();
      //Si appui du boutton des minutes,faire monter les minutes.
      if(input(MINSET)==0)MinsRoutine();
   }
///////////////////////Fonction d'�coulement des minutes.//////////////////////
   void EcouleTemps()
   {
      seconds++;//�coulement des secondes.
      //Faire incr�menter les minutes aux 60 secondes.
      if(seconds==60)
      {
         seconds=0;
         minutes++;
         
         //Faire incr�menter les heures aux 60 minutes.
         if(minutes==60)
         {
            minutes=00;
            hours++;
         }
         //Faire afficher AM ou PM au passage de 12 heures.
         if(hours==13)
         {
            hours=1;
            ampm=~ampm;
         }
      }
   }
///////////////////////Fonction d'affichage du temps.//////////////////////////
   void Display_time(int8 hours,int8 minutes,int8 seconds)
   {
      lcd_gotoxy(1,1);
      printf(lcd_putc,"Time:%2u:%02u:%02u",hours,minutes,seconds);
      lcd_gotoxy(15,1);
      if(hours==12&&ampm==1)lcd_putc("pm");
      if(hours==12&&ampm==0)lcd_putc("am");
   }
