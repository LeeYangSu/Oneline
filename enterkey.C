#include "oneline.h"

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
