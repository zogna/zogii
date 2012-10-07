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
#define ZOGII_INF_MAX 6
/* 
//��ɫ��
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

#pragma pack(1)

struct ZOGII_Pic
{
	//ͼƬĿ¼
	char Path[ZOGII_PAT_MAX];
	//ͼƬ������Դ
	char Info[ZOGII_STR_MAX];
};

//�ɳ�
struct ZOGII_Imago
{
	//��ǰ����
	// 0 =δ֪
	// 1 =��
	// 2 =��
	unsigned char Sex;
	//��ɫ���� 0-9
	//0 =�ýṹ��Ϊ��Ч����
	//1-9 ��Ч���� 
	unsigned char ColorNum;
	//������ɫ ����ɫ��
	unsigned char Color[ZOGII_COR_MAX];
	// 0 =����ë
	// 1 =����ë
	unsigned char Villus; 
	//����
	// 0 =��
	// 1 =����
	// 2 =�ߵ�
	// 3 =�ߵ�+����
	unsigned char Texture; 
	//ͼƬ
	struct ZOGII_Pic Pic;
};

//�׳�
struct ZOGII_Larva
{
	//��ǰ����
	// 0 =δ֪
	// 1 =��
	// 2 =��
	unsigned char Sex;
	//��ɫ���� 0-9
	//0 =�ýṹ��Ϊ��Ч����
	//1-9 ��Ч���� 
	unsigned char ColorNum;
	//������ɫ ����ɫ��
	unsigned char Color[ZOGII_COR_MAX];
	//����
	// 0 =����
	// 1 =ë״
	// 2 =����
	unsigned char Calthrop;
	//����
	// 0 =һ��
	// 1 =����
	// 2 =����
	// 3 =����
	unsigned char Instar;
	//ͼƬ
	struct ZOGII_Pic Pic;
};
//��
struct ZOGII_Ovum
{
	//��ǰ����
	// 0 =δ֪
	// 1 =��
	// 2 =��
	unsigned char Sex;
	//������ɫ ����ɫ��
	unsigned char Color;
	//ͼƬ
	struct ZOGII_Pic Pic;
};

//Ӽ
struct ZOGII_Pupa
{
	//��ǰ����
	// 0 =δ֪
	// 1 =��
	// 2 =��
	unsigned char Sex;
	//��ɫ���� 0-9
	//0 =�ýṹ��Ϊ��Ч����
	//1-9 ��Ч���� 
	unsigned char ColorNum;
	//������ɫ ����ɫ��
	unsigned char Color[ZOGII_COR_MAX];
	//ͼƬ
	struct ZOGII_Pic Pic;
};

//ư���
struct ZOGII_Coccinellidae_DATA
{
	//�ڲ���� 
	// AB CDE FGHI JK(����)	
	// AB(ǰ��λ����) �ǿ�
	// CDE ��
	// FGHI �� 
	// JK ����
	unsigned long int Code;
	//������ʱ�� YY MM DD
	unsigned char year;
	unsigned char month;
	unsigned char day;
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
	// 0 =��ʳ
	// 1 =��ʳ
	// 2 =ֲʳ
	unsigned char FoodType;	
	//ʳ������ 6��
	char FoodName[ZOGII_INF_MAX][ZOGII_STR_MAX];
///////////////////////////////////////////////////
	//���ֵص�ͼ
	struct ZOGII_Pic DiscoverMap;
	//���������� ���
	char DiscoverName[ZOGII_STR_MAX];
///////////////////////////////////////////////////
	//��ǰ���� 0���߸���
	unsigned char ImagoNum;
	struct ZOGII_Imago Imago[ZOGII_PIC_MAX];

	unsigned char LarvaNum;
	struct ZOGII_Larva Larva[ZOGII_PIC_MAX];

	unsigned char PupaNum;
	struct ZOGII_Pupa Pupa[ZOGII_PIC_MAX];

	unsigned char OvumNum;
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

int zogiiReadDB(unsigned int *total,struct ZOGII_Coccinellidae_SUBFamily *data);
int zogiiWriteDB(unsigned int *total,struct ZOGII_Coccinellidae_SUBFamily *data);
void zogiiFreeDB(unsigned int *total,struct ZOGII_Coccinellidae_SUBFamily *data);
void zogiiAddDB(struct ZOGII_Coccinellidae_SUBFamily *data,unsigned int *total,	\
			   unsigned char type,unsigned int sf,unsigned int ge,unsigned int na,	\
				struct ZOGII_Coccinellidae_DATA *newdata);
void zogiiDeleteDB(struct ZOGII_Coccinellidae_SUBFamily *data,unsigned int *total,	\
			  unsigned char type,unsigned int sf,unsigned int ge,unsigned int na,unsigned int sp);


#endif