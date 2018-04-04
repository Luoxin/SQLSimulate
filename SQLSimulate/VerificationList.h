#pragma once
#include<iostream>
#include<string>
using namespace std;

class VerificationDataType
{
public:
	string c;//属性名
	int type;//类型
	int countVDT;
	bool SginMajorKey = false;
	VerificationDataType *nextVDT=NULL;
};

//int VerificationDataType::countVDT = 0;

class MajorKeyList
{
public:
	string VerificationName[10];
	int countMKL = 0;
};