#include<iostream>
using namespace std;
#include<stdio.h>
#include<string>
#include "SaveDisk.h"
#include"DateBase.h"
#include"DBDataType.h"
#pragma warning(disable : 4996)

string FileType(char cc[50],int j,string Type)
{
	j--;
	int i=0;
	for (; i < (Type.length()); i++)
	{
		cc[i + j] = Type[i];
	}
	cc[i + j] = '\0';
	return cc;
}

bool SaveCreateTable(DateTable DB,int k)
{
//	while (true)
//	{
		char cc[50];
		int j;
		for (j = 0; j <= (DB.title.length()); j++)
			cc[j] = DB.title[j];
		

		MajorKeyTitle *tempMKT = &DB.nextMK;
		FILE *fpl;
		fpl = fopen("MajorKey.txt", "ab");
		for (int i = 0; i < k; i++)
		{
			char tt[50];//ÊôÐÔÃû
			for (j = 0; j < tempMKT->title[i].length(); j++)
				tt[j] = tempMKT->title[i][j];
			tt[j] = '\0';
			fprintf(fpl, "%s,%s;", cc, tt);
		}
		fclose(fpl);

		DTTitle *tempDT =&DB.nextT;
		string Filename = FileType(cc, j, "List.txt");
		FILE *fp;
		fp= fopen(cc, "wb");
		while (tempDT->nextT!=NULL)
		{
			char aa[50];
			for (int i = 0; i <= (tempDT->title.length()); i++)
				aa[i] = tempDT->title[i];
			fprintf(fp, "%s,%d;", aa, tempDT->type);
			tempDT = tempDT->nextT;
		}
		fclose(fp);

	return true;
}
