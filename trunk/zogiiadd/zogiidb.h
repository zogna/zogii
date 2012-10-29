#ifndef _ZOGII_DB_H_
#define _ZOGII_DB_H_

#include "stdio.h"
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#if 0

//��64λ 32λ���� WINDOWS 
// 8�ֽ�
typedef __int64 ZOGII_LONG_TYPE;
typedef unsigned __int64 ZOGII_ULONG_TYPE;

#else
// 4�ֽ�
typedef __int32 ZOGII_LONG_TYPE;
typedef unsigned __int32 ZOGII_ULONG_TYPE;

#endif

//�ṹ��ʣ����չ����
#define ZOGII_EXP_SIZ 824
//���·������
#define ZOGII_PAT_MAX 260 
//����ַ�������
#define ZOGII_STR_MAX 128 
//�����������
#define ZOGII_LAG_MAX 3
//�������ɫ��
#define ZOGII_COR_MAX 4
//���ͼƬ��
#define ZOGII_PIC_MAX 12
//��������
#define ZOGII_INF_MAX 7

//���ʳ������
#define ZOGII_FOODINF_MAX 4
//�����Ϣ������
#define ZOGII_LIVIINF_MAX 3
//����ֵص���
#define ZOGII_DISCOVERY_MAX 24

//���ͼƬ��
#define ZOGII_ALL_PIC (ZOGII_PIC_MAX*5)
// 0-11ΪImago 
// 12-23ΪLarva
// 24-35ΪPupa
// 36-47ΪOvum
#define ZOGII_ALL_PIC_Imago_START	(0)
#define ZOGII_ALL_PIC_Larva_START	(ZOGII_PIC_MAX)
#define ZOGII_ALL_PIC_Pupa_START	(ZOGII_PIC_MAX*2)
#define ZOGII_ALL_PIC_Ovum_START	(ZOGII_PIC_MAX*3)
#define ZOGII_ALL_PIC_Closeup_START	(ZOGII_PIC_MAX*4)

////DBĿ¼
#define ZOGII_DB_DIRSTR "zogcidb"
#define ZOGII_DB_FILSTR "zogci.db"
/* 
//��ɫ��
// -1=��Ч
// 0=��
// 1 =���ʻ�
// 2 =�Ȼ�
// 3 =��
// 4 =��
// 5 =��
// 6 =��
// 7 =��
// 8 =��
// 9 =��
// 10 =����
// 11 =�Ϻ�
*/

//�������� TYPE
enum 
{
	TYPE_SubFamily=1,
	TYPE_Genus,
	TYPE_Name,
	TYPE_SpName,
	TYPE_NEW_SubFamily,
	TYPE_NEW_Genus,
	TYPE_NEW_Name,
	TYPE_NEW_SpName
};

#define NEWSubFamily_STR "New SubFamily"
#define NEWGenus_STR	"New Genus"
#define NEWName_STR		"New Name"
#define NEWSpName_STR	"New SpName"
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#pragma pack(1)

struct ZOGII_Pic
{
	// 0=������Ч
	// 1=������Ч
	unsigned char flag;
	//ͼƬĿ¼
	char Path[ZOGII_PAT_MAX];
	//ͼƬ������Դ
	char Info[ZOGII_PAT_MAX];
};

//�ɳ� ��չ
struct ZOGII_Imago_2EX
{
	//////////////////////////�ʳ�
	//�ߵ��� 0-50
	char ElytraPointNum; 
	//////////////////////////ǰ�ر���
	//��ɫ���� 0-9
	// -1=��Ч
	//0 =�ýṹ��Ϊ��Ч����
	//1-9 ��Ч���� 
	char PronotumColorNum;
	//������ɫ ����ɫ��
	char PronotumColor[ZOGII_COR_MAX];
	//����
	// -1=��Ч
	// 0 =��
	// 1 =����
	// 2 =�ߵ�
	// 3 =�ߵ�+����
	char PronotumTexture; 
	//�ߵ��� 0-50
	char PronotumPointNum; 
};

