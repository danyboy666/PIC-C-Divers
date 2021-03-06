///////////////////////////////////////////////////////////////////////////////
/*****************************************************************************/
/*                                                                           */
/* Laboratoire de la serrure avec afficheur LCD et m�morisation de codes     */
/*                                                                           */
/* Nous utilisons un microcontrolleur PIC18F4550 avec Bootloader             */
/*                                                                           */ 
/* Copyright Am�lie Champagne et Dany Ferron                                 */
/*****************************************************************************/
/*                                                                           */ 
/* Travail 2                                                                 */
/* Am�lie et Dany                                                            */
/* le 10 mai 2011                                                            */
/*                                                                           */
/*****************************************************************************/
///////////////////////////////////////////////////////////////////////////////

/////////////////////////Inclure le Fichier en-t�te.////////////////////////////
#include <LCD_keypad.h>
/////////////////Mots de passe stocker dans la m�moire morte.///////////////////
///////////////////////////////PIC 18F//////////////////////////////////////////
#rom int8 0xF00000={4,3,2,1} //Mot de passe utilisateur.
#rom int8 0xF00020={9,8,7,6} //Mot de passe administrateur.
/////////////////Variables pour stocker les mots de passe.//////////////////////
long code_public;
long code_admin;
/////////////////////////Variables de lectures./////////////////////////////////
long code_validation=0,input_read=0,temp_passw;
//Variable pour compter les essaies de combinaisons.
char try_msg=5;//Variable d'essaie initialis�e a 5.

/////Addition des valeurs d�cal�s et mettre en constante le code d'entr�.///////
#define CALCUL_VAL ((val4*1000)+(val3*100)+(val2*10)+(val1*1))
//////////////////////D�clarations des sous-fonctions.//////////////////////////
void unlock();
long kp_read();
void intrusion();
void wrong_code();
long read_combination(int8 x1,int8 y1,int8 x2,int8 y2);
void code_gestion();
void kp_init();
float read_from_EEPROM(long int adr);
void write_to_EEPROM(long int adr,int16 code);

/////////////////////////////Programme principale.//////////////////////////////
   void main()
   { 
      lcd_init(); //Initialisation du pilote LCD.
      
      do //D�but de la boucle faire tant que infini.
      {
         //Lire les mots de passes stock�s dans la EEPROM.
         code_public=read_from_EEPROM(0x00); //Lire le code publique.
         code_admin=read_from_EEPROM(0x20); //Lire le code administrateur.
         
         clr_display(); //�fface l'afficheur LCD.
         
         //Mettre la valeur retourn� dans une variable
         code_validation=read_combination(3,1,8,2); 
         //Si code validation est �gale au mot de passe utilisateur ou administrateur
         if((code_validation==code_admin))code_gestion(); //Appel de la fonction gestion code.
         
         else //Sinon faire le reste du programme.
         {
            if(code_validation==code_public) //Si le code validation est �gal au code public.
            {
               unlock(); //Appel de la fonction d�barrer.
               try_msg=5; //Remettre a variable d'essaie � 5.
            }
           
            else //Sinon
            {
               wrong_code(); //Appel de la fonction intrusion.
               
               if(try_msg==0) //Si les �ssaies sont �coul�es.
               {
                  intrusion(); //Appel de la fonction intrusion.
                  //Mettre le mots de passe public dans une variable temporaire.
                  temp_passw=code_public;
                  //Le code utilisateur est maintenant �gale au code administrateur.
                  code_public=code_admin;
                  try_msg=255; //Remettre a variable d'�ssaie � 255 pour l'administrateur.
               }
            }
         }
         
      }
      while(TRUE);//Fin de la boucle infinie.
   }
