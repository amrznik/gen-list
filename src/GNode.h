#ifndef GNODE_H_
#define GNODE_H_
#include <iostream>
/*typedef struct {
	double coeff;
	char var;
	int power;
} term;*/

/**
 * 
 * @author Amir
 * @version 2013
 * 
 */

class GNode
{
	friend class GList;
	friend class Polynomial;

private:
	int tag;
	GNode *dlink;
	char var;
	int Data;
	// int coef;
	GNode *link;

public:
	GNode(int data)
	{
		tag = 1;
		dlink = NULL;
		var = 'p';
		// coef = 0;
		Data = data;
		link = NULL;
	}
};
#endif