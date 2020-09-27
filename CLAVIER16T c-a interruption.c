

//////////////////////////////////////////////////////////////////////////////////
////                           CLAVIER16T c-a interruption.c                  ////
////     Clavier matriciel g�rer par une interruption mat�rielle              ////
////                           Utilise le port D  du 16F4550                  //// 
////           kbd_getc();         // appelle la fonction                     ////
////          char kbd_getc();     // retourne le caract�re entr�e            ////
////                                                                          ////
////        Auteur : Paul Bernard                                             ////
////                                                                          ////
//////////////////////////////////////////////////////////////////////////////////

#byte kbd = 0xF83                  // adresse du porB= F81h, du porD = F83h

// #define constante �quivalence elles sont remplac�es par leur valeur lors de la compilation
#define set_tris_kbd(x) set_tris_d(x)      // configuration du port 0=ouput, 1=input

#define COL0 (1 << 4)           // COL0=d�calage � gauche de 4 bit : 0001 0000
#define COL1 (1 << 5)           // COL1=d�calage � gauche de 5 bit : 0010 0000
#define COL2 (1 << 6)           // COL2=d�calage � gauche de 6 bit : 0100 0000
#define COL3 (1 << 7)           // COL3=d�calage � gauche de 7 bit : 1000 0000

#define ROW0 (1 << 0)           // ROW0=d�calage � gauche de 0 bit : 0000 0001
#define ROW1 (1 << 1)           // ROW1=d�calage � gauche de 1 bit : 0000 0010   
#define ROW2 (1 << 2)           // ROW2=d�calage � gauche de 2 bit : 0000 0100
#define ROW3 (1 << 3)           // ROW3=d�calage � gauche de 3 bit : 0000 1000


#define ALL_ROWS (ROW0|ROW1|ROW2|ROW3)           // All_ROWS=0000 1111 le r�sultat du OU entre Bits des vars ROWx
#define ALL_PINS (ALL_ROWS|COL0|COL1|COL2|COL3)  //ALL_PINS=1111 1111 le r�sultat du OU entre Bits des vars ROWx et colx

// Keypad layout:
char const KEYS[4][4] ={{'1','4','7','a'},    //  d�claration d'un tableau de 
                        {'2','5','8','0'},    //  caract�res de votre clavier
                        {'3','6','9','b'},    //  ( 4 lignes 4 rang�es)
                        {'*','/','-','+'}};
char kbd_getc() // retourne le caract�re entr�e
{     
  
   static BYTE col;
   BYTE kchar;
   BYTE row;

   kchar='\0';     // la variable=une chaine nulle 
   for (col=0;col<5;++col)
   {
      switch (col) // ex�cute l'instruction selon la valeur de col
      {                                
         case 0   : set_tris_kbd(ALL_PINS&~COL0);   // &~ : ET logique avec le compl�ment 1 de COL0
                    kbd=~COL0&ALL_PINS;   // Le portB =~ le comp 1 de COL1 ET ALL_PIN
                    break;   // On sort de sa structure switch
         case 1   : set_tris_kbd(ALL_PINS&~COL1);
                    kbd=~COL1&ALL_PINS;
                    break;
         case 2   : set_tris_kbd(ALL_PINS&~COL2);
                    kbd=~COL2&ALL_PINS;
                    break;
         case 3   : set_tris_kbd(ALL_PINS&~COL3);
                    kbd=~COL3&ALL_PINS;
                    break;
      }  
      if((kbd & (ALL_ROWS))!=(ALL_ROWS))  // si (le portb ET logique 0000 1111) n'�gale pas  0000 1111
      {  
         if((kbd & ROW0)==0)  row=0;   // choix de la rang�e
         else if((kbd & ROW1)==0) row=1;
         else if((kbd & ROW2)==0) row=2;
         else if((kbd & ROW3)==0) row=3;
         kchar=KEYS[row][col-1];
         
        /* 
         printf("%c%c",0xfe,0x94);
         printf("ranger = %1d",col-1);
         printf("%c%c",0xfe,0xd4);
         printf("Colone = %u",row);
         */
      }
   }
   set_tris_kbd(ALL_PINS);   // configuration du portB en I/O selon la variable ALL_PINS  
   return(kchar);
}
