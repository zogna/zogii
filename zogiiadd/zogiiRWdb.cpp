#include "stdafx.h"
#include "zogiidb.h"

unsigned long int zogii_version=0;

unsigned long int zogiiVersionDB(void)
{
	return zogii_version;
}

int zogiiReadDB(unsigned int *total,struct ZOGII_Coccinellidae_SUBFamily *&data,	\
				unsigned long int *pictotal,struct ZOGII_Pic *&picdata)
{

	unsigned int i,j,k;
	FILE *fp;
	char str[ZOGII_PAT_MAX];
	sprintf(str,"%s\\%s",ZOGII_DB_DIRSTR,ZOGII_DB_FILSTR);
	fp=fopen(str,"rb");
	if(fp)
	{
		fread(&zogii_version,sizeof(unsigned long int),1,fp);
		fread(total,sizeof(unsigned int),1,fp);
		if(*total)
		{
			data=(struct ZOGII_Coccinellidae_SUBFamily *)calloc(*total,sizeof(struct ZOGII_Coccinellidae_SUBFamily));
			fread(data,sizeof(struct ZOGII_Coccinellidae_SUBFamily),*total,fp);
		}
		for(i=0;i<*total;i++)
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
		fread(pictotal,sizeof(unsigned long int),1,fp);
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
		*total=0;
		data=NULL;
		//初始化第一个为无效
		*pictotal=1;
		picdata=(struct ZOGII_Pic *)calloc(*pictotal,sizeof(struct ZOGII_Pic));
		picdata[0].flag=0;		
		//创建根目录
		CreateDirectory(ZOGII_DB_DIRSTR, NULL);

		return 0;
	}
}

int zogiiWriteDB(unsigned int total,struct ZOGII_Coccinellidae_SUBFamily *&data,	\
				 unsigned long int pictotal,struct ZOGII_Pic *&picdata)

