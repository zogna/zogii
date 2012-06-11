#ifndef __ZOGII_UI__
#define __ZOGII_UI__

#include <windows.h>		// Header File For Windows
#include <stdio.h>			// Header File For Standard Input/Output
#include "zogftes.h"

#define MENUNAME_LEN 30

//菜单
struct MENUNAME_FONT
{
	wchar_t eng[MENUNAME_LEN];
	wchar_t chs[MENUNAME_LEN];
	wchar_t cht[MENUNAME_LEN];


	int startx;
	int starty;
	int w;
	int h;
	int select;//当此为1=选中 0=没选中
};

struct MENUNAME_PIC
{
	int startx;
	int starty;
	int w;
	int h;
	unsigned int picID;
	int select;//当此为1=选中 0=没选中
};

void zogiiui_loadfont(void);
void zogiiui_printftest(void);
void zogiiui_clear(void);

void zogiiui_main(void);
void SelectBar(void);
void MenuListA(void);
void MenuListB(void);

#endif