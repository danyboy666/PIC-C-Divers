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
#include <lcd_db666.h>

#define rows 8

#define anim_speed 300


void anim_routine(void)
{
lcd_gotoxy(1,1); 
lcd_putc(0);
lcd_gotoxy(1,2); 
lcd_putc(0);
lcd_gotoxy(5,1); 
lcd_putc("Go Bruins Go!");
lcd_gotoxy(6,2); 
lcd_putc("Habs sucks!");
lcd_gotoxy(20,1);
lcd_putc(0);
lcd_gotoxy(20,2); 
lcd_putc(0);
delay_ms(anim_speed);
}




void dancing_guy_2(void)
{
int8 k;


wr_adress_1;

for (k=0;k<rows;k++)
{
int16 user_char[rows]={132,128,142,149,132,138,138,138};
lcd_send_byte(1,user_char[k]);
}

anim_routine();

wr_adress_1;

for (k=0;k<rows;k++)
{
int16 user_char[rows]={132,129,142,148,148,138,138,138};
lcd_send_byte(1,user_char[k]);
}

anim_routine();

wr_adress_1;

for (k=0;k<rows;k++)
{
int16 user_char[rows]={133,129,142,148,148,138,145,145};
lcd_send_byte(1,user_char[k]);
}


anim_routine();

wr_adress_1;

for (k=0;k<rows;k++)
{
int16 user_char[rows]={128,132,128,142,149,138,145,138};
lcd_send_byte(1,user_char[k]);
}


anim_routine();

wr_adress_1;

for (k=0;k<rows;k++)
{
int16 user_char[rows]={132,128,142,149,132,138,145,138};
lcd_send_byte(1,user_char[k]);
}


anim_routine();
wr_adress_1;

for (k=0;k<rows;k++)
{
int16 user_char[rows]={149,145,142,132,132,138,145,145};
lcd_send_byte(1,user_char[k]);
}

anim_routine();

wr_adress_1;

for (k=0;k<rows;k++)
{
int16 user_char[rows]={148,144,142,133,132,138,145,145};
lcd_send_byte(1,user_char[k]);
}


anim_routine();

wr_adress_1;

for (k=0;k<rows;k++)
{
int16 user_char[rows]={133,129,142,148,132,138,145,145};
lcd_send_byte(1,user_char[k]);
}


anim_routine();

wr_adress_1;

for (k=0;k<rows;k++)
{
int16 user_char[rows]={132,129,142,148,148,138,138,138};
lcd_send_byte(1,user_char[k]);
}


anim_routine();


}

void Go_Boston_Go_Anim(void)

{
int8 i;



wr_adress_1;

for (i=0;i<rows;i++)
{
int8 upper1[rows]={128,128,128,129,129,129,131,131};
lcd_send_byte(1,upper1[i]);
}
//lcd_gotoxy(1,1); 

wr_adress_2;

for (i=0;i<rows;i++)
{
int8 upper2[rows]={131,143,156,155,148,141,157,157};
lcd_send_byte(1,upper2[i]);
}
//lcd_gotoxy(2,1); 

wr_adress_3;

for (i=0;i<rows;i++)
{
int8 upper3[rows]={152,158,135,155,141,150,151,143};
lcd_send_byte(1,upper3[i]);
}
//lcd_gotoxy(1,2); 

wr_adress_4;

for (i=0;i<rows;i++)
{
int8 upper4[rows]={128,128,128,144,144,144,152,152};
lcd_send_byte(1,upper4[i]);
}
//lcd_gotoxy(2,2); 
wr_adress_5;

for (i=0;i<rows;i++)
{
int8 lower1[rows]={131,131,129,129,129,128,128,128};
lcd_send_byte(1,lower1[i]);
}

wr_adress_6;

for (i=0;i<rows;i++)
{
int8 lower2[rows]={157,157,141,148,155,156,143,131};
lcd_send_byte(1,lower2[i]);
}
wr_adress_7;

for (i=0;i<rows;i++)
{
int8 lower3[rows]={143,151,150,141,155,135,158,152};
lcd_send_byte(1,lower3[i]);
}
wr_adress_8;

for (i=0;i<rows;i++)
{
int8 lower4[rows]={152,152,144,144,144,128,128,128};
lcd_send_byte(1,lower4[i]);
}
//Animation_1(); 

lcd_gotoxy(1,1); 
lcd_putc(0);
lcd_gotoxy(2,1); 
lcd_putc(1); 
lcd_gotoxy(3,1); 
lcd_putc(2);
lcd_gotoxy(4,1); 
lcd_putc(3);
lcd_gotoxy(5,1); 
lcd_putc("Go Bruins Go!");
lcd_gotoxy(1,2); 
lcd_putc(4);
lcd_gotoxy(2,2); 
lcd_putc(5);
lcd_gotoxy(3,2); 
lcd_putc(6);
lcd_gotoxy(4,2); 
lcd_putc(7);
lcd_gotoxy(5,2); 
lcd_putc("    2-2     ");

lcd_gotoxy(18,1); 
lcd_putc(0);
lcd_gotoxy(19,1); 
lcd_putc(1); 
lcd_gotoxy(20,1); 
lcd_putc(2);
lcd_gotoxy(21,1); 
lcd_putc(3);

lcd_gotoxy(18,2); 
lcd_putc(4);
lcd_gotoxy(19,2); 
lcd_putc(5);
lcd_gotoxy(20,2); 
lcd_putc(6);
lcd_gotoxy(21,2); 
lcd_putc(7);

//Animation_1(); 
}


void main()
{

int8 j,m,n;




lcd_init(); 

do
{

for (m=0;m<3;m++)
{

dancing_guy_2(); 

}
delay_ms(1000);
clr_display();


Go_Boston_Go_Anim();

for(n=0;n<2;n++) 
  { 
   for(j = 0; j < 20; j++)  // Scroll for 20 chars 
      {
       
       lcd_scroll_left(); 
       delay_ms(300);   // This sets the scroll speed 
      } 

    
  } 
delay_ms(1000);
clr_display();

}

while(true);



 
 



}