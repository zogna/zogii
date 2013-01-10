#include "stdafx.h"
#include "zogiidb.h"

//获取统计信息
ZOGII_ULONG_TYPE zogii_sf_total=0;
ZOGII_ULONG_TYPE zogii_ge_total=0;
ZOGII_ULONG_TYPE zogii_na_total=0;
ZOGII_ULONG_TYPE zogii_sp_total=0;

ZOGII_ULONG_TYPE zogiiSFTotalDB(void)
{
	return zogii_sf_total;
}
ZOGII_ULONG_TYPE zogiiGETotalDB(void)
{
	return zogii_ge_total;
}
ZOGII_ULONG_TYPE zogiiNATotalDB(void)
{
	return zogii_na_total;
}
ZOGII_ULONG_TYPE zogiiSPTotalDB(void)
{
	return zogii_sp_total;
}
//获取数据库版本
ZOGII_ULONG_TYPE zogii_version=0;

ZOGII_ULONG_TYPE zogiiVersionDB(void)
{
	return zogii_version;
}
//获取当前目录
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
#if 0
BOOL DeleteDirectory(CString str)
{
	CFileFind finder; //文件查找类
	CString strdel,strdir;//strdir:要删除的目录，strdel：要删除的文件
	strdir=str+"\\*.*";//删除文件夹，先要清空文件夹,加上路径,注意加"\\"
	BOOL b_finded=(BOOL)finder.FindFile(strdir); 
	while(b_finded) 
	{ 
		b_finded=(BOOL)finder.FindNextFile(); 
		if (finder.IsDots())  continue;//找到的是当前目录或上级目录则跳过
		strdel=finder.GetFileName(); //获取找到的文件名
		if(finder.IsDirectory())   //如果是文件夹
		{ 
			strdel=str + "\\" + strdel;//加上路径,注意加"\\"
			DeleteDirectory(strdel); //递归删除文件夹
		} 
		else //不是文件夹
		{ 
			strdel=str + "\\" + strdel;
			if(finder.IsReadOnly())//清除只读属性
			{    
				SetFileAttributes(strdel,GetFileAttributes(strdel)&(~FILE_ATTRIBUTE_READONLY));
			}
			DeleteFile(strdel); //删除文件(API)
		} 
	} 
	finder.Close(); 
	return RemoveDirectory(str); //删除文件夹(API)
	//return TRUE;
}  
#endif

//WIN32 删除目录含子目录
void zogiiRemoveDirectory(char *str)
{
	char temp[ZOGII_PAT_MAX+16];
//	sprintf(temp,"%s\\%s",CurrentDirectory,str);
//	RemoveDirectory(temp);

//	sprintf(temp,"rmdir /s /q %s\\%s",CurrentDirectory,str);
//	system(temp);

	sprintf(temp,"cmd.exe /c rmdir /s /q %s\\%s",CurrentDirectory,str);
	WinExec(temp,SW_HIDE);
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int zogiiReadDB(ZOGII_ULONG_TYPE *total,struct ZOGII_Coccinellidae_SUBFamily *&data,
				ZOGII_ULONG_TYPE *Imagototal,struct ZOGII_Imago *&Imagodata,
				ZOGII_ULONG_TYPE *Larvatotal,struct ZOGII_Larva *&Larvadata,
				ZOGII_ULONG_TYPE *Pupatotal,struct ZOGII_Pupa *&Pupadata,
				ZOGII_ULONG_TYPE *Ovumtotal,struct ZOGII_Ovum *&Ovumdata,
				ZOGII_ULONG_TYPE *Closeuptotal,struct ZOGII_Closeup *&Closeupdata)
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
			zogii_sf_total=*total;
		}
		for(i=0;i<(*total);i++)
		{
			if(data[i].GenusTotal)
			{
				data[i].GenusData=(struct ZOGII_Coccinellidae_GENUS *)calloc(data[i].GenusTotal,	\
					sizeof(struct ZOGII_Coccinellidae_GENUS));
				fread(data[i].GenusData,sizeof(struct ZOGII_Coccinellidae_GENUS),data[i].GenusTotal,fp);

				zogii_ge_total+=data[i].GenusTotal;

				for(j=0;j<data[i].GenusTotal;j++)
				{
					if(data[i].GenusData[j].NameTotal)
					{
						data[i].GenusData[j].NameData=(struct ZOGII_Coccinellidae_NAME *)calloc(data[i].GenusData[j].NameTotal,	\
							sizeof(struct ZOGII_Coccinellidae_NAME));
						fread(data[i].GenusData[j].NameData,sizeof(struct ZOGII_Coccinellidae_NAME),	\
							data[i].GenusData[j].NameTotal,fp);
						
						zogii_na_total+=data[i].GenusData[j].NameTotal;

						for(k=0;k<data[i].GenusData[j].NameTotal;k++)
						{
							if(data[i].GenusData[j].NameData[k].SpTotal)
							{
								data[i].GenusData[j].NameData[k].SpData=	\
									(struct ZOGII_Coccinellidae_DATA *)calloc(data[i].GenusData[j].NameData[k].SpTotal,	\
										sizeof(struct ZOGII_Coccinellidae_DATA));
								fread(data[i].GenusData[j].NameData[k].SpData, sizeof(struct ZOGII_Coccinellidae_DATA),	\
									data[i].GenusData[j].NameData[k].SpTotal,fp);

								zogii_sp_total+=data[i].GenusData[j].NameData[k].SpTotal;
							}
						}
					}
				}
			}
		}
		fread(Imagototal,sizeof(ZOGII_ULONG_TYPE),1,fp);
		if(*Imagototal)
		{
			Imagodata=(struct ZOGII_Imago *)calloc(*Imagototal,sizeof(struct ZOGII_Imago));
			fread(Imagodata,sizeof(struct ZOGII_Imago),*Imagototal,fp);
		}

		fread(Larvatotal,sizeof(ZOGII_ULONG_TYPE),1,fp);
		if(*Larvatotal)
		{
			Larvadata=(struct ZOGII_Larva *)calloc(*Larvatotal,sizeof(struct ZOGII_Larva));
			fread(Larvadata,sizeof(struct ZOGII_Larva),*Larvatotal,fp);
		}

		fread(Pupatotal,sizeof(ZOGII_ULONG_TYPE),1,fp);
		if(*Pupatotal)
		{
			Pupadata=(struct ZOGII_Pupa *)calloc(*Pupatotal,sizeof(struct ZOGII_Pupa));
			fread(Pupadata,sizeof(struct ZOGII_Pupa),*Pupatotal,fp);
		}

		fread(Ovumtotal,sizeof(ZOGII_ULONG_TYPE),1,fp);
		if(*Ovumtotal)
		{
			Ovumdata=(struct ZOGII_Ovum *)calloc(*Ovumtotal,sizeof(struct ZOGII_Ovum));
			fread(Ovumdata,sizeof(struct ZOGII_Ovum),*Ovumtotal,fp);
		}

		fread(Closeuptotal,sizeof(ZOGII_ULONG_TYPE),1,fp);
		if(*Closeuptotal)
		{
			Closeupdata=(struct ZOGII_Closeup *)calloc(*Closeuptotal,sizeof(struct ZOGII_Closeup));
			fread(Closeupdata,sizeof(struct ZOGII_Closeup),*Closeuptotal,fp);
		}

		fclose(fp);
		return 1;
	}
	else
	{
		(*total)=0;
		data=NULL;	

		//初始化第一个为无效
		(*Imagototal)=1;
		Imagodata=(struct ZOGII_Imago *)calloc(*Imagototal,sizeof(struct ZOGII_Imago));
		Imagodata[0].flag=0;	

		//初始化第一个为无效
		(*Larvatotal)=1;
		Larvadata=(struct ZOGII_Larva *)calloc(*Larvatotal,sizeof(struct ZOGII_Larva));
		Larvadata[0].flag=0;	

		//初始化第一个为无效
		(*Pupatotal)=1;
		Pupadata=(struct ZOGII_Pupa *)calloc(*Pupatotal,sizeof(struct ZOGII_Pupa));
		Pupadata[0].flag=0;	

		//初始化第一个为无效
		(*Ovumtotal)=1;
		Ovumdata=(struct ZOGII_Ovum *)calloc(*Ovumtotal,sizeof(struct ZOGII_Ovum));
		Ovumdata[0].flag=0;	

		//初始化第一个为无效
		(*Closeuptotal)=1;
		Closeupdata=(struct ZOGII_Closeup *)calloc(*Closeuptotal,sizeof(struct ZOGII_Closeup));
		Closeupdata[0].flag=0;	

		//创建根目录
		zogiiCreateDirectory(ZOGII_DB_DIRSTR);

		return 0;
	}
}

