#ifndef _ZOGII_DB_H_
#define _ZOGII_DB_H_

#include "stdio.h"
#include "windows.h"
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#if 0

//跨64位 32位机器 WINDOWS 
// 8字节
typedef __int64 ZOGII_LONG_TYPE;
typedef unsigned __int64 ZOGII_ULONG_TYPE;

#else
// 4字节
typedef __int32 ZOGII_LONG_TYPE;
typedef unsigned __int32 ZOGII_ULONG_TYPE;

#endif

//结构体剩余扩展容量
#define ZOGII_EXP_SIZ 1024
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
//最大图片数
#define ZOGII_ALL_PIC (ZOGII_PIC_MAX*4+1)
// 0-11为Imago 
// 12-23为Larva
// 24-35为Pupa
// 36-47为Ovum
// 48 为MAP
#define ZOGII_ALL_PIC_Imago_START	(0)
#define ZOGII_ALL_PIC_Larva_START	(ZOGII_PIC_MAX)
#define ZOGII_ALL_PIC_Pupa_START	(ZOGII_PIC_MAX*2)
#define ZOGII_ALL_PIC_Ovum_START	(ZOGII_PIC_MAX*3)
#define ZOGII_ALL_PIC_Map_START		(ZOGII_PIC_MAX*4)

////DB目录
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
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#pragma pack(1)

struct ZOGII_Pic_NEW
{
	// 0=数据无效
	// 1=数据有效
	unsigned char flag;
	//图片目录
	char Path[ZOGII_PAT_MAX];
	//图片作者来源
	char Info[ZOGII_PAT_MAX];
};
#pragma pack()


#pragma pack(1)

struct ZOGII_Pic
{
	// 0=数据无效
	// 1=数据有效
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
	ZOGII_ULONG_TYPE Pic;
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
	// 0 =未知
	// 1 =一龄
	// 2 =二龄
	// 3 =三龄
	// 4 =四龄
	char Instar;
	//图片索引值 0为无效
	ZOGII_ULONG_TYPE Pic;
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
	ZOGII_ULONG_TYPE Pic;
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
	ZOGII_ULONG_TYPE Pic;
};

//瓢虫科
struct ZOGII_Coccinellidae_DATA
{
	//本体编号
	ZOGII_ULONG_TYPE code;
	//根据本体编号赋予的唯一文件夹
	char Path[ZOGII_PAT_MAX];
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
	ZOGII_ULONG_TYPE DiscoverMap;
	//命名者名称 年份
	char DiscoverName[ZOGII_STR_MAX];
///////////////////////////////////////////////////
	struct ZOGII_Imago Imago[ZOGII_PIC_MAX];
	struct ZOGII_Larva Larva[ZOGII_PIC_MAX];
	struct ZOGII_Pupa Pupa[ZOGII_PIC_MAX];
	struct ZOGII_Ovum Ovum[ZOGII_PIC_MAX];

	//扩展容量 为了以后更新
	char Expand[ZOGII_EXP_SIZ];
};

//瓢虫科
struct ZOGII_Coccinellidae_NAME
{
	struct ZOGII_Coccinellidae_DATA NA;

	ZOGII_ULONG_TYPE SpTotal;
	struct ZOGII_Coccinellidae_DATA *SpData;
};

//瓢虫科
struct ZOGII_Coccinellidae_GENUS
{
	struct ZOGII_Coccinellidae_DATA GE;

	ZOGII_ULONG_TYPE NameTotal;
	struct ZOGII_Coccinellidae_NAME *NameData;
};

//瓢虫科
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
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
ZOGII_ULONG_TYPE zogiiCodeGen(ZOGII_ULONG_TYPE *total,struct ZOGII_Coccinellidae_SUBFamily *&data,	\
					unsigned char type,ZOGII_ULONG_TYPE sf,ZOGII_ULONG_TYPE ge,ZOGII_ULONG_TYPE na);

void zogiiTEMPSaveDB(struct ZOGII_Coccinellidae_DATA *data,	\
					ZOGII_ULONG_TYPE *tempDiscoverMap,	\
					ZOGII_ULONG_TYPE *Imagopic,	\
					ZOGII_ULONG_TYPE *Larvapic,	\
					ZOGII_ULONG_TYPE *Pupapic,	\
					ZOGII_ULONG_TYPE *Ovumpic,	\
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
				struct ZOGII_Pic *NewPicdata,
				ZOGII_ULONG_TYPE tempDiscoverMap,	\
				ZOGII_ULONG_TYPE *Imagopic,	\
				ZOGII_ULONG_TYPE *Larvapic,	\
				ZOGII_ULONG_TYPE *Pupapic,	\
				ZOGII_ULONG_TYPE *Ovumpic);

void zogiiDeletepicDB(struct ZOGII_Coccinellidae_DATA *data,struct ZOGII_Pic *&picdata);

void zogiiModifypicDBLite(struct ZOGII_Pic *pdata,struct ZOGII_Pic *newpic,char *path);

void zogiiInitpicDB(struct ZOGII_Coccinellidae_DATA *data);
ZOGII_ULONG_TYPE zogiiADDpicDBLite(ZOGII_ULONG_TYPE *pictotal,struct ZOGII_Pic *&picdata,	\
									char *Path,struct ZOGII_Pic *newpic);
ZOGII_ULONG_TYPE zogiiDeletepicDBLite(ZOGII_ULONG_TYPE i,struct ZOGII_Pic *&picdata);



int zogiiWriteNEWDB(ZOGII_ULONG_TYPE total,struct ZOGII_Coccinellidae_SUBFamily *&data,	\
				 ZOGII_ULONG_TYPE pictotal,struct ZOGII_Pic_NEW *&picdataNEW);
#endif