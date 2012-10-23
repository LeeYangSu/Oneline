#ifndef	__ONELINE_H__
#define __ONELINE_H__

//----------Include--------------------------------------------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <dos.h>

//----------Paint Value----------------------------------------------------------------------------------------
#define		RAMaddr			((char far *)0xB8000000)
#define		X_MAX			80
#define		Y_MAX			24

#define		Width_Line		196
#define		Height_Line		179
#define		Right_Top		191
#define		Left_Top		218
#define		Right_Bottom	217
#define		Left_Bottom		192
#define		Rigth_Link		180
#define		Left_Link		195

//----------Move Key-------------------------------------------------------------------------------------------
#define		DOWN			80
#define		UP				72
#define		LEFT			75	
#define		RIGHT			77

//----------Key Value------------------------------------------------------------------------------------------

//----------2Byte Key Value------------------------------------------------------------------------------------
#define		ESC				27
#define		F10				68
#define		ENTER			13
#define		ALTX			45
#define		ALTN			49
#define		ALTL			38
#define		ALTS			31
#define		ALTA			30
#define		ALTE			18
#define		F1				59
#define		BACKSPACE		8
#define		INSERT			82
#define		DELETE			83
#define		HOME			71
#define		END				79

typedef struct move_xy
{
	int x;
	int y;
}xy_point;

static char press_key;

//----------Print function--------------------------------------------------------------------------------------
void print_character(int ,int ,char ,char );
void print_string(int ,int ,char *,char );
void Draw_Width_Line(int , int , char , char , int );
void Draw_Height_Line(int , int , char , char , int );
void Outside_Box(void);
void Inside_Box(void);

//----------Inverse function------------------------------------------------------------------------------------
void VGA_inverse_attrib(unsigned char far *);
void VGA_inverse_bar(int , int , int );
void move_inverse(void);

//----------Cursor function-------------------------------------------------------------------------------------
void move_cursor(int ,int ,int );
void cursor_off(void);
void cursor_on(void);

//----------Key function-------------------------------------------------------------------------------------
char check_key_value(char );

#endif	//__ONELINE_H__