int zogiiWriteDB(ZOGII_ULONG_TYPE total,struct ZOGII_Coccinellidae_SUBFamily *&data,	\
				 ZOGII_ULONG_TYPE Imagototal,struct ZOGII_Imago *&Imagodata,
				 ZOGII_ULONG_TYPE Larvatotal,struct ZOGII_Larva *&Larvadata,
				 ZOGII_ULONG_TYPE Pupatotal,struct ZOGII_Pupa *&Pupadata,
				 ZOGII_ULONG_TYPE Ovumtotal,struct ZOGII_Ovum *&Ovumdata,
				 ZOGII_ULONG_TYPE Closeuptotal,struct ZOGII_Closeup *&Closeupdata)

{
	ZOGII_ULONG_TYPE i,j,k;

	FILE *fp;
	char str[ZOGII_PAT_MAX];
	//先排序
	zogiiSortDB(total,data);

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

		fwrite(&Imagototal,sizeof(ZOGII_ULONG_TYPE),1,fp);
		if(Imagototal)
			fwrite(Imagodata,sizeof(struct ZOGII_Imago),Imagototal,fp);

		fwrite(&Larvatotal,sizeof(ZOGII_ULONG_TYPE),1,fp);
		if(Larvatotal)
			fwrite(Larvadata,sizeof(struct ZOGII_Larva),Larvatotal,fp);

		fwrite(&Pupatotal,sizeof(ZOGII_ULONG_TYPE),1,fp);
		if(Pupatotal)
			fwrite(Pupadata,sizeof(struct ZOGII_Pupa),Pupatotal,fp);

		fwrite(&Ovumtotal,sizeof(ZOGII_ULONG_TYPE),1,fp);
		if(Ovumtotal)
			fwrite(Ovumdata,sizeof(struct ZOGII_Ovum),Ovumtotal,fp);

		fwrite(&Closeuptotal,sizeof(ZOGII_ULONG_TYPE),1,fp);
		if(Closeuptotal)
			fwrite(Closeupdata,sizeof(struct ZOGII_Closeup),Closeuptotal,fp);

		fclose(fp);
		return 1;
	}
	return 0;
}

