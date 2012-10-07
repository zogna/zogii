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
#define ZOGII_INF_MAX 6
/* 
//颜色表
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

#pragma pack(1)

struct ZOGII_Pic
{
	//图片目录
	char Path[ZOGII_PAT_MAX];
	//图片作者来源
	char Info[ZOGII_STR_MAX];
};

//成虫
struct ZOGII_Imago
{
	//当前类型
	// 0 =未知
	// 1 =雄
	// 2 =雌
	unsigned char Sex;
	//颜色总数 0-9
	//0 =该结构体为无效数据
	//1-9 有效数据 
	unsigned char ColorNum;
	//含有颜色 见颜色表
	unsigned char Color[ZOGII_COR_MAX];
	// 0 =无绒毛
	// 1 =有绒毛
	unsigned char Villus; 
	//纹理
	// 0 =无
	// 1 =条纹
	// 2 =斑点
	// 3 =斑点+条纹
	unsigned char Texture; 
	//图片
	struct ZOGII_Pic Pic;
};

//幼虫
struct ZOGII_Larva
{
	//当前类型
	// 0 =未知
	// 1 =雄
	// 2 =雌
	unsigned char Sex;
	//颜色总数 0-9
	//0 =该结构体为无效数据
	//1-9 有效数据 
	unsigned char ColorNum;
	//含有颜色 见颜色表
	unsigned char Color[ZOGII_COR_MAX];
	//棘刺
	// 0 =常规
	// 1 =毛状
	// 2 =长刺
	unsigned char Calthrop;
	//龄期
	// 0 =一龄
	// 1 =二龄
	// 2 =三龄
	// 3 =四龄
	unsigned char Instar;
	//图片
	struct ZOGII_Pic Pic;
};
//卵
struct ZOGII_Ovum
{
	//当前类型
	// 0 =未知
	// 1 =雄
	// 2 =雌
	unsigned char Sex;
	//含有颜色 见颜色表
	unsigned char Color;
	//图片
	struct ZOGII_Pic Pic;
};

//蛹
struct ZOGII_Pupa
{
	//当前类型
	// 0 =未知
	// 1 =雄
	// 2 =雌
	unsigned char Sex;
	//颜色总数 0-9
	//0 =该结构体为无效数据
	//1-9 有效数据 
	unsigned char ColorNum;
	//含有颜色 见颜色表
	unsigned char Color[ZOGII_COR_MAX];
	//图片
	struct ZOGII_Pic Pic;
};

//瓢虫科
struct ZOGII_Coccinellidae_DATA
{
	//内部编号 
	// AB CDE FGHI JK(数字)	
	// AB(前两位数字) 亚科
	// CDE 属
	// FGHI 种 
	// JK 变种
	unsigned long int Code;
	//最后更新时间 YY MM DD
	unsigned char year;
	unsigned char month;
	unsigned char day;
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
	// 0 =肉食
	// 1 =菌食
	// 2 =植食
	unsigned char FoodType;	
	//食物名称 6条
	char FoodName[ZOGII_INF_MAX][ZOGII_STR_MAX];
///////////////////////////////////////////////////
	//发现地地图
	struct ZOGII_Pic DiscoverMap;
	//命名者名称 年份
	char DiscoverName[ZOGII_STR_MAX];
///////////////////////////////////////////////////
	//当前张数 0或者更多
	unsigned char ImagoNum;
	struct ZOGII_Imago Imago[ZOGII_PIC_MAX];

	unsigned char LarvaNum;
	struct ZOGII_Larva Larva[ZOGII_PIC_MAX];

	unsigned char PupaNum;
	struct ZOGII_Pupa Pupa[ZOGII_PIC_MAX];

	unsigned char OvumNum;
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

int zogiiReadDB(unsigned int *total,struct ZOGII_Coccinellidae_SUBFamily *data);
int zogiiWriteDB(unsigned int *total,struct ZOGII_Coccinellidae_SUBFamily *data);
void zogiiFreeDB(unsigned int *total,struct ZOGII_Coccinellidae_SUBFamily *data);
void zogiiAddDB(struct ZOGII_Coccinellidae_SUBFamily *data,unsigned int *total,	\
			   unsigned char type,unsigned int sf,unsigned int ge,unsigned int na,	\
				struct ZOGII_Coccinellidae_DATA *newdata);
void zogiiDeleteDB(struct ZOGII_Coccinellidae_SUBFamily *data,unsigned int *total,	\
			  unsigned char type,unsigned int sf,unsigned int ge,unsigned int na,unsigned int sp);


#endif