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

//最大路径长度
#define ZOGII_PAT_MAX 260 
//最大字符串长度
#define ZOGII_STR_MAX 128 
//最大语言种类
#define ZOGII_LAG_MAX 3
//最大含有颜色数
#define ZOGII_COR_MAX 4
//最大别名数
#define ZOGII_INF_MAX 7

//最大食物名数
#define ZOGII_FOODINF_MAX 4
//最大栖息地名数
#define ZOGII_LIVIINF_MAX 3
//最大发现地地名
#define ZOGII_DISCOVERY_MAX 256

//最大图片数
#define ZOGII_PIC_Imago_MAX		512
#define ZOGII_PIC_Larva_MAX		256
#define ZOGII_PIC_Pupa_MAX		256	
#define ZOGII_PIC_Ovum_MAX		128	
#define ZOGII_PIC_Closeup_MAX	512

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
// 12 =金黄
// 13= 深红褐
*/

//数据类型 TYPE
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

//成虫
struct ZOGII_Imago
{
	//当前类型
	// -1=无效
	// 0 =未知
	// 1 =雄
	// 2 =雌
	char Sex;
	//////////////////////////鞘翅
	//颜色总数 0-9
	// -1=无效
	//0 =该结构体为无效数据
	//1-9 有效数据 
	char ElytraColorNum;
	//含有颜色 见颜色表
	char ElytraColor[ZOGII_COR_MAX];
	//斑纹
	// -1=无效
	// 0 =无
	// 1 =条纹
	// 2 =斑点
	// 3 =斑点+条纹
	char ElytraTexture; 
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

	// 0=数据无效
	// 1=数据有效
	unsigned char flag;
	//图片目录
	char Path[ZOGII_PAT_MAX];
	//图片作者来源
	char Info[ZOGII_PAT_MAX];
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
	// 0=常规
	// 1=全毛
	// 2=枝刺
	// 3=扁平
	// 4=半毛
	// 5=无毛
	// 6=小刺
	char Calthrop;
	//龄期
	// -1=无效
	// 0 =未知
	// 1 =一龄
	// 2 =二龄
	// 3 =三龄
	// 4 =四龄
	char Instar;
	// 0=数据无效
	// 1=数据有效
	unsigned char flag;
	//图片目录
	char Path[ZOGII_PAT_MAX];
	//图片作者来源
	char Info[ZOGII_PAT_MAX];
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
	// 0=数据无效
	// 1=数据有效
	unsigned char flag;
	//图片目录
	char Path[ZOGII_PAT_MAX];
	//图片作者来源
	char Info[ZOGII_PAT_MAX];
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
	//当前类型
	// -1 无效值
	// 0=未知
	// 1=前蛹
	// 2=蛹-常规
	// 3=蛹-全毛
	// 4=蛹-硬刺
	// 5=蛹-软刺
	// 6=蛹壳
	char Type;
	//颜色总数 0-9
	//-1无效
	//0 =该结构体为无效数据
	//1-9 有效数据 
	char ColorNum;
	//含有颜色 见颜色表
	char Color[ZOGII_COR_MAX];
	// 0=数据无效
	// 1=数据有效
	unsigned char flag;
	//图片目录
	char Path[ZOGII_PAT_MAX];
	//图片作者来源
	char Info[ZOGII_PAT_MAX];
};

//特写
struct ZOGII_Closeup
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
	// 7=进食
	// 8=尾部
	// 9=侧面
	// 10=地图
	// 11=器官
	char Type;
	// 0=数据无效
	// 1=数据有效
	unsigned char flag;
	//图片目录
	char Path[ZOGII_PAT_MAX];
	//图片作者来源
	char Info[ZOGII_PAT_MAX];
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
	char Species[ZOGII_LAG_MAX][ZOGII_STR_MAX];	
	//变种名	
	char Subspecies[ZOGII_LAG_MAX][ZOGII_STR_MAX];
	//详细信息 目录
	char Text[ZOGII_LAG_MAX][ZOGII_PAT_MAX];
///////////////////////////////////////////////////
	//别名
	char Synonyms[ZOGII_INF_MAX][ZOGII_STR_MAX];
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

	//命名者名称 年份
	char DiscoverName[ZOGII_STR_MAX];

	//发现地地名
	unsigned char DiscoverMapTotal;
	unsigned char DiscoverMapList[ZOGII_DISCOVERY_MAX];

	// -1=无效
	//毫米mm
	char MinSize;
	char MaxSize;
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
	//胸部颜色
	char ImagochestColor;
	//腹部颜色
	char ImagobellyColor;
	// -1=无效
	// 0 =无绒毛
	// 1 =有绒毛
	char ImagoVillus; 
	//外形
	// -1=无效
	// 0=未知
	// 1=圆形
	// 2=椭圆
	// 3=长形
	char  Contour;
	//数据索引值 0为无效
	ZOGII_ULONG_TYPE Imago[ZOGII_PIC_Imago_MAX];
	ZOGII_ULONG_TYPE Larva[ZOGII_PIC_Larva_MAX];
	ZOGII_ULONG_TYPE Pupa[ZOGII_PIC_Pupa_MAX];
	ZOGII_ULONG_TYPE Ovum[ZOGII_PIC_Ovum_MAX];
	ZOGII_ULONG_TYPE Closeup[ZOGII_PIC_Closeup_MAX];

};

//瓢虫科种
struct ZOGII_Coccinellidae_SPECIES
{
	struct ZOGII_Coccinellidae_DATA SP;

	ZOGII_ULONG_TYPE SubspTotal;
	struct ZOGII_Coccinellidae_DATA *SubspData;
};

//瓢虫科属
struct ZOGII_Coccinellidae_GENUS
{
	struct ZOGII_Coccinellidae_DATA GE;

	ZOGII_ULONG_TYPE SpeciesTotal;
	struct ZOGII_Coccinellidae_SPECIES *SpeciesData;
};

//瓢虫科亚科
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

