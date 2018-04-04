#include "checkNumber.h"

bool checkPositiveInteger(char c)
{
	if (c>='0'&&c<='9')
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool checkPoint(char c)
{
	if (c == '.')
		return true;
	else
		return false;
}

bool checkE(char c)
{
	if (c == 'e')
		return true;
	else
		return false;
}

bool checkAfterE(char c)
{
	if (c == '+' || c == '-')
		return true;
	else
		return false;
}
