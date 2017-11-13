#pragma once
#include<string>


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