////////////////////输出树////////////////////////////////////////////////////////////////
int zogiiPrintfDB(ZOGII_ULONG_TYPE total,struct ZOGII_Coccinellidae_SUBFamily *&data)
{
	ZOGII_ULONG_TYPE i,j,k,m,n;

	FILE *fp;
	char str[ZOGII_PAT_MAX];

	sprintf(str,"%s\\DBtree.txt",CurrentDirectory);
	fp=fopen(str,"w");
	if(fp)
	{
		for(i=0;i<total;i++)
		{
			fprintf(fp,"%05d-\t%s-\t%s-\t%s\n",	\
				data[i].SF.code,	\
				data[i].SF.SubFamily[0],
				data[i].SF.SubFamily[1],
				data[i].SF.SubFamily[2]);
			
			for(j=0;j<data[i].GenusTotal;j++)
			{
				fprintf(fp,"\t%05d-\t%s-\t%s-\t%s\n",	\
					data[i].GenusData[j].GE.code,	\
					data[i].GenusData[j].GE.Genus[0],
					data[i].GenusData[j].GE.Genus[1],
					data[i].GenusData[j].GE.Genus[2]);
				
				for(k=0;k<data[i].GenusData[j].NameTotal;k++)
				{
					fprintf(fp,"\t\t%05d-\t%s-\t%s-\t%s\t",	\
						data[i].GenusData[j].NameData[k].NA.code,	\
						data[i].GenusData[j].NameData[k].NA.Species[0],
						data[i].GenusData[j].NameData[k].NA.Species[1],
						data[i].GenusData[j].NameData[k].NA.Species[2]);
					
					fprintf(fp,"[");
					for(n=0;n<ZOGII_INF_MAX;n++)
					{
						if(	0!= data[i].GenusData[j].NameData[k].NA.OtherName[n][0] || 
							0!= data[i].GenusData[j].NameData[k].NA.OtherName[n][1] 	)
							fprintf(fp,"%s-\t",	data[i].GenusData[j].NameData[k].NA.OtherName[n]);
					}
					fprintf(fp,"]\n");

					for(m=0;m<data[i].GenusData[j].NameData[k].SpTotal;m++)
					{
						fprintf(fp,"\t\t\t%05d-\t%s-\t%s-\t%s\t",	\
							data[i].GenusData[j].NameData[k].SpData[m].code,	\
							data[i].GenusData[j].NameData[k].SpData[m].Subspecies[0],
							data[i].GenusData[j].NameData[k].SpData[m].Subspecies[1],
							data[i].GenusData[j].NameData[k].SpData[m].Subspecies[2]);
					
						fprintf(fp,"[");
						for(n=0;n<ZOGII_INF_MAX;n++)
						{
							if(	0!= data[i].GenusData[j].NameData[k].SpData[m].OtherName[n][0] || 
								0!= data[i].GenusData[j].NameData[k].SpData[m].OtherName[n][1] 	)
								fprintf(fp,"%s-\t",	data[i].GenusData[j].NameData[k].SpData[m].OtherName[n]);
						}
						fprintf(fp,"]\n");
					}
				}
			}
		}

		fclose(fp);
		return 1;
	}
	return 0;
}
//////////////////////排序//////////////////////////////////////////////////////////////
int zogiiSort_SF(const void *A,const void *B)
{
	struct ZOGII_Coccinellidae_SUBFamily *a=(struct ZOGII_Coccinellidae_SUBFamily *)A;
	struct ZOGII_Coccinellidae_SUBFamily *b=(struct ZOGII_Coccinellidae_SUBFamily *)B;
	return strcmp(a->SF.SubFamily[0],b->SF.SubFamily[0]);
}
int zogiiSort_GE(const void *A,const void *B)
{
	struct ZOGII_Coccinellidae_GENUS *a=(struct ZOGII_Coccinellidae_GENUS *)A;
	struct ZOGII_Coccinellidae_GENUS *b=(struct ZOGII_Coccinellidae_GENUS *)B;
	return strcmp(a->GE.Genus[0],b->GE.Genus[0]);
}
int zogiiSort_NA(const void *A,const void *B)
{
	struct ZOGII_Coccinellidae_NAME *a=(struct ZOGII_Coccinellidae_NAME *)A;
	struct ZOGII_Coccinellidae_NAME *b=(struct ZOGII_Coccinellidae_NAME *)B;
	return strcmp(a->NA.Species[0],b->NA.Species[0]);
}
int zogiiSort_SP(const void *A,const void *B)
{
	struct ZOGII_Coccinellidae_DATA *a=(struct ZOGII_Coccinellidae_DATA *)A;
	struct ZOGII_Coccinellidae_DATA *b=(struct ZOGII_Coccinellidae_DATA *)B;
	return strcmp(a->Subspecies[0],b->Subspecies[0]);
}
void zogiiSortDB(ZOGII_ULONG_TYPE total,struct ZOGII_Coccinellidae_SUBFamily *&data)
{
	ZOGII_ULONG_TYPE i,j,k;

	if(total)
	{
		qsort(data,total,sizeof(struct ZOGII_Coccinellidae_SUBFamily),zogiiSort_SF);

		for(i=0;i<total;i++)
		{
			if(data[i].GenusTotal)
			{
				qsort(data[i].GenusData,data[i].GenusTotal,sizeof(struct ZOGII_Coccinellidae_GENUS),zogiiSort_GE);

				for(j=0;j<data[i].GenusTotal;j++)
				{
					if(data[i].GenusData[j].NameTotal)
					{
						qsort(data[i].GenusData[j].NameData,data[i].GenusData[j].NameTotal,	\
							sizeof(struct ZOGII_Coccinellidae_NAME),zogiiSort_NA);

						for(k=0;k<data[i].GenusData[j].NameTotal;k++)
						{
							if(data[i].GenusData[j].NameData[k].SpTotal)
							{
								qsort(data[i].GenusData[j].NameData[k].SpData,data[i].GenusData[j].NameData[k].SpTotal,	\
									sizeof(struct ZOGII_Coccinellidae_DATA),zogiiSort_SP);
							}
						}
					}
				}
			}
		}
	}
}
////////////////////////////////////////////////////////////////////////////////
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
			if(data[sf].GenusData[i].GE.code>max)
				max=data[sf].GenusData[i].GE.code;
		}
		//遍历编号是否有缺
		for(j=0;j<max;j++)
		{
			flag=1;
			for(i=0;i<t;i++)
			{
				//存在编号
				if(j==data[sf].GenusData[i].GE.code)
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
			if(data[sf].GenusData[ge].NameData[i].NA.code>max)
				max=data[sf].GenusData[ge].NameData[i].NA.code;
		}
		//遍历编号是否有缺
		for(j=0;j<max;j++)
		{
			flag=1;
			for(i=0;i<t;i++)
			{
				//存在编号
				if(j==data[sf].GenusData[ge].NameData[i].NA.code)
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
			if(data[sf].GenusData[ge].NameData[na].SpData[i].code>max)
				max=data[sf].GenusData[ge].NameData[na].SpData[i].code;
		}
		//遍历编号是否有缺
		for(j=0;j<max;j++)
		{
			flag=1;
			for(i=0;i<t;i++)
			{
				//存在编号
				if(j==data[sf].GenusData[ge].NameData[na].SpData[i].code)
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
//保存临时编号
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
					char temptext[ZOGII_LAG_MAX][ZOGII_PAT_MAX])
{
	ZOGII_ULONG_TYPE i; 
	
	for(i=0;i<ZOGII_PIC_Imago_MAX;i++)
		tempImago[i]=data->Imago[i];
	
	for(i=0;i<ZOGII_PIC_Larva_MAX;i++)
		tempLarva[i]=data->Larva[i];
	
	for(i=0;i<ZOGII_PIC_Pupa_MAX;i++)
		tempPupa[i]=data->Pupa[i];

	for(i=0;i<ZOGII_PIC_Ovum_MAX;i++)
		tempOvum[i]=data->Ovum[i];
	
	for(i=0;i<ZOGII_PIC_Closeup_MAX;i++)
		tempCloseup[i]=data->Closeup[i];

	//备份编号
	*tempcode=data->code;
	memcpy(temppath,data->Path,ZOGII_PAT_MAX);
	//备份命名
	for(i=0;i<ZOGII_LAG_MAX;i++)
	{
		memcpy(tempsfname[i],data->SubFamily[i],ZOGII_STR_MAX);
		memcpy(tempgename[i],data->Genus[i],ZOGII_STR_MAX);
		memcpy(tempname[i],data->Species[i],ZOGII_STR_MAX);
		memcpy(temptext[i],data->Text[i],ZOGII_PAT_MAX);
	}

}

void zogiiAddSaveDB(ZOGII_ULONG_TYPE *total,struct ZOGII_Coccinellidae_SUBFamily *&data,	\
					ZOGII_ULONG_TYPE *Imagototal,	struct ZOGII_Imago *&Imagodata,
					ZOGII_ULONG_TYPE *Larvatotal,struct ZOGII_Larva *&Larvadata,
					ZOGII_ULONG_TYPE *Pupatotal,	struct ZOGII_Pupa *&Pupadata,
					ZOGII_ULONG_TYPE *Ovumtotal,struct ZOGII_Ovum *&Ovumdata,
					ZOGII_ULONG_TYPE *Closeuptotal,struct ZOGII_Closeup *&Closeupdata,
					unsigned char type,ZOGII_ULONG_TYPE sf,ZOGII_ULONG_TYPE ge,ZOGII_ULONG_TYPE na,	ZOGII_ULONG_TYPE sp,	\
					struct ZOGII_Coccinellidae_DATA *newdata,
					struct ZOGII_Imago *NewImagodata,
					struct ZOGII_Larva *NewLarvadata,
					struct ZOGII_Pupa *NewPupadata,
					struct ZOGII_Ovum *NewOvumdata,
					struct ZOGII_Closeup *NewCloseupdata)
{
	ZOGII_ULONG_TYPE t;

	ZOGII_ULONG_TYPE tempImago[ZOGII_PIC_Imago_MAX]={0}; 
	ZOGII_ULONG_TYPE tempLarva[ZOGII_PIC_Larva_MAX]={0}; 
	ZOGII_ULONG_TYPE tempPupa[ZOGII_PIC_Pupa_MAX]={0}; 
	ZOGII_ULONG_TYPE tempOvum[ZOGII_PIC_Ovum_MAX]={0}; 
	ZOGII_ULONG_TYPE tempCloseup[ZOGII_PIC_Closeup_MAX]={0}; 

	ZOGII_ULONG_TYPE tempcode=0;
	char temppath[ZOGII_PAT_MAX];

	ZOGII_ULONG_TYPE i,j,k,m; 
	char tempsfname[ZOGII_LAG_MAX][ZOGII_STR_MAX];
	char tempgename[ZOGII_LAG_MAX][ZOGII_STR_MAX];
	char tempname[ZOGII_LAG_MAX][ZOGII_STR_MAX];
	char temptext[ZOGII_LAG_MAX][ZOGII_PAT_MAX];

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
			tempImago,tempLarva,tempPupa,tempOvum,tempCloseup,
			&tempcode,temppath,tempsfname,tempgename,tempname,temptext);

		//拷贝信息
		memcpy(&data[sf].SF,newdata,sizeof(struct ZOGII_Coccinellidae_DATA));
		//还原编号
		data[sf].SF.code=tempcode;
		memcpy(data[sf].SF.Path,temppath,ZOGII_PAT_MAX);

		//添加图片
		zogiiADDpicDB(&data[sf].SF,
			Imagototal,Imagodata,
			Larvatotal,Larvadata,
			Pupatotal,Pupadata,
			Ovumtotal,Ovumdata,
			Closeuptotal,Closeupdata,	
			NewImagodata,NewLarvadata,NewPupadata,NewOvumdata,NewCloseupdata,
			tempImago,tempLarva,tempPupa,tempOvum,tempCloseup);

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
			tempImago,tempLarva,tempPupa,tempOvum,tempCloseup,
			&tempcode,temppath,tempsfname,tempgename,tempname,temptext);
		//备份编号
		tempcode=data[sf].GenusData[ge].GE.code;
		memcpy(temppath,data[sf].GenusData[ge].GE.Path,ZOGII_PAT_MAX);

		//拷贝信息
		memcpy(&data[sf].GenusData[ge].GE,newdata,sizeof(struct ZOGII_Coccinellidae_DATA));
		//还原编号
		data[sf].GenusData[ge].GE.code=tempcode;
		memcpy(data[sf].GenusData[ge].GE.Path,temppath,ZOGII_PAT_MAX);
		//添加图片
		zogiiADDpicDB(&data[sf].GenusData[ge].GE,
			Imagototal,Imagodata,
			Larvatotal,Larvadata,
			Pupatotal,Pupadata,
			Ovumtotal,Ovumdata,
			Closeuptotal,Closeupdata,	
			NewImagodata,NewLarvadata,NewPupadata,NewOvumdata,NewCloseupdata,
			tempImago,tempLarva,tempPupa,tempOvum,tempCloseup);

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
					tempImago,tempLarva,tempPupa,tempOvum,tempCloseup,
					&tempcode,temppath,tempsfname,tempgename,tempname,temptext);
		//备份编号
		tempcode=data[sf].GenusData[ge].NameData[na].NA.code;
		memcpy(temppath,data[sf].GenusData[ge].NameData[na].NA.Path,ZOGII_PAT_MAX);
		//拷贝信息
		memcpy(&data[sf].GenusData[ge].NameData[na].NA,newdata,sizeof(struct ZOGII_Coccinellidae_DATA));
		//还原编号
		data[sf].GenusData[ge].NameData[na].NA.code=tempcode;
		memcpy(data[sf].GenusData[ge].NameData[na].NA.Path,temppath,ZOGII_PAT_MAX);

		//添加图片
		zogiiADDpicDB(&data[sf].GenusData[ge].NameData[na].NA,			
			Imagototal,Imagodata,
			Larvatotal,Larvadata,
			Pupatotal,Pupadata,
			Ovumtotal,Ovumdata,
			Closeuptotal,Closeupdata,		
			NewImagodata,NewLarvadata,NewPupadata,NewOvumdata,NewCloseupdata,
			tempImago,tempLarva,tempPupa,tempOvum,tempCloseup);

		zogiiAddtxtDB(&data[sf].GenusData[ge].NameData[na].NA,newdata,temptext);
		
		//更新命名 只改NA
		for(m=0;m<ZOGII_LAG_MAX;m++)
		{
			//命名不同
			if(strcmp(tempname[m],newdata->Species[m]))
			{
				for(k=0;k<data[sf].GenusData[ge].NameData[na].SpTotal;k++)
					memcpy(data[sf].GenusData[ge].NameData[na].SpData[k].Species[m],newdata->Species[m],ZOGII_STR_MAX);
			}
		}
	}	
	else if(TYPE_SpName == type)
	{
		//备份图片编号。
		zogiiTEMPSaveDB(&data[sf].GenusData[ge].NameData[na].SpData[sp],	\
					tempImago,tempLarva,tempPupa,tempOvum,tempCloseup,
					&tempcode,temppath,tempsfname,tempgename,tempname,temptext);
		//备份编号
		tempcode=data[sf].GenusData[ge].NameData[na].SpData[sp].code;
		memcpy(temppath,data[sf].GenusData[ge].NameData[na].SpData[sp].Path,ZOGII_PAT_MAX);
		//拷贝信息
		memcpy(&data[sf].GenusData[ge].NameData[na].SpData[sp],newdata,sizeof(struct ZOGII_Coccinellidae_DATA));
		//还原编号
		data[sf].GenusData[ge].NameData[na].SpData[sp].code=tempcode;
		memcpy(data[sf].GenusData[ge].NameData[na].SpData[sp].Path,temppath,ZOGII_PAT_MAX);
		//添加图片
		zogiiADDpicDB(&data[sf].GenusData[ge].NameData[na].SpData[sp],			
			Imagototal,Imagodata,
			Larvatotal,Larvadata,
			Pupatotal,Pupadata,
			Ovumtotal,Ovumdata,
			Closeuptotal,Closeupdata,	
			NewImagodata,NewLarvadata,NewPupadata,NewOvumdata,NewCloseupdata,
			tempImago,tempLarva,tempPupa,tempOvum,tempCloseup);

		zogiiAddtxtDB(&data[sf].GenusData[ge].NameData[na].SpData[sp],newdata,temptext);
	}
}

