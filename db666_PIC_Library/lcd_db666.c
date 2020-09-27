
/*template for custom characters

lcd_send_byte(0,0x40); 


lcd_send_byte(1,0b00000); // | | | | | | 
lcd_send_byte(1,0b00000); // | | | | | | 
lcd_send_byte(1,0b00000); // | | | | | | 
lcd_send_byte(1,0b00000); // | | | | | | 
lcd_send_byte(1,0b00000); // | | | | | | 
lcd_send_byte(1,0b00000); // | | | | | | 
lcd_send_byte(1,0b00000); // | | | | | | 
lcd_send_byte(1,0b00000); // | | | | | | 





lcd_gotoxy(1,1); 
lcd_send_byte(1,0); 
*/

//Define write to CGRAM adress
#define wr_adress_1  lcd_send_byte(0,0x40) //0 ASCII code
#define wr_adress_2  lcd_send_byte(0,0x48) //1 ASCII code
#define wr_adress_3  lcd_send_byte(0,0x50) //2 ASCII code
#define wr_adress_4  lcd_send_byte(0,0x58) //3 ASCII code
#define wr_adress_5  lcd_send_byte(0,0x60) //4 ASCII code
#define wr_adress_6  lcd_send_byte(0,0x68) //5 ASCII code
#define wr_adress_7  lcd_send_byte(0,0x70) //6 ASCII code
#define wr_adress_8  lcd_send_byte(0,0x78) //7 ASCII code
/*
//Define print to lcd character from CGRAM adress
#define prnt_char_1 lcd_send_byte(1,0)
#define prnt_char_2 lcd_send_byte(1,1)
#define prnt_char_3 lcd_send_byte(1,2)
#define prnt_char_4 lcd_send_byte(1,3)
#define prnt_char_5 lcd_send_byte(1,4)
#define prnt_char_6 lcd_send_byte(1,5)
#define prnt_char_7 lcd_send_byte(1,6)
#define prnt_char_8 lcd_send_byte(1,7)
*/


void clr_display(void)
{
lcd_send_byte(0,1);
}

void lcd_scroll_right(void) 
{ 
lcd_send_byte(0, 0x1E); 
} 


void lcd_scroll_left(void) 
{ 
lcd_send_byte(0, 0x18); 
}


//scroll test template

/*
int8 i; 

lcd_init();
lcd_gotoxy(5,1);
lcd_putc("\f");  // Clear the LCD 
delay_ms(100);    


char ScrollTest[20]={"Hello to the world!"};

printf(lcd_putc,"%s",ScrollTest);


while(1) 
  { 
   for(i = 0; i < 20; i++)  // Scroll for 20 chars 
      { 
       lcd_scroll_left(); 
       delay_ms(300);   // This sets the scroll speed 
      } 

    
  } 
*/

/* side scroll exemple 2

#include <16F877.H> 
#fuses XT, NOWDT, NOPROTECT, BROWNOUT, PUT, NOLVP 
#use delay(clock=4000000) 

#include "flex_lcd.c" 

void lcd_scroll_right(void) 
{ 
lcd_send_byte(0, 0x1E); 
} 
//------------------------- 
void lcd_scroll_left(void) 
{ 
lcd_send_byte(0, 0x18); 
} 
    
//======================= 
void main() 
{ 
int8 i; 

lcd_init(); 

lcd_putc("\f");  // Clear the LCD 
delay_ms(100);    

// The 16x2 LCD memory is 40 characters wide, so fill it 
// up with data for two screens.  Each line below must 
// contain 40 characters (excluding the newline).    
lcd_putc("Hello to the        Side scrolling      \n"); 
lcd_putc("world.              demo.               "); 

delay_ms(1000); 

while(1) 
  { 
   for(i = 0; i < 20; i++)  // Scroll for 20 chars 
      { 
       lcd_scroll_left(); 
       delay_ms(200);   // This sets the scroll speed 
      } 

   delay_ms(2000);   // Wait 2 seconds between scrolling 
                     // each screen. 
  } 

}

*/



/*
char message[15] = "Hello World!  "; 
   int8 ctr; 
   for (ctr=0;ctr<14;ctr++) { 
       lcd_gotoxy(1,2); 
       printf(lcd_putc,"%s",message+ctr); 
       delay_ms(100); 
   } 

*/