#include "CheckDisk.h"
#include <iostream>
#include<io.h>
#include<string>
#include"FileString.h"
using namespace std;
#pragma warning(disable : 4996)

bool checkFile(string cc)
{
	char tt[100];
	for (int jTT = 0; jTT <= cc.length(); jTT++)
	{
		tt[jTT] = cc[jTT];
	}

	if (access(tt,0)==0)
	{
		return true;
	}
	return false;
}

bool checkMajorKeyData(string title, string cc)
{


	string FileName = title + "MajorKeyData.txt";
	if (checkFile(FileName))
	{
		char FN[100];
		for (int jFN = 0; jFN <= FileName.length(); jFN++)
			FN[jFN] = FileName[jFN];
		FILE *fpCMKD;
		fpCMKD = fopen(FN, "rb+");
		while (!feof(fpCMKD))
		{
			char c[1000];
			fscanf(fpCMKD, "%s\n", &c);
			if (c == cc)
			{
				return false;
			}

		}
		fclose(fpCMKD);
	}
	return true;
}

bool checkDigit(string cc)
{
	int tempCD = 0;
	for (; tempCD < cc.length(); tempCD++)
	{
		int d = int(cc[tempCD]);
		if (d >= 48 && d <= 57);
		else
			return false;
	}
	
	return true;
}

bool checkSelectValuseInTable(string tableName, string valuseName)
{
	string FileName = tableName + FileTypeList;
	{
		char FN[100];
		for (int jFN = 0; jFN <= FileName.length(); jFN++)
			FN[jFN] = FileName[jFN];
		FILE *fpCSVIT;
		fpCSVIT = fopen(FN, "rb+");
		int temp;

		fscanf(fpCSVIT, "%d\n", &temp);
		for (int jcsvit = 0; jcsvit < temp; jcsvit++)
		{
			int temp_;
			char VDTC[50];
			fscanf(fpCSVIT, "%s\n%d\n", &VDTC, &temp_);
			string temp_str = VDTC;
			if (temp_str== valuseName)
			{
				fclose(fpCSVIT);
				return true;
			}
		}
		fclose(fpCSVIT);
	}
	return false;
}



bool checkAttributeValueEqual(selectlink list,string conditionl,string conditionr, int LikeCalibrator[1000][4])
{
	int colsl, colsr;
	//conditionl
		char FNl[100];
		int tempFNl = 0;
		int tempFNlc = 0;
		while (true)
		{
			if (conditionl[tempFNlc] == '\0')
			{
				FNl[tempFNl] = '\0';
				break;
			}
			else if (conditionl[tempFNlc] == '.')
			{
				FNl[tempFNl] = '\0';
				colsl=checkvaluse(list, FNl);
				if (colsl==-1)
				{
					return false;
				}
				tempFNlc++;
			}
			else
			{
				FNl[tempFNl++] = conditionl[tempFNlc++];
			}
		}
		FNl[tempFNl] = 'D';
		FNl[tempFNl+1] = 'a';
		FNl[tempFNl+2] = 't';
		FNl[tempFNl+3] = 'a';
		FNl[tempFNl+4] = '.';
		FNl[tempFNl+5] = 't';
		FNl[tempFNl+6] = 'x';
		FNl[tempFNl+7] = 't';
		FNl[tempFNl + 8] = '\0';
	//conditionr
		char FNr[100];
		int tempFNr = 0;
		int tempFNrc = 0;
		while (true)
		{
			if (conditionr[tempFNrc] == '\0')
			{
				FNr[tempFNr] = '\0';
				break;
			}
			else if (conditionr[tempFNrc] == '.')
			{
				FNr[tempFNr] = '\0';
				colsr = checkvaluse(list, FNr);
				if (conditionr[tempFNrc+1]=='\'')//数值等于
				{

				}
				else if (colsr == -1)
				{
					return false;
				}
				tempFNrc++;
			}
			else
			{
				FNr[tempFNr++] = conditionr[tempFNrc++];
			}
		}
		FNr[tempFNr] = 'D';
		FNr[tempFNr + 1] = 'a';
		FNr[tempFNr + 2] = 't';
		FNr[tempFNr + 3] = 'a';
		FNr[tempFNr + 4] = '.';
		FNr[tempFNr + 5] = 't';
		FNr[tempFNr + 6] = 'x';
		FNr[tempFNr + 7] = 't';
		FNr[tempFNr + 8] = '\0';
	//对比字符串
		FILE *fpL = fopen(FNl, "rb+");//左侧的数据
		FILE *fpR = fopen(FNr, "rb+");//右侧的数据
		int cl = 0, cr = 0;
		while (!feof(fpL))
		{
			char valusel[100];
			fscanf(fpL, "%s\n", &valusel);
			string valuseleft=valusel;

			while (!feof(fpR))
			{
				char valuser[100];
				fscanf(fpR, "%s\n", &valuser);
				string valuseright = valuser;
				if (valuseleft== valuseright)
				{
					if (LikeCalibrator[0][colsl]==-1&& LikeCalibrator[0][colsr]==-1)
					{
						LikeCalibrator[0][colsl] = cl;
						LikeCalibrator[0][colsr] = cr;
					}
					else if (LikeCalibrator[0][colsl] == -1 && LikeCalibrator[0][colsr] != -1)
					{
						int trmpr = 0;
						bool sgin =false;
						while (LikeCalibrator[trmpr][colsr]!=-1)
						{
							if (LikeCalibrator[trmpr][colsr]==cr)
							{
								if (LikeCalibrator[trmpr][colsl] == cl)
								{
									;
								}
								else
								{
									LikeCalibrator[trmpr][colsl] = cl;
									sgin = true;
								}
							}
							trmpr++;
						}
						if (!sgin)
						{
							LikeCalibrator[trmpr][colsr] = cr;
							LikeCalibrator[trmpr][colsl] = cl;
						}
					}
					else if (LikeCalibrator[0][colsl] != -1 && LikeCalibrator[0][colsr] == -1)
					{
						int trmpr = 0;
						bool sgin = false;
						while (LikeCalibrator[trmpr][colsl] != -1)
						{
							if (LikeCalibrator[trmpr][colsl] == cl)
							{
								if (LikeCalibrator[trmpr][colsr] == cr)
								{
									;
								}
								else
								{
									LikeCalibrator[trmpr][colsr] = cr;
									sgin = true;
								}
							}
							trmpr++;
						}
						if (!sgin)
						{
							LikeCalibrator[trmpr][colsr] = cr;
							LikeCalibrator[trmpr][colsl] = cl;
						}
					}
					else
					{
						int trmpr = 0;
						while (LikeCalibrator[trmpr][colsl] != -1)
						{
							trmpr++;
						}
						LikeCalibrator[trmpr][colsr] = cr;
						LikeCalibrator[trmpr][colsl] = cl;
					}

				}
				cr++;
			}
			cl++;
		}

		fclose(fpR);
		fclose(fpL);






	return true;
}

int checkvaluse(selectlink list, string cc)
{
	tablenamelist *tempTL = list.nextTNL;
	int k = 0;

	while (tempTL->nextTNL!=NULL)
	{
		if (tempTL->c==cc)
		{
			return k;
		}
		tempTL = tempTL->nextTNL;
		k++;
	}


	return -1;
}
