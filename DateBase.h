#pragma once
#include"DBDataType.h"
#include"WordList.h"

class DataBase
{
public:
	DataBase(string c);
	~DataBase();
	void DataBaseCreateTable(WordlistCreateTitle list);

private:
	DateTable DB;
	string name;

};