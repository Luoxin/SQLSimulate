#pragma once
#include<iostream>
#include<string>
using namespace std;

class VerificationDataType
{
public:
	string c;//������
	int type;//����
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