{
	unsigned int i,j,k;
	FILE *fp;
	char str[ZOGII_PAT_MAX];
	sprintf(str,"%s\\%s",ZOGII_DB_DIRSTR,ZOGII_DB_FILSTR);
	fp=fopen(str,"wb");
	if(fp)
	{
		//保存一次 版本+1次
		zogii_version++;
		fwrite(&zogii_version,sizeof(unsigned long int),1,fp);
		fwrite(&total,sizeof(unsigned int),1,fp);

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

		fwrite(&pictotal,sizeof(unsigned long int),1,fp);
		if(pictotal)
			fwrite(picdata,sizeof(struct ZOGII_Pic),pictotal,fp);

		fclose(fp);
		return 1;
	}
	return 0;
}
//编号生成器
unsigned int zogiiCodeGen(unsigned int *total,struct ZOGII_Coccinellidae_SUBFamily *&data,	\
					unsigned char type,unsigned int sf,unsigned int ge,unsigned int na)
{
	unsigned int i,j;
	unsigned int max=0;
	unsigned char flag=0;
	unsigned int t;

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

void zogiiAddSaveDB(unsigned int *total,struct ZOGII_Coccinellidae_SUBFamily *&data,	\
				unsigned long int *pictotal,struct ZOGII_Pic *&picdata,	\
				unsigned char type,unsigned int sf,unsigned int ge,unsigned int na,	unsigned int sp,	\
				struct ZOGII_Coccinellidae_DATA *newdata,	\
				unsigned char NewPictotal,struct ZOGII_Pic *NewPicdata)
{
	unsigned int t;

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

		memcpy(&data[t].SF,newdata,sizeof(struct ZOGII_Coccinellidae_DATA));
		//创建CODE和目录
		data[t].SF.code=zogiiCodeGen(total,data,type,sf,ge,na);
		sprintf(data[t].SF.path,"%s\\%05d",ZOGII_DB_DIRSTR,data[t].SF.code);
		CreateDirectory(data[t].SF.path, NULL);

		zogiiADDpicDB(&data[t].SF,pictotal,picdata,newdata, NewPictotal,NewPicdata);

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

		memcpy(&data[sf].GenusData[t].GE,newdata,sizeof(struct ZOGII_Coccinellidae_DATA));
		//创建CODE和目录
		data[sf].GenusData[t].GE.code=zogiiCodeGen(total,data,type,sf,ge,na);
		sprintf(data[sf].GenusData[t].GE.path,"%s\\%05d\\%05d",	\
			ZOGII_DB_DIRSTR,data[sf].SF.code,data[sf].GenusData[t].GE.code);
		CreateDirectory(data[sf].GenusData[t].GE.path, NULL);
		
		zogiiADDpicDB(&data[sf].GenusData[t].GE,pictotal,picdata,newdata, NewPictotal,NewPicdata);

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

		memcpy(&data[sf].GenusData[ge].NameData[t].NA,newdata,sizeof(struct ZOGII_Coccinellidae_DATA));
		//创建CODE和目录
		data[sf].GenusData[ge].NameData[t].NA.code=zogiiCodeGen(total,data,type,sf,ge,na);
		sprintf(data[sf].GenusData[ge].NameData[t].NA.path,"%s\\%05d\\%05d\\%05d",	\
			ZOGII_DB_DIRSTR,data[sf].SF.code,	\
			data[sf].GenusData[ge].GE.code,	\
			data[sf].GenusData[ge].NameData[t].NA.code);
		CreateDirectory(data[sf].GenusData[ge].NameData[t].NA.path, NULL);
		
		zogiiADDpicDB(&data[sf].GenusData[ge].NameData[t].NA,pictotal,picdata,newdata, NewPictotal,NewPicdata);

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
		
		memcpy(&data[sf].GenusData[ge].NameData[na].SpData[t],newdata,sizeof(struct ZOGII_Coccinellidae_DATA));
		//创建CODE和目录
		data[sf].GenusData[ge].NameData[na].SpData[t].code=zogiiCodeGen(total,data,type,sf,ge,na);
		sprintf(data[sf].GenusData[ge].NameData[na].SpData[t].path,"%s\\%05d\\%05d\\%05d\\%05d",	\
			ZOGII_DB_DIRSTR,data[sf].SF.code,data[sf].GenusData[ge].GE.code,	\
			data[sf].GenusData[ge].NameData[na].NA.code,	\
			data[sf].GenusData[ge].NameData[na].SpData[t].code);
		CreateDirectory(data[sf].GenusData[ge].NameData[na].SpData[t].path, NULL);

		zogiiADDpicDB(&data[sf].GenusData[ge].NameData[na].SpData[t],pictotal,picdata,newdata, NewPictotal,NewPicdata);

		data[sf].GenusData[ge].NameData[na].SpTotal++;
	}
	else if(TYPE_SubFamily == type)
	{
		memcpy(&data[sf].SF,newdata,sizeof(struct ZOGII_Coccinellidae_DATA));
		zogiiADDpicDB(&data[sf].SF,pictotal,picdata,newdata, NewPictotal,NewPicdata);
	}
	else if(TYPE_Genus == type)
	{
		memcpy(&data[sf].GenusData[ge].GE,newdata,sizeof(struct ZOGII_Coccinellidae_DATA));
		zogiiADDpicDB(&data[sf].GenusData[ge].GE,pictotal,picdata,newdata, NewPictotal,NewPicdata);
	}
	else if(TYPE_Name == type)
	{
		memcpy(&data[sf].GenusData[ge].NameData[na].NA,newdata,sizeof(struct ZOGII_Coccinellidae_DATA));
		zogiiADDpicDB(&data[sf].GenusData[ge].NameData[na].NA,pictotal,picdata,newdata, NewPictotal,NewPicdata);
	}	
	else if(TYPE_SpName == type)
	{
		memcpy(&data[sf].GenusData[ge].NameData[na].SpData[sp],newdata,sizeof(struct ZOGII_Coccinellidae_DATA));
		zogiiADDpicDB(&data[sf].GenusData[ge].NameData[na].SpData[sp],pictotal,picdata,newdata, NewPictotal,NewPicdata);
	}
}

void zogiiDeleteDB(unsigned int *total,struct ZOGII_Coccinellidae_SUBFamily *&data,	\
			   unsigned char type,unsigned int sf,unsigned int ge,unsigned int na,unsigned int sp,	\
			   struct ZOGII_Pic *&picdata)
{
	unsigned int i,j,k;

