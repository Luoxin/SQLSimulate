#pragma once
#include"DateBase.h"
#include"DBDataType.h"
#include"VerificationList.h"

//string addr(string c1, string c2);

bool ReadVerificationList(string title, VerificationDataType *VerificationDT);

int ReadMajorKey(string title, MajorKeyList *listWLIT);
bool ReadShowTableAll(string title);


bool ReadAlterTableDrop(string title, string c);
bool ReadAlterTableAdd(string title, string c, int type);
void showMoreTable(selectlink list, int LikeCalibrator[1000][4]);