#pragma once
#include<string>


class WorldlistCreate
{
public:
	string c;
	int type=1;////char,1;int,2;else,(Ĭ��);
	int key = 0;//���� 1�����2
	WorldlistCreate *next=NULL;
};

class WordlistCreateTitle//����
{
public:
	string title;
	WorldlistCreate *next = NULL;
};