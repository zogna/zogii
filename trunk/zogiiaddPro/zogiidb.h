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

//���·������
#define ZOGII_PAT_MAX 260 
//����ַ�������
#define ZOGII_STR_MAX 128 
//�����������
#define ZOGII_LAG_MAX 3
//�������ɫ��
#define ZOGII_COR_MAX 4
//��������
#define ZOGII_INF_MAX 7

//���ʳ������
#define ZOGII_FOODINF_MAX 4
//�����Ϣ������
#define ZOGII_LIVIINF_MAX 3
//����ֵص���
#define ZOGII_DISCOVERY_MAX 256

//���ͼƬ��
#define ZOGII_PIC_Imago_MAX		512
#define ZOGII_PIC_Larva_MAX		256
#define ZOGII_PIC_Pupa_MAX		256	
#define ZOGII_PIC_Ovum_MAX		128	
#define ZOGII_PIC_Closeup_MAX	512

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
// 12 =���
// 13= ����
*/

//�������� TYPE
enum 
{
	TYPE_SubFamily=1,
	TYPE_Genus,
	TYPE_Species,
	TYPE_Subspecies,
	TYPE_NEW_SubFamily,
	TYPE_NEW_Genus,
	TYPE_NEW_Species,
	TYPE_NEW_Subspecies
};

#define NEWSubFamily_STR "New SubFamily"
#define NEWGenus_STR	"New Genus"
#define NEWSpecies_STR		"New Species"
#define NEWSubspecies_STR	"New Subspecies"
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#pragma pack(1)

//�ɳ�
struct ZOGII_Imago
{
	//��ǰ����
	// -1=��Ч
	// 0 =δ֪
	// 1 =��
	// 2 =��
	char Sex;
	//////////////////////////�ʳ�
	//��ɫ���� 0-9
	// -1=��Ч
	//0 =�ýṹ��Ϊ��Ч����
	//1-9 ��Ч���� 
	char ElytraColorNum;
	//������ɫ ����ɫ��
	char ElytraColor[ZOGII_COR_MAX];
	//����
	// -1=��Ч
	// 0 =��
	// 1 =����
	// 2 =�ߵ�
	// 3 =�ߵ�+����
	char ElytraTexture; 
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

	// 0=������Ч
	// 1=������Ч
	unsigned char flag;
	//ͼƬĿ¼
	char Path[ZOGII_PAT_MAX];
	//ͼƬ������Դ
	char Info[ZOGII_PAT_MAX];
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
	// 0=����
	// 1=ȫë
	// 2=֦��
	// 3=��ƽ
	// 4=��ë
	// 5=��ë
	// 6=С��
	char Calthrop;
	//����
	// -1=��Ч
	// 0 =δ֪
	// 1 =һ��
	// 2 =����
	// 3 =����
	// 4 =����
	char Instar;
	// 0=������Ч
	// 1=������Ч
	unsigned char flag;
	//ͼƬĿ¼
	char Path[ZOGII_PAT_MAX];
	//ͼƬ������Դ
	char Info[ZOGII_PAT_MAX];
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
	// 0=������Ч
	// 1=������Ч
	unsigned char flag;
	//ͼƬĿ¼
	char Path[ZOGII_PAT_MAX];
	//ͼƬ������Դ
	char Info[ZOGII_PAT_MAX];
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
	//��ǰ����
	// -1 ��Чֵ
	// 0=δ֪
	// 1=ǰӼ
	// 2=Ӽ-����
	// 3=Ӽ-ȫë
	// 4=Ӽ-Ӳ��
	// 5=Ӽ-���
	// 6=Ӽ��
	char Type;
	//��ɫ���� 0-9
	//-1��Ч
	//0 =�ýṹ��Ϊ��Ч����
	//1-9 ��Ч���� 
	char ColorNum;
	//������ɫ ����ɫ��
	char Color[ZOGII_COR_MAX];
	// 0=������Ч
	// 1=������Ч
	unsigned char flag;
	//ͼƬĿ¼
	char Path[ZOGII_PAT_MAX];
	//ͼƬ������Դ
	char Info[ZOGII_PAT_MAX];
};

//��д
struct ZOGII_Closeup
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
	// 7=��ʳ
	// 8=β��
	// 9=����
	// 10=��ͼ
	// 11=����
	char Type;
	// 0=������Ч
	// 1=������Ч
	unsigned char flag;
	//ͼƬĿ¼
	char Path[ZOGII_PAT_MAX];
	//ͼƬ������Դ
	char Info[ZOGII_PAT_MAX];
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
	char Species[ZOGII_LAG_MAX][ZOGII_STR_MAX];	
	//������	
	char Subspecies[ZOGII_LAG_MAX][ZOGII_STR_MAX];
	//��ϸ��Ϣ Ŀ¼
	char Text[ZOGII_LAG_MAX][ZOGII_PAT_MAX];
