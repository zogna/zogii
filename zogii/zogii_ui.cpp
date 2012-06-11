#include "zogii_ui.h"

void zogiiui_loadfont(void)
{
	TCHAR path[MAX_PATH];
	char fullPath[MAX_PATH];

	GetModuleFileName(NULL, path, MAX_PATH);

	TCHAR *pos = wcsrchr(path, '\\');
	*(pos + 1) = '\0';
	
	wcstombs(fullPath, path, MAX_PATH);
	strcat(fullPath, "MSYH.TTF");

	if(zogftes_init(fullPath)<0)
	{
		fprintf(stderr,"no load font");	
		exit(1);
	}
	//zogftes_preload_font(32,16);

	zogftes_preload_font_lite(32);

}

void zogiiui_printftest(void)
{
	glColor4f(1,0,0,1);
zogftes_print(500,500,L"0123456789",10,32);

}

void zogiiui_clear(void)
{
	zogftes_clean();
}