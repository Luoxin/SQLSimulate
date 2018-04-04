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

	while (sginCreate != 0 && sginCreate != 3)//0 ����1 ��������2 ���ͣ�3 ��ȷ������4 ������ 5 ���
	{
		while (c[i] == ' ' || c[i] == ',')//�Թ��ո�ͣ�
		{
			i++;
		}

		if (c[i] == ')')//������
		{
			tempWL->next = NULL;
			sginCreate = 3;
			continue;
		}
		if(sginCreate == 4 && c[i] == '(')//����
		{
			i++;
			while (true)
			{
				char Key[20];
				if (c[i] == ')')//���������ж���ֹ
				{
					i++;
					break;
				}
				while (c[i] == ' '||c[i]==',')//�����ո񼰣�
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
				cout << "��������" << endl;
				return false;
			}
			continue;
		}

		if (sginCreate == 5 && c[i] == '(')//���
		{
			i++;
			while (true)
			{
				char Key[20];
				if (c[i] == ')')//���������ж���ֹ
				{
					i++;
					break;
				}
				while (c[i] == ' ' || c[i] == ',')//�����ո񼰣�
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
				cout << "��������" << endl;
				return false;
			}
			continue;
		}

		int tempI = i;
		char tempC[20];
		string tempSTRc;
		for (; i < 1000; i++)//�����������ַ���
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

		if (sginCreate == 2 && (c[i] == ',' || c[i] == ')'))//�����ж�
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

		else if (sginCreate == 1 && c[i] == ' ')//�������������
		{
			if (AfterHeardKeywordsCreatePFKey(tempSTRc) != 0)//�ж��Ƿ�Ϊ�������
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
				if (c[i] != ' ')//�Ƿ�ΪKEY
				{
					i = PF;
					tempWL->c = tempSTRc;
					sginCreate = 2;
					continue;
				}
				else
				{
					tempPF[3] = '\0';
					if (AfterHeardKeywordsCreateKey(tempPF))//�ж��Ƿ�ΪKEY
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