///////////////////////////////////////////////////
	//����
	char Synonyms[ZOGII_INF_MAX][ZOGII_STR_MAX];
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

	//���������� ���
	char DiscoverName[ZOGII_STR_MAX];

	//���ֵص���
	unsigned char DiscoverMapTotal;
	unsigned char DiscoverMapList[ZOGII_DISCOVERY_MAX];

	// -1=��Ч
	//����mm
	char MinSize;
	char MaxSize;
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
	//�ز���ɫ
	char ImagochestColor;
	//������ɫ
	char ImagobellyColor;
	// -1=��Ч
	// 0 =����ë
	// 1 =����ë
	char ImagoVillus; 
	//����
	// -1=��Ч
	// 0=δ֪
	// 1=Բ��
	// 2=��Բ
	// 3=����
	char  Contour;
	//��������ֵ 0Ϊ��Ч
	ZOGII_ULONG_TYPE Imago[ZOGII_PIC_Imago_MAX];
	ZOGII_ULONG_TYPE Larva[ZOGII_PIC_Larva_MAX];
	ZOGII_ULONG_TYPE Pupa[ZOGII_PIC_Pupa_MAX];
	ZOGII_ULONG_TYPE Ovum[ZOGII_PIC_Ovum_MAX];
	ZOGII_ULONG_TYPE Closeup[ZOGII_PIC_Closeup_MAX];

};

//ư�����
struct ZOGII_Coccinellidae_SPECIES
{
	struct ZOGII_Coccinellidae_DATA SP;

	ZOGII_ULONG_TYPE SubspTotal;
	struct ZOGII_Coccinellidae_DATA *SubspData;
};

//ư�����
struct ZOGII_Coccinellidae_GENUS
{
	struct ZOGII_Coccinellidae_DATA GE;

	ZOGII_ULONG_TYPE SpeciesTotal;
	struct ZOGII_Coccinellidae_SPECIES *SpeciesData;
};

//ư����ǿ�
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
ZOGII_ULONG_TYPE zogiiSPTotalDB(void);
ZOGII_ULONG_TYPE zogiiSSPTotalDB(void);

ZOGII_ULONG_TYPE zogiiVersionDB(void);
void zogiiSetDirectory(char *dir);
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void zogiiCopyFile(char *src,char *dst);
void zogiiDeleteFile(char *str);
void zogiiCreateDirectory(char *str);
void zogiiRemoveDirectory(char *str);
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int zogiiReadDB(ZOGII_ULONG_TYPE *total,struct ZOGII_Coccinellidae_SUBFamily *&data,
				ZOGII_ULONG_TYPE *Imagototal,struct ZOGII_Imago *&Imagodata,
				ZOGII_ULONG_TYPE *Larvatotal,struct ZOGII_Larva *&Larvadata,
				ZOGII_ULONG_TYPE *Pupatotal,struct ZOGII_Pupa *&Pupadata,
				ZOGII_ULONG_TYPE *Ovumtotal,struct ZOGII_Ovum *&Ovumdata,
				ZOGII_ULONG_TYPE *Closeuptotal,struct ZOGII_Closeup *&Closeupdata);

int zogiiWriteDB(ZOGII_ULONG_TYPE total,struct ZOGII_Coccinellidae_SUBFamily *&data,
				 ZOGII_ULONG_TYPE Imagototal,struct ZOGII_Imago *&Imagodata,
				 ZOGII_ULONG_TYPE Larvatotal,struct ZOGII_Larva *&Larvadata,
				 ZOGII_ULONG_TYPE Pupatotal,struct ZOGII_Pupa *&Pupadata,
				 ZOGII_ULONG_TYPE Ovumtotal,struct ZOGII_Ovum *&Ovumdata,
				 ZOGII_ULONG_TYPE Closeuptotal,struct ZOGII_Closeup *&Closeupdata);

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int zogiiSort_SF(const void *A,const void *B);
int zogiiSort_GE(const void *A,const void *B);
int zogiiSort_NA(const void *A,const void *B);
int zogiiSort_SP(const void *A,const void *B);
void zogiiSortDB(ZOGII_ULONG_TYPE total,struct ZOGII_Coccinellidae_SUBFamily *&data);
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int zogiiPrintfDB(ZOGII_ULONG_TYPE total,struct ZOGII_Coccinellidae_SUBFamily *&data);

void zogiiSearchDB(char *printfstr,unsigned int printflen,char *str,
				  ZOGII_ULONG_TYPE total,struct ZOGII_Coccinellidae_SUBFamily *&data);

