#include "oneline.h"

extern char press_key;

void new_function(void)
{
	char insert_key;

	cursor_on();
	move_cursor( 0, 2, 4);

	while(1)
	{
		press_key = getch();
		insert_key = check_key_value(press_key);	
		switch(insert_key)
		{
		case F10:
			move_inverse();
			break;
		case F1:
			print_string(9, 9, "Help", 7);
			break;
		case ALTL:
			print_string(9, 9, "Load", 7);
			break;
		case ALTS:
			print_string(9, 9, "Save", 7);
			break;
		case ALTA:
			print_string(9, 9, "Save as", 7);
			break;
		case ALTX:
			move_inverse();
			return ;
		}
	}
}