//�ɳ�
struct ZOGII_Imago
{
	//��ǰ����
	// -1=��Ч
	// 0 =δ֪
	// 1 =��
	// 2 =��
	char Sex;
	//��ɫ���� 0-9
	// -1=��Ч
	//0 =�ýṹ��Ϊ��Ч����
	//1-9 ��Ч���� 
	char ElytraColorNum;
	//������ɫ ����ɫ��
	char ElytraColor[ZOGII_COR_MAX];

	// -1=��Ч
	// 0 =����ë
	// 1 =����ë
//	char Villus; 
	//��չ
	char Expand; 
	//����
	// -1=��Ч
	// 0 =��
	// 1 =����
	// 2 =�ߵ�
	// 3 =�ߵ�+����
	char ElytraTexture; 

	//ͼƬ����ֵ 0Ϊ��Ч
	ZOGII_ULONG_TYPE Pic;
};

//�׳�
struct ZOGII_Larva
{
	//��ǰ����
	// -1=��Ч
	// 0 =δ֪
	// 1 =��
	// 2 =��
	char Sex;
	//��ɫ���� 0-9
	// -1=��Ч
	//0 =�ýṹ��Ϊ��Ч����
	//1-9 ��Ч���� 
	char ColorNum;
	//������ɫ ����ɫ��
	char Color[ZOGII_COR_MAX];
	//����
	// -1=��Ч
	// 0 =����
	// 1 =ë״
	// 2 =����
	char Calthrop;
	//����
	// -1=��Ч
	// 0 =δ֪
	// 1 =һ��
	// 2 =����
	// 3 =����
	// 4 =����
	char Instar;
	//ͼƬ����ֵ 0Ϊ��Ч
	ZOGII_ULONG_TYPE Pic;
};
//��
struct ZOGII_Ovum
{
	//��ǰ����
	//-1=��Ч
	// 0 =δ֪
	// 1 =��
	// 2 =��
	char Sex;
	//������ɫ ����ɫ��
	char Color;
	//ͼƬ����ֵ 0Ϊ��Ч
	ZOGII_ULONG_TYPE Pic;
};

//Ӽ
struct ZOGII_Pupa
{
	//��ǰ����
	// -1 ��Чֵ
	// 0 =δ֪
	// 1 =��
	// 2 =��
	char Sex;
	//��ɫ���� 0-9
	//-1��Ч
	//0 =�ýṹ��Ϊ��Ч����
	//1-9 ��Ч���� 
	char ColorNum;
	//������ɫ ����ɫ��
	char Color[ZOGII_COR_MAX];
	//ͼƬ����ֵ 0Ϊ��Ч
	ZOGII_ULONG_TYPE Pic;
};

//Ӽ��չ
struct ZOGII_Pupa_2EX
{
	//��ǰ����
	// -1 ��Чֵ
	// 0 =δ֪
	// 1 =ǰӼ
	// 2 =Ӽ
	// 3 =Ӽ��
	char Type;
};

//��д
struct ZOGII_CloseUp
{
	//��ǰ����
	//-1=��Ч
	// 0=����
	// 1=ͷ��
	// 2=��β
	// 3=Խ��
	// 4=����
	// 5=չ��
	// 6=��Ϣ����
	char Type;
	//ͼƬ����ֵ 0Ϊ��Ч
	ZOGII_ULONG_TYPE Pic;
};


