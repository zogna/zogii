#include "stdafx.h"
#include "zogiidb.h"

ZOGII_ULONG_TYPE zogii_version=0;

ZOGII_ULONG_TYPE zogiiVersionDB(void)
{
	return zogii_version;
}

char CurrentDirectory[ZOGII_PAT_MAX];

void zogiiSetDirectory(char *dir)
{
	memcpy(CurrentDirectory,dir,ZOGII_PAT_MAX);
}
//WIN32 拷贝文件
void zogiiCopyFile(char *src,char *dst)
{
	char temp[ZOGII_PAT_MAX];
	sprintf(temp,"%s\\%s",CurrentDirectory,dst);
	CopyFile(src,temp,FALSE);
}
//WIN32 删除文件
void zogiiDeleteFile(char *str)
{
	char temp[ZOGII_PAT_MAX];
	sprintf(temp,"%s\\%s",CurrentDirectory,str);
	DeleteFile(temp);
}	
//WIN32 创建目录
void zogiiCreateDirectory(char *str)
{
	char temp[ZOGII_PAT_MAX];
	sprintf(temp,"%s\\%s",CurrentDirectory,str);
	CreateDirectory(temp, NULL);
}
//WIN32 删除目录
void zogiiRemoveDirectory(char *str)
{
	char temp[ZOGII_PAT_MAX];
	sprintf(temp,"%s\\%s",CurrentDirectory,str);
	RemoveDirectory(temp);
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int zogiiReadDB(ZOGII_ULONG_TYPE *total,struct ZOGII_Coccinellidae_SUBFamily *&data,	\
				ZOGII_ULONG_TYPE *pictotal,struct ZOGII_Pic *&picdata)
{

	ZOGII_ULONG_TYPE i,j,k;

	FILE *fp;
	char str[ZOGII_PAT_MAX];
	sprintf(str,"%s\\%s\\%s",CurrentDirectory,ZOGII_DB_DIRSTR,ZOGII_DB_FILSTR);
	fp=fopen(str,"rb");
	if(fp)
	{
		fread(&zogii_version,sizeof(ZOGII_ULONG_TYPE),1,fp);
		fread(total,sizeof(ZOGII_ULONG_TYPE),1,fp);
		if(*total)
		{
			data=(struct ZOGII_Coccinellidae_SUBFamily *)calloc(*total,sizeof(struct ZOGII_Coccinellidae_SUBFamily));
			fread(data,sizeof(struct ZOGII_Coccinellidae_SUBFamily),*total,fp);
		}
		for(i=0;i<(*total);i++)
		{
			if(data[i].GenusTotal)
			{
				data[i].GenusData=(struct ZOGII_Coccinellidae_GENUS *)calloc(data[i].GenusTotal,	\
					sizeof(struct ZOGII_Coccinellidae_GENUS));
				fread(data[i].GenusData,sizeof(struct ZOGII_Coccinellidae_GENUS),data[i].GenusTotal,fp);

				for(j=0;j<data[i].GenusTotal;j++)
				{
					if(data[i].GenusData[j].NameTotal)
					{
						data[i].GenusData[j].NameData=(struct ZOGII_Coccinellidae_NAME *)calloc(data[i].GenusData[j].NameTotal,	\
							sizeof(struct ZOGII_Coccinellidae_NAME));
						fread(data[i].GenusData[j].NameData,sizeof(struct ZOGII_Coccinellidae_NAME),	\
							data[i].GenusData[j].NameTotal,fp);

						for(k=0;k<data[i].GenusData[j].NameTotal;k++)
						{
							if(data[i].GenusData[j].NameData[k].SpTotal)
							{
								data[i].GenusData[j].NameData[k].SpData=	\
									(struct ZOGII_Coccinellidae_DATA *)calloc(data[i].GenusData[j].NameData[k].SpTotal,	\
										sizeof(struct ZOGII_Coccinellidae_DATA));
								fread(data[i].GenusData[j].NameData[k].SpData, sizeof(struct ZOGII_Coccinellidae_DATA),	\
									data[i].GenusData[j].NameData[k].SpTotal,fp);
							}
						}
					}
				}
			}
		}
		//读图片索引 
		fread(pictotal,sizeof(ZOGII_ULONG_TYPE),1,fp);
		if(*pictotal)
		{
			picdata=(struct ZOGII_Pic *)calloc(*pictotal,sizeof(struct ZOGII_Pic));
			fread(picdata,sizeof(struct ZOGII_Pic),*pictotal,fp);
		}

		fclose(fp);
		return 1;
	}
	else
	{
		(*total)=0;
		data=NULL;
		//初始化第一个为无效
		(*pictotal)=1;
		picdata=(struct ZOGII_Pic *)calloc(*pictotal,sizeof(struct ZOGII_Pic));
		picdata[0].flag=0;		
		//创建根目录
		zogiiCreateDirectory(ZOGII_DB_DIRSTR);

		return 0;
	}
}

int zogiiWriteDB(ZOGII_ULONG_TYPE total,struct ZOGII_Coccinellidae_SUBFamily *&data,	\
				 ZOGII_ULONG_TYPE pictotal,struct ZOGII_Pic *&picdata)

{
	ZOGII_ULONG_TYPE i,j,k;

	FILE *fp;
	char str[ZOGII_PAT_MAX];
	sprintf(str,"%s\\%s\\%s",CurrentDirectory,ZOGII_DB_DIRSTR,ZOGII_DB_FILSTR);
	fp=fopen(str,"wb");
	if(fp)
	{
		//保存一次 版本+1次
		zogii_version++;
		fwrite(&zogii_version,sizeof(ZOGII_ULONG_TYPE),1,fp);
		fwrite(&total,sizeof(ZOGII_ULONG_TYPE),1,fp);

		if(total)
			fwrite(data,sizeof(struct ZOGII_Coccinellidae_SUBFamily),total,fp);

		for(i=0;i<total;i++)
		{
			if(data[i].GenusTotal)
			{
				fwrite(data[i].GenusData,sizeof(struct ZOGII_Coccinellidae_GENUS),data[i].GenusTotal,fp);
				for(j=0;j<data[i].GenusTotal;j++)
				{
					if(data[i].GenusData[j].NameTotal)
					{
						fwrite(data[i].GenusData[j].NameData,sizeof(struct ZOGII_Coccinellidae_NAME),	\
							data[i].GenusData[j].NameTotal,fp);
						for(k=0;k<data[i].GenusData[j].NameTotal;k++)
						{
							if(data[i].GenusData[j].NameData[k].SpTotal)
							{
								fwrite(data[i].GenusData[j].NameData[k].SpData, sizeof(struct ZOGII_Coccinellidae_DATA),	\
									data[i].GenusData[j].NameData[k].SpTotal,fp);
							}
						}
					}
				}
			}
		}
	
		fwrite(&pictotal,sizeof(ZOGII_ULONG_TYPE),1,fp);
		if(pictotal)
			fwrite(picdata,sizeof(struct ZOGII_Pic),pictotal,fp);

		fclose(fp);
		return 1;
	}
	return 0;
}
//编号生成器
ZOGII_ULONG_TYPE zogiiCodeGen(ZOGII_ULONG_TYPE *total,struct ZOGII_Coccinellidae_SUBFamily *&data,	\
					unsigned char type,ZOGII_ULONG_TYPE sf,ZOGII_ULONG_TYPE ge,ZOGII_ULONG_TYPE na)
{
	ZOGII_ULONG_TYPE i,j;
	ZOGII_ULONG_TYPE max=0;
	unsigned char flag=0;
	ZOGII_ULONG_TYPE t;

	if(TYPE_NEW_SubFamily == type)
	{
		t=*total;
		if(0==t)
			return 0;
		//先找最大编号
		for(i=0;i<t;i++)
		{
			if(data[i].SF.code>max)
				max=data[i].SF.code;
		}
		//遍历编号是否有缺
		for(j=0;j<max;j++)
		{
			flag=1;
			for(i=0;i<t;i++)
			{
				//存在编号
				if(j==data[i].SF.code)
				{
					flag=0;
					break;
				}
			}
			//不存在
			if(flag)
				return j;
		}
		return max+1;

	}
	else if(TYPE_NEW_Genus == type)
	{
		t=data[sf].GenusTotal;
		if(0==t)
			return 0;
		//先找最大编号
		for(i=0;i<t;i++)
		{
			if(data[sf].GenusData[t].GE.code>max)
				max=data[sf].GenusData[t].GE.code;
		}
		//遍历编号是否有缺
		for(j=0;j<max;j++)
		{
			flag=1;
			for(i=0;i<t;i++)
			{
				//存在编号
				if(j==data[sf].GenusData[t].GE.code)
				{
					flag=0;
					break;
				}
			}
			//不存在
			if(flag)
				return j;
		}
		return max+1;
	}
	else if(TYPE_NEW_Name == type)
	{
		t=data[sf].GenusData[ge].NameTotal;
		if(0==t)
			return 0;
		//先找最大编号
		for(i=0;i<t;i++)
		{
			if(data[sf].GenusData[ge].NameData[t].NA.code>max)
				max=data[sf].GenusData[ge].NameData[t].NA.code;
		}
		//遍历编号是否有缺
		for(j=0;j<max;j++)
		{
			flag=1;
			for(i=0;i<t;i++)
			{
				//存在编号
				if(j==data[sf].GenusData[ge].NameData[t].NA.code)
				{
					flag=0;
					break;
				}
			}
			//不存在
			if(flag)
				return j;
		}
		return max+1;
	}	
	else if(TYPE_NEW_SpName == type)
	{
		t=data[sf].GenusData[ge].NameData[na].SpTotal;
		if(0==t)
			return 0;
		//先找最大编号
		for(i=0;i<t;i++)
		{
			if(data[sf].GenusData[ge].NameData[na].SpData[t].code>max)
				max=data[sf].GenusData[ge].NameData[na].SpData[t].code;
		}
		//遍历编号是否有缺
		for(j=0;j<max;j++)
		{
			flag=1;
			for(i=0;i<t;i++)
			{
				//存在编号
				if(j==data[sf].GenusData[ge].NameData[na].SpData[t].code)
				{
					flag=0;
					break;
				}
			}
			//不存在
			if(flag)
				return j;
		}
		return max+1;
	}
	return 0;
}

void zogiiTEMPSaveDB(struct ZOGII_Coccinellidae_DATA *data,	\
					char temptext[ZOGII_LAG_MAX][ZOGII_PAT_MAX],	\
					ZOGII_ULONG_TYPE *tempDiscoverMap,	\
					ZOGII_ULONG_TYPE *Imagopic,	\
					ZOGII_ULONG_TYPE *Larvapic,	\
					ZOGII_ULONG_TYPE *Pupapic,	\
					ZOGII_ULONG_TYPE *Ovumpic,	\
					ZOGII_ULONG_TYPE *tempcode,	\
					char *temppath,	\
					char tempsfname[ZOGII_LAG_MAX][ZOGII_STR_MAX],	\
					char tempgename[ZOGII_LAG_MAX][ZOGII_STR_MAX],	\
					char tempname[ZOGII_LAG_MAX][ZOGII_STR_MAX])
{
	unsigned char i; 
	
	//备份文本
	for(i=0;i<ZOGII_LAG_MAX;i++)
		memcpy(temptext[i],data->Text[i],ZOGII_PAT_MAX);
	//备份图片
	(*tempDiscoverMap)=data->DiscoverMap;
	for(i=0;i<ZOGII_PIC_MAX;i++)
	{
		Imagopic[i]=data->Imago[i].Pic;
		Larvapic[i]=data->Larva[i].Pic;
		Pupapic[i]=data->Pupa[i].Pic;
		Ovumpic[i]=data->Ovum[i].Pic;
	}

	//备份编号
	*tempcode=data->code;
	memcpy(temppath,data->Path,ZOGII_PAT_MAX);
	//备份命名
	for(i=0;i<ZOGII_LAG_MAX;i++)
	{
		memcpy(tempsfname[i],data->SubFamily[i],ZOGII_STR_MAX);
		memcpy(tempgename[i],data->Genus[i],ZOGII_STR_MAX);
		memcpy(tempname[i],data->Name[i],ZOGII_STR_MAX);
	}

}

void zogiiAddSaveDB(ZOGII_ULONG_TYPE *total,struct ZOGII_Coccinellidae_SUBFamily *&data,	\
				ZOGII_ULONG_TYPE *pictotal,struct ZOGII_Pic *&picdata,	\
				unsigned char type,ZOGII_ULONG_TYPE sf,ZOGII_ULONG_TYPE ge,ZOGII_ULONG_TYPE na,	ZOGII_ULONG_TYPE sp,	\
				struct ZOGII_Coccinellidae_DATA *newdata,struct ZOGII_Pic *NewPicdata)
{
	ZOGII_ULONG_TYPE t;

	ZOGII_ULONG_TYPE tempDiscoverMap=0;
	ZOGII_ULONG_TYPE Imagopic[ZOGII_PIC_MAX]={0};
	ZOGII_ULONG_TYPE Larvapic[ZOGII_PIC_MAX]={0};
	ZOGII_ULONG_TYPE Pupapic[ZOGII_PIC_MAX]={0};
	ZOGII_ULONG_TYPE Ovumpic[ZOGII_PIC_MAX]={0};
	char temptext[ZOGII_LAG_MAX][ZOGII_PAT_MAX]={{0}};

	ZOGII_ULONG_TYPE tempcode=0;
	char temppath[ZOGII_PAT_MAX];

	ZOGII_ULONG_TYPE i,j,k,m; 
	char tempsfname[ZOGII_LAG_MAX][ZOGII_STR_MAX];
	char tempgename[ZOGII_LAG_MAX][ZOGII_STR_MAX];
	char tempname[ZOGII_LAG_MAX][ZOGII_STR_MAX];

	if(TYPE_NEW_SubFamily == type)
	{
		t=*total;
		//判断是否T=0
		if(t)
			data=(struct ZOGII_Coccinellidae_SUBFamily *)realloc(data,	\
				(t+1)*sizeof(struct ZOGII_Coccinellidae_SUBFamily));
		else
			data=(struct ZOGII_Coccinellidae_SUBFamily *)calloc(	\
				(t+1),sizeof(struct ZOGII_Coccinellidae_SUBFamily));
		
		//拷贝信息
		memcpy(&data[t].SF,newdata,sizeof(struct ZOGII_Coccinellidae_DATA));
		//创建CODE和目录
		data[t].SF.code=zogiiCodeGen(total,data,type,sf,ge,na);
		sprintf(data[t].SF.Path,"%s\\%05d",ZOGII_DB_DIRSTR,data[t].SF.code);
		zogiiCreateDirectory(data[t].SF.Path);
		//初始化图片
		zogiiInitpicDB(&data[t].SF);

		data[t].GenusTotal=0;
		(*total)++;
	}
	else if(TYPE_NEW_Genus == type)
	{
		t=data[sf].GenusTotal;
		if(t)
			data[sf].GenusData=(struct ZOGII_Coccinellidae_GENUS *)realloc(data[sf].GenusData,	\
				(t+1)*sizeof(struct ZOGII_Coccinellidae_GENUS));
		else
			data[sf].GenusData=(struct ZOGII_Coccinellidae_GENUS *)calloc(	\
				(t+1),sizeof(struct ZOGII_Coccinellidae_GENUS));

		//拷贝信息
		memcpy(&data[sf].GenusData[t].GE,newdata,sizeof(struct ZOGII_Coccinellidae_DATA));
		//创建CODE和目录
		data[sf].GenusData[t].GE.code=zogiiCodeGen(total,data,type,sf,ge,na);
		sprintf(data[sf].GenusData[t].GE.Path,"%s\\%05d\\%05d",	\
			ZOGII_DB_DIRSTR,data[sf].SF.code,data[sf].GenusData[t].GE.code);
	
		zogiiCreateDirectory(data[sf].GenusData[t].GE.Path);
		//初始化图片
		zogiiInitpicDB(&data[sf].GenusData[t].GE);

		data[sf].GenusData[t].NameTotal=0;
		data[sf].GenusTotal++;
	}
	else if(TYPE_NEW_Name == type)
	{
		t=data[sf].GenusData[ge].NameTotal;
		if(t)
			data[sf].GenusData[ge].NameData=(struct ZOGII_Coccinellidae_NAME *)realloc(data[sf].GenusData[ge].NameData,	\
				(t+1)*sizeof(struct ZOGII_Coccinellidae_NAME));
		else
			data[sf].GenusData[ge].NameData=(struct ZOGII_Coccinellidae_NAME *)calloc(	\
				(t+1),sizeof(struct ZOGII_Coccinellidae_NAME));

		//拷贝信息
		memcpy(&data[sf].GenusData[ge].NameData[t].NA,newdata,sizeof(struct ZOGII_Coccinellidae_DATA));
		//创建CODE和目录
		data[sf].GenusData[ge].NameData[t].NA.code=zogiiCodeGen(total,data,type,sf,ge,na);
		sprintf(data[sf].GenusData[ge].NameData[t].NA.Path,"%s\\%05d\\%05d\\%05d",	\
			ZOGII_DB_DIRSTR,data[sf].SF.code,	\
			data[sf].GenusData[ge].GE.code,	\
			data[sf].GenusData[ge].NameData[t].NA.code);
	
		zogiiCreateDirectory(data[sf].GenusData[ge].NameData[t].NA.Path);
		
		//初始化图片
		zogiiInitpicDB(&data[sf].GenusData[ge].NameData[t].NA);

		data[sf].GenusData[ge].NameData[t].SpTotal=0;
		data[sf].GenusData[ge].NameTotal++;
	}	
	else if(TYPE_NEW_SpName == type)
	{
		t=data[sf].GenusData[ge].NameData[na].SpTotal;
		if(t)
			data[sf].GenusData[ge].NameData[na].SpData=(struct ZOGII_Coccinellidae_DATA *)realloc(	\
				data[sf].GenusData[ge].NameData[na].SpData,(t+1)*sizeof(struct ZOGII_Coccinellidae_DATA));
		else
			data[sf].GenusData[ge].NameData[na].SpData=(struct ZOGII_Coccinellidae_DATA *)calloc(	\
				(t+1),sizeof(struct ZOGII_Coccinellidae_DATA));

		//拷贝信息
		memcpy(&data[sf].GenusData[ge].NameData[na].SpData[t],newdata,sizeof(struct ZOGII_Coccinellidae_DATA));
		//创建CODE和目录
		data[sf].GenusData[ge].NameData[na].SpData[t].code=zogiiCodeGen(total,data,type,sf,ge,na);
		sprintf(data[sf].GenusData[ge].NameData[na].SpData[t].Path,"%s\\%05d\\%05d\\%05d\\%05d",	\
			ZOGII_DB_DIRSTR,data[sf].SF.code,data[sf].GenusData[ge].GE.code,	\
			data[sf].GenusData[ge].NameData[na].NA.code,	\
			data[sf].GenusData[ge].NameData[na].SpData[t].code);

		zogiiCreateDirectory(data[sf].GenusData[ge].NameData[na].SpData[t].Path);
		
		//初始化图片
		zogiiInitpicDB(&data[sf].GenusData[ge].NameData[na].SpData[t]);

		data[sf].GenusData[ge].NameData[na].SpTotal++;
	}
	else if(TYPE_SubFamily == type)
	{
		//备份图片编号。
		zogiiTEMPSaveDB(&data[sf].SF,	\
			temptext,&tempDiscoverMap,Imagopic,Larvapic,Pupapic,Ovumpic,	\
			&tempcode,temppath,tempsfname,tempgename,tempname);

		//拷贝信息
		memcpy(&data[sf].SF,newdata,sizeof(struct ZOGII_Coccinellidae_DATA));
		//还原编号
		data[sf].SF.code=tempcode;
		memcpy(data[sf].SF.Path,temppath,ZOGII_PAT_MAX);

		//添加图片
		zogiiADDpicDB(&data[sf].SF,pictotal,picdata,NewPicdata,	\
						tempDiscoverMap,Imagopic,Larvapic,Pupapic,Ovumpic);
		zogiiAddtxtDB(&data[sf].SF,newdata,temptext);

		//更新命名 只改SF
		for(m=0;m<ZOGII_LAG_MAX;m++)
		{
			//命名不同
			if(strcmp(tempsfname[m],newdata->SubFamily[m]))
			{
				for(i=0;i<data[sf].GenusTotal;i++)
				{
					for(j=0;j<data[sf].GenusData[i].NameTotal;j++)
					{
						for(k=0;k<data[sf].GenusData[i].NameData[j].SpTotal;k++)
							memcpy(data[sf].GenusData[i].NameData[j].SpData[k].SubFamily[m],newdata->SubFamily[m],ZOGII_STR_MAX);

						memcpy(data[sf].GenusData[i].NameData[j].NA.SubFamily[m],newdata->SubFamily[m],ZOGII_STR_MAX);
					}
					memcpy(data[sf].GenusData[i].GE.SubFamily[m],newdata->SubFamily[m],ZOGII_STR_MAX);
				}
			}
		}
	}
	else if(TYPE_Genus == type)
	{
		//备份图片编号。
		zogiiTEMPSaveDB(&data[sf].GenusData[ge].GE,	\
				temptext,&tempDiscoverMap,Imagopic,Larvapic,Pupapic,Ovumpic,	\
				&tempcode,temppath,tempsfname,tempgename,tempname);
		//备份编号
		tempcode=data[sf].GenusData[ge].GE.code;
		memcpy(temppath,data[sf].GenusData[ge].GE.Path,ZOGII_PAT_MAX);

		//拷贝信息
		memcpy(&data[sf].GenusData[ge].GE,newdata,sizeof(struct ZOGII_Coccinellidae_DATA));
		//还原编号
		data[sf].GenusData[ge].GE.code=tempcode;
		memcpy(data[sf].GenusData[ge].GE.Path,temppath,ZOGII_PAT_MAX);
		//添加图片
		zogiiADDpicDB(&data[sf].GenusData[ge].GE,pictotal,picdata,NewPicdata,	\
						tempDiscoverMap,Imagopic,Larvapic,Pupapic,Ovumpic);
		zogiiAddtxtDB(&data[sf].GenusData[ge].GE,newdata,temptext);
		
		//更新命名 只改GE
		for(m=0;m<ZOGII_LAG_MAX;m++)
		{
			//命名不同
			if(strcmp(tempgename[m],newdata->Genus[m]))
			{
				for(j=0;j<data[sf].GenusData[ge].NameTotal;j++)
				{
					for(k=0;k<data[sf].GenusData[ge].NameData[j].SpTotal;k++)
						memcpy(data[sf].GenusData[ge].NameData[j].SpData[k].Genus[m],newdata->Genus[m],ZOGII_STR_MAX);

					memcpy(data[sf].GenusData[ge].NameData[j].NA.Genus[m],newdata->Genus[m],ZOGII_STR_MAX);
				}
			}
		}
	}
	else if(TYPE_Name == type)
	{
		//备份图片编号。
		zogiiTEMPSaveDB(&data[sf].GenusData[ge].NameData[na].NA,	\
					temptext,&tempDiscoverMap,Imagopic,Larvapic,Pupapic,Ovumpic,	\
					&tempcode,temppath,tempsfname,tempgename,tempname);
		//备份编号
		tempcode=data[sf].GenusData[ge].NameData[na].NA.code;
		memcpy(temppath,data[sf].GenusData[ge].NameData[na].NA.Path,ZOGII_PAT_MAX);
		//拷贝信息
		memcpy(&data[sf].GenusData[ge].NameData[na].NA,newdata,sizeof(struct ZOGII_Coccinellidae_DATA));
		//还原编号
		data[sf].GenusData[ge].NameData[na].NA.code=tempcode;
		memcpy(data[sf].GenusData[ge].NameData[na].NA.Path,temppath,ZOGII_PAT_MAX);

		//添加图片
		zogiiADDpicDB(&data[sf].GenusData[ge].NameData[na].NA,pictotal,picdata,NewPicdata,	\
						tempDiscoverMap,Imagopic,Larvapic,Pupapic,Ovumpic);
		zogiiAddtxtDB(&data[sf].GenusData[ge].NameData[na].NA,newdata,temptext);
		
		//更新命名 只改NA
		for(m=0;m<ZOGII_LAG_MAX;m++)
		{
			//命名不同
			if(strcmp(tempname[m],newdata->Name[m]))
			{
				for(k=0;k<data[sf].GenusData[ge].NameData[na].SpTotal;k++)
					memcpy(data[sf].GenusData[ge].NameData[na].SpData[k].Name[m],newdata->Name[m],ZOGII_STR_MAX);
			}
		}
	}	
	else if(TYPE_SpName == type)
	{
		//备份图片编号。
		zogiiTEMPSaveDB(&data[sf].GenusData[ge].NameData[na].SpData[sp],	\
					temptext,&tempDiscoverMap,Imagopic,Larvapic,Pupapic,Ovumpic,	\
					&tempcode,temppath,tempsfname,tempgename,tempname);
		//备份编号
		tempcode=data[sf].GenusData[ge].NameData[na].SpData[sp].code;
		memcpy(temppath,data[sf].GenusData[ge].NameData[na].SpData[sp].Path,ZOGII_PAT_MAX);
		//拷贝信息
		memcpy(&data[sf].GenusData[ge].NameData[na].SpData[sp],newdata,sizeof(struct ZOGII_Coccinellidae_DATA));
		//还原编号
		data[sf].GenusData[ge].NameData[na].SpData[sp].code=tempcode;
		memcpy(data[sf].GenusData[ge].NameData[na].SpData[sp].Path,temppath,ZOGII_PAT_MAX);
		//添加图片
		zogiiADDpicDB(&data[sf].GenusData[ge].NameData[na].SpData[sp],pictotal,picdata,NewPicdata,	\
						tempDiscoverMap,Imagopic,Larvapic,Pupapic,Ovumpic);
		zogiiAddtxtDB(&data[sf].GenusData[ge].NameData[na].SpData[sp],newdata,temptext);
	}
}

void zogiiDeleteDB(ZOGII_ULONG_TYPE *total,struct ZOGII_Coccinellidae_SUBFamily *&data,	\
			   unsigned char type,ZOGII_ULONG_TYPE sf,ZOGII_ULONG_TYPE ge,ZOGII_ULONG_TYPE na,ZOGII_ULONG_TYPE sp,	\
			   struct ZOGII_Pic *&picdata)
{
	ZOGII_ULONG_TYPE i,j,k;

	if(TYPE_SubFamily == type)
	{
		//删整个文件夹
		zogiiRemoveDirectory(data[sf].SF.Path);
		//删图片数据
		if(data[sf].GenusTotal)
		{
			for(i=0;i<data[sf].GenusTotal;i++)
			{
				if(data[sf].GenusData[i].NameTotal)
				{
					for(j=0;j<data[sf].GenusData[i].NameTotal;j++)
					{
						if(data[sf].GenusData[i].NameData[j].SpTotal)
						{
							for(k=0;k<data[sf].GenusData[i].NameData[j].SpTotal;k++)
								zogiiDeletepicDB(&data[sf].GenusData[i].NameData[j].SpData[k],picdata);

							free(data[sf].GenusData[i].NameData[j].SpData);
							data[sf].GenusData[i].NameData[j].SpData=NULL;
						}
						zogiiDeletepicDB(&data[sf].GenusData[i].NameData[j].NA,picdata);
					}
					
					free(data[sf].GenusData[i].NameData);
					data[sf].GenusData[i].NameData=NULL;
				}
				zogiiDeletepicDB(&data[sf].GenusData[i].GE,picdata);
			}
			free(data[sf].GenusData);
			data[sf].GenusData=NULL;
		}
		zogiiDeletepicDB(&data[sf].SF,picdata);

		//如果不是最后一个数据 则移动
		if( sf != ((*total) -1))
			memmove(&data[sf],&data[sf+1],sizeof(struct ZOGII_Coccinellidae_SUBFamily)*(*total-sf-1));

		(*total)--;
	}
	else if(TYPE_Genus == type)
	{
		//删整个文件夹
		zogiiRemoveDirectory(data[sf].GenusData[ge].GE.Path);
		//删图片
		if(data[sf].GenusData[ge].NameTotal)
		{
			for(j=0;j<data[sf].GenusData[ge].NameTotal;j++)
			{
				if(data[sf].GenusData[ge].NameData[j].SpTotal)
				{
					for(k=0;k<data[sf].GenusData[ge].NameData[j].SpTotal;k++)
						zogiiDeletepicDB(&data[sf].GenusData[ge].NameData[j].SpData[k],picdata);
					
					free(data[sf].GenusData[ge].NameData[j].SpData);
					data[sf].GenusData[ge].NameData[j].SpData=NULL;
				}
				zogiiDeletepicDB(&data[sf].GenusData[ge].NameData[j].NA,picdata);
			}
			free(data[sf].GenusData[ge].NameData);
			data[sf].GenusData[ge].NameData=NULL;
		}
		zogiiDeletepicDB(&data[sf].GenusData[ge].GE,picdata);

		if(ge != (data[sf].GenusTotal -1))
			memmove(&data[sf].GenusData[ge],&data[sf].GenusData[ge+1],	\
				sizeof(struct ZOGII_Coccinellidae_GENUS)*(data[sf].GenusTotal-ge-1));

		data[sf].GenusTotal--;
	}
	else if(TYPE_Name == type)
	{
		//删整个文件夹
		zogiiRemoveDirectory(data[sf].GenusData[ge].NameData[na].NA.Path);
		//删图片
		if(data[sf].GenusData[ge].NameData[na].SpTotal)
		{
			for(k=0;k<data[sf].GenusData[ge].NameData[na].SpTotal;k++)
				zogiiDeletepicDB(&data[sf].GenusData[ge].NameData[na].SpData[k],picdata);

			free(data[sf].GenusData[ge].NameData[na].SpData);
			data[sf].GenusData[ge].NameData[na].SpData=NULL;
		}
		zogiiDeletepicDB(&data[sf].GenusData[ge].NameData[na].NA,picdata);

		if(na != (data[sf].GenusData[ge].NameTotal -1))
			memmove(&data[sf].GenusData[ge].NameData[na],&data[sf].GenusData[ge].NameData[na+1],	\
				sizeof(struct ZOGII_Coccinellidae_NAME)*(data[sf].GenusData[ge].NameTotal-na-1));
			
		data[sf].GenusData[ge].NameTotal--;
	}	
	else if(TYPE_SpName == type)
	{
		//删整个文件夹
		zogiiRemoveDirectory(data[sf].GenusData[ge].NameData[na].SpData[sp].Path);
		//删图片
		zogiiDeletepicDB(&data[sf].GenusData[ge].NameData[na].SpData[sp],picdata);

		if(sp != (data[sf].GenusData[ge].NameData[na].SpTotal -1))
			memmove(&data[sf].GenusData[ge].NameData[na].SpData[sp],&data[sf].GenusData[ge].NameData[na].SpData[sp+1],	\
				sizeof(struct ZOGII_Coccinellidae_DATA)*(data[sf].GenusData[ge].NameData[na].SpTotal-sp-1));

		data[sf].GenusData[ge].NameData[na].SpTotal--;
	}
}

void zogiiFreeDB(ZOGII_ULONG_TYPE *total,struct ZOGII_Coccinellidae_SUBFamily *&data,	\
				  ZOGII_ULONG_TYPE *pictotal,struct ZOGII_Pic *&picdata)
{
	ZOGII_ULONG_TYPE i,j,k;

	for(i=0;i<(*total);i++)
	{
		if(data[i].GenusTotal)
		{
			for(j=0;j<data[i].GenusTotal;j++)
			{
				if(data[i].GenusData[j].NameTotal)
				{
					for(k=0;k<data[i].GenusData[j].NameTotal;k++)
					{
						if(data[i].GenusData[j].NameData[k].SpTotal)
						{
							free(data[i].GenusData[j].NameData[k].SpData);
							data[i].GenusData[j].NameData[k].SpData=NULL;
						}
					}
					free(data[i].GenusData[j].NameData);
					data[i].GenusData[j].NameData=NULL;
				}
			}
			free(data[i].GenusData);
			data[i].GenusData=NULL;
		}
	}

	(*total)=0;
	free(data);
	data=NULL;

	(*pictotal)=0;
	free(picdata);
	picdata=NULL;
}
////////////////////////////增加文本
void zogiiAddtxtDB(struct ZOGII_Coccinellidae_DATA *data,struct ZOGII_Coccinellidae_DATA *newdata,	\
				   	char temptext[ZOGII_LAG_MAX][ZOGII_PAT_MAX])
{
	zogiiAddtxtDBLite(data,newdata,0,temptext[0]);
	zogiiAddtxtDBLite(data,newdata,1,temptext[1]);
	zogiiAddtxtDBLite(data,newdata,2,temptext[2]);
}

void zogiiAddtxtDBLite(struct ZOGII_Coccinellidae_DATA *data,struct ZOGII_Coccinellidae_DATA *newdata,	\
					   int i,char *Path)
{
	char str[ZOGII_PAT_MAX];

	if( NULL!=newdata->Text[i][0] || NULL!=newdata->Text[i][1])
	{
		//值相同则不必拷
		if(strcmp(newdata->Text[i],Path))
		{
			sprintf(str,"%s\\Text%02d%s",data->Path,i,strrchr(newdata->Text[i],'.'));
			//拷贝路径名
			memcpy(data->Text[i],str,ZOGII_PAT_MAX);
			
			//覆盖
			zogiiCopyFile(newdata->Text[i],data->Text[i]);
		}
	}
	else
	{	
		//如果相等 则为空文件 不用删
		if(strcmp(newdata->Text[i],Path))
		{
			zogiiDeleteFile(Path);
			memset(data->Text[i],0,sizeof(ZOGII_PAT_MAX));
		}
	}
}

////////////////////////////增加图片
void zogiiADDpicDB(struct ZOGII_Coccinellidae_DATA *data,	\
				ZOGII_ULONG_TYPE *pictotal,struct ZOGII_Pic *&picdata,	\
				struct ZOGII_Pic *NewPicdata,
				ZOGII_ULONG_TYPE tempDiscoverMap,	\
				ZOGII_ULONG_TYPE *Imagopic,	\
				ZOGII_ULONG_TYPE *Larvapic,	\
				ZOGII_ULONG_TYPE *Pupapic,	\
				ZOGII_ULONG_TYPE *Ovumpic)
{
	unsigned char i; 
	char str[ZOGII_PAT_MAX];

	//有新值添加
	if(NewPicdata[ZOGII_ALL_PIC_Map_START].flag)
	{
		sprintf(str,"%s\\DiscoverMap%s",data->Path,strrchr(NewPicdata[ZOGII_ALL_PIC_Map_START].Path,'.'));
		// 修改
		if(tempDiscoverMap && picdata[tempDiscoverMap].flag)
		{
			zogiiModifypicDBLite(&picdata[tempDiscoverMap],&NewPicdata[ZOGII_ALL_PIC_Map_START],str);
			data->DiscoverMap=tempDiscoverMap;
		}
		else //原先为0 则增加
		{
			data->DiscoverMap=zogiiADDpicDBLite(pictotal,picdata,str,&NewPicdata[ZOGII_ALL_PIC_Map_START]);
		}
	}
	else	if(tempDiscoverMap)
		data->DiscoverMap=zogiiDeletepicDBLite(tempDiscoverMap,picdata);

	for(i=0;i<ZOGII_PIC_MAX;i++)
	{	
		//有新值添加
		if(NewPicdata[ZOGII_ALL_PIC_Imago_START+i].flag)
		{
			sprintf(str,"%s\\Imago%02d%s",data->Path,i,strrchr(NewPicdata[ZOGII_ALL_PIC_Imago_START+i].Path,'.'));
			// 修改
			if(Imagopic[i] && picdata[Imagopic[i]].flag)
			{
				zogiiModifypicDBLite(&picdata[Imagopic[i]],&NewPicdata[ZOGII_ALL_PIC_Imago_START+i],str);
				data->Imago[i].Pic=Imagopic[i];
			}
			else //原先为0 则增加
			{
				data->Imago[i].Pic=zogiiADDpicDBLite(pictotal,picdata,str,&NewPicdata[ZOGII_ALL_PIC_Imago_START+i]);
			}
		}
		else	 if(Imagopic[i])
			data->Imago[i].Pic=zogiiDeletepicDBLite(Imagopic[i],picdata);
		//有新值添加
		if(NewPicdata[ZOGII_ALL_PIC_Larva_START+i].flag)
		{
			sprintf(str,"%s\\Larva%02d%s",data->Path,i,strrchr(NewPicdata[ZOGII_ALL_PIC_Larva_START+i].Path,'.'));
			// 修改
			if(Larvapic[i] && picdata[Larvapic[i]].flag)
			{
				zogiiModifypicDBLite(&picdata[Larvapic[i]],&NewPicdata[ZOGII_ALL_PIC_Larva_START+i],str);
				data->Larva[i].Pic=Larvapic[i];
			}
			else //原先为0 则增加
			{
				data->Larva[i].Pic=zogiiADDpicDBLite(pictotal,picdata,str,&NewPicdata[ZOGII_ALL_PIC_Larva_START+i]);
			}
		}
		else	 if(Larvapic[i])
			data->Larva[i].Pic=zogiiDeletepicDBLite(Larvapic[i],picdata);
		//有新值添加
		if(NewPicdata[ZOGII_ALL_PIC_Pupa_START+i].flag)
		{
			sprintf(str,"%s\\Pupa%02d%s",data->Path,i,strrchr(NewPicdata[ZOGII_ALL_PIC_Pupa_START+i].Path,'.'));
			// 修改
			if(Pupapic[i] && picdata[Pupapic[i]].flag)
			{
				zogiiModifypicDBLite(&picdata[Pupapic[i]],&NewPicdata[ZOGII_ALL_PIC_Pupa_START+i],str);
				data->Pupa[i].Pic=Pupapic[i];
			}
			else //原先为0 则增加
			{
				data->Pupa[i].Pic=zogiiADDpicDBLite(pictotal,picdata,str,&NewPicdata[ZOGII_ALL_PIC_Pupa_START+i]);
			}
		}
		else	 if(Pupapic[i])
			data->Pupa[i].Pic=zogiiDeletepicDBLite(Pupapic[i],picdata);
		//有新值添加
		if(NewPicdata[ZOGII_ALL_PIC_Ovum_START+i].flag)
		{
			sprintf(str,"%s\\Ovum%02d%s",data->Path,i,strrchr(NewPicdata[ZOGII_ALL_PIC_Ovum_START+i].Path,'.'));
			// 修改
			if(Ovumpic[i] && picdata[Ovumpic[i]].flag)
			{
				zogiiModifypicDBLite(&picdata[Ovumpic[i]],&NewPicdata[ZOGII_ALL_PIC_Ovum_START+i],str);
				data->Ovum[i].Pic=Ovumpic[i];
			}
			else //原先为0 则增加
			{
				data->Ovum[i].Pic=zogiiADDpicDBLite(pictotal,picdata,str,&NewPicdata[ZOGII_ALL_PIC_Ovum_START+i]);
			}
		}
		else	 if(Ovumpic[i]) //无新值 则旧值删去
			data->Ovum[i].Pic=zogiiDeletepicDBLite(Ovumpic[i],picdata);
	}
	
}

ZOGII_ULONG_TYPE zogiiADDpicDBLite(ZOGII_ULONG_TYPE *pictotal,struct ZOGII_Pic *&picdata,	\
									char *Path,struct ZOGII_Pic *newpic)
{
	ZOGII_ULONG_TYPE i,t;
	t=(*pictotal);

	if(t)
	{	
		//先找无效的
		for(i=1;i<t;i++)
		{
			if(0==picdata[i].flag)
			{
				picdata[i].flag=1;
				memcpy(picdata[i].Info,newpic->Info,ZOGII_STR_MAX);
				memcpy(picdata[i].Path,Path,ZOGII_PAT_MAX);
			
				//覆盖
				zogiiCopyFile(newpic->Path,picdata[i].Path);
				return i;
			}
		}
		//都是有效则新建
		picdata=(struct ZOGII_Pic *)realloc(picdata,(t+1)*sizeof(struct ZOGII_Pic));
	}
	else
		picdata=(struct ZOGII_Pic *)calloc((t+1),sizeof(struct ZOGII_Pic));

	picdata[t].flag=1;
	memcpy(picdata[t].Info,newpic->Info,ZOGII_STR_MAX);
	memcpy(picdata[t].Path,Path,ZOGII_PAT_MAX);
		
	//覆盖
	zogiiCopyFile(newpic->Path,picdata[t].Path);
	(*pictotal)++;
	return t;
}

void zogiiModifypicDBLite(struct ZOGII_Pic *pdata,struct ZOGII_Pic *newpic,char *path)
{

	//路径不同 拷贝
	if(strcmp(pdata->Path,newpic->Path))
	{
		memcpy(pdata->Path,path,ZOGII_PAT_MAX);
		//覆盖
		zogiiCopyFile(newpic->Path,pdata->Path);
	}
	memcpy(pdata->Info,newpic->Info,ZOGII_STR_MAX);
}

void zogiiInitpicDB(struct ZOGII_Coccinellidae_DATA *data)
{
	unsigned char i; 

	data->DiscoverMap=0;

	for(i=0;i<ZOGII_PIC_MAX;i++)
	{
		data->Imago[i].Pic=0;
		data->Larva[i].Pic=0;
		data->Pupa[i].Pic=0;
		data->Ovum[i].Pic=0;
	}
}
/////////删除图片

void zogiiDeletepicDB(struct ZOGII_Coccinellidae_DATA *data,struct ZOGII_Pic *&picdata)
{
	unsigned char i; 

	if(data->DiscoverMap)
		data->DiscoverMap=zogiiDeletepicDBLite(data->DiscoverMap,picdata);

	for(i=0;i<ZOGII_PIC_MAX;i++)
	{
		if(data->Imago[i].Pic)
			data->Imago[i].Pic=zogiiDeletepicDBLite(data->Imago[i].Pic,picdata);
		if(data->Larva[i].Pic)
			data->Larva[i].Pic=zogiiDeletepicDBLite(data->Larva[i].Pic,picdata);
		if(data->Pupa[i].Pic)
			data->Pupa[i].Pic=zogiiDeletepicDBLite(data->Pupa[i].Pic,picdata);
		if(data->Ovum[i].Pic)
			data->Ovum[i].Pic=zogiiDeletepicDBLite(data->Ovum[i].Pic,picdata);
	}
}

ZOGII_ULONG_TYPE zogiiDeletepicDBLite(ZOGII_ULONG_TYPE i,struct ZOGII_Pic *&picdata)
{
	picdata[i].flag=0;

	//删除图片
	zogiiDeleteFile(picdata[i].Path);
	memset(picdata[i].Path,0,sizeof(ZOGII_PAT_MAX));
	memset(picdata[i].Info,0,sizeof(ZOGII_STR_MAX));
	return 0;
}