///////////////////////////////Fonction d�barre.///////////////////////////////
   void unlock()
   {
      char buzz_led_loop,door_opening,door_closing;//Variables locales.
      
      clr_display(); //�fface l'afficheur LCD.
      cursor_off(); //�teint le curseur de l'afficheur LCD.
      lcd_gotoxy(5,1); //Mettre le curseur � la position.
      
      lcd_putc("Door Unlocked"); //Faire afficher ce message.
      
      //Si le code validation est �gale au code administrateur.
      if(code_validation==code_admin)code_public=temp_passw; //Remettre le bon code utilisateur.
            
      code_public=temp_passw; //Remettre le bon code utilisateur.
      code_validation=code_public; //Code validation est �gal au code utilisateur.
      
      //Boucle indication sonore pour indiquer que la porte est ouverte.
      for(buzz_led_loop=0;buzz_led_loop<4;buzz_led_loop++)
      {
         delay_ms(50);
         output_high(BUZZER);
         output_low(LEDR);
         delay_ms(100);
         output_low(BUZZER);
         output_high(LEDR);
      }
      output_low(LEDR);
      //Boucle indicateur lumineux pour indiquer que la porte est ouverte.
      for(door_opening=0;door_opening<10;door_opening++)
      {
         output_low(LEDV);
         delay_ms(500);
         output_high(LEDV);
         delay_ms(500);
      }
      //Indicateur sonore et lumineux pour indiquer que la porte se barre.
      for(door_closing=0;door_closing<2;door_closing++)
      {
         delay_ms(50);
         output_high(BUZZER);
         output_low(LEDV);
         delay_ms(100);
         output_low(BUZZER);
         output_high(LEDV);
      }
      output_low(LEDV); //Remettre l'indicateur lumineux � off.
   }
   
///////////////////////Fonction lecture de clavier./////////////////////////////
   long kp_read()
   {
      long temp=15; //Variable de lecture de touche temporaire.
      
      //Boucle d'attente faire tant que...
      do
      {
         input_read=INPUT_AB; //Mettre en variable la touche entr�e.
      }//Fin de la boucle d'attente.
      while(input_read>=0xFFF); //Tant que que lecture clavier est plus grand que 4095.
      
      //Si une des touches est appuy�e on la met en banque.
      if(input_read==KP_0)temp=0;
      if(input_read==KP_1)temp=1;
      if(input_read==KP_2)temp=2;
      if(input_read==KP_3)temp=3;
      if(input_read==KP_4)temp=4;
      if(input_read==KP_5)temp=5;
      if(input_read==KP_6)temp=6;
      if(input_read==KP_7)temp=7;
      if(input_read==KP_8)temp=8;
      if(input_read==KP_9)temp=9;
      
      if(input_read==KP_S)temp=STAR_KEY;
      if(input_read==KP_P)temp=POUND_KEY;
      
      input_read=0; //Remettre la variable lecture � 0
      
      return temp; //Retour de la touche vers le programme appelant.
   }
///////////////////////////Fonction intrusion.//////////////////////////////////
   void intrusion()
   {
      char pulsar1; //Variable pour le compteur.
      
      clr_display(); //�fface l'afficheur LCD.
      lcd_gotoxy(8,1); //Mettre le curseur � la position.
      lcd_putc("Alarm!"); //Faire afficher le message suivant.
      delay_ms(500); //Pause de 500 ms.
      lcd_gotoxy(4,2); //Mettre le curseur � la position.
      lcd_putc("Admin required"); //Faire afficher le message suivant.
      output_high(BUZZER);//Niveau haut au buzzeur
      
      for(pulsar1=0;pulsar1<10;pulsar1++)//Compteur de z�ro � dix.
      {
         output_high(LEDR); //LED Rouge allum�e.
         delay_ms(500); //Pause de une demi seconde.
         output_low(LEDR); //LED Rouge �teinte.
         delay_ms(500); //Pause de une demi seconde.
      }
      
      output_low(BUZZER); //Niveau bas au buzzeur
   }
////////////////Fonction lire combine qui retourne une variable.////////////////
   long read_combination(int8 x1,int8 y1,int8 x2,int8 y2)
   {
      char count_input; //Variables locales.
      long val1=15,val2=15,val3=15,val4=15,touche;//Variables de lecture.
      
      //Boucle � compteur permettant d'accumuler 4 touches entr�es.
      lcd_gotoxy(x1,y1); //Utilis� les coordonn�es recus et placer le curseur.
      lcd_putc("Enter Code :"); //Faire afficher le message suivant.
      lcd_gotoxy(x2,y2); //Utilis� les coordonn�es recus et placer le curseur.
      cursor_blink_on(); //Faire clignoter le curseur.
      
      for(count_input=1;count_input<=4;count_input++)
      {
         touche=kp_read();//Appel de la fonction lecture de clavier.
         
         //D�calage de la variable temporaire 4 fois.
         val4=val3;
         val3=val2;
         val2=val1;
         val1=touche;
         
         lcd_putc("*"); //Faire afficher le message suivant.
         output_high(BUZZER); //Activer le buzzeur.
         delay_ms(250); //Pause de 250 ms.
         output_low(BUZZER); //D�sactiver le buzzeur.
      }
      //Retour du calcul des variables val1 � val 4 vers le programme appelant.
      return CALCUL_VAL;
   }