//ư���
struct ZOGII_Coccinellidae_DATA
{
	//������
	ZOGII_ULONG_TYPE code;
	//���ݱ����Ÿ����Ψһ�ļ���
	char Path[ZOGII_PAT_MAX];
	//������ʱ�� YY MM DD
	char year;
	char month;
	char day;
///////////////////////////////////////////////////
	//ZOGII_LAG_MAX ������ 
	// 0 =Ӣ�� ���� 
	// 1 =���ļ���
	// 2 =���ķ���	
	//�ǿ���	
	char SubFamily[ZOGII_LAG_MAX][ZOGII_STR_MAX];
	//����	
	char Genus[ZOGII_LAG_MAX][ZOGII_STR_MAX];
	//����	
	char Name[ZOGII_LAG_MAX][ZOGII_STR_MAX];	
	//������	
	char SpName[ZOGII_LAG_MAX][ZOGII_STR_MAX];
	//��ϸ��Ϣ Ŀ¼
	char Text[ZOGII_LAG_MAX][ZOGII_PAT_MAX];
///////////////////////////////////////////////////
	//����
	char OtherName[ZOGII_INF_MAX][ZOGII_STR_MAX];
	//ʳ��
	//-1 ��Ч
	// 0 =��ʳ
	// 1 =��ʳ
	// 2 =ֲʳ
	char FoodType;	
	//ʳ������ 4��
	char FoodName[ZOGII_FOODINF_MAX][ZOGII_STR_MAX];
	//��Ϣ��
	char LivingName[ZOGII_LIVIINF_MAX][ZOGII_STR_MAX];
///////////////////////////////////////////////////
	char Expand2ex[4];
	//���������� ���
	char DiscoverName[ZOGII_STR_MAX];
///////////////////////////////////////////////////
	struct ZOGII_Imago Imago[ZOGII_PIC_MAX];
	struct ZOGII_Larva Larva[ZOGII_PIC_MAX];
	struct ZOGII_Pupa Pupa[ZOGII_PIC_MAX];
	struct ZOGII_Ovum Ovum[ZOGII_PIC_MAX];

	//ʹ����չ
	struct ZOGII_Imago_2EX Imago2ex[ZOGII_PIC_MAX];
	struct ZOGII_Pupa_2EX Pupa2ex[ZOGII_PIC_MAX];

	// -1=��Ч
	// 0=δ֪
	// 1=3mm����
	// 2=2mm-4mm
	// 3=3mm-5mm
	// 4=4mm-6mm
	// 5=5mm-7mm
	// 6=6mm-8mm
	// 7=7mm-9mm
	// 8=8mm����
	char Size;
	// -1=��Ч
	// 0=δ֪
	// 1=ɽ��
	// 2=ũ��
	// 3=ɭ��
	char Living;
	// -1=��Ч
	// 0=δ֪
	// 1=����
	// 2=������
	char Light;

	// -1=��Ч
	// 0=δ֪
	// 1=Խ��
	// 2=��Խ��
	char OverWintering;
	// -1=��Ч
	// 0=δ֪
	// 1=��ʼ�·� 1��
	// ..
	// 12=��ʼ�·� 12��
	char StartMonth;
	// -1=��Ч
	// 0=δ֪
	// 1=�����·� 1��
	// ..
	// 12=�����·� 12��
	char EndMonth;
	//������ɫ
	char ImagobellyColor;
	// -1=��Ч
	// 0 =����ë
	// 1 =����ë
	char ImagoVillus; 
	//��д
	struct ZOGII_CloseUp Closeup[ZOGII_PIC_MAX];
	//���ֵص���
	char DiscoverMapList[ZOGII_DISCOVERY_MAX];

	//��չ���� Ϊ���Ժ����
	char Expand[ZOGII_EXP_SIZ];
};

//ư���
struct ZOGII_Coccinellidae_NAME
{
	struct ZOGII_Coccinellidae_DATA NA;

	ZOGII_ULONG_TYPE SpTotal;
	struct ZOGII_Coccinellidae_DATA *SpData;
};

//ư���
struct ZOGII_Coccinellidae_GENUS
{
	struct ZOGII_Coccinellidae_DATA GE;

	ZOGII_ULONG_TYPE NameTotal;
	struct ZOGII_Coccinellidae_NAME *NameData;
};

