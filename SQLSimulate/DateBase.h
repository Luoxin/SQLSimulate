#pragma once
#include"DBDataType.h"
#include"WordList.h"
#include"VerificationList.h"

class DataBase
{
public:
	DataBase(string c);
	~DataBase();
	void DataBaseCreateTable(WordlistCreateTitle list);
	bool DataBaseInsertInto(VerificationDataType VerificationDT,string title,WordlListInsert *WLI,string MajorKeyVerificationData);

private:
	DateTable DB;
	string name;

};