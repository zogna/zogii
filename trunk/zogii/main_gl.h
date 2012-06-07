#ifndef __MAIN_GL__
#define __MAIN_GL__


#include <windows.h>		// Header File For Windows
#include <stdio.h>			// Header File For Standard Input/Output
#include <gl\gl.h>			// Header File For The OpenGL32 Library
#include <math.h>


void ReSizeGLScene(GLsizei width, GLsizei height);

void InitGL(void);
void DrawGLScene(void);

#endif