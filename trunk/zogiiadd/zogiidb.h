#ifndef _ZOGII_DB_H_
#define _ZOGII_DB_H_

#include "stdio.h"

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
//	CreateDirectory(temppath, NULL);
#define ZOGII_DB_DIRSTR "zogcidb"
#define ZOGII_DB_FILSTR "zogci.db"
/* 
//��ɫ��
// -1=��Ч
// 0 =���ʻ�
// 1 =�Ȼ�
// 2 =��
// 3 =��
// 4 =��
// 5 =��
// 6 =��
// 7 =��
// 8 =��
// 9 =����
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

#pragma pack(1)

struct ZOGII_Pic
{
	// 1=������Ч 0=������Ч
	unsigned char flag;
	//ͼƬĿ¼
	char Path[ZOGII_PAT_MAX];
	//ͼƬ������Դ
	char Info[ZOGII_STR_MAX];
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
	char ColorNum;
	//������ɫ ����ɫ��
	char Color[ZOGII_COR_MAX];
	// -1=��Ч
	// 0 =����ë
	// 1 =����ë
	char Villus; 
	//����
	// -1=��Ч
	// 0 =��
	// 1 =����
	// 2 =�ߵ�
	// 3 =�ߵ�+����
	char Texture; 
	//ͼƬ����ֵ 0Ϊ��Ч
	unsigned long int Pic;
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
	// 0 =һ��
	// 1 =����
	// 2 =����
	// 3 =����
	char Instar;
	//ͼƬ����ֵ 0Ϊ��Ч
	unsigned long int Pic;
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
	unsigned long int Pic;
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
	unsigned long int Pic;
};

//ư���
struct ZOGII_Coccinellidae_DATA
{
	//������
	unsigned int code;
	//���ݱ����Ÿ����Ψһ�ļ���
	char path[ZOGII_PAT_MAX];
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
	//ʳ������ 6��
	char FoodName[ZOGII_INF_MAX][ZOGII_STR_MAX];
///////////////////////////////////////////////////
	//���ֵص�ͼ 0Ϊ��Ч
	unsigned long int DiscoverMap;
	//���������� ���
	char DiscoverName[ZOGII_STR_MAX];
///////////////////////////////////////////////////
	struct ZOGII_Imago Imago[ZOGII_PIC_MAX];
	struct ZOGII_Larva Larva[ZOGII_PIC_MAX];
	struct ZOGII_Pupa Pupa[ZOGII_PIC_MAX];
	struct ZOGII_Ovum Ovum[ZOGII_PIC_MAX];
};

//ư���
struct ZOGII_Coccinellidae_NAME
{
	struct ZOGII_Coccinellidae_DATA NA;

	unsigned int SpTotal;
	struct ZOGII_Coccinellidae_DATA *SpData;
};

//ư���
struct ZOGII_Coccinellidae_GENUS
{
	struct ZOGII_Coccinellidae_DATA GE;

	unsigned int NameTotal;
	struct ZOGII_Coccinellidae_NAME *NameData;
};

//ư���
struct ZOGII_Coccinellidae_SUBFamily
{
	struct ZOGII_Coccinellidae_DATA SF;

	unsigned int GenusTotal;
	struct ZOGII_Coccinellidae_GENUS *GenusData;
};


#pragma pack()

unsigned long int zogiiVersionDB(void);

int zogiiReadDB(unsigned int *total,struct ZOGII_Coccinellidae_SUBFamily *&data,	\
				unsigned long int *pictotal,struct ZOGII_Pic *&picdata);
int zogiiWriteDB(unsigned int total,struct ZOGII_Coccinellidae_SUBFamily *&data,	\
				 unsigned long int pictotal,struct ZOGII_Pic *&picdata);
void zogiiFreeDB(unsigned int *total,struct ZOGII_Coccinellidae_SUBFamily *&data,	\
				  unsigned long int *pictotal,struct ZOGII_Pic *&picdata);

unsigned int zogiiCodeGen(unsigned int *total,struct ZOGII_Coccinellidae_SUBFamily *&data,	\
					unsigned char type,unsigned int sf,unsigned int ge,unsigned int na);

void zogiiAddSaveDB(unsigned int *total,struct ZOGII_Coccinellidae_SUBFamily *&data,	\
				unsigned long int *pictotal,struct ZOGII_Pic *&picdata,	\
				unsigned char type,unsigned int sf,unsigned int ge,unsigned int na,	unsigned int sp,	\
				struct ZOGII_Coccinellidae_DATA *newdata,	\
				unsigned char NewPictotal,struct ZOGII_Pic *NewPicdata);

void zogiiDeleteDB(unsigned int *total,struct ZOGII_Coccinellidae_SUBFamily *&data,	\
			   unsigned char type,unsigned int sf,unsigned int ge,unsigned int na,unsigned int sp,	\
			   struct ZOGII_Pic *&picdata);

void zogiiADDpicDB(struct ZOGII_Coccinellidae_DATA *data,	\
				unsigned long int *pictotal,struct ZOGII_Pic *&picdata,	\
				struct ZOGII_Coccinellidae_DATA *newdata,	\
				unsigned char NewPictotal,struct ZOGII_Pic *NewPicdata);

void zogiiDeletepicDB(struct ZOGII_Coccinellidae_DATA *data,struct ZOGII_Pic *&picdata);
unsigned long int zogiiADDpicDBLite(unsigned long int *pictotal,struct ZOGII_Pic *&picdata,	\
								struct ZOGII_Pic *newpic);
unsigned long int zogiiDeletepicDBLite(unsigned long int i,struct ZOGII_Pic *&picdata);



#endif