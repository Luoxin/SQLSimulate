#include "LinkShow.h"
#include"StatementSelect.h"
#include"CheckDisk.h"
#include"ReadDisk.h"
//#include<string>
//#include<iostream>
//using namespace std;

bool LinkShowTable(selectlink list)
{
	
	/*int row = 1;
	{
		tablenamelist *temp_tnl = list.nextTNL;
		while (temp_svl->nextSVL!=NULL)
		{
			row++;
			temp_svl = temp_svl->nextSVL;
		}
	}*/

	int LikeCalibrator[1000][4];//链接校验
	for (int jc = 0; jc < 1000; jc++)//初始化校验表
	{
		for (int jr = 0; jr < 4; jr++)
		{
			LikeCalibrator[jc][jr] = -1;
		}
	}

	wherelist *temp_wl = list.nextWL;
	while (temp_wl->nextWL != NULL)
	{
		int templ = 0;
		char tempstr[100];

		while (true)//left 
		{
			if (temp_wl->c[templ] == '=')
			{
				tempstr[templ] = '\0';
				break;
			}
			else
			{
				tempstr[templ] = temp_wl->c[templ];
				templ++;
			}
		}
		string strleft = tempstr;

		int tempr = 0;
		while (true)//reght
		{
			if (temp_wl->c[templ] == '\0')
			{
				tempstr[tempr] = '\0';
				break;
			}
			else
			{
				tempstr[tempr++] = temp_wl->c[templ++];
			}
		}
		string strright = tempstr;

		if (checkAttributeValueEqual(list,strleft, strright, LikeCalibrator));
		temp_wl = temp_wl->nextWL;
	}

	showMoreTable(list, LikeCalibrator);























	//showvaluselist showTable;//即将显示的表
	//showvaluselist *temp_showTable = &showTable;//showTable的指针
	//wherelist *temp_listWL = list.nextWL;//待处理的条件
//	int row = 0, cols = 0;//行，列
	//int tempJ;

	//while (true)
	//{
	//	if (temp_listWL->nextWL=NULL)//结束标记
	//	{
	//		break;
	//	}

	//	{
	//		char temp_element[100];//临时存储字符串
	//		tempJ = 0;
	//		while (true)
	//		{
	//			if (temp_listWL->c[tempJ]=='.')
	//			{
	//				temp_element[tempJ] = '\0';
	//			}
	//			else
	//			{
	//				temp_element[tempJ++] = temp_listWL->c[tempJ++];
	//			}
	//		}
	//		temp_showTable->ct = temp_element;
	//		
	//		tempJ++;

	//		int tempJ1 = 0;
	//		while (true)
	//		{
	//			if (temp_listWL->c[tempJ] == '.')
	//			{
	//				temp_element[tempJ1] = '\0';
	//			}
	//			else
	//			{
	//				temp_element[tempJ1++] = temp_listWL->c[tempJ++];
	//			}
	//		}
	//		temp_showTable->cv = temp_element;
	//	}
	//}










	return true;
}
 