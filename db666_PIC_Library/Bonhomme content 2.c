#define LCD_TYPE 2  
#define LCD_ENABLE_PIN  PIN_E2
#define LCD_RW_PIN      PIN_E1
#define LCD_RS_PIN      PIN_E0
#define LCD_DATA4       PIN_D4
#define LCD_DATA5       PIN_D5
#define LCD_DATA6       PIN_D6
#define LCD_DATA7       PIN_D7

#include <lcd.c>
#include <string.h>

#define rows 8

void Animation_1(void)
{
int8 i;

do
{

lcd_send_byte(0,0x40);

for (i=0;i<rows;i++)
{
int16 user_char[rows]={132,128,142,149,132,138,138,138};
lcd_send_byte(1,user_char[i]);
}

lcd_gotoxy(1,1); 
lcd_send_byte(1,0); 
delay_ms(250);
lcd_send_byte(0,1); 


lcd_send_byte(0,0x40);

delay_ms(1);

for (i=0;i<rows;i++)
{
int16 user_char[rows]={132,129,142,148,148,138,138,138};
lcd_send_byte(1,user_char[i]);
}

lcd_gotoxy(1,1); 
lcd_send_byte(1,0); 
delay_ms(250);
lcd_send_byte(0,1); 




lcd_send_byte(0,0x40);

delay_ms(1);

for (i=0;i<rows;i++)
{
int16 user_char[rows]={133,129,142,148,148,138,145,145};
lcd_send_byte(1,user_char[i]);
}

lcd_gotoxy(1,1); 
lcd_send_byte(1,0); 
delay_ms(250);
lcd_send_byte(0,1); 

lcd_send_byte(0,0x40);

delay_ms(1);

for (i=0;i<rows;i++)
{
int16 user_char[rows]={128,132,128,142,149,138,145,138};
lcd_send_byte(1,user_char[i]);
}

lcd_gotoxy(1,1); 
lcd_send_byte(1,0); 
delay_ms(250);
lcd_send_byte(0,1); 

lcd_send_byte(0,0x40);

delay_ms(1);

for (i=0;i<rows;i++)
{
int16 user_char[rows]={132,128,142,149,132,138,145,138};
lcd_send_byte(1,user_char[i]);
}

lcd_gotoxy(1,1); 
lcd_send_byte(1,0); 
delay_ms(250);
lcd_send_byte(0,1);

lcd_send_byte(0,0x40);

delay_ms(1);

for (i=0;i<rows;i++)
{
int16 user_char[rows]={149,145,142,132,132,138,145,145};
lcd_send_byte(1,user_char[i]);
}

lcd_gotoxy(1,1); 
lcd_send_byte(1,0); 
delay_ms(250);
lcd_send_byte(0,1);

lcd_send_byte(0,0x40);

delay_ms(1);

for (i=0;i<rows;i++)
{
int16 user_char[rows]={148,144,142,133,132,138,145,145};
lcd_send_byte(1,user_char[i]);
}

lcd_gotoxy(1,1); 
lcd_send_byte(1,0); 
delay_ms(250);
lcd_send_byte(0,1);

lcd_send_byte(0,0x40);

delay_ms(1);

for (i=0;i<rows;i++)
{
int16 user_char[rows]={133,129,142,148,132,138,145,145};
lcd_send_byte(1,user_char[i]);
}

lcd_gotoxy(1,1); 
lcd_send_byte(1,0); 
delay_ms(250);
lcd_send_byte(0,1);

lcd_send_byte(0,0x40);

delay_ms(1);

for (i=0;i<rows;i++)
{
int16 user_char[rows]={132,129,142,148,148,138,138,138};
lcd_send_byte(1,user_char[i]);
}

lcd_gotoxy(1,1); 
lcd_send_byte(1,0); 
delay_ms(250);
lcd_send_byte(0,1); 

}
while(true);
}

void main()
{
lcd_init(); 




Animation_1();  

 
 



}
