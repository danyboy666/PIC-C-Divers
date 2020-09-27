#define rows 8

void Animation_1(void)
{
int8 i;
char msgL1[21],msgL2[21];




strcpy(msgL1, "LCD Pacman");


strcpy(msgL2, "Game Over");







do
{


lcd_send_byte(0,0x58);

delay_ms(1);

for (i=0;i<rows;i++)
{
int16 clr_pos[rows]={128,128,128,128,128,128,128,128};
lcd_send_byte(1,clr_pos[i]);
}





lcd_send_byte(0,0x48);
for (i=0;i<rows;i++)
{
int16 Ghost[rows]={128,142,149,159,159,149,128,128};
lcd_send_byte(1,Ghost[i]);
}





lcd_send_byte(0,0x50);
for (i=0;i<rows;i++)
{
int16 dot[rows]={128,128,128,152,152,128,128,128};
lcd_send_byte(1,dot[i]);
}


lcd_send_byte(0,0x40);

delay_ms(1);

for (i=0;i<rows;i++)
{
int16 Pac_Open[rows]={128,143,158,156,158,143,128,128};
lcd_send_byte(1,Pac_Open[i]);
}


lcd_gotoxy(6,1);
printf(lcd_putc,"%s",msgL1);




lcd_gotoxy(20,2); 
lcd_send_byte(1,1); 
lcd_gotoxy(1,2); 
lcd_send_byte(1,0); 
lcd_gotoxy(2,2);
lcd_send_byte(1,2);
lcd_gotoxy(3,2);
lcd_send_byte(1,2);
lcd_gotoxy(4,2);
lcd_send_byte(1,2);
lcd_gotoxy(5,2);
lcd_send_byte(1,2);
lcd_gotoxy(6,2);
lcd_send_byte(1,2);
lcd_gotoxy(7,2);
lcd_send_byte(1,2);
lcd_gotoxy(8,2);
lcd_send_byte(1,2);
lcd_gotoxy(9,2);
lcd_send_byte(1,2);
lcd_gotoxy(10,2);
lcd_send_byte(1,2);
lcd_gotoxy(11,2);
lcd_send_byte(1,2);
lcd_gotoxy(12,2);
lcd_send_byte(1,2);
lcd_gotoxy(13,2);
lcd_send_byte(1,2);
lcd_gotoxy(14,2);
lcd_send_byte(1,2);
lcd_gotoxy(15,2);
lcd_send_byte(1,2);
lcd_gotoxy(16,2);
lcd_send_byte(1,2);
lcd_gotoxy(17,2);
lcd_send_byte(1,2);
lcd_gotoxy(18,2);
lcd_send_byte(1,2);
lcd_gotoxy(19,2);
lcd_send_byte(1,2);

delay_ms(250);
lcd_send_byte(0,1);
 

lcd_send_byte(0,0x40);

delay_ms(1);

for (i=0;i<rows;i++)
{
int16 Pac_Close[rows]={128,142,159,159,159,142,128,128};
lcd_send_byte(1,Pac_Close[i]);
}


lcd_gotoxy(6,1);
printf(lcd_putc,"%s",msgL1);

lcd_gotoxy(20,2); 
lcd_send_byte(1,1); 
lcd_gotoxy(2,2); 
lcd_send_byte(1,0); 
lcd_send_byte(1,2);
lcd_gotoxy(3,2);
lcd_send_byte(1,2);
lcd_gotoxy(4,2);
lcd_send_byte(1,2);
lcd_gotoxy(5,2);
lcd_send_byte(1,2);
lcd_gotoxy(6,2);
lcd_send_byte(1,2);
lcd_gotoxy(7,2);
lcd_send_byte(1,2);
lcd_gotoxy(8,2);
lcd_send_byte(1,2);
lcd_gotoxy(9,2);
lcd_send_byte(1,2);
lcd_gotoxy(10,2);
lcd_send_byte(1,2);
lcd_gotoxy(11,2);
lcd_send_byte(1,2);
lcd_gotoxy(12,2);
lcd_send_byte(1,2);
lcd_gotoxy(13,2);
lcd_send_byte(1,2);
lcd_gotoxy(14,2);
lcd_send_byte(1,2);
lcd_gotoxy(15,2);
lcd_send_byte(1,2);
lcd_gotoxy(16,2);
lcd_send_byte(1,2);
lcd_gotoxy(17,2);
lcd_send_byte(1,2);
lcd_gotoxy(18,2);
lcd_send_byte(1,2);
lcd_gotoxy(19,2);
lcd_send_byte(1,2);
delay_ms(250);
lcd_send_byte(0,1);


lcd_send_byte(0,0x40);

for (i=0;i<rows;i++)
{
int16 Pac_Open[rows]={128,143,158,156,158,143,128,128};
lcd_send_byte(1,Pac_Open[i]);
}


lcd_gotoxy(6,1);
printf(lcd_putc,"%s",msgL1);

lcd_gotoxy(20,2); 
lcd_send_byte(1,1);
lcd_gotoxy(3,2); 
lcd_send_byte(1,0); 
lcd_send_byte(1,2);
lcd_gotoxy(4,2);
lcd_send_byte(1,2);
lcd_gotoxy(5,2);
lcd_send_byte(1,2);
lcd_gotoxy(6,2);
lcd_send_byte(1,2);
lcd_gotoxy(7,2);
lcd_send_byte(1,2);
lcd_gotoxy(8,2);
lcd_send_byte(1,2);
lcd_gotoxy(9,2);
lcd_send_byte(1,2);
lcd_gotoxy(10,2);
lcd_send_byte(1,2);
lcd_gotoxy(11,2);
lcd_send_byte(1,2);
lcd_gotoxy(12,2);
lcd_send_byte(1,2);
lcd_gotoxy(13,2);
lcd_send_byte(1,2);
lcd_gotoxy(14,2);
lcd_send_byte(1,2);
lcd_gotoxy(15,2);
lcd_send_byte(1,2);
lcd_gotoxy(16,2);
lcd_send_byte(1,2);
lcd_gotoxy(17,2);
lcd_send_byte(1,2);
lcd_gotoxy(18,2);
lcd_send_byte(1,2);
lcd_gotoxy(19,2);
lcd_send_byte(1,2);
delay_ms(250);
lcd_send_byte(0,1);


lcd_send_byte(0,0x40);

delay_ms(1);

for (i=0;i<rows;i++)
{
int16 Pac_Close[rows]={128,142,159,159,159,142,128,128};
lcd_send_byte(1,Pac_Close[i]);
}


lcd_gotoxy(6,1);
printf(lcd_putc,"%s",msgL1);

lcd_gotoxy(20,2); 
lcd_send_byte(1,1);
lcd_gotoxy(4,2); 
lcd_send_byte(1,0); 
lcd_send_byte(1,2);
lcd_gotoxy(5,2);
lcd_send_byte(1,2);
lcd_gotoxy(6,2);
lcd_send_byte(1,2);
lcd_gotoxy(7,2);
lcd_send_byte(1,2);
lcd_gotoxy(8,2);
lcd_send_byte(1,2);
lcd_gotoxy(9,2);
lcd_send_byte(1,2);
lcd_gotoxy(10,2);
lcd_send_byte(1,2);
lcd_gotoxy(11,2);
lcd_send_byte(1,2);
lcd_gotoxy(12,2);
lcd_send_byte(1,2);
lcd_gotoxy(13,2);
lcd_send_byte(1,2);
lcd_gotoxy(14,2);
lcd_send_byte(1,2);
lcd_gotoxy(15,2);
lcd_send_byte(1,2);
lcd_gotoxy(16,2);
lcd_send_byte(1,2);
lcd_gotoxy(17,2);
lcd_send_byte(1,2);
lcd_gotoxy(18,2);
lcd_send_byte(1,2);
lcd_gotoxy(19,2);
lcd_send_byte(1,2);
delay_ms(250);
lcd_send_byte(0,1);

lcd_send_byte(0,0x40);

for (i=0;i<rows;i++)
{
int16 Pac_Open[rows]={128,143,158,156,158,143,128,128};
lcd_send_byte(1,Pac_Open[i]);
}


lcd_gotoxy(6,1);
printf(lcd_putc,"%s",msgL1);

lcd_gotoxy(20,2); 
lcd_send_byte(1,1);
lcd_gotoxy(5,2); 
lcd_send_byte(1,0); 
lcd_send_byte(1,2);
lcd_gotoxy(6,2);
lcd_send_byte(1,2);
lcd_gotoxy(7,2);
lcd_send_byte(1,2);
lcd_gotoxy(8,2);
lcd_send_byte(1,2);
lcd_gotoxy(9,2);
lcd_send_byte(1,2);
lcd_gotoxy(10,2);
lcd_send_byte(1,2);
lcd_gotoxy(11,2);
lcd_send_byte(1,2);
lcd_gotoxy(12,2);
lcd_send_byte(1,2);
lcd_gotoxy(13,2);
lcd_send_byte(1,2);
lcd_gotoxy(14,2);
lcd_send_byte(1,2);
lcd_gotoxy(15,2);
lcd_send_byte(1,2);
lcd_gotoxy(16,2);
lcd_send_byte(1,2);
lcd_gotoxy(17,2);
lcd_send_byte(1,2);
lcd_gotoxy(18,2);
lcd_send_byte(1,2);
lcd_gotoxy(19,2);
lcd_send_byte(1,2);
delay_ms(250);
lcd_send_byte(0,2);


lcd_send_byte(0,0x40);

delay_ms(1);

for (i=0;i<rows;i++)
{
int16 Pac_Close[rows]={128,142,159,159,159,142,128,128};
lcd_send_byte(1,Pac_Close[i]);
}


lcd_gotoxy(6,1);
printf(lcd_putc,"%s",msgL1);

lcd_gotoxy(20,2); 
lcd_send_byte(1,1);
lcd_gotoxy(6,2); 
lcd_send_byte(1,0); 
lcd_send_byte(1,2);
lcd_gotoxy(7,2);
lcd_send_byte(1,2);
lcd_gotoxy(8,2);
lcd_send_byte(1,2);
lcd_gotoxy(9,2);
lcd_send_byte(1,2);
lcd_gotoxy(10,2);
lcd_send_byte(1,2);
lcd_gotoxy(11,2);
lcd_send_byte(1,2);
lcd_gotoxy(12,2);
lcd_send_byte(1,2);
lcd_gotoxy(13,2);
lcd_send_byte(1,2);
lcd_gotoxy(14,2);
lcd_send_byte(1,2);
lcd_gotoxy(15,2);
lcd_send_byte(1,2);
lcd_gotoxy(16,2);
lcd_send_byte(1,2);
lcd_gotoxy(17,2);
lcd_send_byte(1,2);
lcd_gotoxy(18,2);
lcd_send_byte(1,2);
lcd_gotoxy(19,2);
lcd_send_byte(1,2);
delay_ms(250);
lcd_send_byte(0,1);

lcd_send_byte(0,0x40);

for (i=0;i<rows;i++)
{
int16 Pac_Open[rows]={128,143,158,156,158,143,128,128};
lcd_send_byte(1,Pac_Open[i]);
}


lcd_gotoxy(6,1);
printf(lcd_putc,"%s",msgL1);

lcd_gotoxy(20,2); 
lcd_send_byte(1,1);
lcd_gotoxy(7,2); 
lcd_send_byte(1,0);
lcd_send_byte(1,2);
lcd_gotoxy(8,2);
lcd_send_byte(1,2);
lcd_gotoxy(9,2);
lcd_send_byte(1,2);
lcd_gotoxy(10,2);
lcd_send_byte(1,2);
lcd_gotoxy(11,2);
lcd_send_byte(1,2);
lcd_gotoxy(12,2);
lcd_send_byte(1,2);
lcd_gotoxy(13,2);
lcd_send_byte(1,2);
lcd_gotoxy(14,2);
lcd_send_byte(1,2);
lcd_gotoxy(15,2);
lcd_send_byte(1,2);
lcd_gotoxy(16,2);
lcd_send_byte(1,2);
lcd_gotoxy(17,2);
lcd_send_byte(1,2);
lcd_gotoxy(18,2);
lcd_send_byte(1,2);
lcd_gotoxy(19,2);
lcd_send_byte(1,2);
delay_ms(250);
lcd_send_byte(0,1);


lcd_send_byte(0,0x40);

delay_ms(1);

for (i=0;i<rows;i++)
{
int16 Pac_Close[rows]={128,142,159,159,159,142,128,128};
lcd_send_byte(1,Pac_Close[i]);
}


lcd_gotoxy(6,1);
printf(lcd_putc,"%s",msgL1);

lcd_gotoxy(20,2); 
lcd_send_byte(1,1);
lcd_gotoxy(8,2); 
lcd_send_byte(1,0);
lcd_send_byte(1,2);
lcd_gotoxy(9,2);
lcd_send_byte(1,2);
lcd_gotoxy(10,2);
lcd_send_byte(1,2);
lcd_gotoxy(11,2);
lcd_send_byte(1,2);
lcd_gotoxy(12,2);
lcd_send_byte(1,2);
lcd_gotoxy(13,2);
lcd_send_byte(1,2);
lcd_gotoxy(14,2);
lcd_send_byte(1,2);
lcd_gotoxy(15,2);
lcd_send_byte(1,2);
lcd_gotoxy(16,2);
lcd_send_byte(1,2);
lcd_gotoxy(17,2);
lcd_send_byte(1,2);
lcd_gotoxy(18,2);
lcd_send_byte(1,2);
lcd_gotoxy(19,2);
lcd_send_byte(1,2);
delay_ms(250);
lcd_send_byte(0,1);

lcd_send_byte(0,0x40);

for (i=0;i<rows;i++)
{
int16 Pac_Open[rows]={128,143,158,156,158,143,128,128};
lcd_send_byte(1,Pac_Open[i]);
}


lcd_gotoxy(6,1);
printf(lcd_putc,"%s",msgL1);

lcd_gotoxy(20,2); 
lcd_send_byte(1,1);
lcd_gotoxy(9,2); 
lcd_send_byte(1,0); 
lcd_send_byte(1,2);
lcd_gotoxy(10,2);
lcd_send_byte(1,2);
lcd_gotoxy(11,2);
lcd_send_byte(1,2);
lcd_gotoxy(12,2);
lcd_send_byte(1,2);
lcd_gotoxy(13,2);
lcd_send_byte(1,2);
lcd_gotoxy(14,2);
lcd_send_byte(1,2);
lcd_gotoxy(15,2);
lcd_send_byte(1,2);
lcd_gotoxy(16,2);
lcd_send_byte(1,2);
lcd_gotoxy(17,2);
lcd_send_byte(1,2);
lcd_gotoxy(18,2);
lcd_send_byte(1,2);
lcd_gotoxy(19,2);
lcd_send_byte(1,2);
delay_ms(250);
lcd_send_byte(0,1);


lcd_send_byte(0,0x40);

delay_ms(1);

for (i=0;i<rows;i++)
{
int16 Pac_Close[rows]={128,142,159,159,159,142,128,128};
lcd_send_byte(1,Pac_Close[i]);
}


lcd_gotoxy(6,1);
printf(lcd_putc,"%s",msgL1);

lcd_gotoxy(20,2); 
lcd_send_byte(1,1);
lcd_gotoxy(10,2); 
lcd_send_byte(1,0); 
lcd_send_byte(1,2);
lcd_gotoxy(11,2);
lcd_send_byte(1,2);
lcd_gotoxy(12,2);
lcd_send_byte(1,2);
lcd_gotoxy(13,2);
lcd_send_byte(1,2);
lcd_gotoxy(14,2);
lcd_send_byte(1,2);
lcd_gotoxy(15,2);
lcd_send_byte(1,2);
lcd_gotoxy(16,2);
lcd_send_byte(1,2);
lcd_gotoxy(17,2);
lcd_send_byte(1,2);
lcd_gotoxy(18,2);
lcd_send_byte(1,2);
lcd_gotoxy(19,2);
lcd_send_byte(1,2);
delay_ms(250);
lcd_send_byte(0,1);

lcd_send_byte(0,0x40);

for (i=0;i<rows;i++)
{
int16 Pac_Open[rows]={128,143,158,156,158,143,128,128};
lcd_send_byte(1,Pac_Open[i]);
}


lcd_gotoxy(6,1);
printf(lcd_putc,"%s",msgL1);

lcd_gotoxy(20,2); 
lcd_send_byte(1,1);
lcd_gotoxy(11,2); 
lcd_send_byte(1,0);
lcd_send_byte(1,2);
lcd_gotoxy(12,2);
lcd_send_byte(1,2);
lcd_gotoxy(13,2);
lcd_send_byte(1,2);
lcd_gotoxy(14,2);
lcd_send_byte(1,2);
lcd_gotoxy(15,2);
lcd_send_byte(1,2);
lcd_gotoxy(16,2);
lcd_send_byte(1,2);
lcd_gotoxy(17,2);
lcd_send_byte(1,2);
lcd_gotoxy(18,2);
lcd_send_byte(1,2);
lcd_gotoxy(19,2);
lcd_send_byte(1,2);
delay_ms(250);
lcd_send_byte(0,1);


lcd_send_byte(0,0x40);

delay_ms(1);

for (i=0;i<rows;i++)
{
int16 Pac_Close[rows]={128,142,159,159,159,142,128,128};
lcd_send_byte(1,Pac_Close[i]);
}


lcd_gotoxy(6,1);
printf(lcd_putc,"%s",msgL1);

lcd_gotoxy(20,2); 
lcd_send_byte(1,1);
lcd_gotoxy(12,2); 
lcd_send_byte(1,0);
lcd_send_byte(1,2);
lcd_gotoxy(13,2);
lcd_send_byte(1,2);
lcd_gotoxy(14,2);
lcd_send_byte(1,2);
lcd_gotoxy(15,2);
lcd_send_byte(1,2);
lcd_gotoxy(16,2);
lcd_send_byte(1,2);
lcd_gotoxy(17,2);
lcd_send_byte(1,2);
lcd_gotoxy(18,2);
lcd_send_byte(1,2);
lcd_gotoxy(19,2);
lcd_send_byte(1,2);
delay_ms(250);
lcd_send_byte(0,1);

lcd_send_byte(0,0x40);

for (i=0;i<rows;i++)
{
int16 Pac_Open[rows]={128,143,158,156,158,143,128,128};
lcd_send_byte(1,Pac_Open[i]);
}


lcd_gotoxy(6,1);
printf(lcd_putc,"%s",msgL1);

lcd_gotoxy(20,2); 
lcd_send_byte(1,1);
lcd_gotoxy(13,2); 
lcd_send_byte(1,0);
lcd_send_byte(1,2);
lcd_gotoxy(14,2);
lcd_send_byte(1,2);
lcd_gotoxy(15,2);
lcd_send_byte(1,2);
lcd_gotoxy(16,2);
lcd_send_byte(1,2);
lcd_gotoxy(17,2);
lcd_send_byte(1,2);
lcd_gotoxy(18,2);
lcd_send_byte(1,2);
lcd_gotoxy(19,2);
lcd_send_byte(1,2);
delay_ms(250);
lcd_send_byte(0,1);


lcd_send_byte(0,0x40);

delay_ms(1);

for (i=0;i<rows;i++)
{
int16 Pac_Close[rows]={128,142,159,159,159,142,128,128};
lcd_send_byte(1,Pac_Close[i]);
}


lcd_gotoxy(6,1);
printf(lcd_putc,"%s",msgL1);

lcd_gotoxy(20,2); 
lcd_send_byte(1,1);
lcd_gotoxy(14,2); 
lcd_send_byte(1,0); 
lcd_send_byte(1,2);
lcd_gotoxy(15,2);
lcd_send_byte(1,2);
lcd_gotoxy(16,2);
lcd_send_byte(1,2);
lcd_gotoxy(17,2);
lcd_send_byte(1,2);
lcd_gotoxy(18,2);
lcd_send_byte(1,2);
lcd_gotoxy(19,2);
lcd_send_byte(1,2);
delay_ms(250);
lcd_send_byte(0,1);

lcd_send_byte(0,0x40);

for (i=0;i<rows;i++)
{
int16 Pac_Open[rows]={128,143,158,156,158,143,128,128};
lcd_send_byte(1,Pac_Open[i]);
}


lcd_gotoxy(6,1);
printf(lcd_putc,"%s",msgL1);

lcd_gotoxy(20,2); 
lcd_send_byte(1,1);
lcd_gotoxy(15,2); 
lcd_send_byte(1,0);
lcd_send_byte(1,2);
lcd_gotoxy(16,2);
lcd_send_byte(1,2);
lcd_gotoxy(17,2);
lcd_send_byte(1,2);
lcd_gotoxy(18,2);
lcd_send_byte(1,2);
lcd_gotoxy(19,2);
lcd_send_byte(1,2);
delay_ms(250);
lcd_send_byte(0,1);


lcd_send_byte(0,0x40);

delay_ms(1);

for (i=0;i<rows;i++)
{
int16 Pac_Close[rows]={128,142,159,159,159,142,128,128};
lcd_send_byte(1,Pac_Close[i]);
}


lcd_gotoxy(6,1);
printf(lcd_putc,"%s",msgL1);

lcd_gotoxy(20,2); 
lcd_send_byte(1,1);
lcd_gotoxy(16,2); 
lcd_send_byte(1,0); 
lcd_send_byte(1,2);
lcd_gotoxy(17,2);
lcd_send_byte(1,2);
lcd_gotoxy(18,2);
lcd_send_byte(1,2);
lcd_gotoxy(19,2);
lcd_send_byte(1,2);
delay_ms(250);
lcd_send_byte(0,1);

lcd_send_byte(0,0x40);

for (i=0;i<rows;i++)
{
int16 Pac_Open[rows]={128,143,158,156,158,143,128,128};
lcd_send_byte(1,Pac_Open[i]);
}


lcd_gotoxy(6,1);
printf(lcd_putc,"%s",msgL1);

lcd_gotoxy(20,2); 
lcd_send_byte(1,1);
lcd_gotoxy(17,2); 
lcd_send_byte(1,0);
lcd_send_byte(1,2);
lcd_gotoxy(18,2);
lcd_send_byte(1,2);
lcd_gotoxy(19,2);
lcd_send_byte(1,2);
delay_ms(250);
lcd_send_byte(0,1);


lcd_send_byte(0,0x40);

delay_ms(1);

for (i=0;i<rows;i++)
{
int16 Pac_Close[rows]={128,142,159,159,159,142,128,128};
lcd_send_byte(1,Pac_Close[i]);
}


lcd_gotoxy(6,1);
printf(lcd_putc,"%s",msgL1);

lcd_gotoxy(20,2); 
lcd_send_byte(1,1);
lcd_gotoxy(18,2); 
lcd_send_byte(1,0);
lcd_send_byte(1,2);
lcd_gotoxy(19,2);
lcd_send_byte(1,2);
delay_ms(250);
lcd_send_byte(0,1);

lcd_send_byte(0,0x40);

for (i=0;i<rows;i++)
{
int16 Pac_Dead1[rows]={128,128,145,155,159,142,128,128};
lcd_send_byte(1,Pac_Dead1[i]);
}



lcd_gotoxy(6,1);
printf(lcd_putc,"%s",msgL2);

lcd_gotoxy(20,2); 
lcd_send_byte(1,1);
lcd_gotoxy(19,2); 
lcd_send_byte(1,0); 

delay_ms(250);
lcd_send_byte(0,1);


lcd_send_byte(0,0x40);

delay_ms(1);

for (i=0;i<rows;i++)
{
int16 Pac_Dead2[rows]={128,128,128,128,159,142,128,128};
lcd_send_byte(1,Pac_Dead2[i]);
}

lcd_gotoxy(6,1);
printf(lcd_putc,"%s",msgL2);

lcd_gotoxy(20,2); 
lcd_send_byte(1,1);
lcd_gotoxy(19,2); 
lcd_send_byte(1,0);

delay_ms(250);
lcd_send_byte(0,1);


lcd_send_byte(0,0x40);

delay_ms(1);

for (i=0;i<rows;i++)
{
int16 Pac_Dead3[rows]={128,128,128,128,128,142,128,128};
lcd_send_byte(1,Pac_Dead3[i]);
}

lcd_gotoxy(6,1);
printf(lcd_putc,"%s",msgL2);

lcd_gotoxy(20,2); 
lcd_send_byte(1,1);
lcd_gotoxy(19,2); 
lcd_send_byte(1,0); 
delay_ms(250);
lcd_send_byte(0,1);

lcd_send_byte(0,0x40);

delay_ms(1);

for (i=0;i<rows;i++)
{
int16 Pac_Dead4[rows]={128,128,128,128,128,128,128,128};
lcd_send_byte(1,Pac_Dead4[i]);
}


lcd_gotoxy(6,1);
printf(lcd_putc,"%s",msgL2);

lcd_gotoxy(20,2); 
lcd_send_byte(1,1);
lcd_gotoxy(19,2); 
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