#ifndef GLIST_H_
#define GLIST_H_
#include <iostream>
#include "GNode.h"
#include "Polynomial.h"

/**
 * 
 * @author Amir
 * @version 2013
 * 
 */

class GList
{
private:
	GNode *first;

public:
	GList()
	{
		first = NULL;
	}

	Polynomial *pol;

	GList::~GList()
	{
		delete pol;
	}
};
#endif