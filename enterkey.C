#include "oneline.h"

extern CTAG *head;
extern CTAG *now_cur;
extern char press_key;

char check_key_value(char press_key)
{
	char Low_Key;
	char High_Key;

	Low_Key = press_key;
	if( 0 == Low_Key )
	{
		High_Key = getch();
		press_key = High_Key;
	}
	else
	{
		press_key = Low_Key;
	}

	return press_key;
}

void input_character(char insert_key, int x)
{
	int Cnt = 1;
	CTAG *fallow;
	CTAG *current;
	CTAG *newnode;

	newnode = (CTAG *) malloc (sizeof(CTAG));
	
	if(NULL == head)
	{
		head = newnode;
		newnode->next = NULL;
		newnode->prev = NULL;
		newnode->character = insert_key;
		newnode->cNum = 1;
		now_cur = newnode;
		move_cursor(0, x, 4);
		print_character(x, 4, insert_key, 7);
	}
	else
	{
        fallow = now_cur;
        current = now_cur->next;
		Cnt++;

        if(current == NULL)
        {
            newnode->prev = fallow;
            fallow->next = newnode;
            now_cur = newnode;
			newnode->character = insert_key;
			newnode->cNum = Cnt;
			move_cursor(0, x, 4);
			print_character(x, 4, insert_key, 7);
		}
	}
	return ;
}