char zogiiCodeSearchDB(char *printfstr,	char flag,
					   ZOGII_ULONG_TYPE sfcode,ZOGII_ULONG_TYPE gecode,ZOGII_ULONG_TYPE spcode,ZOGII_ULONG_TYPE sppcode,
					   ZOGII_ULONG_TYPE total,struct ZOGII_Coccinellidae_SUBFamily *&data,
					   	ZOGII_ULONG_TYPE *sf,ZOGII_ULONG_TYPE *ge,ZOGII_ULONG_TYPE *sp,ZOGII_ULONG_TYPE *ssp);

//void zogiicheckDB(ZOGII_ULONG_TYPE total,struct ZOGII_Coccinellidae_SUBFamily *&data);
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
ZOGII_ULONG_TYPE zogiiCodeGen(ZOGII_ULONG_TYPE *total,struct ZOGII_Coccinellidae_SUBFamily *&data,	\
					unsigned char type,ZOGII_ULONG_TYPE sf,ZOGII_ULONG_TYPE ge,ZOGII_ULONG_TYPE sp);

void zogiiTEMPSaveDB(struct ZOGII_Coccinellidae_DATA *data,	\
					ZOGII_ULONG_TYPE *tempImago,	\
					ZOGII_ULONG_TYPE *tempLarva,
					ZOGII_ULONG_TYPE *tempPupa,
					ZOGII_ULONG_TYPE *tempOvum,
					ZOGII_ULONG_TYPE *tempCloseup,
					ZOGII_ULONG_TYPE *tempcode,	\
					char *temppath,	\
					char tempsfname[ZOGII_LAG_MAX][ZOGII_STR_MAX],	\
					char tempgename[ZOGII_LAG_MAX][ZOGII_STR_MAX],	\
					char tempname[ZOGII_LAG_MAX][ZOGII_STR_MAX],	\
					char temptext[ZOGII_LAG_MAX][ZOGII_PAT_MAX]);

void zogiiAddSaveDB(ZOGII_ULONG_TYPE *total,struct ZOGII_Coccinellidae_SUBFamily *&data,	\
					ZOGII_ULONG_TYPE *Imagototal,	struct ZOGII_Imago *&Imagodata,
					ZOGII_ULONG_TYPE *Larvatotal,struct ZOGII_Larva *&Larvadata,
					ZOGII_ULONG_TYPE *Pupatotal,	struct ZOGII_Pupa *&Pupadata,
					ZOGII_ULONG_TYPE *Ovumtotal,struct ZOGII_Ovum *&Ovumdata,
					ZOGII_ULONG_TYPE *Closeuptotal,struct ZOGII_Closeup *&Closeupdata,
					unsigned char type,ZOGII_ULONG_TYPE sf,ZOGII_ULONG_TYPE ge,ZOGII_ULONG_TYPE sp,	ZOGII_ULONG_TYPE ssp,	\
					struct ZOGII_Coccinellidae_DATA *newdata,
					struct ZOGII_Imago *NewImagodata,
					struct ZOGII_Larva *NewLarvadata,
					struct ZOGII_Pupa *NewPupadata,
					struct ZOGII_Ovum *NewOvumdata,
					struct ZOGII_Closeup *NewCloseupdata);


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void zogiiAddtxtDB(struct ZOGII_Coccinellidae_DATA *data,struct ZOGII_Coccinellidae_DATA *newdata,	\
				   char temptext[ZOGII_LAG_MAX][ZOGII_PAT_MAX]);
void zogiiAddtxtDBLite(struct ZOGII_Coccinellidae_DATA *data,struct ZOGII_Coccinellidae_DATA *newdata,	\
					   int i,char *temp);
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void zogiiADDpicDB(struct ZOGII_Coccinellidae_DATA *data,	\
					ZOGII_ULONG_TYPE *Imagototal,	struct ZOGII_Imago *&Imagodata,
					ZOGII_ULONG_TYPE *Larvatotal,struct ZOGII_Larva *&Larvadata,
					ZOGII_ULONG_TYPE *Pupatotal,	struct ZOGII_Pupa *&Pupadata,
					ZOGII_ULONG_TYPE *Ovumtotal,struct ZOGII_Ovum *&Ovumdata,
					ZOGII_ULONG_TYPE *Closeuptotal,struct ZOGII_Closeup *&Closeupdata,
					struct ZOGII_Imago *NewImagodata,
					struct ZOGII_Larva *NewLarvadata,
					struct ZOGII_Pupa *NewPupadata,
					struct ZOGII_Ovum *NewOvumdata,
					struct ZOGII_Closeup *NewCloseupdata,
					ZOGII_ULONG_TYPE *tempImago,	\
					ZOGII_ULONG_TYPE *tempLarva,	\
					ZOGII_ULONG_TYPE *tempPupa,	\
					ZOGII_ULONG_TYPE *tempOvum,	\
					ZOGII_ULONG_TYPE *tempCloseup);