//ư���
struct ZOGII_Coccinellidae_SUBFamily
{
	struct ZOGII_Coccinellidae_DATA SF;

	ZOGII_ULONG_TYPE GenusTotal;
	struct ZOGII_Coccinellidae_GENUS *GenusData;
};


#pragma pack()
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
ZOGII_ULONG_TYPE zogiiSFTotalDB(void);
ZOGII_ULONG_TYPE zogiiGETotalDB(void);
ZOGII_ULONG_TYPE zogiiNATotalDB(void);
ZOGII_ULONG_TYPE zogiiSPTotalDB(void);

ZOGII_ULONG_TYPE zogiiVersionDB(void);
void zogiiSetDirectory(char *dir);
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void zogiiCopyFile(char *src,char *dst);
void zogiiDeleteFile(char *str);
void zogiiCreateDirectory(char *str);
void zogiiRemoveDirectory(char *str);
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int zogiiReadDB(ZOGII_ULONG_TYPE *total,struct ZOGII_Coccinellidae_SUBFamily *&data,	\
				ZOGII_ULONG_TYPE *pictotal,struct ZOGII_Pic *&picdata);
int zogiiWriteDB(ZOGII_ULONG_TYPE total,struct ZOGII_Coccinellidae_SUBFamily *&data,	\
				 ZOGII_ULONG_TYPE pictotal,struct ZOGII_Pic *&picdata);
void zogiiFreeDB(ZOGII_ULONG_TYPE *total,struct ZOGII_Coccinellidae_SUBFamily *&data,	\
				  ZOGII_ULONG_TYPE *pictotal,struct ZOGII_Pic *&picdata);
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int zogiiSort_SF(const void *A,const void *B);
int zogiiSort_GE(const void *A,const void *B);
int zogiiSort_NA(const void *A,const void *B);
int zogiiSort_SP(const void *A,const void *B);
void zogiiSortDB(ZOGII_ULONG_TYPE total,struct ZOGII_Coccinellidae_SUBFamily *&data);
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
ZOGII_ULONG_TYPE zogiiCodeGen(ZOGII_ULONG_TYPE *total,struct ZOGII_Coccinellidae_SUBFamily *&data,	\
					unsigned char type,ZOGII_ULONG_TYPE sf,ZOGII_ULONG_TYPE ge,ZOGII_ULONG_TYPE na);

void zogiiTEMPSaveDB(struct ZOGII_Coccinellidae_DATA *data,	\
					ZOGII_ULONG_TYPE *Imagopic,	\
					ZOGII_ULONG_TYPE *Larvapic,	\
					ZOGII_ULONG_TYPE *Pupapic,	\
					ZOGII_ULONG_TYPE *Ovumpic,	\
					ZOGII_ULONG_TYPE *Closeuppic,	\
					ZOGII_ULONG_TYPE *tempcode,	\
					char *temppath,	\
					char tempsfname[ZOGII_LAG_MAX][ZOGII_STR_MAX],	\
					char tempgename[ZOGII_LAG_MAX][ZOGII_STR_MAX],	\
					char tempname[ZOGII_LAG_MAX][ZOGII_STR_MAX]);

void zogiiAddSaveDB(ZOGII_ULONG_TYPE *total,struct ZOGII_Coccinellidae_SUBFamily *&data,	\
				ZOGII_ULONG_TYPE *pictotal,struct ZOGII_Pic *&picdata,	\
				unsigned char type,ZOGII_ULONG_TYPE sf,ZOGII_ULONG_TYPE ge,ZOGII_ULONG_TYPE na,	ZOGII_ULONG_TYPE sp,	\
				struct ZOGII_Coccinellidae_DATA *newdata,struct ZOGII_Pic *NewPicdata);

