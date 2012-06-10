#ifndef FTES_ZOG_H
#define FTES_ZOG_H

//FreeType Headers
#include <ft2build.h>
#include <freetype/freetype.h>
#include <freetype/ftglyph.h>
#include <freetype/ftoutln.h>
#include <freetype/fttrigon.h>

//OpenGL Headers 
#include <windows.h>		//(the GL headers need it)
#include <GLES/gl.h>

//Ԥ�����ַ�
struct zogftes_font_data 
{
	//�ַ����
	unsigned long int charcode;	
	//�ַ���С
	int fontsize;
	//�ƶ����
	int advancex;
	int advancey;
	//texCoords����
	float texx;
	float texy;
	//box����
	float boxw;
	float boxh;
	//��ƫ��
	float left;
	float top;
};

void zogftes_pop_projection_matrix(void);
void zogftes_pushScreenCoordinateMatrix(void);

int zogftes_next_p2(int a);
int zogftes_init(const char * fname);
void zogftes_preload_font(int fontsizeA,int fontsizeB);
void zogftes_preload_font_lite(int fontsize);
void zogftes_clean();

void zogftes_load_single(FT_Face face, unsigned long int charcode,int fontsize);
void zogftes_draw_single(int texid);
void zogftes_spec_single(FT_Face face, unsigned long int charcode);

void zogftes_print(float x, float y,  wchar_t  *fmt,int fmtsize,int fontsize);
void zogftes_print_lite(float x, float y,  wchar_t  *fmt,int fmtsize,int fontsize);



#endif