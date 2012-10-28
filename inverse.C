#include "oneline.h"

extern char press_key;

void VGA_inverse_attrib(unsigned char far *attrib)
{
	unsigned char origin_attrib;

	origin_attrib = *attrib;
	*attrib >>= 4;
	*attrib = *attrib & 0x0F;
	origin_attrib <<= 4;
	*attrib = *attrib | origin_attrib;

	return ;
}

void VGA_inverse_bar(int x, int y, int length)
{
	int icnt = 0;
	unsigned char far *attr_memory = (unsigned char far *)0xb8000001L;

	attr_memory = attr_memory + y * 160 + x * 2;
	for(icnt = 0; icnt < length; ++icnt)
	{
		VGA_inverse_attrib(attr_memory);
		attr_memory = attr_memory + 2;
	}

	return ;
}

void move_inverse(void)
{
	char insert_key;
	char key;
	int x = 5;

	cursor_off();
	VGA_inverse_bar(x, 1, 7);
	while(1)
	{
		press_key = getch();
		insert_key = check_key_value(press_key);
		
		switch(insert_key)
		{
		case RIGHT:
			if(x < 53)
			{
				x = x + 12;
				VGA_inverse_bar(x, 1, 7);
				VGA_inverse_bar(x - 12, 1, 7);
			}
			break;
		case LEFT:
			if(x > 5)
			{
				x = x - 12;
				VGA_inverse_bar(x, 1, 7);
				VGA_inverse_bar(x + 12, 1, 7);
			}
			break;
		case ENTER:
			if(x == 5)
			{
				VGA_inverse_bar(5, 1, 7);
				new_function();
			}
			break;
		case ALTX:
			return ;
		case ESC:
			return ;
		default :
			break;
		}
	}
}

