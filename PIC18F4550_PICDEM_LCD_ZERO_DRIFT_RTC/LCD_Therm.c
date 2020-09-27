///////////////////////////////////////////////////////////////////////////////
/*****************************************************************************/
/*                                                                           */
/* Programme de thermostat interfacé avec un capteur de température          */
/* intelligent Dallas DS18S20, alarmes pour indiquer les temperatures trop   */
/* basses et trop élevées et déclanchement de plainte électrique.            */
/*                                                                           */ 
/* Copyright Dany Ferron                                                     */
/*****************************************************************************/
/*                                                                           */ 
/* Projet Final(Boni)                                                        */
/* Dany Ferron 816806                                                        */
/* le 13 mai 2011                                                            */
/*                                                                           */
/*****************************************************************************/
///////////////////////////////////////////////////////////////////////////////
#EXPORT (FILE=DS1820_THERMOSTAT_PROJECT.HEX)
//Bibliothèques utilisés
#include <LCD_Therm.h> //Header pour le programme.
#include <lcd.c> //Pilote LCD.
#include <lcd_db666.h> //Bibliothèque personelle pour l'afficheur LCD.
#include <DS18B20.c> //Mini driver pour le capteur.
///////////////////////////Programme principale.////////////////////////////////
void temp()
{
   float temperature; //Variable flotante pour stocker les données provenant du capteur.
   
  // lcd_init(); //Initialisation de l'afficheur.
   //lcd_clear(); //Commande pour éffacer l'afficheur.
   
   while(TRUE) //Boucle infinie.
   {
      temperature=ds1820_read(); //Stocker les données provenant du capteur.
      lcd_gotoxy(1,1); //Mettre le curseur à la position.
      printf(lcd_putc,"TEMP:%3.1f ",temperature); //Afficher à l'écran.
      
      if(temperature<0)printf(lcd_putc,"TEMP:-%3.1f ",temperature); //Afficher à l'écran.
      
      lcd_putc(223); //Afficher à l'écran le symbole pour les degrés.
      lcd_putc("C "); //Afficher à l'écran le symbole pour les Celcius.
      lcd_gotoxy(1,2); //Mettre le curseur à la position.
      
      //Si la température est plus élevée ou égale à 29 degrés Celcius.
      if(temperature>=29.0)
      {
         printf(lcd_putc,"Hot!     "); //Afficher à l'écran.
         output_high(ALARME); //Donner un alarme.
      }
      //Sinon si la température est entre 20 et 28 degrés Celcius.
      else if(temperature>=20&&temperature<29.0)
      {
         printf(lcd_putc,"Comfort! "); //Afficher à l'écran.
         output_low(THERMOSTAT); //Arrêter la plainte électrique.
         output_low(ALARME); //Désactiver l'alarme.
      }
      //Sinon si la température est entre 15 et 19 degrés Celcius.
      else if(temperature>=15&&temperature<20.0)
      {
         printf(lcd_putc,"Cold!    "); //Afficher à l'écran.
         output_high(THERMOSTAT); //Démarrer la plainte électrique. 
         output_low(ALARME); //Désactiver l'alarme.
      }
      //Sinon c'est trop froid.
      else
      {
         printf(lcd_putc,"Too cold!"); //Afficher à l'écran.
         
         output_high(ALARME); //Donner un alarme.
      }
   }  //Fin de la boucle infinie. 
} //Fin du programme principal.
