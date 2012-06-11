#ifndef __ZOGII_JPG__
#define __ZOGII_JPG__


#include <windows.h>
#include <stdio.h>
#include <setjmp.h>

#include <jpeg/jpeglib.h>
#include <jpeg/jerror.h>
#include <gl\gl.h>			// Header File For The OpenGL32 Library


void zogaes_setimage_size(unsigned  int w,unsigned int h);
int zogaes_getimage_scale(unsigned int w,unsigned int h);

METHODDEF(void)	my_error_exit (j_common_ptr cinfo);

GLubyte * zoga_loadJPEG(wchar_t *filename,GLuint *iWidth, GLuint *iHeight);
GLubyte *zoga_jpg_conv_image(struct jpeg_decompress_struct *cinfo,GLint num_components,GLuint src_w,GLuint src_h,int scale_denom);
void zoga_freeImage(GLubyte *image);

void zogiijpg_initJPG(void);
void zogii_convWH(int srcw,int srch,unsigned char *srcdata,
				  int dstw,int dsth,unsigned char *dstdata);
void zogiijpg_load2texJPG( int w, int h, wchar_t *fullPath, unsigned int ID);
void zogiijpg_drawJPG(int startx, int starty, int w, int h, unsigned int ID);
void zogiijpg_clearJPG(void);

#endif