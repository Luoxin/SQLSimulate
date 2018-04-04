#include<iostream>
using namespace std;
#include<stdio.h>
#include<string.h>
#include "SaveDisk.h"
#include"ReadDisk.h"
#include"DateBase.h"
#include"DBDataType.h"
#include"VerificationList.h"
#include"FileString.h"
#include"CheckDisk.h"
#pragma warning(disable : 4996)

//string addr(string c1, string c2)
//{
//	char str[100];
//	{
//		int ja1;
//		for (ja1 = 0; c1[ja1]!='\0'; ja1++)
//			str[ja1] = c1[ja1];
//		for (int j2 = 0; j2 <= c2.length(); j2++)
//			str[ja1 + j2] = c2[j2];
//	}
//	return str;
//}

bool ReadVerificationList(string title, VerificationDataType *VerificationDT)
{

	string FileTitle;
	FileTitle = title + "List.txt";
	char cc[50];

	for (int j = 0; j <= FileTitle.length(); j++)
		cc[j] = FileTitle[j];

	VerificationDataType *tempVDT = VerificationDT;

	FILE *fpRVL;
	fpRVL = fopen(cc, "rb+");
	int temp;

	fscanf(fpRVL, "%d\n", &temp);
	for (int j = 0; j < temp; j++)
	{
		char VDTC[50];
		fscanf(fpRVL, "%s\n%d\n", &VDTC, &(tempVDT->type));
		tempVDT->c = VDTC;
		tempVDT->countVDT = temp;
		tempVDT = tempVDT->nextVDT = new VerificationDataType();
	}
	fclose(fpRVL);
	tempVDT->nextVDT = NULL;
	return true;
}

int ReadMajorKey(string title, MajorKeyList *listWLIT)
{
	FILE *fpRMK;
	fpRMK = fopen("MajorKey.txt", "rb");
	int k = 0;
	while (!feof(fpRMK))
	{
		char cc[50];
		char tt[50];
		fscanf(fpRMK, "%s\n%s\n", tt, cc);
		if (tt == title)
		{
			listWLIT->VerificationName[k++] = cc;
			//			cout << listWLIT->VerificationName[k - 1];
		}
	}
	return k;
}

bool ReadShowTableAll(string title)
{
	VerificationDataType *VerificationDT = new VerificationDataType;
	VerificationDataType *tempRSTAVDT = VerificationDT;
	if (!(ReadVerificationList(title, tempRSTAVDT)))//文件是否存在
	{
		return false;
	}
	tempRSTAVDT = VerificationDT;
	//for (int iDT = 0; iDT < tempRSTAVDT->countVDT; iDT++)
	//{

	//}


	for (int jVDT = 0; jVDT < (tempRSTAVDT->countVDT); jVDT++)
	{
		cout << tempRSTAVDT->c << "    ";
		string FileTitle = title + (tempRSTAVDT->c) + "Data.txt";
		char FT[100];
		for (int iFT = 0; iFT <= FileTitle.length(); iFT++)
			FT[iFT] = FileTitle[iFT];
		FILE *fpRSTA;
		fpRSTA = fopen(FT, "rb+");

		while (!feof(fpRSTA))
		{
			char cc[100];
			fscanf(fpRSTA, "%s\n", cc);
			cout << cc << "     ";
		}

		fclose(fpRSTA);
		cout << endl;
		tempRSTAVDT = tempRSTAVDT->nextVDT;
	}

}


bool ReadAlterTableDrop(string title, string c)
{
	VerificationDataType VerificationDT;
	string FileTitle = title + "List.txt";
	char FT[100];
	for (int iFT = 0; iFT <= FileTitle.length(); iFT++)
		FT[iFT] = FileTitle[iFT];
	VerificationDataType *tempRATAVDT = &VerificationDT;

	FILE *fpRATA1;
	fpRATA1 = fopen(FT, "rb+");

	int jS;

	fscanf(fpRATA1, "%d\n", &jS);
	for (int jFPRATA = 0; jFPRATA < jS; jFPRATA++)
	{
		char VDTC[50];
		fscanf(fpRATA1, "%s\n%d\n", &VDTC, &(tempRATAVDT->type));
		if (VDTC != c)
		{
			tempRATAVDT->c = VDTC;
			tempRATAVDT->countVDT = jS - 1;
			tempRATAVDT = tempRATAVDT->nextVDT = new VerificationDataType();
		}
	}

	fclose(fpRATA1);


	tempRATAVDT = &VerificationDT;
	{
		FILE *fpRATA;
		fpRATA = fopen(FT, "wb+");

		fprintf(fpRATA, "%d\n", tempRATAVDT->countVDT);

		for (int jFPRATA = 0; jFPRATA < tempRATAVDT->countVDT; jFPRATA++)
		{
			char VDTC[50];
			for (int j1 = 0; j1 <= tempRATAVDT->c.length(); j1++)
				VDTC[j1] = tempRATAVDT->c[j1];

			fprintf(fpRATA, "%s\n%d\n", VDTC, (tempRATAVDT->type));
			tempRATAVDT = tempRATAVDT->nextVDT;

		}

		fclose(fpRATA);
	}
	return true;
}

