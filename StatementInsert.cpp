#include "StatementInsert.h"
#include<string>
#include<iostream>
#include"VerificationList.h"
#include"ReadDisk.h"
using namespace std;

string AddStr(string a, string b)//×Ö·û´®ºÏ²¢
{
	char aa[1000];
	int i;
	for (i = 0; i < a.length(); i++)
		aa[i] = a[i];
	int tempI = i-1;
	for (; i < (tempI + b.length()); i++)
		aa[i] = b[i - tempI];
	aa[i] = '\0';
	return aa;
}

bool StatementInsertInto(char c[1000], int i, DataBase * MySQL)
{
	while (c[i] == ' ')
		i++;

	string TableLitle;
	{
		int j = 0;
		char tempTL[50];
		while (true)
		{
			if (c[i] == ' ')
			{
				tempTL[j] = '\0';
				break;
			}
			else
			{
				tempTL[j++] = c[i++];
			}
		}
		TableLitle = tempTL;
	}


	VerificationDataType VerificationDT;
	if (!ReadDTList(AddStr(TableLitle,"List.txt"),VerificationDT))
	{
		return false;
	}

	for (int j = 0; j < VerificationDT.i; j++)
	{
		cout << VerificationDT.c[j] << VerificationDT.type[j] << endl;
	}

	cout << TableLitle << endl;
	return true;
}

