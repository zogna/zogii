#include "zogii_gl.h"
#include "zogii_ui.h"
#include "zogii_jpg.h"

extern HWND		hWnd ;

#define ClearColor	0.6627f,0.89019f,0.643137f,1.0f

int winOpenFileJPG(wchar_t *buf, int len)
{
	OPENFILENAME ofn;
	buf[0] = 0;
	memset(&ofn, 0, sizeof(OPENFILENAME));
	ofn.lStructSize = sizeof(OPENFILENAME);
	ofn.hwndOwner = hWnd;
	ofn.lpstrFile = buf;
	ofn.nMaxFile = len;
	ofn.lpstrInitialDir = NULL;
	ofn.lpstrTitle = L"zogii: Open JPEG file";
	ofn.lpstrFilter = L"JPEG Files (*.jpg)\0*.jpg\0All Files\0*\0\0";
	ofn.Flags = OFN_FILEMUSTEXIST|OFN_HIDEREADONLY;
	return GetOpenFileName(&ofn);
}

int winOpenFileTXT(wchar_t *buf, int len)
{
	OPENFILENAME ofn;
	buf[0] = 0;
	memset(&ofn, 0, sizeof(OPENFILENAME));
	ofn.lStructSize = sizeof(OPENFILENAME);
	ofn.hwndOwner = hWnd;
	ofn.lpstrFile = buf;
	ofn.nMaxFile = len;
	ofn.lpstrInitialDir = NULL;
	ofn.lpstrTitle = L"zogii: Open TXT file";
	ofn.lpstrFilter = L"TXT Files (*.txt)\0*.txt\0All Files\0*\0\0";
	ofn.Flags = OFN_FILEMUSTEXIST|OFN_HIDEREADONLY;
	return GetOpenFileName(&ofn);
}

void ReSizeGLScene(GLsizei width, GLsizei height)		// Resize And Initialize The GL Window
{
	if (height==0)										// Prevent A Divide By Zero By
	{
		height=1;										// Making Height Equal One
	}

	glViewport(0,0,width,height);						// Reset The Current Viewport

	glMatrixMode(GL_PROJECTION);						// Select The Projection Matrix
	glLoadIdentity();									// Reset The Projection Matrix

	// Calculate The Aspect Ratio Of The Window
	glOrtho(0,width, height,0,-1,1 );

	glMatrixMode(GL_MODELVIEW);							// Select The Modelview Matrix
	glLoadIdentity();									// Reset The Modelview Matrix
}

void InitGL(void)										// All Setup For OpenGL Goes Here
{
//	glShadeModel(GL_SMOOTH);							// Enable Smooth Shading
	glShadeModel(GL_FLAT);
	glClearColor(ClearColor);				// Black Background

	glDisable(GL_DEPTH_TEST);

	//glGenTextures(10, textureID);
	// glPixelStorei(GL_UNPACK_ALIGNMENT, 1);	

	zogiiui_loadfont();
	zogiijpg_initJPG();

	wchar_t path[260];

	if(winOpenFileJPG(path,260))
		zogiijpg_load2texJPG(64,64,path,0);
}

void DrawGLScene(void)	
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	// Clear Screen And Depth Buffer
	glLoadIdentity();		



zogiiui_main();

//zogiiui_printftest();
//zogiijpg_drawJPG(50,50,64,64,0);
}

void clearGL(void)
{
zogiiui_clear();
zogiijpg_clearJPG();
}