void zogiiDeleteDB(ZOGII_ULONG_TYPE *total,struct ZOGII_Coccinellidae_SUBFamily *&data,	\
					unsigned char type,ZOGII_ULONG_TYPE sf,ZOGII_ULONG_TYPE ge,ZOGII_ULONG_TYPE na,ZOGII_ULONG_TYPE sp,	\
					struct ZOGII_Imago *&Imagodata,
					struct ZOGII_Larva *&Larvadata,
					struct ZOGII_Pupa *&Pupadata,
					struct ZOGII_Ovum *&Ovumdata,
					struct ZOGII_Closeup *&Closeupdata)
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
								zogiiDeletepicDB(&data[sf].GenusData[i].NameData[j].SpData[k],	\
											Imagodata,Larvadata,Pupadata,Ovumdata,Closeupdata);

							free(data[sf].GenusData[i].NameData[j].SpData);
							data[sf].GenusData[i].NameData[j].SpData=NULL;
						}
						zogiiDeletepicDB(&data[sf].GenusData[i].NameData[j].NA,	\
							Imagodata,Larvadata,Pupadata,Ovumdata,Closeupdata);
					}
					
					free(data[sf].GenusData[i].NameData);
					data[sf].GenusData[i].NameData=NULL;
				}
				zogiiDeletepicDB(&data[sf].GenusData[i].GE,	\
							Imagodata,Larvadata,Pupadata,Ovumdata,Closeupdata);
			}
			free(data[sf].GenusData);
			data[sf].GenusData=NULL;
		}
		zogiiDeletepicDB(&data[sf].SF,	\
							Imagodata,Larvadata,Pupadata,Ovumdata,Closeupdata);

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
						zogiiDeletepicDB(&data[sf].GenusData[ge].NameData[j].SpData[k],	\
							Imagodata,Larvadata,Pupadata,Ovumdata,Closeupdata);
					
					free(data[sf].GenusData[ge].NameData[j].SpData);
					data[sf].GenusData[ge].NameData[j].SpData=NULL;
				}
				zogiiDeletepicDB(&data[sf].GenusData[ge].NameData[j].NA,	\
							Imagodata,Larvadata,Pupadata,Ovumdata,Closeupdata);
			}
			free(data[sf].GenusData[ge].NameData);
			data[sf].GenusData[ge].NameData=NULL;
		}
		zogiiDeletepicDB(&data[sf].GenusData[ge].GE,	\
							Imagodata,Larvadata,Pupadata,Ovumdata,Closeupdata);

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
				zogiiDeletepicDB(&data[sf].GenusData[ge].NameData[na].SpData[k],	\
							Imagodata,Larvadata,Pupadata,Ovumdata,Closeupdata);

			free(data[sf].GenusData[ge].NameData[na].SpData);
			data[sf].GenusData[ge].NameData[na].SpData=NULL;
		}
		zogiiDeletepicDB(&data[sf].GenusData[ge].NameData[na].NA,	\
							Imagodata,Larvadata,Pupadata,Ovumdata,Closeupdata);

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
		zogiiDeletepicDB(&data[sf].GenusData[ge].NameData[na].SpData[sp],	\
							Imagodata,Larvadata,Pupadata,Ovumdata,Closeupdata);

		if(sp != (data[sf].GenusData[ge].NameData[na].SpTotal -1))
			memmove(&data[sf].GenusData[ge].NameData[na].SpData[sp],&data[sf].GenusData[ge].NameData[na].SpData[sp+1],	\
				sizeof(struct ZOGII_Coccinellidae_DATA)*(data[sf].GenusData[ge].NameData[na].SpTotal-sp-1));

		data[sf].GenusData[ge].NameData[na].SpTotal--;
	}
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
					   int i,char *temp)
{
	char str[ZOGII_PAT_MAX];
	//数据不为空
	if( NULL!=newdata->Text[i][0] || NULL!=newdata->Text[i][1])
	{
		//值相同则不必拷
		if(strcmp(newdata->Text[i],temp))
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
		//如果都为空则不必删
		if(strcmp(newdata->Text[i],temp))
			zogiiDeleteFile(temp);
	}
}

