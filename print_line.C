#include "oneline.h"

void print_character(int x ,int y ,char ch ,char attr)
{
	char far *location;

	location    = RAMaddr + y * 160 + x * 2;
	*location++ = ch;
	*location   = attr;

	return ;
}

void print_string(int x, int y, char *string, char attr)
{
	int icnt;
	char buff[255];

	strcpy(buff, string);
	for(icnt = 0; icnt < strlen(string); ++icnt)
	{
		print_character(x + icnt, y, buff[icnt], attr);
	}

	return ;
}

void Draw_Width_Line(int x, int y, char ch, char attr, int length)
{
	int icnt;

	for(icnt = 0; icnt < length; ++icnt)
	{
		print_character(x + icnt ,y ,ch ,attr);
	}

	return ;
}

void Draw_Height_Line(int x, int y, char ch, char attr, int length)
{
	int icnt;

	for(icnt = 0; icnt < length; ++icnt)
	{
		print_character(x ,y + icnt ,ch ,attr);
	}

	return ;
}

void Outside_Box(void)
{
	Draw_Width_Line(0, 0, Width_Line, 7, X_MAX);
	Draw_Width_Line(0, Y_MAX, Width_Line, 7, X_MAX);
	Draw_Height_Line(0, 0, Height_Line, 7, Y_MAX);
	Draw_Height_Line(X_MAX - 1, 0, Height_Line, 7, Y_MAX);

	print_character(0 ,0 ,Left_Top ,7);
	print_character(X_MAX - 1 ,0 ,Right_Top ,7);
	print_character(0 ,Y_MAX ,Left_Bottom ,7);
	print_character(X_MAX - 1 ,Y_MAX ,Right_Bottom ,7);

	print_string(7, 1, "New        Load        Save       Save As      Exit  ", 7);
	Draw_Width_Line(0, 2, Width_Line, 7, X_MAX);
	print_character(0 ,2 ,Left_Link ,7);
	print_character(X_MAX - 1 ,2 ,Rigth_Link ,7);

	Draw_Width_Line(0, 6, Width_Line, 7, X_MAX);
	print_character(0 ,6 ,Left_Link ,7);
	print_character(X_MAX - 1 ,6 ,Rigth_Link ,7);

	print_string(7, 23, "       F10 - Menu       Alt + X = Exit       F1 - Help", 7);
	Draw_Width_Line(0, 22, Width_Line, 7, X_MAX);
	print_character(0 ,22 ,Left_Link ,7);
	print_character(X_MAX - 1 ,22 ,Rigth_Link ,7);

	return ;
}

void Inside_Box(void)
{
	Draw_Width_Line(1, 3, Width_Line, 7, X_MAX - 2);
	Draw_Width_Line(1, 5, Width_Line, 7, X_MAX - 2);
	Draw_Height_Line(1, 3, Height_Line, 7, 3);
	Draw_Height_Line(X_MAX - 2, 3, Height_Line, 7, 3);

	print_character(1 ,3 ,Left_Top ,7);
	print_character(X_MAX - 2 ,3 ,Right_Top ,7);
	print_character(1 ,5 ,Left_Bottom ,7);
	print_character(X_MAX - 2 ,5 ,Right_Bottom ,7);

	return ;
}




