#include "oneline.h"

extern char press_key;
extern xy_point location;

void new_function(void)
{
	char insert_key;
	location.x = 1;

	cursor_on();
	move_cursor( 0, 2, 4);

	while(1)
	{
		press_key = getch();
		insert_key = check_key_value(press_key);

		if(F10 == insert_key)
		{
			move_inverse();
			break;
		}
		else if(F1 == insert_key)
		{
			print_string(9, 9, "Help", 7);
			break;
		}
		else if(ALTL == insert_key)
		{
			print_string(9, 9, "Load", 7);
			break;
		}
		else if(ALTS == insert_key)
		{
			print_string(9, 9, "Save", 7);
			test_save_link();
			break;
		}
		else if(ALTA == insert_key)
		{
			print_string(9, 9, "Save as", 7);
			break;
		}
		else if(ALTX == insert_key)
		{
			return ;
		}
		else if((96 < insert_key) && (123 > insert_key))
		{
			++location.x;
			input_character(insert_key, location.x);
		}
	}
}