////////////////////////////增加图片
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
					ZOGII_ULONG_TYPE *tempCloseup)
{
	ZOGII_ULONG_TYPE i; 
	char str[ZOGII_PAT_MAX];

/////////////////////Imago////////////////
	for(i=0;i<ZOGII_PIC_Imago_MAX;i++)
	{
		//有新值添加
		if(NewImagodata[i].flag)
		{
			sprintf(str,"%s\\Imago%02d%s",data->Path,i,strrchr(NewImagodata[i].Path,'.'));
			// 修改
			if(tempImago[i] && Imagodata[tempImago[i]].flag)
			{
				zogiiModifyImagoDBLite(&Imagodata[tempImago[i]],&NewImagodata[i],str);
				data->Imago[i]=tempImago[i];
			}
			else //原先为0 则增加
			{
				data->Imago[i]=zogiiADDImagoDBLite(Imagototal,Imagodata,str,&NewImagodata[i]);
			}
		}
		else	 if(tempImago[i])
			data->Imago[i]=zogiiDeleteImagoDBLite(tempImago[i],Imagodata);
	}

/////////////////////Larva////////////////
	for(i=0;i<ZOGII_PIC_Larva_MAX;i++)
	{
		//有新值添加
		if(NewLarvadata[i].flag)
		{
			sprintf(str,"%s\\Larva%02d%s",data->Path,i,strrchr(NewLarvadata[i].Path,'.'));
			// 修改
			if(tempLarva[i] && Larvadata[tempLarva[i]].flag)
			{
				zogiiModifyLarvaDBLite(&Larvadata[tempLarva[i]],&NewLarvadata[i],str);
				data->Larva[i]=tempLarva[i];
			}
			else //原先为0 则增加
			{
				data->Larva[i]=zogiiADDLarvaDBLite(Larvatotal,Larvadata,str,&NewLarvadata[i]);
			}
		}
		else	 if(tempLarva[i])
			data->Larva[i]=zogiiDeleteLarvaDBLite(tempLarva[i],Larvadata);
	}

/////////////////////Pupa////////////////
	for(i=0;i<ZOGII_PIC_Pupa_MAX;i++)
	{
		//有新值添加
		if(NewPupadata[i].flag)
		{
			sprintf(str,"%s\\Pupa%02d%s",data->Path,i,strrchr(NewPupadata[i].Path,'.'));
			// 修改
			if(tempPupa[i] && Pupadata[tempPupa[i]].flag)
			{
				zogiiModifyPupaDBLite(&Pupadata[tempPupa[i]],&NewPupadata[i],str);
				data->Pupa[i]=tempPupa[i];
			}
			else //原先为0 则增加
			{
				data->Pupa[i]=zogiiADDPupaDBLite(Pupatotal,Pupadata,str,&NewPupadata[i]);
			}
		}
		else	 if(tempPupa[i])
			data->Pupa[i]=zogiiDeletePupaDBLite(tempPupa[i],Pupadata);
	}
/////////////////////Ovum////////////////
	for(i=0;i<ZOGII_PIC_Ovum_MAX;i++)
	{
		//有新值添加
		if(NewOvumdata[i].flag)
		{
			sprintf(str,"%s\\Ovum%02d%s",data->Path,i,strrchr(NewOvumdata[i].Path,'.'));
			// 修改
			if(tempOvum[i] && Ovumdata[tempOvum[i]].flag)
			{
				zogiiModifyOvumDBLite(&Ovumdata[tempOvum[i]],&NewOvumdata[i],str);
				data->Ovum[i]=tempOvum[i];
			}
			else //原先为0 则增加
			{
				data->Ovum[i]=zogiiADDOvumDBLite(Ovumtotal,Ovumdata,str,&NewOvumdata[i]);
			}
		}
		else	 if(tempOvum[i])
			data->Ovum[i]=zogiiDeleteOvumDBLite(tempOvum[i],Ovumdata);
	}
/////////////////////Closeup////////////////
	for(i=0;i<ZOGII_PIC_Closeup_MAX;i++)
	{
		//有新值添加
		if(NewCloseupdata[i].flag)
		{
			sprintf(str,"%s\\Closeup%02d%s",data->Path,i,strrchr(NewCloseupdata[i].Path,'.'));
			// 修改
			if(tempCloseup[i] && Closeupdata[tempCloseup[i]].flag)
			{
				zogiiModifyCloseupDBLite(&Closeupdata[tempCloseup[i]],&NewCloseupdata[i],str);
				data->Closeup[i]=tempCloseup[i];
			}
			else //原先为0 则增加
			{
				data->Closeup[i]=zogiiADDCloseupDBLite(Closeuptotal,Closeupdata,str,&NewCloseupdata[i]);
			}
		}
		else	 if(tempCloseup[i])
			data->Closeup[i]=zogiiDeleteCloseupDBLite(tempCloseup[i],Closeupdata);
	}
}

