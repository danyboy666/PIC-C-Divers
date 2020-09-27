#define BUFFER_SIZE 32 
BYTE buffer[BUFFER_SIZE]; 
BYTE next_in = 0; 
BYTE next_out = 0; 


// The RTCC preload value calculated below will 
// will give an RTCC interrupt rate of 100 Hz. 
// This is intended for an oscillator of 4 to 20 MHz. 

#define FOSC getenv("CLOCK") 

#if(FOSC < 26000000) 
  #define RTCC_PRELOAD (256 - (FOSC/4/256/100)) 
#else 
  #error Oscillator frequency is too high:  FOSC 
#endif 

// Setup Timer0 to provide a 10ms tick for the keypad driver. 
void kbd_buffer_init(void) 
{ 
setup_timer_0(RTCC_INTERNAL | RTCC_DIV_256 | RTCC_8_BIT); 
set_rtcc(RTCC_PRELOAD); 
enable_interrupts(INT_RTCC); 
enable_interrupts(GLOBAL); 
} 


//------------------------------ 
// The keypad is polled every 10ms in this interrupt 
// routine. 
#int_rtcc 
void rtcc_isr(void) 
{ 
int t; 
int k; 

set_rtcc(RTCC_PRELOAD); // Reload Timer0 for 10ms rate 

k = kbd_getc();  // Check the keypad for a keypress 

// If we got a keypress, put it in the circular 
// buffer. 
if(k != 0)  
  { 
   buffer[next_in] = k; 
   t=next_in; 
   next_in=(next_in+1) % BUFFER_SIZE; 
   if(next_in==next_out) 
      next_in=t; 
  } 

} 

#define bkbhit (next_in!=next_out) 

//------------------------------ 
int8 bgetc(void) 
{ 
int8 c; 

while(!bkbhit); 
c=buffer[next_out]; 
next_out=(next_out+1) % BUFFER_SIZE; 
return(c); 
} 

//------------------------------ 
// This version of get_string() works with a keypad 
// and LCD.  The max_str_size parameter is the max 
// length of the actual text the user is allowed to 
// enter.   Your array that holds the text must be 
// at least 1 char larger than this, to allow for 
// the terminator null byte (0x00) at the end of a 
// string. 

#define KEYPAD_ENTER '#' 
#define KEYPAD_BS    '*' 

void kbd_get_string(int8 *str, int8 max_str_size) 
{ 
int8 len; 
int8 c; 

if(max_str_size == 0) 
  { 
   *str = 0; 
   return; 
  } 

len=0; 

while(1) 
  { 
   c=bgetc(); 

   if(c == KEYPAD_BS) // Was the backspace key pressed ? 
     {  
      if(len>0)   // If yes, then do we have any existing text ? 
        { 
         len--;    
         //lcd_putc('\b'); 
         //lcd_putc(' '); 
         //lcd_putc('\b'); 
        } 
     } 
   else if(c == KEYPAD_ENTER) 
     { 
      break; 
     } 
   else 
     { 
      if(len < max_str_size) 
        { 
         str[len++]=c; 
         
         printf("%c%c",0xfe,0xd0);
         printf(":%c",c);
         
         //lcd_putc(c); 
        } 
     } 
   } 

str[len]=0; 
}
