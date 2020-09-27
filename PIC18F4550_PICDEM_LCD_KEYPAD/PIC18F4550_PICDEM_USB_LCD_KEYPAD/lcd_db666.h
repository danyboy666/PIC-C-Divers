
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
#define WR_ADRESS_1  lcd_send_byte(0,0x40) //0 ASCII code
#define WR_ADRESS_2  lcd_send_byte(0,0x48) //1 ASCII code
#define WR_ADRESS_3  lcd_send_byte(0,0x50) //2 ASCII code
#define WR_ADRESS_4  lcd_send_byte(0,0x58) //3 ASCII code
#define WR_ADRESS_5  lcd_send_byte(0,0x60) //4 ASCII code
#define WR_ADRESS_6  lcd_send_byte(0,0x68) //5 ASCII code
#define WR_ADRESS_7  lcd_send_byte(0,0x70) //6 ASCII code
#define WR_ADRESS_8  lcd_send_byte(0,0x78) //7 ASCII code
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

//table de fonctions LCD
#define clear_lcd         0x01 // Clear Display
#define return_home       0x02 // Cursor to Home position
#define entry_mode            0x06 // Normal entry mode
#define entry_mode_rev        0x04 // Normal entry mode  -reverse direction
#define entry_mode_scroll 0x07 // - with shift
#define entry_mode_scroll_rev   0x05 // reverse direction
 
#define system_set_8_bit      0x38 // 8 bit data mode 2 line ( 5x7 font )
#define system_set_4_bit      0x28 // 4 bit data mode 2 line ( 5x7 font )
#define system_set_reset      0x30 // Reset code
#define display_on            0x0C // Display ON - 2 line mode
#define display_off       0x08 // Display off
#define set_dd_line1          0x80 // Line 1 position 1
#define set_dd_line2          0xC0 // Line 2 position 1
#define set_dd_ram            0x80 // Line 1 position 1
#define write_data            0x00 // With RS = 1
#define cursor_on         0x0E // Switch Cursor ON
#define cursor_off            0x0C // Switch Cursor OFF
#define cursor_blink_on   0x0F // Cursor plus blink
#define cursor_shift_right    0x14 // Move cursor right
#define cursor_shift_left 0x10 // Move cursor left
#define display_shift_right    0x1C // Scroll display right
#define display_shift_left    0x18 // Scroll display left
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

void cursor_on(void) 
{ 
lcd_send_byte(0, 0x0E); 
}

void cursor_off(void) 
{ 
lcd_send_byte(0, 0x0C); 
}
void cursor_blink_on(void) 
{ 
lcd_send_byte(0, 0x0F); 
}

void cursor_blink_off(void) 
{ 
lcd_send_byte(0, 0x0D); 
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


/*You can use it in 'one byte' steps, using: 
#ROM int8 0xF00000 = {1,2,3,4} 


The following is an example of how to read and write a floating point number from/to EEPROM. The same concept may be used for structures, arrays or any other type.

n is an offset into the eeprom.
For example if the first float is at 0 the second
For floats you must increment it by 4.
one should be at 4 and the third at 8.
WRITE_FLOAT_EXT_EEPROM(long int n, float data) { 
   int i;

   for (i = 0; i < 4; i++) 
      write_ext_eeprom(i + n, *((int8*)&data + i) ) ; 
}

float READ_FLOAT_EXT_EEPROM(long int n) { 
   int i; 
   float data;

   for (i = 0; i < 4; i++) 
      *((int8*)&data + i) = read_ext_eeprom(i + n);

   return(data); 
}*/
