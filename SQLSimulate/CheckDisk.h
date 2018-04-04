#pragma once
#include<string>
#include<iostream>
#include"WordList.h"
using namespace std;

bool checkFile(string cc);
bool checkMajorKeyData(string title,string cc);
bool checkDigit(string cc);

bool checkSelectValuseInTable(string tableName, string valuseName);
bool checkAttributeValueEqual(selectlink list, string conditionl, string conditionr, int LikeCalibrator[1000][4]);
int checkvaluse(selectlink list, string cc);