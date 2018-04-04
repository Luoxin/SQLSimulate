#pragma once
#include<iostream>
using namespace std;
#include<string>

class DTTitle;
class DTData;
class DateTable;
class MajorKeyTitle;
class MajorKey;
class ForeignKeyTitle;
class ForeignKey;

class DTTitle//属性标题
{
public:
	string title;
	int type=1;//char 1,int 2
	DTData *nextD = NULL;//接存储结构
	DTTitle *nextT = NULL;//接下一个属性
};//列

class DTData//属性数据
{
public:
	string c[50];//存储内容
	int countData;//该结构体存储的最大个数
	int rows;//存储个数校验值
	DTData *next=NULL;
};//c类型存储

class MajorKey//主键表
{
public:
	string c[50];
	MajorKey *nextMK = NULL;
};

class MajorKeyTitle//主键
{
public:
	string title[10];//主键名
	MajorKey nextMK ;
};

class ForeignKey//外键表
{
public:
	string c[50];
	ForeignKey *nextFK = NULL;
};

class ForeignKeyTitle//外键
{
public:
	string title[10];
	ForeignKey nextFK;
};

class DateTable
{
public:
	string title;//表名
	MajorKeyTitle nextMK;//接主键
	ForeignKeyTitle nextFK ;//接外键
	DTTitle nextT;//接第一个属性
	DateTable *next = NULL;//接下一张表
};
