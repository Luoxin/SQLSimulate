#include<iostream>
using namespace std;
#include<stdio.h>
#include<string>
#include"SemanticAnalysis.h"
#include"DateBase.h"
#include"Index.h"
#pragma warning(disable : 4996)

static DataBase *MySQL=new DataBase("MySQL");


//���浽�ļ�
//FILE *fp = fopen("save.txt","w");
//fputs("abcd", fp);

//��ȡ�ļ�
//FILE *fp = fopen("save.txt", "r");
//fgets(a, 4,);
//cout << a;


void main()
{
	while (true)
	{
		bool validity = true;//�ж�����Ƿ�Ϸ��ı��

		char c[1000];
		for (int i = 0; i < 1000; i++)
		{
			char temp;
			scanf("%c", &temp);
			c[i] = temp;
			if (c[i] >= 'A' && c[i] <= 'Z')
			{
				c[i] += 32;
			}
			if (c[i] == '\n')
			{
				i--;
				continue;
			}
			if (c[i] == ';')
			{
				c[i + 1] = '\0';
				break;
			}
		}

		SemanticAnalysis(c, MySQL);
		cout << "-------------------------------------------------------------------------------" << endl;
	}
}