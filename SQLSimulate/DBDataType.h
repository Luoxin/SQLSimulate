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

class DTTitle//���Ա���
{
public:
	string title;
	int type=1;//char 1,int 2
	DTData *nextD = NULL;//�Ӵ洢�ṹ
	DTTitle *nextT = NULL;//����һ������
};//��

class DTData//��������
{
public:
	string c[50];//�洢����
	int countData;//�ýṹ��洢��������
	int rows;//�洢����У��ֵ
	DTData *next=NULL;
};//c���ʹ洢

class MajorKey//������
{
public:
	string c[50];
	MajorKey *nextMK = NULL;
};

class MajorKeyTitle//����
{
public:
	string title[10];//������
	MajorKey nextMK ;
};

class ForeignKey//�����
{
public:
	string c[50];
	ForeignKey *nextFK = NULL;
};

class ForeignKeyTitle//���
{
public:
	string title[10];
	ForeignKey nextFK;
};

class DateTable
{
public:
	string title;//����
	MajorKeyTitle nextMK;//������
	ForeignKeyTitle nextFK ;//�����
	DTTitle nextT;//�ӵ�һ������
	DateTable *next = NULL;//����һ�ű�
};
