#pragma once
#include<string>
#include<iostream>
using namespace std;

//create table
class WorldlistCreate
{
public:
	string c;
	int type=1;////char,1;int,2;else,(默认);
	int key = 0;//主键 1，外键2
	WorldlistCreate *next=NULL;
};

class WordlistCreateTitle//表名
{
public:
	string title;
	WorldlistCreate *next = NULL;
};

//select into
class WordlListInsert
{
public:
	string c;
	WordlListInsert *next;
};

class WordlListInsertTitle
{
public:
	string title;
	WordlListInsert *nextWLSI;
};

//sekect some
class showvaluselist
{
public:
	string ct;
	string cv;
	bool is_exist = false;
	showvaluselist *nextSVL = NULL;
};

class tablenamelist
{
public:
	string c;
	tablenamelist *nextTNL = NULL;
};

class wherelist
{
public:
	string c;
	wherelist *nextWL = NULL;
};

class selectlink
{
public:
	showvaluselist *nextSVL = NULL;//select
	tablenamelist *nextTNL = NULL;//form
	wherelist *nextWL = NULL;//where
};