/////////
ZOGII_ULONG_TYPE zogiiADDImagoDBLite(ZOGII_ULONG_TYPE *Imagototal,	struct ZOGII_Imago *&Imagodata,
									char *Path,struct ZOGII_Imago *NewImagodata);

void zogiiModifyImagoDBLite(struct ZOGII_Imago *pdata,struct ZOGII_Imago *newpic,char *path);
void  zogiiCopyImagoDBLite(struct ZOGII_Imago *pdata,struct ZOGII_Imago *newpic);
/////////
ZOGII_ULONG_TYPE zogiiADDLarvaDBLite(ZOGII_ULONG_TYPE *Larvatotal,	struct ZOGII_Larva *&Larvadata,
									char *Path,struct ZOGII_Larva *NewLarvadata);

void zogiiModifyLarvaDBLite(struct ZOGII_Larva *pdata,struct ZOGII_Larva *newpic,char *path);
void  zogiiCopyLarvaDBLite(struct ZOGII_Larva *pdata,struct ZOGII_Larva *newpic);
/////////
ZOGII_ULONG_TYPE zogiiADDPupaDBLite(ZOGII_ULONG_TYPE *Pupatotal,	struct ZOGII_Pupa *&Pupadata,
									char *Path,struct ZOGII_Pupa *NewPupadata);

void zogiiModifyPupaDBLite(struct ZOGII_Pupa *pdata,struct ZOGII_Pupa *newpic,char *path);
void  zogiiCopyPupaDBLite(struct ZOGII_Pupa *pdata,struct ZOGII_Pupa *newpic);
/////////
ZOGII_ULONG_TYPE zogiiADDOvumDBLite(ZOGII_ULONG_TYPE *Ovumtotal,	struct ZOGII_Ovum *&Ovumdata,
									char *Path,struct ZOGII_Ovum *NewOvumdata);

void zogiiModifyOvumDBLite(struct ZOGII_Ovum *pdata,struct ZOGII_Ovum *newpic,char *path);
void  zogiiCopyOvumDBLite(struct ZOGII_Ovum *pdata,struct ZOGII_Ovum *newpic);
/////////
ZOGII_ULONG_TYPE zogiiADDCloseupDBLite(ZOGII_ULONG_TYPE *Closeuptotal,	struct ZOGII_Closeup *&Closeupdata,
									char *Path,struct ZOGII_Closeup *NewCloseupdata);

void zogiiModifyCloseupDBLite(struct ZOGII_Closeup *pdata,struct ZOGII_Closeup *newpic,char *path);
void  zogiiCopyCloseupDBLite(struct ZOGII_Closeup *pdata,struct ZOGII_Closeup *newpic);




void zogiiInitpicDB(struct ZOGII_Coccinellidae_DATA *data);


/////////////////////////////////////////////////
void zogiiDeleteDB(ZOGII_ULONG_TYPE *total,struct ZOGII_Coccinellidae_SUBFamily *&data,	\
					unsigned char type,ZOGII_ULONG_TYPE sf,ZOGII_ULONG_TYPE ge,ZOGII_ULONG_TYPE sp,ZOGII_ULONG_TYPE ssp,	\
					struct ZOGII_Imago *&Imagodata,
					struct ZOGII_Larva *&Larvadata,
					struct ZOGII_Pupa *&Pupadata,
					struct ZOGII_Ovum *&Ovumdata,
					struct ZOGII_Closeup *&Closeupdata);

void zogiiDeletepicDB(struct ZOGII_Coccinellidae_DATA *data,
					struct ZOGII_Imago *&Imagodata,
					struct ZOGII_Larva *&Larvadata,
					struct ZOGII_Pupa *&Pupadata,
					struct ZOGII_Ovum *&Ovumdata,
					struct ZOGII_Closeup *&Closeupdata);

ZOGII_ULONG_TYPE zogiiDeleteImagoDBLite(ZOGII_ULONG_TYPE i,
							struct ZOGII_Imago *&Imagodata);
ZOGII_ULONG_TYPE zogiiDeleteLarvaDBLite(ZOGII_ULONG_TYPE i,
							struct ZOGII_Larva *&Larvadata);
ZOGII_ULONG_TYPE zogiiDeletePupaDBLite(ZOGII_ULONG_TYPE i,
							struct ZOGII_Pupa *&Pupadata);
ZOGII_ULONG_TYPE zogiiDeleteOvumDBLite(ZOGII_ULONG_TYPE i,
							struct ZOGII_Ovum *&Ovumdata);
ZOGII_ULONG_TYPE zogiiDeleteCloseupDBLite(ZOGII_ULONG_TYPE i,
							struct ZOGII_Closeup *&Closeupdata);



#endif

