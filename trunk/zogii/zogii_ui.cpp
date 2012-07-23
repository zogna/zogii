#include "zogii_ui.h"

extern unsigned short width_win ,height_win;
#define FONT_SIZE_BIG 20
#define FONT_SIZE_SMALL 10

enum LANGUAGE_LIST
{
	L_ENGLISH=0,
	L_CHINASIMPLE=1,
	L_CHINATRADITION=2,
};

//���� 0=Ӣ�� 1=���� 2=����
int Language=L_ENGLISH;

void zogiiui_loadfont(void)
{

	if(zogftes_init(".\\MSYH.TTF")<0)
	{
		fprintf(stderr,"no load font");	
		exit(1);
	}
	zogftes_preload_font(FONT_SIZE_BIG,FONT_SIZE_SMALL);

	//zogftes_preload_font_lite(FONT_SIZE);

}

void zogiiui_printftest(void)
{
	glColor4f(1,0,0,1);
zogftes_print(500,500,L"0123456789",10,16);

}

void zogiiui_clear(void)
{
	zogftes_clean();
}


void zogiiui_main(void)
{

	SelectBar();
	MenuListA();
}

#define SelectBarColor  13,184,211
#define SelectBarLine1W 170.0f

void SelectBar(void)
{
    float SelectBarLine[] =
    {
        SelectBarLine1W, (float)0,
        SelectBarLine1W, (float)height_win,
    };

    glColor3ub(SelectBarColor);

    glLineWidth(2);

    glEnableClientState(GL_VERTEX_ARRAY);

    glVertexPointer(2, GL_FLOAT, 0, SelectBarLine);
    glDrawArrays(GL_LINES, 0, 2);

    glDisableClientState(GL_VERTEX_ARRAY);

    glLineWidth(1);
}

#define MENULIST_BOXX 12
#define MENULIST_BOXW 155
#define MENULIST_BOXH 20

//�����һ���˵�����
int menulistA_num=11;

struct MENUNAME_FONT menulistA_info[50]=
{
	{L"Classification tree", L"������", L"���", MENULIST_BOXX, 50, MENULIST_BOXW, MENULIST_BOXH, 1},

	{L"Eggs ", L"����", L"�x��", MENULIST_BOXX, 70, MENULIST_BOXW, MENULIST_BOXH, 0},

	{L"Larvae ", L"�׳�", L"���x", MENULIST_BOXX, 90, MENULIST_BOXW, MENULIST_BOXH, 0},
	{L"Pupa ", L"Ӽ<��>", L"Ӽ<�O>", MENULIST_BOXX, 110, MENULIST_BOXW, MENULIST_BOXH, 1},
	{L"Adults abdomen ", L"�ɳ渹��", L"���x����", MENULIST_BOXX, 130, MENULIST_BOXW, MENULIST_BOXH, 0},
	{L"Adults back ", L"�ɳ汳��", L"���x����", MENULIST_BOXX, 150, MENULIST_BOXW, MENULIST_BOXH, 0},

	{L"Professional Mode",L"ר��ģʽ",L"����ģʽ",MENULIST_BOXX,170,MENULIST_BOXW,MENULIST_BOXH,1},

	{L"ENGLISH",L"ENGLISH",L"ENGLISH",MENULIST_BOXX,590,MENULIST_BOXW,MENULIST_BOXH,0},
	{L"��������",L"��������",L"��������",MENULIST_BOXX,610,MENULIST_BOXW,MENULIST_BOXH,1},
	{L"���w����",L"���w����",L"���w����",MENULIST_BOXX,630,MENULIST_BOXW,MENULIST_BOXH,0},

	{L"Sources of Info",L"��Ϣ��Դ",L"��Ϣ��Դ",MENULIST_BOXX,680,MENULIST_BOXW,MENULIST_BOXH,1},

};

#define MenuListColor  117,36,121

void MenuListA(void)
{
    int i;
    glColor3ub(MenuListColor);

    //����
    for(i = 0; i < menulistA_num; i++)
    {
        if(L_ENGLISH == Language)
            zogftes_print((float)menulistA_info[i].startx, (float)menulistA_info[i].starty,
                          menulistA_info[i].eng, wcslen(menulistA_info[i].eng), FONT_SIZE_SMALL);
        else if(L_CHINASIMPLE == Language)
            zogftes_print((float)menulistA_info[i].startx, (float)menulistA_info[i].starty,
                          menulistA_info[i].chs, wcslen(menulistA_info[i].chs), FONT_SIZE_SMALL);
        else if(L_CHINATRADITION == Language)
            zogftes_print((float)menulistA_info[i].startx, (float)menulistA_info[i].starty,
                          menulistA_info[i].cht, wcslen(menulistA_info[i].cht), FONT_SIZE_SMALL);
    }

    float sx, sy, ex, ey;

    //����
    for(i = 0; i < menulistA_num; i++)
    {
        if(menulistA_info[i].select)
        {
            sx =(float) menulistA_info[i].startx - 5;
            sy = (float)menulistA_info[i].starty + 5;
            ex = sx + menulistA_info[i].w;
            ey = sy - menulistA_info[i].h;

            float SelectBox[] =
            {
                sx, sy,
                ex, sy,
                ex, ey,
                sx, ey
            };

            float SelectLine[] =
            {
                ex, sy -(float)( menulistA_info[i].h / 2.0),
                SelectBarLine1W, sy - (float)(menulistA_info[i].h / 2.0),
            };

            glColor3ub(SelectBarColor);

            glLineWidth(2);
            glEnableClientState(GL_VERTEX_ARRAY);

            glVertexPointer(2, GL_FLOAT, 0, SelectBox);
            glDrawArrays(GL_LINE_LOOP, 0, 4);

            glVertexPointer(2, GL_FLOAT, 0, SelectLine);
            glDrawArrays(GL_LINES, 0, 2);

            glDisableClientState(GL_VERTEX_ARRAY);

            glLineWidth(1);
        }
    }
}
