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
#define SelectBarLine1W 170.0f
#define SelectBarLine2W 305.0f

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
#define MENULIST_BOXW 155
#define MENULIST_BOXH 20

//�����һ���˵�����
int menulistA_num=9;

struct MENUNAME_FONT menulistA_info[50]=
{
	{L"Lepidoptera<Butterfly>",L"�۳�Ŀ<��>",L"�[��Ŀ<��>",MENULIST_BOXX,50,MENULIST_BOXW,MENULIST_BOXH,0},
	{L"Lepidoptera<Moth>",L"�۳�Ŀ<��>",L"�[��Ŀ<��>",MENULIST_BOXX,70,MENULIST_BOXW,MENULIST_BOXH,0},
	{L"Araneida",L"֩��Ŀ",L"֩��Ŀ",MENULIST_BOXX,90,MENULIST_BOXW,MENULIST_BOXH,1},

	{L"Normal Mode",L"��ͨģʽ",L"��ͨģʽ",MENULIST_BOXX,530,MENULIST_BOXW,MENULIST_BOXH,0},
	{L"Professional Mode",L"ר��ģʽ",L"����ģʽ",MENULIST_BOXX,550,MENULIST_BOXW,MENULIST_BOXH,1},

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

//һֱ��Ķ����˵�����
int menulistB_num[10]=
{
	15,
	24,
	21,

};

#define MENULIST_B_BOXX (MENULIST_BOXX+(int)SelectBarLine1W)
#define MENULIST_B_BOXW 120

//�� ����50���ܱ��Ǽ��ڴ�
struct MENUNAME_FONT menulistB_info[10][50] =
{
    {
        {L"All", L"ȫ��", L"ȫ��", MENULIST_B_BOXX, 50, MENULIST_B_BOXW, MENULIST_BOXH, 1},

        {L"Amathusiidae", L"���Ƶ���", L"�h�y����", MENULIST_B_BOXX, 70, MENULIST_B_BOXW, MENULIST_BOXH, 1},
        {L"Danainae", L"�ߵ���", L"�ߵ���", MENULIST_B_BOXX, 90, MENULIST_B_BOXW, MENULIST_BOXH, 1},
        {L"Hesperiidae", L"Ū����", L"Ū����", MENULIST_B_BOXX, 110, MENULIST_B_BOXW, MENULIST_BOXH, 1},
        {L"Lycaenidae", L"С�ҵ���", L"С�ҵ���", MENULIST_B_BOXX, 130, MENULIST_B_BOXW, MENULIST_BOXH, 1},
        {L"Nymphalidae", L"͐����", L"͐����", MENULIST_B_BOXX, 150, MENULIST_B_BOXW, MENULIST_BOXH, 1},
        {L"Papilionidae", L"�����", L"�P����", MENULIST_B_BOXX, 170, MENULIST_B_BOXW, MENULIST_BOXH, 1},
        {L"Pieridae", L"�۵���", L"�۵���", MENULIST_B_BOXX, 190, MENULIST_B_BOXW, MENULIST_BOXH, 1},
        {L"Satyridae", L"��Ŀ����", L"��Ŀ����", MENULIST_B_BOXX, 210, MENULIST_B_BOXW, MENULIST_BOXH, 1},

        {L"Other", L"����", L"����", MENULIST_B_BOXX, 490, MENULIST_B_BOXW, MENULIST_BOXH, 1},

        {L"Name of Query", L"���Ʋ�ѯ", L"���Q��ԃ", MENULIST_B_BOXX, 530, MENULIST_B_BOXW, MENULIST_BOXH, 1},
        {L"Adults of Query", L"�ɳ��ѯ", L"���x��ԃ", MENULIST_B_BOXX, 550, MENULIST_B_BOXW, MENULIST_BOXH, 0},
        {L"Larvae of Query", L"�׳��ѯ", L"���x��ԃ", MENULIST_B_BOXX, 570, MENULIST_B_BOXW, MENULIST_BOXH, 0},
        {L"Pupa of Query", L"Ӽ<��>��ѯ", L"Ӽ<�O>��ԃ", MENULIST_B_BOXX, 590, MENULIST_B_BOXW, MENULIST_BOXH, 1},
        {L"Eggs of Query", L"���Ѳ�ѯ", L"�x�Ѳ�ԃ", MENULIST_B_BOXX, 610, MENULIST_B_BOXW, MENULIST_BOXH, 0},
    },
    {
        {L"All", L"ȫ��", L"ȫ��", MENULIST_B_BOXX, 50, MENULIST_B_BOXW, MENULIST_BOXH, 1},

        {L"Arctiidae", L"�ƶ��", L"�����", MENULIST_B_BOXX, 70, MENULIST_B_BOXW, MENULIST_BOXH, 1},
        {L"Crambidae", L"������", L"������", MENULIST_B_BOXX, 90, MENULIST_B_BOXW, MENULIST_BOXH, 1},
        {L"Drepanidae", L"�����", L"�^���", MENULIST_B_BOXX, 110, MENULIST_B_BOXW, MENULIST_BOXH, 1},
        {L"Erebidae", L"��ҹ���", L"��ҹ���", MENULIST_B_BOXX, 130, MENULIST_B_BOXW, MENULIST_BOXH, 1},
        {L"Gelechiidae", L"�����<����>", L"�����<�����>", MENULIST_B_BOXX, 150, MENULIST_B_BOXW, MENULIST_BOXH, 1},
        {L"Geometridae", L"�߶��", L"�߶��", MENULIST_B_BOXX, 170, MENULIST_B_BOXW, MENULIST_BOXH, 1},
        {L"Lecithoceridae", L"�۽Ƕ��", L"�۽Ƕ��", MENULIST_B_BOXX, 190, MENULIST_B_BOXW, MENULIST_BOXH, 1},
        {L"Limacodidae", L"�̶��", L"�̶��", MENULIST_B_BOXX, 210, MENULIST_B_BOXW, MENULIST_BOXH, 1},
        {L"Lymantriidae", L"�����", L"�����", MENULIST_B_BOXX, 230, MENULIST_B_BOXW, MENULIST_BOXH, 1},
        {L"Noctuidae", L"ҹ���", L"ҹ���", MENULIST_B_BOXX, 250, MENULIST_B_BOXW, MENULIST_BOXH, 1},
        {L"Nolidae", L"�����", L"�����", MENULIST_B_BOXX, 270, MENULIST_B_BOXW, MENULIST_BOXH, 1},
        {L"Notodontidae", L"�۶��", L"�۶��", MENULIST_B_BOXX, 290, MENULIST_B_BOXW, MENULIST_BOXH, 1},
        {L"Oecophoridae", L"֯���", L"�����", MENULIST_B_BOXX, 310, MENULIST_B_BOXW, MENULIST_BOXH, 1},
        {L"Pyralidae", L"�����", L"�����", MENULIST_B_BOXX, 330, MENULIST_B_BOXW, MENULIST_BOXH, 1},
        {L"Sphingidae", L"����", L"����", MENULIST_B_BOXX, 350, MENULIST_B_BOXW, MENULIST_BOXH, 1},
        {L"Tortricidae", L"����", L"�Զ��", MENULIST_B_BOXX, 370, MENULIST_B_BOXW, MENULIST_BOXH, 1},
        {L"Zygaenidae", L"�߶��", L"�߶��", MENULIST_B_BOXX, 390, MENULIST_B_BOXW, MENULIST_BOXH, 1},

        {L"Other", L"����", L"����", MENULIST_B_BOXX, 490, MENULIST_B_BOXW, MENULIST_BOXH, 1},

        {L"Name of Query", L"���Ʋ�ѯ", L"���Q��ԃ", MENULIST_B_BOXX, 530, MENULIST_B_BOXW, MENULIST_BOXH, 1},
        {L"Adults of Query", L"�ɳ��ѯ", L"���x��ԃ", MENULIST_B_BOXX, 550, MENULIST_B_BOXW, MENULIST_BOXH, 0},
        {L"Larvae of Query", L"�׳��ѯ", L"���x��ԃ", MENULIST_B_BOXX, 570, MENULIST_B_BOXW, MENULIST_BOXH, 0},
        {L"Pupa of Query", L"Ӽ<��>��ѯ", L"Ӽ<�O>��ԃ", MENULIST_B_BOXX, 590, MENULIST_B_BOXW, MENULIST_BOXH, 1},
        {L"Eggs of Query", L"���Ѳ�ѯ", L"�x�Ѳ�ԃ", MENULIST_B_BOXX, 610, MENULIST_B_BOXW, MENULIST_BOXH, 0},
    },
    {
        {L"All", L"ȫ��", L"ȫ��", MENULIST_B_BOXX, 50, MENULIST_B_BOXW, MENULIST_BOXH, 1},

        {L"Araneidae", L"�����", L"�����", MENULIST_B_BOXX, 70, MENULIST_B_BOXW, MENULIST_BOXH, 1},
        {L"Agelenidae", L"�����", L"�����", MENULIST_B_BOXX, 90, MENULIST_B_BOXW, MENULIST_BOXH, 1},
        {L"Clubionidae", L"�����", L"�����", MENULIST_B_BOXX, 110, MENULIST_B_BOXW, MENULIST_BOXH, 1},
        {L"Gnaphosidae", L"�����<ƽ����>", L"�����<ƽ����>", MENULIST_B_BOXX, 130, MENULIST_B_BOXW, MENULIST_BOXH, 1},
        {L"Heteropodidae", L"�߽����", L"���_���", MENULIST_B_BOXX, 150, MENULIST_B_BOXW, MENULIST_BOXH, 1},
        {L"Lycosidae", L"�����", L"�����", MENULIST_B_BOXX, 170, MENULIST_B_BOXW, MENULIST_BOXH, 1},
        {L"Nephilidae", L"���¸���", L"�j�D��", MENULIST_B_BOXX, 190, MENULIST_B_BOXW, MENULIST_BOXH, 1},
        {L"Oxyopidae", L"è���", L"؈���", MENULIST_B_BOXX, 210, MENULIST_B_BOXW, MENULIST_BOXH, 1},
        {L"Pisauridae", L"�����", L"�����", MENULIST_B_BOXX, 230, MENULIST_B_BOXW, MENULIST_BOXH, 1},
        {L"Salticidae", L"Ӭ����", L"ω����", MENULIST_B_BOXX, 250, MENULIST_B_BOXW, MENULIST_BOXH, 1},
        {L"Tetragnathidae", L"�������", L"�L�_���", MENULIST_B_BOXX, 270, MENULIST_B_BOXW, MENULIST_BOXH, 1},
        {L"Thomisidae", L"з���", L"з���", MENULIST_B_BOXX, 290, MENULIST_B_BOXW, MENULIST_BOXH, 1},
        {L"Theridiidae", L"�����", L"�����", MENULIST_B_BOXX, 310, MENULIST_B_BOXW, MENULIST_BOXH, 1},
        {L"Uloboridae", L"�u���", L"�u���", MENULIST_B_BOXX, 330, MENULIST_B_BOXW, MENULIST_BOXH, 1},

        {L"Other", L"����", L"����", MENULIST_B_BOXX, 490, MENULIST_B_BOXW, MENULIST_BOXH, 1},

        {L"Name of Query", L"���Ʋ�ѯ", L"���Q��ԃ", MENULIST_B_BOXX, 530, MENULIST_B_BOXW, MENULIST_BOXH, 1},
        {L"Adults of Query", L"�ɳ��ѯ", L"���x��ԃ", MENULIST_B_BOXX, 550, MENULIST_B_BOXW, MENULIST_BOXH, 0},
        {L"Larvae of Query", L"�׳��ѯ", L"���x��ԃ", MENULIST_B_BOXX, 570, MENULIST_B_BOXW, MENULIST_BOXH, 0},
        {L"Eye of Query", L"��ʽ��ѯ", L"��ʽ��ԃ", MENULIST_B_BOXX, 590, MENULIST_B_BOXW, MENULIST_BOXH, 0},
        {L"Cobweb of Query", L"֩������ѯ", L"֩��W��ԃ", MENULIST_B_BOXX, 610, MENULIST_B_BOXW, MENULIST_BOXH, 0},
    }
};

void MenuListB(void)
{
    int i,j;
    glColor3ub(MenuListColor);

	for(i = 0; i < menulistA_num; i++)
	 if(menulistA_info[i].select)
		 break;

    //����
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

    //����
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