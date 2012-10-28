#include "oneline.h"

CTAG *head;
CTAG *current;
char press_key;

int main()
{
	char insert_key;

	clrscr();
	Outside_Box();
	Inside_Box();
	cursor_off();

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
			return 0;
		}
	}
}

void init_head(void)
{
	head = (CTAG *) malloc (sizeof(CTAG));
	head = NULL;
	head->prev = NULL;
	head->next = NULL;
	current = head;

	return ;
}