////////////////////////////Fonction mauvais code.//////////////////////////////
   void wrong_code()
   {
      char pulsar2;
      
      for(pulsar2=0;pulsar2<3;pulsar2++)
      {
         delay_ms(50); //Pause de 50 ms.
         output_high(BUZZER); //Activer le buzzeur.
         output_low(LEDR); //D�sactiver le LED.
         delay_ms(100); //Pause de 100 ms.
         output_low(BUZZER); //D�sactiver le buzzeur.
         output_high(LEDR); //D�sactiver le LED.
      }
      
      try_msg--; //On d�cremente le nombre d'essais a chaque mauvais code entr�s.
      clr_display(); //�fface l'afficheur LCD.
      cursor_off(); //Eteint le curseur.
      lcd_gotoxy(6,1); //Mettre le curseur � la position.
      lcd_putc("Wrong Code"); //Faire afficher ce message.
      delay_ms(1000); //Pause de 1000 ms.
      clr_display(); //�fface l'afficheur LCD.
      lcd_gotoxy(6,2); //Mettre le curseur � la position.
      //On fait afficher a l'ecran le nombres d'essaies restants.
      printf(lcd_putc,"Try Left%u",try_msg);
      delay_ms(5000); //Pause de 5000 ms.
      output_low(LEDR); //On �teint le led.
   }
//////////////////////Fonction gestion des codes.///////////////////////////////
   void code_gestion()
   {
      //Variables locales.
      char response;
      long temp_code;
      
      clr_display(); //�fface l'afficheur LCD.
      cursor_off(); //Eteint le curseur.
      lcd_gotoxy(5,1); //Mettre le curseur � la position.
      lcd_putc("Code Gestion"); //Faire afficher ce message.
      lcd_gotoxy(3,2); //Mettre le curseur � la position.
      lcd_putc("*=Admin #=Public"); //Faire afficher ce message.
      response=kp_read(); //On met la reponse du clavier dans une variable.
      delay_ms(3000); //Pause de 3000 ms.
      
      clr_display(); //�fface l'afficheur LCD.
      
      if(response==STAR_KEY) //Si la r�ponse du clavier est �gale � la touche �toile.
      {
         lcd_gotoxy(3,1); //Mettre le curseur � la position.
         lcd_putc("Code Superviseur"); //Faire afficher ce message.
         temp_code=read_combination(2,2,15,2); //on met la combinaison recues en variable.
         write_to_EEPROM(0x20,temp_code); //On �cris le nouveau code entr� en EEPROM.
      }
      
      if(response==POUND_KEY) //Si la r�ponse du clavier est �gale � la touche carr�.
      {
         lcd_gotoxy(5,1); //Mettre le curseur � la position.
         lcd_putc("Code Public"); //Faire afficher ce message.
         temp_code=read_combination(2,2,15,2); //on met la combinaison recues en variable.
         write_to_EEPROM(0x00,temp_code); //On �cris le nouveau code entr� en EEPROM.
      }
   }
   
////////////////////Fonction de lecture des codes en EEPROM/////////////////////   
   float read_from_EEPROM(long int adr)
   {
      //Variables locales.
      int i;
      long val1=0,val2=0,val3=0,val4=0,val_temp=0;
      
      for(i=0;i<4;i++) //Boucle pour lire les valeur en EEPROM.
      {
         //On lit les valeurs en les d�calants.
         val_temp=read_eeprom(i+adr); 
         val4=val3;
         val3=val2;
         val2=val1;
         val1=val_temp;
      }
      //Retour du calcul des variables val1 � val 4 vers le programme appelant.
      return CALCUL_VAL;
   }

////////////////////////Fonction �criture en EEPROM.////////////////////////////
   void write_to_EEPROM(long int adr,int16 code)
   {
      //Variables locales.
      int8 j;
      int8 tableau[4]={0,0,0,0};
      int16 divider=1000;
      
      //Boucle pour calculer et mettre les valeurs recus de la EEPROM et les tranferer dans le tableau.
      for(j=0;j<4;j++) 
      {
         tableau[j]=code/divider; //On met �gale le tableau au code divis� par 1000.
         code=code%divider; //On se sert du code et on utilise la fonction modulus pour se servir du reste de la division.
         divider=divider/10; //On divise par dix la valeur de la variable.  
      }
      for(j=0;j<4;j++) //Boucle pour remettre les valeur recus en EEPROM.
      {
         write_EEPROM((j+adr),(tableau[j])); //On �cris dans la EEPROM le code calcul�.  
      }
   }