	if(TYPE_SubFamily == type)
	{
		//删整个文件夹
		RemoveDirectory(data[sf].SF.path);
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
						}
						zogiiDeletepicDB(&data[sf].GenusData[i].NameData[j].NA,picdata);
					}
				}
				zogiiDeletepicDB(&data[sf].GenusData[i].GE,picdata);
			}
		}
		zogiiDeletepicDB(&data[sf].SF,picdata);

		//如果不是最后一个数据 则移动
		if( sf != (*total -1))
			memmove(&data[sf],&data[sf+1],sizeof(struct ZOGII_Coccinellidae_SUBFamily)*(*total-sf-1));

		(*total)--;
	}
	else if(TYPE_Genus == type)
	{
		//删整个文件夹
		RemoveDirectory(data[sf].GenusData[ge].GE.path);
		//删图片
		if(data[sf].GenusData[ge].NameTotal)
		{
			for(j=0;j<data[sf].GenusData[ge].NameTotal;j++)
			{
				if(data[sf].GenusData[ge].NameData[j].SpTotal)
				{
					for(k=0;k<data[sf].GenusData[ge].NameData[j].SpTotal;k++)
						zogiiDeletepicDB(&data[sf].GenusData[ge].NameData[j].SpData[k],picdata);
				}
				zogiiDeletepicDB(&data[sf].GenusData[ge].NameData[j].NA,picdata);
			}
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
		RemoveDirectory(data[sf].GenusData[ge].NameData[na].NA.path);
		//删图片
		if(data[sf].GenusData[ge].NameData[na].SpTotal)
		{
			for(k=0;k<data[sf].GenusData[ge].NameData[na].SpTotal;k++)
				zogiiDeletepicDB(&data[sf].GenusData[ge].NameData[na].SpData[k],picdata);
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
		RemoveDirectory(data[sf].GenusData[ge].NameData[na].SpData[sp].path);
		//删图片
		zogiiDeletepicDB(&data[sf].GenusData[ge].NameData[na].SpData[sp],picdata);

		if(sp != (data[sf].GenusData[ge].NameData[na].SpTotal -1))
			memmove(&data[sf].GenusData[ge].NameData[na].SpData[sp],&data[sf].GenusData[ge].NameData[na].SpData[sp+1],	\
				sizeof(struct ZOGII_Coccinellidae_DATA)*(data[sf].GenusData[ge].NameData[na].SpTotal-sp-1));

		data[sf].GenusData[ge].NameData[na].SpTotal--;
	}
}

void zogiiFreeDB(unsigned int *total,struct ZOGII_Coccinellidae_SUBFamily *&data,	\
				  unsigned long int *pictotal,struct ZOGII_Pic *&picdata)
{
	unsigned int i,j,k;

	for(i=0;i<*total;i++)
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

	*total=0;
	free(data);
	data=NULL;

	*pictotal=0;
	free(picdata);
	picdata=NULL;
}

void zogiiADDpicDB(struct ZOGII_Coccinellidae_DATA *data,	\
				unsigned long int *pictotal,struct ZOGII_Pic *&picdata,	\
				struct ZOGII_Coccinellidae_DATA *newdata,	\
				unsigned char NewPictotal,struct ZOGII_Pic *NewPicdata)
{
	unsigned char i; 
	if(NewPictotal>1)
	{
		if(newdata->DiscoverMap)
			data->DiscoverMap=zogiiADDpicDBLite(pictotal,picdata,&NewPicdata[newdata->DiscoverMap]);

		for(i=0;i<ZOGII_PIC_MAX;i++)
		{
			if(newdata->Imago[i].Pic)
				data->Imago[i].Pic=zogiiADDpicDBLite(pictotal,picdata,&NewPicdata[newdata->Imago[i].Pic]);
			if(newdata->Larva[i].Pic)
				data->Larva[i].Pic=zogiiADDpicDBLite(pictotal,picdata,&NewPicdata[newdata->Larva[i].Pic]);
			if(newdata->Pupa[i].Pic)
				data->Pupa[i].Pic=zogiiADDpicDBLite(pictotal,picdata,&NewPicdata[newdata->Pupa[i].Pic]);
			if(newdata->Ovum[i].Pic)
				data->Ovum[i].Pic=zogiiADDpicDBLite(pictotal,picdata,&NewPicdata[newdata->Ovum[i].Pic]);
		}
	}
}

void zogiiDeletepicDB(struct ZOGII_Coccinellidae_DATA *data,struct ZOGII_Pic *&picdata)
{
	unsigned char i; 

	if(data->DiscoverMap)
		zogiiDeletepicDBLite(data->DiscoverMap,picdata);

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

unsigned long int zogiiADDpicDBLite(unsigned long int *pictotal,struct ZOGII_Pic *&picdata,	\
								struct ZOGII_Pic *newpic)
{
	unsigned long int i,t;

	t=*pictotal;

	if(t)
	{	
		//先找无效的
		for(i=0;i<t;i++)
		{
			if(0==picdata[i].flag)
			{
				memcpy(&picdata[i],newpic,sizeof(struct ZOGII_Pic));
				return i;
			}
		}
		//都是有效则新建
		picdata=(struct ZOGII_Pic *)realloc(picdata,(t+1)*sizeof(struct ZOGII_Pic));
	}
	else
		picdata=(struct ZOGII_Pic *)calloc((t+1),sizeof(struct ZOGII_Pic));

	memcpy(&picdata[t],newpic,sizeof(struct ZOGII_Pic));
	*pictotal++;
	return t;
}

unsigned long int zogiiDeletepicDBLite(unsigned long int i,struct ZOGII_Pic *&picdata)
{
	picdata[i].flag=0;

	memset(picdata[i].Path,0,sizeof(ZOGII_PAT_MAX));
	memset(picdata[i].Info,0,sizeof(ZOGII_STR_MAX));
	return 0;
}

