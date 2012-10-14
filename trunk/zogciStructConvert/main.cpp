#include "zogiidb.h"

ZOGII_ULONG_TYPE total=0;
struct ZOGII_Coccinellidae_SUBFamily *data=NULL;
				
ZOGII_ULONG_TYPE pictotal=0;
struct ZOGII_Pic *picdata=NULL;
	char CurrentDir[ZOGII_PAT_MAX];



struct ZOGII_Pic_NEW *picdataNEW=NULL;


int main(void)
{
	GetCurrentDirectory(ZOGII_PAT_MAX,CurrentDir);
	zogiiSetDirectory(CurrentDir);

	zogiiReadDB(&total,data,&pictotal,picdata);
	
	picdataNEW=(struct ZOGII_Pic_NEW *)calloc(pictotal,sizeof(struct ZOGII_Pic_NEW));

	for(ZOGII_ULONG_TYPE i=0;i<pictotal;i++)
	{
		picdataNEW[i].flag=picdata[i].flag;
		memcpy(	picdataNEW[i].Path,picdata[i].Path,ZOGII_PAT_MAX);
		memcpy(	picdataNEW[i].Info,picdata[i].Info,ZOGII_STR_MAX);
	}
	
zogiiWriteNEWDB(total,data,pictotal,picdataNEW);
	
return 0;
}