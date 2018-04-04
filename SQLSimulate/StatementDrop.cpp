#include "StatementDrop.h"

bool StatementDropTable(char c[1000], int i, DataBase * MySQL)
{
	while (c[i] == ' ')
		i++;
	char tempSDT[50];
	int tempSDTi = i;
	while (c[i]!=' '&&c[i]!=';')
		tempSDT[i - tempSDTi] = c[i++];



	return true;
}
