#define clear_lcd         0x01 // Clear Display
#define return_home       0x02 // Cursor to Home position
#define entry_mode        	 0x06 // Normal entry mode
#define entry_mode_rev    	 0x04 // Normal entry mode  -reverse direction
#define entry_mode_scroll 0x07 // - with shift
#define entry_mode_scroll_rev	0x05 // reverse direction
 
#define system_set_8_bit  	 0x38 // 8 bit data mode 2 line ( 5x7 font )
#define system_set_4_bit  	 0x28 // 4 bit data mode 2 line ( 5x7 font )
#define system_set_reset  	 0x30 // Reset code
#define display_on        	 0x0C // Display ON - 2 line mode
#define display_off       0x08 // Display off
#define set_dd_line1      	 0x80 // Line 1 position 1
#define set_dd_line2      	 0xC0 // Line 2 position 1
#define set_dd_ram        	 0x80 // Line 1 position 1
#define write_data        	 0x00 // With RS = 1
#define cursor_on         0x0E // Switch Cursor ON
#define cursor_off        	 0x0C // Switch Cursor OFF
#define cursor_blink_on   0x0F // Cursor plus blink
#define cursor_shift_right	 0x14 // Move cursor right
#define cursor_shift_left 0x10 // Move cursor left
#define display_shift_right	 0x1C // Scroll display right
#define display_shift_left	 0x18 // Scroll display left