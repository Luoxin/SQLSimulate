#include "StatementInsert.h"
#include<string>
#include<iostream>
#include"VerificationList.h"
#include"SaveDisk.h"
#include"ReadDisk.h"
#include"WordList.h"
#include"HeardKeyWords.h"
#include"CheckDisk.h"
using namespace std;

bool StatementInsertInto(char c[1000], int i, DataBase *MySQL)
{
	while (c[i] == ' ')
		i++;

	string TableName;
	{//获取表名
		char tempTableName[100];
		int tempTi = 0;
		while (true)
		{
			if (c[i] == ' ')
			{
				tempTableName[tempTi] = '\0';
				break;
			}
			else
			{
				tempTableName[tempTi++] = c[i++];
			}
		}
		TableName = tempTableName;
	}

	while (c[i] == ' ')
		i++;

	{//判断valuse
		char tempvaluse[20];
		int tempVi = 0;
		while (true)
		{
			if (c[i] == ' ' || c[i] == '(')
			{
				tempvaluse[tempVi] = '\0';
				break;
			}
			else
			{
				tempvaluse[tempVi++] = c[i++];
			}
		}
		if (!AfterHeardKeywordsInsertValuse(tempvaluse))
			return false;
	}


	VerificationDataType VerificationDT;//属性
	MajorKeyList MajorKL;//主键

	//获取属性表及主键
	if (ReadVerificationList(TableName, &VerificationDT));
	int MKcount = ReadMajorKey(TableName, &MajorKL);

	while (c[i] == ' ')
		i++;

	string MajorKeyValuse;

	WordlListInsert ValuseWordList;//存属性的值
	WordlListInsert *tempVWL = &ValuseWordList;

	if (c[i++] == '(')
	{
		VerificationDataType *tempVDT = &VerificationDT;
		MajorKeyList *tempMKL = &MajorKL;
		int tempMKC = 0;
		while (true)
		{
			if (tempVDT->nextVDT == NULL)
			{
				break;
			}
			while (c[i] == ' ' || c[i] == ',')
				i++;


			string valuse;

			if (c[i] == '\'')//字符
			{

				if (tempVDT->type == 2)
					return false;
				char tempvaluse[100];
				int tempSI = 0;
				i++;
				while (true)
				{
					if (c[i] == '\'')
					{
						tempvaluse[tempSI] = '\0';
						break;
					}
					else
					{
						tempvaluse[tempSI++] = c[i++];
					}
				}
				valuse = tempvaluse;
			}
			else//数字
			{
				char tempvaluse[100];
				int tempSI = 0;

				while (true)
				{
					if (c[i] == ',' || c[i] == ')')
					{
						tempvaluse[tempSI] = '\0';
						break;
					}
					else
					{
						tempvaluse[tempSI++] = c[i++];
					}
				}
				/*if (!checkDigit(valuse))
				{
					return false;
				}*/
				valuse = tempvaluse;
			}
			if (tempVDT->c == tempMKL->VerificationName[tempMKC])
			{
				MajorKeyValuse = MajorKeyValuse + valuse;
				tempMKC++;
			}
			tempVWL->c = valuse;
			cout << tempVWL->c << endl;
			tempVDT = tempVDT->nextVDT;
			tempVWL = tempVWL->next = new WordlListInsert();
		}
	}
	else
	{
		return false;
	}

	tempVWL = &ValuseWordList;
	VerificationDataType *tempVDT = &VerificationDT;
	if (!SaveInsertInto(tempVDT, TableName, tempVWL, MajorKeyValuse))
		return false;

	cout << "end" << endl;
	return true;
}









































