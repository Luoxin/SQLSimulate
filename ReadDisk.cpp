#include "ReadDisk.h"
#include<iostream>
#include"VerificationList.h"
#include<string>
#include<stdio.h>
#include<filesystem>
#pragma warning(disable : 4996)
using namespace std;

bool ReadDTList(char title[50], VerificationDataType VerificationDT)
{
	FILE *fp;
	fp = fopen(title, "rb");
	while (feof(fp) != 1)
	{
		fscanf(fp, "%s,%d;", VerificationDT.c[VerificationDT.i], VerificationDT.type[VerificationDT.i]);
		VerificationDT.i++;
	}
	
	return true;
}