//////////////////////////////////Imago////////////////
ZOGII_ULONG_TYPE zogiiADDImagoDBLite(ZOGII_ULONG_TYPE *Imagototal,	struct ZOGII_Imago *&Imagodata,
									char *Path,struct ZOGII_Imago *NewImagodata)
{
	ZOGII_ULONG_TYPE i,t;
	t=(*Imagototal);

	if(t)
	{	
		//先找无效的
		for(i=1;i<t;i++)
		{
			if(0==Imagodata[i].flag)
			{
				zogiiCopyImagoDBLite(&Imagodata[i],NewImagodata);
				memcpy(Imagodata[i].Path,Path,ZOGII_PAT_MAX);

				//覆盖
				zogiiCopyFile(NewImagodata->Path,Imagodata[i].Path);
				return i;
			}
		}
		//都是有效则新建
		Imagodata=(struct ZOGII_Imago *)realloc(Imagodata,(t+1)*sizeof(struct ZOGII_Imago));
	}
	else
		Imagodata=(struct ZOGII_Imago *)calloc((t+1),sizeof(struct ZOGII_Imago));

	zogiiCopyImagoDBLite(&Imagodata[t],NewImagodata);
	memcpy(Imagodata[t].Path,Path,ZOGII_PAT_MAX);
		
	//覆盖
	zogiiCopyFile(NewImagodata->Path,Imagodata[t].Path);
	(*Imagototal)++;
	return t;
}

void zogiiModifyImagoDBLite(struct ZOGII_Imago *pdata,struct ZOGII_Imago *newpic,char *path)
{
	//路径不同 拷贝
	if(strcmp(pdata->Path,newpic->Path))
	{
		//删除旧的 故意不删
	//	zogiiDeleteFile(pdata->Path);

		memcpy(pdata->Path,path,ZOGII_PAT_MAX);
		//覆盖
		zogiiCopyFile(newpic->Path,pdata->Path);
	}
	zogiiCopyImagoDBLite(pdata,newpic);
}

void  zogiiCopyImagoDBLite(struct ZOGII_Imago *pdata,struct ZOGII_Imago *newpic)
{
	pdata->flag=1;
	memcpy(pdata->Info,newpic->Info,sizeof(char)*ZOGII_PAT_MAX);

	memcpy(pdata->ElytraColor,newpic->ElytraColor,sizeof(char)*ZOGII_COR_MAX);
	pdata->ElytraColorNum=newpic->ElytraColorNum;
	pdata->ElytraPointNum=newpic->ElytraPointNum;
	pdata->ElytraTexture=newpic->ElytraTexture;
	memcpy(pdata->PronotumColor,newpic->PronotumColor,sizeof(char)*ZOGII_COR_MAX);
	pdata->PronotumColorNum=newpic->PronotumColorNum;
	pdata->PronotumPointNum=newpic->PronotumPointNum;
	pdata->PronotumTexture=newpic->PronotumTexture;
	pdata->Sex=newpic->Sex;
}
//////////////////////////Larva////////////////////////////////////////
ZOGII_ULONG_TYPE zogiiADDLarvaDBLite(ZOGII_ULONG_TYPE *Larvatotal,	struct ZOGII_Larva *&Larvadata,
									char *Path,struct ZOGII_Larva *NewLarvadata)
{
	ZOGII_ULONG_TYPE i,t;
	t=(*Larvatotal);

	if(t)
	{	
		//先找无效的
		for(i=1;i<t;i++)
		{
			if(0==Larvadata[i].flag)
			{
				zogiiCopyLarvaDBLite(&Larvadata[i],NewLarvadata);
				memcpy(Larvadata[i].Path,Path,ZOGII_PAT_MAX);

				//覆盖
				zogiiCopyFile(NewLarvadata->Path,Larvadata[i].Path);
				return i;
			}
		}
		//都是有效则新建
		Larvadata=(struct ZOGII_Larva *)realloc(Larvadata,(t+1)*sizeof(struct ZOGII_Larva));
	}
	else
		Larvadata=(struct ZOGII_Larva *)calloc((t+1),sizeof(struct ZOGII_Larva));

	zogiiCopyLarvaDBLite(&Larvadata[t],NewLarvadata);
	memcpy(Larvadata[t].Path,Path,ZOGII_PAT_MAX);
		
	//覆盖
	zogiiCopyFile(NewLarvadata->Path,Larvadata[t].Path);
	(*Larvatotal)++;
	return t;
}

