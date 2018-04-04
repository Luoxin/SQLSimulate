#pragma once
#include<iostream>
using namespace std;
#include<string>
#include"StatementCreate.h"
#include"WordList.h"
#include"HeardKeyWords.h"
#include"DateBase.h"



bool StatementCreateTable(char c[1000], int i, DataBase *MySQL)
{
	WordlistCreateTitle list;

	int tempI = ++i;
	char tempCT[15];
	for (; i < 100; i++)
	{
		if (c[i] != ' '&&c[i] != '(')
		{
			tempCT[i - tempI] = c[i];
		}
		else
		{
			tempCT[i - tempI] = '\0';
			break;
		}
	}

	list.title = tempCT;
	list.next = new WorldlistCreate();
	WorldlistCreate *tempWL = list.next;

	for (;; i++)
	{
		if (c[i] == '(' || c[i] == ' ')
		{
			continue;
		}
		else
		{
			break;
		}
	}
	//	i--;

	int sginCreate = 1;

	while (sginCreate != 0 && sginCreate != 3)//0 错误，1 属性名，2 类型，3 正确结束，4 主键， 5 外键
	{
		while (c[i] == ' ' || c[i] == ',')//略过空格和，
		{
			i++;
		}

		if (c[i] == ')')//）结束
		{
			tempWL->next = NULL;
			sginCreate = 3;
			continue;
		}
		if(sginCreate == 4 && c[i] == '(')//主键
		{
			i++;
			while (true)
			{
				char Key[20];
				if (c[i] == ')')//主键属性判断终止
				{
					i++;
					break;
				}
				while (c[i] == ' '||c[i]==',')//消除空格及，
				{
					i++;
				}
				int j = 0;
				while (c[i] != ','&&c[i] != ')')
				{

					Key[j++] = c[i++];
				}
				Key[j] = '\0';
				WorldlistCreate *temp = list.next;
				while (temp->next!=NULL)
				{
					if (temp->c==Key)
					{
						temp->key = 1;
						sginCreate = 1;
						break;
					}
					temp = temp->next;
				}
			}
			if (sginCreate!=1)
			{
				cout << "主键错误" << endl;
				return false;
			}
			continue;
		}

		if (sginCreate == 5 && c[i] == '(')//外键
		{
			i++;
			while (true)
			{
				char Key[20];
				if (c[i] == ')')//主键属性判断终止
				{
					i++;
					break;
				}
				while (c[i] == ' ' || c[i] == ',')//消除空格及，
				{
					i++;
				}
				int j = 0;
				while (c[i] != ','&&c[i] != ')')
				{

					Key[j++] = c[i++];
				}
				Key[j] = '\0';
				WorldlistCreate *temp = list.next;
				while (temp->next != NULL)
				{
					if (temp->c == Key)
					{
						temp->key = 2;
						sginCreate = 1;
						break;
					}
					temp = temp->next;
				}
			}
			if (sginCreate != 1)
			{
				cout << "主键错误" << endl;
				return false;
			}
			continue;
		}

		int tempI = i;
		char tempC[20];
		string tempSTRc;
		for (; i < 1000; i++)//读入待处理的字符串
		{
			if (c[i] != ' '&&c[i] != ','&& c[i] != ')')
			{
				tempC[i - tempI] = c[i];
			}
			else
			{
				tempC[i - tempI] = '\0';
				tempSTRc = tempC;
				break;
			}
		}

		if (sginCreate == 2 && (c[i] == ',' || c[i] == ')'))//类型判断
		{
			int a = AfterHeardKeywordsCreateAttributeType(tempSTRc);
			tempWL->type = a;
			//			cout << a<<endl;
			if (tempWL->type != 0)
			{
				tempWL->next = new WorldlistCreate();
				tempWL = tempWL->next;
				sginCreate = 1;
			}
			else
			{
				sginCreate = 0;
			}
			continue;
		}

		else if (sginCreate == 1 && c[i] == ' ')//变量及主键外键
		{
			if (AfterHeardKeywordsCreatePFKey(tempSTRc) != 0)//判断是否为主键外键
			{
				int PFK = AfterHeardKeywordsCreatePFKey(tempSTRc);
				int PF = i;
				char tempPF[4];
				while (c[i] == ' ')
				{
					i++;
				}
				for (int j = 0; j < 3; j++)
				{
					tempPF[j] = c[i++];
				}
				if (c[i] != ' ')//是否为KEY
				{
					i = PF;
					tempWL->c = tempSTRc;
					sginCreate = 2;
					continue;
				}
				else
				{
					tempPF[3] = '\0';
					if (AfterHeardKeywordsCreateKey(tempPF))//判断是否为KEY
					{
						sginCreate = PFK;
					}
					else
					{
						i = PF;
						tempWL->c = tempSTRc;
						sginCreate = 2;
					}
					continue;
				}
			}
			else
			{
				tempWL->c = tempSTRc;
				sginCreate = 2;
			}
			continue;
			//			cout << tempWL->c<<endl;
		}

		else
		{
			sginCreate = 0;
		}
	}

	cout << "1" << endl;

	if (sginCreate == 0)
	{
		if (c[++i] == ';');
		else
		{
			return	false;
		}
	}

	WorldlistCreate *tempWLS = list.next;
	//while (true)
	//{
	//	cout << tempWLS->c << endl;
	//	if (tempWLS->next == NULL)
	//	{
	//		break;
	//	}
	//	else
	//	{
	//		tempWLS = tempWLS->next;
	//	}
	//}

	MySQL->DataBaseCreateTable(list);

	return true;
}