bool ReadAlterTableAdd(string title, string c, int type)
{
	VerificationDataType VerificationDT;
	string FileTitle = title + "List.txt";
	char FT[100];
	for (int iFT = 0; iFT <= FileTitle.length(); iFT++)
		FT[iFT] = FileTitle[iFT];
	VerificationDataType *tempRATAVDT = &VerificationDT;

	FILE *fpRATA1;
	fpRATA1 = fopen(FT, "rb+");

	int jS;

	fscanf(fpRATA1, "%d\n", &jS);
	for (int jFPRATA = 0; jFPRATA < jS; jFPRATA++)
	{
		char VDTC[50];
		fscanf(fpRATA1, "%s\n%d\n", &VDTC, &(tempRATAVDT->type));
		if (VDTC != c)
		{
			tempRATAVDT->c = VDTC;
			tempRATAVDT->countVDT = jS + 1;
			tempRATAVDT = tempRATAVDT->nextVDT = new VerificationDataType();
		}
		else
		{
			return false;
		}
	}
	tempRATAVDT->c = c;
	tempRATAVDT->type = type;
	tempRATAVDT = tempRATAVDT->nextVDT = new VerificationDataType();
	fclose(fpRATA1);

	jS++;

	int jtempNew = 0;

	tempRATAVDT = &VerificationDT;
	{
		string FileTitle1 = title + tempRATAVDT->c + "Data.txt";
		char FT1[100];
		for (int iFT1 = 0; iFT1 <= FileTitle1.length(); iFT1++)
			FT1[iFT1] = FileTitle1[iFT1];
		FILE *fptemp;
		fptemp = fopen(FT1, "rb+");
		while (!feof(fptemp))
		{
			char tempjtempNew[100];
			fscanf(fptemp, "%s\n", &tempjtempNew);
			jtempNew++;
		}
		fclose(fptemp);
	}

	{
		string FileTitle1 = title + c + "Data.txt";
		char FT1[100];
		for (int iFT1 = 0; iFT1 <= FileTitle1.length(); iFT1++)
			FT1[iFT1] = FileTitle1[iFT1];
		FILE *fptemp;
		fptemp = fopen(FT1, "wb+");

		for (int jnew = 0; jnew < jtempNew; jnew++)
		{
			char m = '\0';
			fprintf(fptemp, "%s\n", m);
		}

		fclose(fptemp);
	}


	tempRATAVDT = &VerificationDT;
	{
		FILE *fpRATA;
		fpRATA = fopen(FT, "wb+");

		fprintf(fpRATA, "%d\n", tempRATAVDT->countVDT);

		for (int jFPRATA = 0; jFPRATA < jS; jFPRATA++)
		{
			char VDTC[50];
			for (int j1 = 0; j1 <= tempRATAVDT->c.length(); j1++)
				VDTC[j1] = tempRATAVDT->c[j1];

			fprintf(fpRATA, "%s\n%d\n", VDTC, (tempRATAVDT->type));
			tempRATAVDT = tempRATAVDT->nextVDT;

		}

		fclose(fpRATA);
	}
	return true;
}

void showMoreTable(selectlink list, int LikeCalibrator[1000][4])
{
	string FileName;
	FileName = list.nextSVL->ct + list.nextSVL->cv + "Data.txt";
	char FN[100];
	for (int jj = 0; jj <= FileName.length(); jj++)
	{
		FN[jj] = FileName[jj];
	}

	
	int jjj=0;
	while (LikeCalibrator[jjj][0]!=-1)
	{
		FILE *fpSMT = fopen(FN, "rb+");
		int q = 0;
		while (!feof(fpSMT))
		{
			char v[100];
			fscanf(fpSMT, "%s\n", &v);
			if (q == LikeCalibrator[jjj][0])
			{
				cout << v << "    ";
			}
			q++;

		}
		jjj++;
	}

}
