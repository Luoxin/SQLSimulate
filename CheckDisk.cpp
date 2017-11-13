#include "CheckDisk.h"
#include <iostream>
#include <fstream>
using namespace std;


void FilenameAdd(char *cc, int j, string Type)
{
	j--;
	int i;
	for (i = 0; i < (Type.length()); i++)
	{
		cc[i + j] = Type[i];
	}
	cc[i + j] = '\0';
}

bool checkFileList(string cc)
{
	char aa[50];
	int j;
	for (j = 0; j <= cc.length(); j++)
		aa[j] = cc[j];
	FilenameAdd(aa, j, "List.txt");

	string Filename = cc;
	fstream _file;
	_file.open(Filename, ios::in);
	if (_file)
	{
		return true;
	}
	return false;
}
