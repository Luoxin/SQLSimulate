#include<iostream>
using namespace std;
#include<stdio.h>
#include<string>
#include"SemanticAnalysis.h"
#include"DateBase.h"
#include"SaveDisk.h"

DataBase::DataBase(string c)
{
	name = c;
}

DataBase::~DataBase()
{
}

void DataBase::DataBaseCreateTable(WordlistCreateTitle list)//������
{
	DB.title = list.title;
	WorldlistCreate *tempWLC = list.next;//�﷨�������ʱ�
//	DB.nextT = new DTTitle();
	DTTitle *tempDT = &DB.nextT;
	int countMK = 0;
	int countV = 0;
	while (true)
	{
		if (tempWLC->next == NULL)
		{
			tempDT->nextT = NULL;
			break;
		}
		else
		{
			if (tempWLC->key == 1)
			{
				/*if (i > 9)
				{
					cout << "��������ʧ��" << endl;
				}
				else
				{*/
					DB.nextMK.title[countMK] = tempWLC->c;
					countMK++;
				//}
			}
			tempDT->title = tempWLC->c;
			tempDT->type = tempWLC->type;
			tempDT->nextT = new DTTitle();
			tempDT = tempDT->nextT;
			tempWLC = tempWLC->next;
			countV++;
		}
	}
	if (SaveCreateTable(DB, countMK, countV))
	{
		cout << true << endl;
	}
	cout << false << endl;
}

	bool DataBase::DataBaseInsertInto(VerificationDataType VerificationDT,string title, WordlListInsert *WLI, string MajorKeyVerificationData)//��������
	{
		if (SaveInsertInto(&VerificationDT,title, WLI,MajorKeyVerificationData))
			return true;
		return false;
	}
