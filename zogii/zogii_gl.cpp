#include "zogii_gl.h"
#include "zogii_ui.h"

unsigned int textureID[10];


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
	glClearColor(0.6f, 0.87451f, 0.58431f, 1.0f);				// Black Background
//	glClearDepth(1.0f);									// Depth Buffer Setup
//	glEnable(GL_DEPTH_TEST);							// Enables Depth Testing
//	glDepthFunc(GL_LEQUAL);								// The Type Of Depth Testing To Do
//	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);	// Really Nice Perspective Calculations

	//glGenTextures(10, textureID);
	// glPixelStorei(GL_UNPACK_ALIGNMENT, 1);	

	zogiiui_loadfont();
}

void DrawGLScene(void)	
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	// Clear Screen And Depth Buffer
	glLoadIdentity();		

	zogiiui_printftest();
}

