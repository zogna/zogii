#ifndef _ZOGII_DB_H_
#define _ZOGII_DB_H_

#include "stdio.h"

//最大路径长度
#define ZOGII_PAT_MAX 260 
//最大字符串长度
#define ZOGII_STR_MAX 128 
//最大语言种类
#define ZOGII_LAG_MAX 3
//最大含有颜色数
#define ZOGII_COR_MAX 4
//最大图片数
#define ZOGII_PIC_MAX 12
//最大别名数
#define ZOGII_INF_MAX 7
//	CreateDirectory(temppath, NULL);
#define ZOGII_DB_DIRSTR "zogcidb"
#define ZOGII_DB_FILSTR "zogci.db"
/* 
//颜色表
// -1=无效
// 0 =柠檬黄
// 1 =橙黄
// 2 =红
// 3 =蓝
// 4 =绿
// 5 =黑
// 6 =白
// 7 =杏
// 8 =褐
// 9 =银灰
*/

//数据类型 TYPE
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
	// 1=数据有效 0=数据无效
	unsigned char flag;
	//图片目录
	char Path[ZOGII_PAT_MAX];
	//图片作者来源
	char Info[ZOGII_STR_MAX];
};

//成虫
struct ZOGII_Imago
{
	//当前类型
	// -1=无效
	// 0 =未知
	// 1 =雄
	// 2 =雌
	char Sex;
	//颜色总数 0-9
	// -1=无效
	//0 =该结构体为无效数据
	//1-9 有效数据 
	char ColorNum;
	//含有颜色 见颜色表
	char Color[ZOGII_COR_MAX];
	// -1=无效
	// 0 =无绒毛
	// 1 =有绒毛
	char Villus; 
	//纹理
	// -1=无效
	// 0 =无
	// 1 =条纹
	// 2 =斑点
	// 3 =斑点+条纹
	char Texture; 
	//图片索引值 0为无效
	unsigned long int Pic;
};

//幼虫
struct ZOGII_Larva
{
	//当前类型
	// -1=无效
	// 0 =未知
	// 1 =雄
	// 2 =雌
	char Sex;
	//颜色总数 0-9
	// -1=无效
	//0 =该结构体为无效数据
	//1-9 有效数据 
	char ColorNum;
	//含有颜色 见颜色表
	char Color[ZOGII_COR_MAX];
	//棘刺
	// -1=无效
	// 0 =常规
	// 1 =毛状
	// 2 =长刺
	char Calthrop;
	//龄期
	// -1=无效
	// 0 =一龄
	// 1 =二龄
	// 2 =三龄
	// 3 =四龄
	char Instar;
	//图片索引值 0为无效
	unsigned long int Pic;
};
//卵
struct ZOGII_Ovum
{
	//当前类型
	//-1=无效
	// 0 =未知
	// 1 =雄
	// 2 =雌
	char Sex;
	//含有颜色 见颜色表
	char Color;
	//图片索引值 0为无效
	unsigned long int Pic;
};

//蛹
struct ZOGII_Pupa
{
	//当前类型
	// -1 无效值
	// 0 =未知
	// 1 =雄
	// 2 =雌
	char Sex;
	//颜色总数 0-9
	//-1无效
	//0 =该结构体为无效数据
	//1-9 有效数据 
	char ColorNum;
	//含有颜色 见颜色表
	char Color[ZOGII_COR_MAX];
	//图片索引值 0为无效
	unsigned long int Pic;
};

//瓢虫科
struct ZOGII_Coccinellidae_DATA
{
	//本体编号
	unsigned int code;
	//根据本体编号赋予的唯一文件夹
	char path[ZOGII_PAT_MAX];
	//最后更新时间 YY MM DD
	char year;
	char month;
	char day;
///////////////////////////////////////////////////
	//ZOGII_LAG_MAX 种语言 
	// 0 =英语 拉丁 
	// 1 =中文简体
	// 2 =中文繁体	
	//亚科名	
	char SubFamily[ZOGII_LAG_MAX][ZOGII_STR_MAX];
	//属名	
	char Genus[ZOGII_LAG_MAX][ZOGII_STR_MAX];
	//种名	
	char Name[ZOGII_LAG_MAX][ZOGII_STR_MAX];	
	//变种名	
	char SpName[ZOGII_LAG_MAX][ZOGII_STR_MAX];
	//详细信息 目录
	char Text[ZOGII_LAG_MAX][ZOGII_PAT_MAX];
///////////////////////////////////////////////////
	//别名
	char OtherName[ZOGII_INF_MAX][ZOGII_STR_MAX];
	//食物
	//-1 无效
	// 0 =肉食
	// 1 =菌食
	// 2 =植食
	char FoodType;	
	//食物名称 6条
	char FoodName[ZOGII_INF_MAX][ZOGII_STR_MAX];
///////////////////////////////////////////////////
	//发现地地图 0为无效
	unsigned long int DiscoverMap;
	//命名者名称 年份
	char DiscoverName[ZOGII_STR_MAX];
///////////////////////////////////////////////////
	struct ZOGII_Imago Imago[ZOGII_PIC_MAX];
	struct ZOGII_Larva Larva[ZOGII_PIC_MAX];
	struct ZOGII_Pupa Pupa[ZOGII_PIC_MAX];
	struct ZOGII_Ovum Ovum[ZOGII_PIC_MAX];
};

//瓢虫科
struct ZOGII_Coccinellidae_NAME
{
	struct ZOGII_Coccinellidae_DATA NA;

	unsigned int SpTotal;
	struct ZOGII_Coccinellidae_DATA *SpData;
};

//瓢虫科
struct ZOGII_Coccinellidae_GENUS
{
	struct ZOGII_Coccinellidae_DATA GE;

	unsigned int NameTotal;
	struct ZOGII_Coccinellidae_NAME *NameData;
};

//瓢虫科
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