void zogiiModifyLarvaDBLite(struct ZOGII_Larva *pdata,struct ZOGII_Larva *newpic,char *path)
{
	//路径不同 拷贝
	if(strcmp(pdata->Path,newpic->Path))
	{
		//删除旧的 故意不删
	//	zogiiDeleteFile(pdata->Path);

		memcpy(pdata->Path,path,ZOGII_PAT_MAX);
		//覆盖
		zogiiCopyFile(newpic->Path,pdata->Path);
	}
	zogiiCopyLarvaDBLite(pdata,newpic);
}

void  zogiiCopyLarvaDBLite(struct ZOGII_Larva *pdata,struct ZOGII_Larva *newpic)
{
	pdata->flag=1;
	memcpy(pdata->Info,newpic->Info,sizeof(char)*ZOGII_PAT_MAX);

	pdata->Calthrop=newpic->Calthrop;
	memcpy(pdata->Color,newpic->Color,sizeof(char)*ZOGII_COR_MAX);
	pdata->ColorNum=newpic->ColorNum;
	pdata->Instar=newpic->Instar;
	pdata->Sex=newpic->Sex;
}

//////////////////////////Pupa////////////////////////////////////////

ZOGII_ULONG_TYPE zogiiADDPupaDBLite(ZOGII_ULONG_TYPE *Pupatotal,	struct ZOGII_Pupa *&Pupadata,
									char *Path,struct ZOGII_Pupa *NewPupadata)
{
	ZOGII_ULONG_TYPE i,t;
	t=(*Pupatotal);

	if(t)
	{	
		//先找无效的
		for(i=1;i<t;i++)
		{
			if(0==Pupadata[i].flag)
			{
				zogiiCopyPupaDBLite(&Pupadata[i],NewPupadata);
				memcpy(Pupadata[i].Path,Path,ZOGII_PAT_MAX);

				//覆盖
				zogiiCopyFile(NewPupadata->Path,Pupadata[i].Path);
				return i;
			}
		}
		//都是有效则新建
		Pupadata=(struct ZOGII_Pupa *)realloc(Pupadata,(t+1)*sizeof(struct ZOGII_Pupa));
	}
	else
		Pupadata=(struct ZOGII_Pupa *)calloc((t+1),sizeof(struct ZOGII_Pupa));

	zogiiCopyPupaDBLite(&Pupadata[t],NewPupadata);
	memcpy(Pupadata[t].Path,Path,ZOGII_PAT_MAX);
		
	//覆盖
	zogiiCopyFile(NewPupadata->Path,Pupadata[t].Path);
	(*Pupatotal)++;
	return t;
}

void zogiiModifyPupaDBLite(struct ZOGII_Pupa *pdata,struct ZOGII_Pupa *newpic,char *path)
{
	//路径不同 拷贝
	if(strcmp(pdata->Path,newpic->Path))
	{
		//删除旧的 故意不删
	//	zogiiDeleteFile(pdata->Path);

		memcpy(pdata->Path,path,ZOGII_PAT_MAX);
		//覆盖
		zogiiCopyFile(newpic->Path,pdata->Path);
	}
	zogiiCopyPupaDBLite(pdata,newpic);
}

void  zogiiCopyPupaDBLite(struct ZOGII_Pupa *pdata,struct ZOGII_Pupa *newpic)
{
	pdata->flag=1;
	memcpy(pdata->Info,newpic->Info,sizeof(char)*ZOGII_PAT_MAX);

	memcpy(pdata->Color,newpic->Color,sizeof(char)*ZOGII_COR_MAX);
	pdata->ColorNum=newpic->ColorNum;
	pdata->Sex=newpic->Sex;
	pdata->Type=newpic->Type;
}
//////////////////////////Ovum////////////////////////////////////////
ZOGII_ULONG_TYPE zogiiADDOvumDBLite(ZOGII_ULONG_TYPE *Ovumtotal,	struct ZOGII_Ovum *&Ovumdata,
									char *Path,struct ZOGII_Ovum *NewOvumdata)
{
	ZOGII_ULONG_TYPE i,t;
	t=(*Ovumtotal);

	if(t)
	{	
		//先找无效的
		for(i=1;i<t;i++)
		{
			if(0==Ovumdata[i].flag)
			{
				zogiiCopyOvumDBLite(&Ovumdata[i],NewOvumdata);
				memcpy(Ovumdata[i].Path,Path,ZOGII_PAT_MAX);

				//覆盖
				zogiiCopyFile(NewOvumdata->Path,Ovumdata[i].Path);
				return i;
			}
		}
		//都是有效则新建
		Ovumdata=(struct ZOGII_Ovum *)realloc(Ovumdata,(t+1)*sizeof(struct ZOGII_Ovum));
	}
	else
		Ovumdata=(struct ZOGII_Ovum *)calloc((t+1),sizeof(struct ZOGII_Ovum));

	zogiiCopyOvumDBLite(&Ovumdata[t],NewOvumdata);
	memcpy(Ovumdata[t].Path,Path,ZOGII_PAT_MAX);
		
	//覆盖
	zogiiCopyFile(NewOvumdata->Path,Ovumdata[t].Path);
	(*Ovumtotal)++;
	return t;
}

void zogiiModifyOvumDBLite(struct ZOGII_Ovum *pdata,struct ZOGII_Ovum *newpic,char *path)
{
	//路径不同 拷贝
	if(strcmp(pdata->Path,newpic->Path))
	{
		//删除旧的 故意不删
	//	zogiiDeleteFile(pdata->Path);

		memcpy(pdata->Path,path,ZOGII_PAT_MAX);
		//覆盖
		zogiiCopyFile(newpic->Path,pdata->Path);
	}
	zogiiCopyOvumDBLite(pdata,newpic);
}

void  zogiiCopyOvumDBLite(struct ZOGII_Ovum *pdata,struct ZOGII_Ovum *newpic)
{
	pdata->flag=1;
	memcpy(pdata->Info,newpic->Info,sizeof(char)*ZOGII_PAT_MAX);

	pdata->Color=newpic->Color;
	pdata->Sex=newpic->Sex;
}

