// filecat.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "windows.h"
#include "stdlib.h"

int main(int argc, char* argv[])
{
	system("dir /s /b \"*.txt\" >file.list");

	FILE *fp;
	char tempstr[260];

	FILE *dstfp;
	dstfp=fopen("dst.txt","wb");
	if(!dstfp)
		return 0;

	FILE *srcfp;
	int i;

	long int fsize;
	unsigned char temp[5120];

	fp=fopen("file.list","r");
	if(fp)
	{
		do
		{
			memset(tempstr,0,sizeof(char)*260);
			fgets(tempstr,260*sizeof(char),fp);
			i=strlen(tempstr);
			if(i>0)
			{
				tempstr[i-1]=0;
				
				srcfp=fopen(tempstr,"rb");
				
				if(srcfp)
				{
					fsize=0;
					fseek(srcfp,0,SEEK_END);
					fsize = ftell(srcfp);
					fseek(srcfp,0,SEEK_SET);

					fread(temp,fsize,1,srcfp);

					fwrite(temp,fsize,1,dstfp);




					fclose(srcfp);
				}

			}



		}while(!feof(fp));
		fclose(fp);
	}


	return 0;
}

