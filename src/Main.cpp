#include <iostream>
#include <string>
#include <conio.h>
#include "Polynomial.h"
#include "GNode.h"
#include "GList.h"

/**
 * Generalized Linked List to represent Polynomials with more than one variable
 * 
 * @author Amir
 * @version 2013
 * 
 */

using namespace std;

int f;
char c;
int funckey(char &c)
{
	c = _getch();
	if (c == 0)
	{
		c = _getch();
		return 1;
	}
	else
		return 0;
}

int main()
{
	char c = 0;
	int in[20][5];
	string var[] = {"coeff", "pow x", "pow y", "pow z", "pow w"};
	int i = 0;

	Polynomial *pol = new Polynomial();
	GList *gen = new GList();

	while (i < 20 && c != 27)
	{
		for (int j = 0; j <= 4; j++)
		{
			cout << var[j] << " = ";
			cin >> in[i][j];
		}
		i++;
		cout << "Please choose function: ";
		f = funckey(c);
		pol->Create(in);
		if (c == 100)
		{
			cout << "Distruct...";
			pol->~Polynomial();
			// gen->~GList();
		}
		if (c == 103)
		{
			cout << "getCoeff..."
				 << "\n";
			cout << pol->getCoef();
		}
		if (c == 101)
		{
			cout << "Eval..."
				 << "\n";
			cout << pol->Eval();
		}
		if (c == 102)
		{
			cout << "Find..."
				 << "\n";
			GNode *m = pol->find();
			cout << m;
			cout << "\n";
			pol->Print(m);
		}
		if (c == 97)
		{
			cout << "Add..."
				 << "\n";
			while (c == 97)
			{
				pol->Add();
				/*for (int i1 = 0; i1 < i; i1++){
					for (int j = 0; j < 5; j++){
						in[i1][j] = pol->c[i1][j];
						//cout << in[i1][j];
					}
				}
				pol->i--;
				pol->Create(in);*/
				pol->Print();
				i++;
				cout << "\n"
					 << "If you want to continue, please press a, otherwise press Enter..."
					 << "\n";
				f = funckey(c);
			}
		}
		if (c == 112)
		{
			cout << "Print..."
				 << "\n";
			pol->Print();
		}
		cout << "\n";
		if (c == 27)
		{
			cout << "Bye!";
		}
	}
	cout << "Polynomial is full, Bye!";
	_getch();
}