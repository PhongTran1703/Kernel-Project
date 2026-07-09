#include "source.h"
#include "keyboard.h"

void main (void)
{
	terminal_buffer = (unsigned short*) VGA_ADDRESS;
		vga_index = 0;

		clear_screen();
		print_string("hello", YELLOW);
		vga_index = 80;
		print_string("first version", RED);
		vga_index = 160;
		print_char('b', GREEN);
		vga_index = 240;
		while (1) {
		
			keyboard_handler();
		}
	return;	

}
