#pragma once
#include<iostream>
using namespace std;
#include<string>
#include "HeardKeyWords.h"
#include"SemanticAnalysis.h"
#include"StatementCreate.h"
#include"StatementInsert.h"
#include"WordList.h"

void SemanticAnalysis(char c[1000],DataBase *MySQL)
{
	bool validity = true;
	int i = 0;

	char tempHK[7];
	for (; i < 7; i++)
	{
		if (c[i] != ' ')
		{
			tempHK[i] = c[i];
		}
		else
		{
			tempHK[i] = '\0';
			break;
		}
	}
	int heardKeywords = HeardKeyWords(tempHK);
//	cout << heardKeywords << endl;

	switch (heardKeywords)
	{
	case 0: {//select
		break;
	}
	case 1: {//create
		int tempI = ++i;
		char tempC[10];
		for (; i < 100; i++)
		{
			if (c[i] != ' ')
			{
				tempC[i - tempI] = c[i];
			}
			else
			{
				tempC[i - tempI] = '\0';
				break;
			}
		}
		if (AfterHeardKeywordsCreate(tempC))
		{
			if (StatementCreateTable(c, i,MySQL))
				cout << "true" << endl;
			else
			{
				cout << "false" << endl;
				validity=false;
			}
		}
		else
		{
			validity = false;
		}
		break;
	}
	case 2: {//insert
		int tempI = ++i;
		char tempC[10];
		for (; i < 100; i++)
		{
			if (c[i] != ' ')
			{
				tempC[i - tempI] = c[i];
			}
			else
			{
				tempC[i - tempI] = '\0';
				break;
			}
		}
		if (AfterHeardKeywordsInsert(tempC))
		{
			if (StatementInsertInto(c, i, MySQL))
				cout << "true" << endl;
			else
			{
				cout << "false" << endl;
				validity = false;
			}
		}
		else
		{
			validity = false;
		}
		break;
	}
	case 3: {//delect
		break;
	}
	case 4: {//update
		break;
	}
	case 5: {//alter
		break;
	}
	case 6: {//drop
		break;
	}
	default: {
		validity = false;
		break;
	}
	}

}
