#include "stdafx.h"
#include "zogiidb.h"

int zogiiReadDB(unsigned int *total,struct ZOGII_Coccinellidae_SUBFamily *data)
{
	unsigned int i,j,k;
	FILE *fp;
	fp=fopen("zogci.db","rb");
	if(fp)
	{
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

		fclose(fp);
		return 1;
	}
	else
	{
		*total=0;
		data=NULL;
		return 0;
	}
}

int zogiiWriteDB(unsigned int total,struct ZOGII_Coccinellidae_SUBFamily *data)
{
	unsigned int i,j,k;
	FILE *fp;
	fp=fopen("zogci.db","wb");
	if(fp)
	{
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

		fclose(fp);
		return 1;
	}
	return 0;
}

void zogiiAddDB(struct ZOGII_Coccinellidae_SUBFamily *data,unsigned int *total,	\
			   unsigned char type,unsigned int sf,unsigned int ge,unsigned int na,	\
				struct ZOGII_Coccinellidae_DATA *newdata)
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
		data[sf].GenusData[ge].NameData[na].SpTotal++;
	}
}

void zogiiDeleteDB(struct ZOGII_Coccinellidae_SUBFamily *data,unsigned int *total,	\
			   unsigned char type,unsigned int sf,unsigned int ge,unsigned int na,unsigned int sp)
{
	if(TYPE_NEW_SubFamily == type)
	{
		//如果不是最后一个数据 则移动
		if( sf != (*total -1))
			memmove(&data[sf],&data[sf+1],sizeof(struct ZOGII_Coccinellidae_SUBFamily)*(*total-sf-1));
		(*total)--;
	}
	else if(TYPE_NEW_Genus == type)
	{
		if(ge != (data[sf].GenusTotal -1))
			memmove(&data[sf].GenusData[ge],&data[sf].GenusData[ge+1],	\
				sizeof(struct ZOGII_Coccinellidae_GENUS)*(data[sf].GenusTotal-ge-1));
		data[sf].GenusTotal--;
	}
	else if(TYPE_NEW_Name == type)
	{
		if(na != (data[sf].GenusData[ge].NameTotal -1))
			memmove(&data[sf].GenusData[ge].NameData[na],&data[sf].GenusData[ge].NameData[na+1],	\
				sizeof(struct ZOGII_Coccinellidae_NAME)*(data[sf].GenusData[ge].NameTotal-na-1));
		data[sf].GenusData[ge].NameTotal--;
	}	
	else if(TYPE_NEW_SpName == type)
	{
		if(sp != (data[sf].GenusData[ge].NameData[na].SpTotal -1))
			memmove(&data[sf].GenusData[ge].NameData[na].SpData[sp],&data[sf].GenusData[ge].NameData[na].SpData[sp+1],	\
				sizeof(struct ZOGII_Coccinellidae_DATA)*(data[sf].GenusData[ge].NameData[na].SpTotal-sp-1));
		data[sf].GenusData[ge].NameData[na].SpTotal--;
	}
}

void zogiiFreeDB(unsigned int *total,struct ZOGII_Coccinellidae_SUBFamily *data)
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
}