void zogiiDeleteDB(ZOGII_ULONG_TYPE *total,struct ZOGII_Coccinellidae_SUBFamily *&data,	\
			   unsigned char type,ZOGII_ULONG_TYPE sf,ZOGII_ULONG_TYPE ge,ZOGII_ULONG_TYPE na,ZOGII_ULONG_TYPE sp,	\
			   struct ZOGII_Pic *&picdata);
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void zogiiAddtxtDB(struct ZOGII_Coccinellidae_DATA *data,struct ZOGII_Coccinellidae_DATA *newdata);
void zogiiAddtxtDBLite(struct ZOGII_Coccinellidae_DATA *data,struct ZOGII_Coccinellidae_DATA *newdata,	\
					   int i);
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void zogiiADDpicDB(struct ZOGII_Coccinellidae_DATA *data,	\
				ZOGII_ULONG_TYPE *pictotal,struct ZOGII_Pic *&picdata,	\
				struct ZOGII_Pic *NewPicdata,	\
				ZOGII_ULONG_TYPE *Imagopic,	\
				ZOGII_ULONG_TYPE *Larvapic,	\
				ZOGII_ULONG_TYPE *Pupapic,	\
				ZOGII_ULONG_TYPE *Ovumpic,	\
				ZOGII_ULONG_TYPE *Closeuppic);

void zogiiDeletepicDB(struct ZOGII_Coccinellidae_DATA *data,struct ZOGII_Pic *&picdata);

void zogiiModifypicDBLite(struct ZOGII_Pic *pdata,struct ZOGII_Pic *newpic,char *path);

void zogiiInitpicDB(struct ZOGII_Coccinellidae_DATA *data);
ZOGII_ULONG_TYPE zogiiADDpicDBLite(ZOGII_ULONG_TYPE *pictotal,struct ZOGII_Pic *&picdata,	\
									char *Path,struct ZOGII_Pic *newpic);
ZOGII_ULONG_TYPE zogiiDeletepicDBLite(ZOGII_ULONG_TYPE i,struct ZOGII_Pic *&picdata);



#endif


/*
0 = δ֪
1 = �й�
2 = �й�-̨��
3 = �й�-����
4 = �й�-����
5 = �й�-����
6 = �й�-����
7 = �й�-����
8 = �й�-����
9 = �й�-�ӱ�
10 = �й�-�㶫
11 = �й�-����
12 = �й�-����
13 = �й�-����
14 = �й�-�㽭
15 = �й�-����
16 = �й�-����
17 = �й�-�½�
18 = �й�-����
19 = �й�-���
20 = �й�-����
21 = �й�-�Ĵ�
22 = �й�-����
23 = �й�-����
24 = �й�-ɽ��
25 = �й�-ɽ��
26 = �й�-�Ϻ�
27 = �й�-����
28 = �й�-����
29 = �й�-�ຣ
30 = �й�-������
31 = �й�-���ɹ�
32 = ����
33 = �ɹ�
34 = ����
35 = ɳ�ذ�����
36 = ���
37 = Խ��
38 = ����
39 = �ձ�
40 = �ձ�-����Ⱥ��
41 = ӡ��
42 = ӡ��-����
43 = �Ჴ��
44 = ˹������
45 = ̩��
46 = ���ɱ�
47 = ��������
48 = Ӣ��
49 = ����
50 = �¼���
51 = ��ʲ�׶�����
52 = ӡ��������
53 = ������
54 = ����
55 = �ܿ���������
56 = ����
57 = �߼�������
58 = �������ǵ���
59 = �������Ƕ��ϲ�
60 = �Ĵ�����
61 = ������
62 = ����-����˹��
63 = ����-������
64 = ����
65 = ��ӡ��Ⱥ��
66 = Ҳ��
67 = ����
68 = �ͻ�˹̹
69 = �ϼ���
70 = ����
71 = ����˹
72 = ����կ
73 = ������
74 = �������뵺
75 = ������˹̹
76 = �¼�����
77 = ����
78 = ����
79 = ����
80 = ŷ��
81 = ����
82 = ���к�����
*/