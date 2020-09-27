///////////////////////////////////////////////////////////////////////////////
/*****************************************************************************/
/*                                                                           */
/* Programme de thermostat interfac� avec un capteur de temp�rature          */
/* intelligent Dallas DS18S20, alarmes pour indiquer les temperatures trop   */
/* basses et trop �lev�es et d�clanchement de plainte �lectrique.            */
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
//Biblioth�ques utilis�s
#include <LCD_Therm.h> //Header pour le programme.
#include <lcd.c> //Pilote LCD.
#include <lcd_db666.h> //Biblioth�que personelle pour l'afficheur LCD.
#include <DS18B20.c> //Mini driver pour le capteur.
///////////////////////////Programme principale.////////////////////////////////
void temp()
{
   float temperature; //Variable flotante pour stocker les donn�es provenant du capteur.
   
  // lcd_init(); //Initialisation de l'afficheur.
   //lcd_clear(); //Commande pour �ffacer l'afficheur.
   
   while(TRUE) //Boucle infinie.
   {
      temperature=ds1820_read(); //Stocker les donn�es provenant du capteur.
      lcd_gotoxy(1,1); //Mettre le curseur � la position.
      printf(lcd_putc,"TEMP:%3.1f ",temperature); //Afficher � l'�cran.
      
      if(temperature<0)printf(lcd_putc,"TEMP:-%3.1f ",temperature); //Afficher � l'�cran.
      
      lcd_putc(223); //Afficher � l'�cran le symbole pour les degr�s.
      lcd_putc("C "); //Afficher � l'�cran le symbole pour les Celcius.
      lcd_gotoxy(1,2); //Mettre le curseur � la position.
      
      //Si la temp�rature est plus �lev�e ou �gale � 29 degr�s Celcius.
      if(temperature>=29.0)
      {
         printf(lcd_putc,"Hot!     "); //Afficher � l'�cran.
         output_high(ALARME); //Donner un alarme.
      }
      //Sinon si la temp�rature est entre 20 et 28 degr�s Celcius.
      else if(temperature>=20&&temperature<29.0)
      {
         printf(lcd_putc,"Comfort! "); //Afficher � l'�cran.
         output_low(THERMOSTAT); //Arr�ter la plainte �lectrique.
         output_low(ALARME); //D�sactiver l'alarme.
      }
      //Sinon si la temp�rature est entre 15 et 19 degr�s Celcius.
      else if(temperature>=15&&temperature<20.0)
      {
         printf(lcd_putc,"Cold!    "); //Afficher � l'�cran.
         output_high(THERMOSTAT); //D�marrer la plainte �lectrique. 
         output_low(ALARME); //D�sactiver l'alarme.
      }
      //Sinon c'est trop froid.
      else
      {
         printf(lcd_putc,"Too cold!"); //Afficher � l'�cran.
         
         output_high(ALARME); //Donner un alarme.
      }
   }  //Fin de la boucle infinie. 
} //Fin du programme principal.
