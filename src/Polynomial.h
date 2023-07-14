#ifndef POLYNOMIAL_H_
#define POLYNOMIAL_H_

#include <iostream>
#include <string>
#include <math.h>
#include "GNode.h"
#include "GList.h"

/**
 * 
 * @author Amir
 * @version 2013
 * 
 */

using namespace std;

class Polynomial
{
	friend class GList;

private:
	GNode *first;

public:
	int i = 0;
	// int c[5][5];
	Polynomial()
	{
		first = new GNode(-1);
	}

	Polynomial::~Polynomial()
	{
		// GList *g = new GList();
		// g->~GList();
		Delete(first);
		first = new GNode(-1);
	}

	void Polynomial::Delete(GNode *p)
	{
		while (p)
		{
			if (p->dlink)
				Delete(p->dlink);
			GNode *q = p->link;
			delete p;
			p = q;
			// delete q;
		}
	}

	void Polynomial::Create(int b[20][5])
	{
		/*first->Data = b[0][4];
		first->var = 'w';
		GNode *p = first;
		for (int j = 3; j >= 0; j--){
			p->dlink = new GNode(b[0][j]);
			p = p->dlink;
		}*/
		// for (int i = 0; i <= 0; i++){
		GNode *p = first;
		for (int j = 4; j >= 0; j--)
		{
			while (p->Data != b[i][j] && p->link != NULL)
			{
				p = p->link;
			}
			if (p->Data == b[i][j])
			{
				p = p->dlink;
				if (j == 1)
				{
					j--;
					if (p->Data == -1)
						p->Data = p->Data + b[i][j] + 1;
					else
						p->Data = p->Data + b[i][j];
					b[i][j] = p->Data;
				}
				continue;
			}
			else if (p->link == NULL)
			{
				if (p->Data == -1)
				{
					p->Data = b[i][j];
				}
				else
				{
					GNode *q = new GNode(b[i][j]);
					p->link = q;
					p = p->link;
				}
				if (j == 4)
					p->var = 'w';
				if (j == 3)
					p->var = 'z';
				if (j == 2)
					p->var = 'y';
				if (j == 1)
					p->var = 'x';
				if (j != 0)
				{
					p->dlink = new GNode(-1);
					p = p->dlink;
				}
			}
		}
		/*for (int i1 = 0; i1 <= i; i1++){
			for (int j = 0; j < 5; j++){
				c[i1][j] = b[i1][j];
			}
		}*/
		i++;
		//}
	}

	int Polynomial::getCoef()
	{

		int term[4];
		string var[] = {"coeff", "pow x", "pow y", "pow z", "pow w"};
		int j = 0;
		while (j <= 3)
		{
			cout << var[j + 1] << " = ";
			cin >> term[j];
			j++;
		}
		j = 3;
		GNode *p = first;
		while (j >= 0)
		{
			while (p->Data != term[j] && p->link)
			{
				p = p->link;
			}
			if (p->Data == term[j])
				p = p->dlink;
			else if (!p->link)
			{
				cout << "Coeff = ";
				return 0;
			}
			j--;
		}
		cout << "Coeff = ";
		return p->Data;
	}

	int Polynomial::Eval()
	{
		int term[4];
		int j = 0;
		int s[5];
		string var[] = {"coeff", "pow x", "pow y", "pow z", "pow w"};
		int res = 0;
		while (j <= 3)
		{
			cout << var[j + 1] << " = ";
			cin >> term[j];
			j++;
		}
		int i1 = 0;
		GNode *p = first;
		GNode *q = p;
		while (p)
		{
			j = 3;
			s[i1] = 1;
			while (p)
			{
				if (j == -1)
					s[i1] = p->Data * s[i1];
				else
				{
					if (j != 3)
					{
						int m = 0;
						GNode *q1 = p;
						while (p)
						{
							m = m + pow(term[j], p->Data);
							p = p->link;
						}
						s[i1] = m * s[i1];
						p = q1;
					}
					else
						s[i1] = s[i1] * pow(term[j], p->Data);
					j--;
				}
				p = p->dlink;
			}
			p = q;
			p = p->link;
			q = p;
			res = res + s[i1];
			i1++;
		}
		/*for (int i1 = 0; i1 < i; i1++){
			s[i1] = 1;
			for (j = 1; j < 5; j++){
				s[i1] = s[i1]*pow(term[j-1], c[i1][j]);
			}
			s[i1] = s[i1] * c[i1][0];
			res = res + s[i1];
		}*/
		cout << "result = ";
		return res;
	}

	void Polynomial::Add()
	{

		int d[20][5];
		string var[] = {"coeff", "pow x", "pow y", "pow z", "pow w"};
		// for (int i1 = 0; i1 < i; i1++){
		for (int j = 0; j < 5; j++)
		{
			cout << var[j] << " = ";
			cin >> d[i][j];
		}
		Create(d);
		//}
		/*int m1 = 0;
		//int m = i;
		for (int i1 = 0; i1 < i; i1++){
			int i2 = 0;
			while ((d[i1][1] != c[i2][1] ||
				d[i1][2] != c[i2][2] ||
				d[i1][3] != c[i2][3] ||
				d[i1][4] != c[i2][4]) &&
				(i2 < i)){
				i2++;
			}
			if (i2 == i){
				for (int j = 0; j < 5; j++){
					c[m1][j] = d[i1][j];
				}
				m1++;
			}
			else{
				i2--;
				c[i2][0] = c[i2][0] + d[i1][0];
			}
		}*/
	}

	GNode *find()
	{

		int term[5];
		string var[] = {"coeff", "pow x", "pow y", "pow z", "pow w"};
		int j = 0;
		while (j <= 4)
		{
			cout << var[j] << " = ";
			cin >> term[j];
			j++;
		}
		j = 4;
		GNode *q;
		GNode *p = first;
		while (j >= 0)
		{
			while (p->Data != term[j] && p->link)
			{
				p = p->link;
			}
			if (p->Data == term[j])
			{
				if (j == 4)
					q = p;
				p = p->dlink;
			}
			else if (!p->link)
			{
				cout << "Address = ";
				return 0;
			}
			j--;
		}
		cout << "Start Address = ";
		return q;
	}

	void Print()
	{
		Print(first);
	}

	void Print(GNode *p)
	{
		while (p)
		{
			if (p->dlink)
				Print(p->dlink);
			if (!p->dlink)
				cout << "+";
			if (p->var != 'p')
			{
				// cout << "(";
				cout << p->var << "^" << p->Data;
				// cout << ")";
			}
			else
				cout << p->Data;
			p = p->link;
		}
	}
};
#endif