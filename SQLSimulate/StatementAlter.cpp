#include "StatementAlter.h"
#include"HeardKeyWords.h"
#include"SaveDisk.h"
#include"ReadDisk.h"

bool StatementAlterTable(char c[1000], int i, DataBase * MySQL)
{
	while (c[i] == ' ')
		i++;

	char tempSATT[50];
	int tempSATTi = i;
	while (c[i] != ' '&&c[i] != ';')
		tempSATT[i - tempSATTi] = c[i++];
	tempSATT[i - tempSATTi] = '\0';

	while (c[i] == ' ')
		i++;

	char tempSAT[50];
	{
		int tempj = i;
		while (c[i] != ' '&&c[i] != ';')
			tempSAT[i - tempj] = c[i++];
		tempSAT[i - tempj] = '\0';
	}
	int sginSAT = AfterHeardKeywordAlterTable(tempSAT);//1 add 2 dorp
	if (sginSAT == 0)
	{
		return false;
	}

	while (c[i] == ' ')
		i++;
	char tempSATc[50];
	{
		int tempjc = i;
		while (c[i] != ' '&&c[i] != ';')
			tempSATc[i - tempjc] = c[i++];
		tempSATc[i - tempjc] = '\0';
	}

	if (sginSAT == 2)
	{
		if (ReadAlterTableDrop(tempSATT, tempSATc))
			return true;
		else
			return false;
	}
	else
	{
		int tempSATType;
		{
			while (c[i]==' ')
				i++;
			char tempSATc1[50];
			int tempjc = i;
			while (c[i] != ' '&&c[i] != ';')
				tempSATc1[i - tempjc] = c[i++];
			tempSATc1[i - tempjc] = '\0';
			tempSATType=AfterHeardKeywordsCreateAttributeType(tempSATc1);
		}
		if (ReadAlterTableAdd(tempSATT, tempSATc, tempSATType))
			return true;
		else
			return false;
	}
	return true;
}