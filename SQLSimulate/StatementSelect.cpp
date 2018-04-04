#include "StatementSelect.h"
#include"HeardKeyWords.h"
#include"SaveDisk.h"
#include"ReadDisk.h"
#include"CheckDisk.h"
#include"LinkShow.h"

bool StatementSelectAll(char c[1000], int i, DataBase * MySQL)//select * from ;
{
	while (c[i] == ' ')
		i++;
	{
		while (c[i] == ' ')
			i++;
		int j = 0;
		char tempTL[50];
		while (true)
		{
			if (c[i] == ' ' || c[i] == '(')
			{
				tempTL[j] = '\0';
				break;
			}
			else
			{
				tempTL[j++] = c[i++];
			}
		}
		if (!AfterHeardKeywordSelectFrom(tempTL))
			return false;
	}

	while (true)
	{
		while (c[i] == ' ')
			i++;
		if (c[i] == ';')
			return true;

		char tempSelectT[50];
		int j = 0;
		while (c[i] != ' '&& c[i]!=','&&c[i]!=';')
		{
			tempSelectT[j++] = c[i++];
		}
		tempSelectT[j] = '\0';

		if (AfterHeardKeywordSelectWhere(tempSelectT))
			break;
		if (!ReadShowTableAll(tempSelectT))
		{
			return false;
		}

	}

	return true;
}






bool StatementSelectSomeValuse(char c[1000], int i, DataBase * MySQL)//select��*ͨ��
{
	selectlink list;
	list.nextSVL = new showvaluselist();
	showvaluselist *tempsvl = list.nextSVL;

	//select
	while (true)
	{
		while (c[i] == ' ')
			i++;

		string tempVlause;
		{
			char tempVlause1[100];
			int js1 = 0;
			while (true)//��ȡ���Ե��ַ���
			{

				if (c[i] == ',' || c[i] == ' ' || c[i] == '.')
				{
					tempVlause1[js1] = '\0';
					tempVlause = tempVlause1;
					break;
				}
				else
				{
					tempVlause1[js1++] = c[i++];
				}
			}
		}

		if (tempVlause == "from")//��ֹ�洢����
		{
			tempsvl->nextSVL = NULL;
			break;
		}
		else if (c[i] == '.')//����
		{
			i++;
			tempsvl->ct = tempVlause;
			char tempVlause1[100];
			int js1 = 0;
			while (true)//��ȡ���Ե��ַ���
			{
				if (c[i] == ',' || c[i] == ' ')
				{
					tempVlause1[js1] = '\0';
					break;
				}
				else
				{
					tempVlause1[js1++] = c[i++];
				}
			}
			tempsvl->cv = tempVlause1;//������
			tempsvl = tempsvl->nextSVL = new showvaluselist();
		}
		else
		{
			tempsvl->cv = tempVlause;//������
			tempsvl->nextSVL = new showvaluselist();
			tempsvl = tempsvl->nextSVL;
		}
	}

	cout << "select successful" << endl;

	list.nextTNL = new tablenamelist();
	tablenamelist *tempTNL = list.nextTNL;

	//form
	string tempTbale;
	while (true)
	{
		while (c[i] == ' ' || c[i] == ',')
			i++;

		string tempTable;
		{
			char tempTbale1[100];
			int js1 = 0;
			while (true)//��ȡ����
			{

				if (c[i] == ',' || c[i] == ' ' || c[i] == '.')
				{
					tempTbale1[js1] = '\0';
					tempTbale = tempTbale1;
					break;
				}
				else
				{
					tempTbale1[js1++] = c[i++];
				}
			}
		}

		if (tempTbale == "where")
		{
			tempTNL->nextTNL = NULL;
			break;
		}

		tempTNL->c = tempTbale;
		tempTNL->nextTNL = new tablenamelist();
		tempTNL = tempTNL->nextTNL;
	}

	//��֤����
	tempsvl = list.nextSVL;//valuse
	while (true)
	{
		if (tempsvl->nextSVL == NULL)//select�գ�����
		{
			break;
		}

		if (tempsvl->ct[0] == '\0')//δָ������
		{
			tempTNL = list.nextTNL;//table
			while (true)
			{
				if (checkSelectValuseInTable(tempTNL->c, tempsvl->cv))//���ҵ�ƥ���
				{
					tempsvl->ct = tempTNL->c;
					tempsvl->is_exist = true;
					break;
				}
				else if (tempTNL->nextTNL == NULL)//���Ա�������δ�ҵ�ƥ��ֵ
				{
					return false;
				}
				else
				{
					tempTNL = tempTNL->nextTNL;
				}
			}
		}

		else//��ָ������
		{
			tempTNL = list.nextTNL;//table
			while (true)
			{
				if (tempTNL->nextTNL == NULL)//��������
				{
					return false;
				}
				else if (tempsvl->ct == tempTNL->c)//�Ա�ʱ������ڵı�ƥ��
				{
					break;
				}
				else
				{
					tempTNL = tempTNL->nextTNL;
				}
			}
		}

		tempsvl = tempsvl->nextSVL;
		tempTNL = tempTNL->nextTNL;
	}

	list.nextWL = new wherelist();
	wherelist *tempwl = list.nextWL;
	//�ռ�Լ������
	while (true)
	{
		while (c[i] == ' ' || c[i] == ',')
			i++;
		if (c[i] == ';')
		{
			tempwl->nextWL = NULL;
			break;
		}
		string condition;//�������
		while (true)
		{
			while (c[i] == ' ')
				i++;
				string temp_str1;
				char tempVlause1[100];
				int js2 = 0;
				while (true)//��ȡ���Ե��ַ���
				{
					if (c[i] == ' '||c[i]==';')
					{
						tempVlause1[js2] = '\0';
						break;
					}
					else
					{
						tempVlause1[js2++] = c[i++];
					}
				}
				temp_str1 = tempVlause1;
				if (temp_str1 == "and" || c[i] == ';')//���Ϊand�������һ�������ε��ж�
				{
//					tempwl->c = condition;
					break;
				}
				condition = condition + temp_str1;
		}

		tempwl->c = condition;
		tempwl->nextWL = new wherelist();
		tempwl = tempwl->nextWL;
	}

	/*bool is_show[1000];
	for (int ja3 = 0; ja3 < 1000; ja3++)
	{
		is_show[ja3] = false;
	}*/
	if (LinkShowTable(list))
	{
		;
	}



	return true;
}