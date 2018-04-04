#pragma once
#include<iostream>
using namespace std;
#include<string>
#include "HeardKeyWords.h"

int HeardKeyWords(string c)
{
	string heardkeywords[7] = { "select","create","insert","delect","upsate","alter","drop" };
	for (int i = 0; i < 7; i++)
	{
		if (c == heardkeywords[i])
		{
			return i;
		}
	}
	return -1;
}

bool AfterHeardKeywordsCreate(string c)
{
	if (c == "table")
	{
		return true;
	}
	return false;
}

//////////////////////////////////////////////create
int AfterHeardKeywordsCreateAttributeType(string c)//char,1;int,2;else,0;//类型
{
	if (c=="char")
	{
		return 1;
	}
	if (c=="int")
	{
		return 2;
	}
	return 0;
}

int AfterHeardKeywordsCreatePFKey(string c)
{
	if (c=="primary")
	{
		return 4;
	}
	else if (c=="foreign")
	{
		return 5;
	}
	return 0;
}

bool AfterHeardKeywordsCreateKey(string c)//是否为key
{
	if (c == "key")
	{
		return true;
	}
	return false;
}

/////////////////////////////////////////////

bool AfterHeardKeywordsInsert(string c)
{
	if (c=="into")
	{
		return true;
	}
	return false;
}

bool AfterHeardKeywordsInsertValuse(string c)
{
	if (c=="valuse")
	{
		return true;
	}
	return false;
}

bool AfterHeardKeywordSelectFrom(string c)
{
	if (c=="from")
	{
		return true;
	}
	return false;
}

bool AfterHeardKeywordSelectWhere(string c)
{
	if (c == "where")
	{
		return true;
	}
	return false;
}

int AfterHeardKeywordAlterTable(string c)
{
	if (c=="add")
	{
		return 1;
	}
	else if(c=="drop")
	{
		return 2;
	}
	return 0;
}