//
//bool StatementInsertInto(char c[1000], int i, DataBase * MySQL)
//{
//	while (c[i] == ' ')
//		i++;
//
//	string TableLitle;
//	{
//		int j = 0;
//		char tempTL[50];
//		while (true)
//		{
//			if (c[i] == ' ')
//			{
//				tempTL[j] = '\0';
//				break;
//			}
//			else
//			{
//				tempTL[j++] = c[i++];
//			}
//		}
//		TableLitle = tempTL;
//	}
//	
//	VerificationDataType VerificationDT;
//
//	if (!(ReadVerificationList(TableLitle,&(VerificationDT))))//文件是否存在
//	{
//		return false;
//	}
//
//	{//判断是否为valuse
//		while (c[i] == ' ')
//			i++;
//		int j = 0;
//		char tempTL[50];
//		while (true)
//		{
//			if (c[i] == ' '||c[i]=='(')
//			{
//				tempTL[j] = '\0';
//				break;
//			}
//			else
//			{
//				tempTL[j++] = c[i++];
//			}
//		}
//		if (!AfterHeardKeywordsInsertValuse(tempTL))
//			return false;
//	}
//
//	while (c[i] == ' ')
//		i++;
//	
//	if (c[i] == '(')
//		i++;
//	else
//		return false;
//
//
//
//
//	WordlListInsertTitle list;
//	list.title = TableLitle;
//	list.nextWLSI = new WordlListInsert();
//	WordlListInsert *tempWLSI = list.nextWLSI;
//	VerificationDataType *tempVD = &VerificationDT;//属性列表
//
//	MajorKeyList MKL;//主键列表
//	MajorKeyList *tempMKL = &MKL;
//
//	int k = ReadMajorKey(TableLitle, tempMKL);
//	if (!ReadVerificationList(TableLitle, tempVD))
//		return false;
//	int q = tempVD->countVDT;
//	for (int j1 = 0; j1 < q; j1++)
//	{
//		for (int j2 = 0; j2 < k; j2++)
//		{
//			if (tempVD->c== tempMKL->VerificationName[j2])
//			{
//				tempVD->SginMajorKey=true;
//				break;
//			}
//		}
//		tempVD = tempVD->nextVDT;
//	}
//
//	string MajorKeyVerificationData;
//
//	tempVD = &VerificationDT;
//
//	while (true)//判断输入合法性
//	{
//		
//		while (c[i] == ' '||c[i]==',')
//			i++;
//		
//		if (c[i]==')')
//		{
//			tempWLSI->next = NULL;
//			break;
//		}
//
//		char tempInsert[50];
//		int j = 0;
//
//		if (c[i]=='\'')
//		{
//			i++;
//			while (c[i]!='\'')
//			{
//				tempInsert[j++] = c[i++];
//			}
//			tempInsert[j] = '\0';
//			i++;
//		}
//		else
//		{
//			while (c[i] != ','&&c[i]!=')')
//				tempInsert[j++] = c[i++];
//			tempInsert[j] = '\0';
//		}
//
//		for (j = 0; j < q; j++)
//		{
//			if (tempVD->SginMajorKey)
//			{
//				MajorKeyVerificationData += tempInsert;
//			}
//			if (tempVD->type == 2)//int判断
//			{
//				int tempVDTT = 0;
//				while (tempInsert[tempVDTT] != '\0')
//				{
//					if (int(tempInsert[tempVDTT]) >= 48 && int(tempInsert[tempVDTT]) <= 57)
//					{
//						tempVDTT++;
//						continue;
//					}
//					else
//					{
//						cout << "输入数据不符合属性限制" << endl;
//						return false;
//					}
//				}
//				tempWLSI->c = tempInsert;
//				cout << tempWLSI->c << endl;
//				tempVD = tempVD->nextVDT;
//				tempWLSI->next = new WordlListInsert();
//				tempWLSI = tempWLSI->next;
//				break;
//			}
//			else//char判断
//			{
//				tempWLSI->c = tempInsert;
//				cout << tempInsert << endl;
//				tempVD = tempVD->nextVDT;
//				tempWLSI->next = new WordlListInsert();
//				tempWLSI = tempWLSI->next;
//				break;
//			}
//		}
//	}
//
//	if (!checkMajorKeyData(TableLitle,MajorKeyVerificationData))
//	{
//		return false;
//	}//判断主键
//
//
//	tempWLSI = list.nextWLSI;
//
//	if (MySQL->DataBaseInsertInto(VerificationDT, TableLitle, tempWLSI, MajorKeyVerificationData));
//
//	cout << TableLitle << endl;
//	return true;
//}
//
