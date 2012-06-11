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

//语言 0=英文 1=简中 2=繁中
int Language=L_CHINATRADITION;

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
	MenuListB();
}

#define SelectBarColor  13,184,211
#define SelectBarLine1W 190.0f
#define SelectBarLine2W 380.0f

void SelectBar(void)
{
    float SelectBarLine[] =
    {
        SelectBarLine1W, (float)0,
        SelectBarLine1W, (float)height_win,
        SelectBarLine2W, (float)0,
        SelectBarLine2W, (float)height_win,
        70, 500.0,
        SelectBarLine2W - 70, 500.0,
    };

    glColor3ub(SelectBarColor);

    glLineWidth(2);

    glEnableClientState(GL_VERTEX_ARRAY);

    glVertexPointer(2, GL_FLOAT, 0, SelectBarLine);
    glDrawArrays(GL_LINES, 0, 6);

    glDisableClientState(GL_VERTEX_ARRAY);

    glLineWidth(1);
}

#define MENULIST_BOXX 12
#define MENULIST_BOXW 170
#define MENULIST_BOXH 20

//不变的一级菜单数量
int menulistA_num=9;

struct MENUNAME_FONT menulistA_info[50]=
{
	{L"Lepidoptera<Butterfly>",L"鳞翅目<蝶>",L"鱗翅目<蝶>",MENULIST_BOXX,50,MENULIST_BOXW,MENULIST_BOXH,0},
	{L"Lepidoptera<Moth>",L"鳞翅目<蛾>",L"鱗翅目<蛾>",MENULIST_BOXX,70,MENULIST_BOXW,MENULIST_BOXH,0},
	{L"Araneida",L"蜘蛛目",L"蜘蛛目",MENULIST_BOXX,90,MENULIST_BOXW,MENULIST_BOXH,1},

	{L"Normal Mode",L"普通模式",L"普通模式",MENULIST_BOXX,530,MENULIST_BOXW,MENULIST_BOXH,0},
	{L"Professional Mode",L"专家模式",L"專家模式",MENULIST_BOXX,550,MENULIST_BOXW,MENULIST_BOXH,1},

	{L"ENGLISH",L"ENGLISH",L"ENGLISH",MENULIST_BOXX,590,MENULIST_BOXW,MENULIST_BOXH,0},
	{L"简体中文",L"简体中文",L"简体中文",MENULIST_BOXX,610,MENULIST_BOXW,MENULIST_BOXH,1},
	{L"繁體中文",L"繁體中文",L"繁體中文",MENULIST_BOXX,630,MENULIST_BOXW,MENULIST_BOXH,0},

	{L"Sources of Info",L"信息来源",L"信息來源",MENULIST_BOXX,680,MENULIST_BOXW,MENULIST_BOXH,1},

};

#define MenuListColor  117,36,121

