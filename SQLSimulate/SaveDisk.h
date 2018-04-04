#pragma once
#include"DateBase.h"
#include"DBDataType.h"
#include"VerificationList.h"


bool SaveCreateTable(DateTable DB,int conutMK,int countV);
bool SaveInsertInto(VerificationDataType *VerificationDT,string title, WordlListInsert *WLI, string MajorKeyVerificationData);