//////////////////////////Closeup////////////////////////////////////////
ZOGII_ULONG_TYPE zogiiADDCloseupDBLite(ZOGII_ULONG_TYPE *Closeuptotal,	struct ZOGII_Closeup *&Closeupdata,
									char *Path,struct ZOGII_Closeup *NewCloseupdata)
{
	ZOGII_ULONG_TYPE i,t;
	t=(*Closeuptotal);

	if(t)
	{	
		//先找无效的
		for(i=1;i<t;i++)
		{
			if(0==Closeupdata[i].flag)
			{
				zogiiCopyCloseupDBLite(&Closeupdata[i],NewCloseupdata);
				memcpy(Closeupdata[i].Path,Path,ZOGII_PAT_MAX);

				//覆盖
				zogiiCopyFile(NewCloseupdata->Path,Closeupdata[i].Path);
				return i;
			}
		}
		//都是有效则新建
		Closeupdata=(struct ZOGII_Closeup *)realloc(Closeupdata,(t+1)*sizeof(struct ZOGII_Closeup));
	}
	else
		Closeupdata=(struct ZOGII_Closeup *)calloc((t+1),sizeof(struct ZOGII_Closeup));

	zogiiCopyCloseupDBLite(&Closeupdata[t],NewCloseupdata);
	memcpy(Closeupdata[t].Path,Path,ZOGII_PAT_MAX);
		
	//覆盖
	zogiiCopyFile(NewCloseupdata->Path,Closeupdata[t].Path);
	(*Closeuptotal)++;
	return t;
}

void zogiiModifyCloseupDBLite(struct ZOGII_Closeup *pdata,struct ZOGII_Closeup *newpic,char *path)
{
	//路径不同 拷贝
	if(strcmp(pdata->Path,newpic->Path))
	{
		//删除旧的 故意不删
	//	zogiiDeleteFile(pdata->Path);

		memcpy(pdata->Path,path,ZOGII_PAT_MAX);
		//覆盖
		zogiiCopyFile(newpic->Path,pdata->Path);
	}
	zogiiCopyCloseupDBLite(pdata,newpic);
}

void  zogiiCopyCloseupDBLite(struct ZOGII_Closeup *pdata,struct ZOGII_Closeup *newpic)
{
	pdata->flag=1;
	memcpy(pdata->Info,newpic->Info,sizeof(char)*ZOGII_PAT_MAX);
	
	pdata->Type=newpic->Type;
}
///////////////////////////////////////////////////
void zogiiInitpicDB(struct ZOGII_Coccinellidae_DATA *data)
{
	unsigned int i; 
	for(i=0;i<ZOGII_PIC_Imago_MAX;i++)
		data->Imago[i]=0;
	
	for(i=0;i<ZOGII_PIC_Larva_MAX;i++)
		data->Larva[i]=0;
	
	for(i=0;i<ZOGII_PIC_Pupa_MAX;i++)
		data->Pupa[i]=0;

	for(i=0;i<ZOGII_PIC_Ovum_MAX;i++)
		data->Ovum[i]=0;
	
	for(i=0;i<ZOGII_PIC_Closeup_MAX;i++)
		data->Closeup[i]=0;

	//清理文本信息
	for(i=0;i<ZOGII_LAG_MAX;i++)
		memset(data->Text[i],0,sizeof(char)*ZOGII_PAT_MAX);
	
}

/////////删除图片////////////////////////////////////////////////////

void zogiiDeletepicDB(struct ZOGII_Coccinellidae_DATA *data,
					struct ZOGII_Imago *&Imagodata,
					struct ZOGII_Larva *&Larvadata,
					struct ZOGII_Pupa *&Pupadata,
					struct ZOGII_Ovum *&Ovumdata,
					struct ZOGII_Closeup *&Closeupdata)
{
	unsigned int i; 
	
	for(i=0;i<ZOGII_PIC_Imago_MAX;i++)
	{
		if(data->Imago[i])
			data->Imago[i]=zogiiDeleteImagoDBLite(data->Imago[i],Imagodata);
	}
	
	for(i=0;i<ZOGII_PIC_Larva_MAX;i++)
	{
		if(data->Larva[i])
			data->Larva[i]=zogiiDeleteLarvaDBLite(data->Larva[i],Larvadata);
	}
	
	for(i=0;i<ZOGII_PIC_Pupa_MAX;i++)
	{
		if(data->Pupa[i])
			data->Pupa[i]=zogiiDeletePupaDBLite(data->Pupa[i],Pupadata);
	}
	
	for(i=0;i<ZOGII_PIC_Ovum_MAX;i++)
	{
		if(data->Ovum[i])
			data->Ovum[i]=zogiiDeleteOvumDBLite(data->Ovum[i],Ovumdata);
	}
	
	for(i=0;i<ZOGII_PIC_Closeup_MAX;i++)
	{
		if(data->Closeup[i])
			data->Closeup[i]=zogiiDeleteCloseupDBLite(data->Closeup[i],Closeupdata);
	}
}

ZOGII_ULONG_TYPE zogiiDeleteImagoDBLite(ZOGII_ULONG_TYPE i,
							struct ZOGII_Imago *&Imagodata)
{
	Imagodata[i].flag=0;

	//删除图片
	zogiiDeleteFile(Imagodata[i].Path);
	memset(Imagodata[i].Path,0,sizeof(ZOGII_PAT_MAX));
	memset(Imagodata[i].Info,0,sizeof(ZOGII_PAT_MAX));

	return 0;
}

ZOGII_ULONG_TYPE zogiiDeleteLarvaDBLite(ZOGII_ULONG_TYPE i,
							struct ZOGII_Larva *&Larvadata)
{
	Larvadata[i].flag=0;

	//删除图片
	zogiiDeleteFile(Larvadata[i].Path);
	memset(Larvadata[i].Path,0,sizeof(ZOGII_PAT_MAX));
	memset(Larvadata[i].Info,0,sizeof(ZOGII_PAT_MAX));

	return 0;
}

ZOGII_ULONG_TYPE zogiiDeletePupaDBLite(ZOGII_ULONG_TYPE i,
							struct ZOGII_Pupa *&Pupadata)
{
	Pupadata[i].flag=0;

	//删除图片
	zogiiDeleteFile(Pupadata[i].Path);
	memset(Pupadata[i].Path,0,sizeof(ZOGII_PAT_MAX));
	memset(Pupadata[i].Info,0,sizeof(ZOGII_PAT_MAX));

	return 0;
}

ZOGII_ULONG_TYPE zogiiDeleteOvumDBLite(ZOGII_ULONG_TYPE i,
							struct ZOGII_Ovum *&Ovumdata)
{
	Ovumdata[i].flag=0;

	//删除图片
	zogiiDeleteFile(Ovumdata[i].Path);
	memset(Ovumdata[i].Path,0,sizeof(ZOGII_PAT_MAX));
	memset(Ovumdata[i].Info,0,sizeof(ZOGII_PAT_MAX));

	return 0;
}

ZOGII_ULONG_TYPE zogiiDeleteCloseupDBLite(ZOGII_ULONG_TYPE i,
							struct ZOGII_Closeup *&Closeupdata)
{
	Closeupdata[i].flag=0;

	//删除图片
	zogiiDeleteFile(Closeupdata[i].Path);
	memset(Closeupdata[i].Path,0,sizeof(ZOGII_PAT_MAX));
	memset(Closeupdata[i].Info,0,sizeof(ZOGII_PAT_MAX));

	return 0;
}