void MenuListA(void)
{
    int i;
    glColor3ub(MenuListColor);

    //画字
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

    //画框
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

//一直变的二级菜单数量
int menulistB_num[10]=
{
	5,
	5,
	5,

};

#define MENULIST_B_BOXX (MENULIST_BOXX+(int)SelectBarLine1W)

struct MENUNAME_FONT menulistB_info[10][50] =
{
    {
        {L"Name of Query", L"名称查询", L"名稱查詢", MENULIST_B_BOXX, 530, MENULIST_BOXW, MENULIST_BOXH, 1},
        {L"Adults of Query", L"成虫查询", L"成蟲查詢", MENULIST_B_BOXX, 550, MENULIST_BOXW, MENULIST_BOXH, 0},
        {L"Larvae of Query", L"幼虫查询", L"幼蟲查詢", MENULIST_B_BOXX, 570, MENULIST_BOXW, MENULIST_BOXH, 0},
        {L"Pupa<Cocoon> of Query", L"蛹<茧>查询", L"蛹<繭>查詢", MENULIST_B_BOXX, 590, MENULIST_BOXW, MENULIST_BOXH, 1},
        {L"Eggs of Query", L"虫卵查询", L"蟲卵查詢", MENULIST_B_BOXX, 610, MENULIST_BOXW, MENULIST_BOXH, 0},
    },
    {
        {L"Name of Query", L"名称查询", L"名稱查詢", MENULIST_B_BOXX, 530, MENULIST_BOXW, MENULIST_BOXH, 1},
        {L"Adults of Query", L"成虫查询", L"成蟲查詢", MENULIST_B_BOXX, 550, MENULIST_BOXW, MENULIST_BOXH, 0},
        {L"Larvae of Query", L"幼虫查询", L"幼蟲查詢", MENULIST_B_BOXX, 570, MENULIST_BOXW, MENULIST_BOXH, 0},
        {L"Pupa<Cocoon> of Query", L"蛹<茧>查询", L"蛹<繭>查詢", MENULIST_B_BOXX, 590, MENULIST_BOXW, MENULIST_BOXH, 1},
        {L"Eggs of Query", L"虫卵查询", L"蟲卵查詢", MENULIST_B_BOXX, 610, MENULIST_BOXW, MENULIST_BOXH, 0},
    },
    {
        {L"Name of Query", L"名称查询", L"名稱查詢", MENULIST_B_BOXX, 530, MENULIST_BOXW, MENULIST_BOXH, 1},
        {L"Adults of Query", L"成虫查询", L"成蟲查詢", MENULIST_B_BOXX, 550, MENULIST_BOXW, MENULIST_BOXH, 0},
        {L"Larvae of Query", L"幼虫查询", L"幼蟲查詢", MENULIST_B_BOXX, 570, MENULIST_BOXW, MENULIST_BOXH, 0},
        {L"Eye of Query", L"眼式查询", L"眼式查詢", MENULIST_B_BOXX, 590, MENULIST_BOXW, MENULIST_BOXH, 0},
        {L"Cobweb of Query", L"蜘蛛网查询", L"蜘蛛網查詢", MENULIST_B_BOXX, 610, MENULIST_BOXW, MENULIST_BOXH, 0},
    }

};

void MenuListB(void)
{
    int i,j;
    glColor3ub(MenuListColor);

	for(i = 0; i < menulistA_num; i++)
	 if(menulistA_info[i].select)
		 break;

    //画字
    for(j = 0; j < menulistB_num[i]; j++)
    {
        if(L_ENGLISH == Language)
            zogftes_print((float)menulistB_info[i][j].startx, (float)menulistB_info[i][j].starty,
                          menulistB_info[i][j].eng, wcslen(menulistB_info[i][j].eng), FONT_SIZE_SMALL);
        else if(L_CHINASIMPLE == Language)
            zogftes_print((float)menulistB_info[i][j].startx, (float)menulistB_info[i][j].starty,
                          menulistB_info[i][j].chs, wcslen(menulistB_info[i][j].chs), FONT_SIZE_SMALL);
        else if(L_CHINATRADITION == Language)
            zogftes_print((float)menulistB_info[i][j].startx, (float)menulistB_info[i][j].starty,
                          menulistB_info[i][j].cht, wcslen(menulistB_info[i][j].cht), FONT_SIZE_SMALL);
    }

    float sx, sy, ex, ey;

    //画框
    for(j = 0; j < menulistB_num[i]; j++)
    {
        if(menulistB_info[i][j].select)
        {
            sx =(float) menulistB_info[i][j].startx - 5;
            sy = (float)menulistB_info[i][j].starty + 5;
            ex = sx + menulistB_info[i][j].w;
            ey = sy - menulistB_info[i][j].h;

            float SelectBox[] =
            {
                sx, sy,
                ex, sy,
                ex, ey,
                sx, ey
            };

            float SelectLine[] =
            {
                ex, sy -(float)( menulistB_info[i][j].h / 2.0),
                SelectBarLine2W, sy - (float)(menulistB_info[i][j].h / 2.0),
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