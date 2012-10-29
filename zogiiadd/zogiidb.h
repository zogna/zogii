#ifndef _ZOGII_DB_H_
#define _ZOGII_DB_H_

#include "stdio.h"
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
#define ZOGII_EXP_SIZ 824
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

//最大食物名数
#define ZOGII_FOODINF_MAX 4
//最大栖息地名数
#define ZOGII_LIVIINF_MAX 3
//最大发现地地名
#define ZOGII_DISCOVERY_MAX 24

//最大图片数
#define ZOGII_ALL_PIC (ZOGII_PIC_MAX*5)
// 0-11为Imago 
// 12-23为Larva
// 24-35为Pupa
// 36-47为Ovum
#define ZOGII_ALL_PIC_Imago_START	(0)
#define ZOGII_ALL_PIC_Larva_START	(ZOGII_PIC_MAX)
#define ZOGII_ALL_PIC_Pupa_START	(ZOGII_PIC_MAX*2)
#define ZOGII_ALL_PIC_Ovum_START	(ZOGII_PIC_MAX*3)
#define ZOGII_ALL_PIC_Closeup_START	(ZOGII_PIC_MAX*4)

////DB目录
#define ZOGII_DB_DIRSTR "zogcidb"
#define ZOGII_DB_FILSTR "zogci.db"
/* 
//颜色表
// -1=无效
// 0=无
// 1 =柠檬黄
// 2 =橙黄
// 3 =红
// 4 =蓝
// 5 =绿
// 6 =黑
// 7 =白
// 8 =杏
// 9 =褐
// 10 =银灰
// 11 =紫红
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

struct ZOGII_Pic
{
	// 0=数据无效
	// 1=数据有效
	unsigned char flag;
	//图片目录
	char Path[ZOGII_PAT_MAX];
	//图片作者来源
	char Info[ZOGII_PAT_MAX];
};

//成虫 扩展
struct ZOGII_Imago_2EX
{
	//////////////////////////鞘翅
	//斑点数 0-50
	char ElytraPointNum; 
	//////////////////////////前胸背板
	//颜色总数 0-9
	// -1=无效
	//0 =该结构体为无效数据
	//1-9 有效数据 
	char PronotumColorNum;
	//含有颜色 见颜色表
	char PronotumColor[ZOGII_COR_MAX];
	//斑纹
	// -1=无效
	// 0 =无
	// 1 =条纹
	// 2 =斑点
	// 3 =斑点+条纹
	char PronotumTexture; 
	//斑点数 0-50
	char PronotumPointNum; 
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
	char ElytraColorNum;
	//含有颜色 见颜色表
	char ElytraColor[ZOGII_COR_MAX];

	// -1=无效
	// 0 =无绒毛
	// 1 =有绒毛
//	char Villus; 
	//扩展
	char Expand; 
	//斑纹
	// -1=无效
	// 0 =无
	// 1 =条纹
	// 2 =斑点
	// 3 =斑点+条纹
	char ElytraTexture; 

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

//蛹扩展
struct ZOGII_Pupa_2EX
{
	//当前类型
	// -1 无效值
	// 0 =未知
	// 1 =前蛹
	// 2 =蛹
	// 3 =蛹壳
	char Type;
};

//特写
struct ZOGII_CloseUp
{
	//当前类型
	//-1=无效
	// 0=腹部
	// 1=头部
	// 2=交尾
	// 3=越冬
	// 4=羽化中
	// 5=展翅
	// 6=栖息环境
	char Type;
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
	//食物名称 4条
	char FoodName[ZOGII_FOODINF_MAX][ZOGII_STR_MAX];
	//栖息地
	char LivingName[ZOGII_LIVIINF_MAX][ZOGII_STR_MAX];
///////////////////////////////////////////////////
	char Expand2ex[4];
	//命名者名称 年份
	char DiscoverName[ZOGII_STR_MAX];
///////////////////////////////////////////////////
	struct ZOGII_Imago Imago[ZOGII_PIC_MAX];
	struct ZOGII_Larva Larva[ZOGII_PIC_MAX];
	struct ZOGII_Pupa Pupa[ZOGII_PIC_MAX];
	struct ZOGII_Ovum Ovum[ZOGII_PIC_MAX];

	//使用扩展
	struct ZOGII_Imago_2EX Imago2ex[ZOGII_PIC_MAX];
	struct ZOGII_Pupa_2EX Pupa2ex[ZOGII_PIC_MAX];

	// -1=无效
	// 0=未知
	// 1=3mm以下
	// 2=2mm-4mm
	// 3=3mm-5mm
	// 4=4mm-6mm
	// 5=5mm-7mm
	// 6=6mm-8mm
	// 7=7mm-9mm
	// 8=8mm以上
	char Size;
	// -1=无效
	// 0=未知
	// 1=山地
	// 2=农田
	// 3=森林
	char Living;
	// -1=无效
	// 0=未知
	// 1=趋光
	// 2=不趋光
	char Light;

	// -1=无效
	// 0=未知
	// 1=越冬
	// 2=不越冬
	char OverWintering;
	// -1=无效
	// 0=未知
	// 1=起始月份 1月
	// ..
	// 12=起始月份 12月
	char StartMonth;
	// -1=无效
	// 0=未知
	// 1=结束月份 1月
	// ..
	// 12=结束月份 12月
	char EndMonth;
	//腹部颜色
	char ImagobellyColor;
	// -1=无效
	// 0 =无绒毛
	// 1 =有绒毛
	char ImagoVillus; 
	//特写
	struct ZOGII_CloseUp Closeup[ZOGII_PIC_MAX];
	//发现地地名
	char DiscoverMapList[ZOGII_DISCOVERY_MAX];

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
0 = 未知
1 = 中国
2 = 中国-台湾
3 = 中国-福建
4 = 中国-云南
5 = 中国-贵州
6 = 中国-湖南
7 = 中国-湖北
8 = 中国-河南
9 = 中国-河北
10 = 中国-广东
11 = 中国-广西
12 = 中国-海南
13 = 中国-安徽
14 = 中国-浙江
15 = 中国-江西
16 = 中国-西藏
17 = 中国-新疆
18 = 中国-北京
19 = 中国-香港
20 = 中国-陕西
21 = 中国-四川
22 = 中国-吉林
23 = 中国-辽宁
24 = 中国-山东
25 = 中国-山西
26 = 中国-上海
27 = 中国-江苏
28 = 中国-甘肃
29 = 中国-青海
30 = 中国-黑龙江
31 = 中国-内蒙古
32 = 朝鲜
33 = 蒙古
34 = 伊朗
35 = 沙特阿拉伯
36 = 缅甸
37 = 越南
38 = 韩国
39 = 日本
40 = 日本-琉球群岛
41 = 印度
42 = 印度-锡金
43 = 尼泊尔
44 = 斯里兰卡
45 = 泰国
46 = 菲律宾
47 = 马来西亚
48 = 英国
49 = 老挝
50 = 新加坡
51 = 克什米尔地区
52 = 印度尼西亚
53 = 西班牙
54 = 埃及
55 = 密克罗尼西亚
56 = 法国
57 = 高加索地区
58 = 西伯利亚地区
59 = 西伯利亚东南部
60 = 澳大利亚
61 = 新西兰
62 = 美国-阿拉斯加
63 = 美国-夏威夷
64 = 美国
65 = 西印度群岛
66 = 也门
67 = 不丹
68 = 巴基斯坦
69 = 孟加拉
70 = 东亚
71 = 俄罗斯
72 = 柬埔寨
73 = 阿富汗
74 = 阿拉伯半岛
75 = 哈萨克斯坦
76 = 新几内亚
77 = 北美
78 = 中亚
79 = 亚洲
80 = 欧洲
81 = 非洲
82 = 地中海地区
*/