#include<iostream>
using namespace std;
#include<stdio.h>
#include<string>
#include "SaveDisk.h"
#include"DateBase.h"
#include"DBDataType.h"
#include"VerificationList.h"
#include"FileString.h"
#include"CheckDisk.h"
#pragma warning(disable : 4996)

bool SaveCreateTable(DateTable DB, int conutMK, int countV)
{

	string FileTitle = DB.title + FileTypeList;
	if (!checkFile(FileTitle))
	{
		{
			char cc[50];
			int j;
			for (j = 0; j < DB.title.length(); j++)
				cc[j] = DB.title[j];
			cc[j] = '\0';

			MajorKeyTitle *tempMKT = &DB.nextMK;
			FILE *fpl;
			fpl = fopen("MajorKey.txt", "ab");
			for (int i = 0; i < conutMK; i++)
			{
				char tt[50];//属性名
				for (j = 0; j < (tempMKT->title[i].length()); j++)
					tt[j] = tempMKT->title[i][j];
				tt[j] = '\0';
				fprintf(fpl, "%s\n%s\n", cc, tt);
			}
			fclose(fpl);
		}
		DTTitle *tempDT = &DB.nextT;
		{
			char cc[50];
			int j;
			for (j = 0; j < FileTitle.length(); j++)
				cc[j] = FileTitle[j];
			cc[j] = '\0';

			FILE *fpSCT;
			fpSCT = fopen(cc, "wb");
			fprintf(fpSCT, "%d\n", countV);
			while (tempDT->nextT != NULL)
			{
				char aa[50];
				for (int i = 0; i <= (tempDT->title.length()); i++)
					aa[i] = tempDT->title[i];
				fprintf(fpSCT, "%s\n%d\n", aa, tempDT->type);
				tempDT = tempDT->nextT;
			}
			fclose(fpSCT);
		}
		return true;
	}
	else
		return false;
}

bool SaveInsertInto(VerificationDataType *VerificationDT, string title, WordlListInsert *WLI, string MajorKeyVerificationData)
{
	for (int k1 = 0; k1 < VerificationDT->countVDT; k1++)//保存属性值
	{
		string FileName = title + VerificationDT->c + "Data.txt";
		char FN[100];
		for (int jFN = 0; jFN <= FileName.length(); jFN++)
			FN[jFN] = FileName[jFN];
		FILE *fpSIIV;
		fpSIIV = fopen(FN, "ab");
		char cc[50];
		for (int jCC = 0; jCC <= WLI->c.length(); jCC++)
			cc[jCC] = WLI->c[jCC];
		fprintf(fpSIIV, "%s\n", cc);
		VerificationDT = VerificationDT->nextVDT;
		WLI = WLI->next;
		fclose(fpSIIV);
	}

	{
		string FileName = title + "MajorKeyData.txt";
		char FN[100];
		for (int jFN = 0; jFN <= FileName.length(); jFN++)
			FN[jFN] = FileName[jFN];
		FILE *fpSIIMK;
		fpSIIMK = fopen(FN, "ab");

		char cc[1000];
		for (int jCC = 0; jCC <= MajorKeyVerificationData.length(); jCC++)
			cc[jCC] = MajorKeyVerificationData[jCC];

		fprintf(fpSIIMK, "%s\n", cc);

		fclose(fpSIIMK);
	}



	return true;
}




/////////read
