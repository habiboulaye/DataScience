//============================================================================
// Name        : Affinity 
// Description : Compatibility test, Audience targeting, Customers profiling
// Version     : 1.0
// Language     : C++
// Copyright   : Co. 2011-2013
// Author      : Habib
// Email	   : habiboulaye@gmail.com
//============================================================================

#ifndef AFFINITYTEST_H_
#define AFFINITYTEST_H_

///////////////////////////////////////////////////////////////////////////

#include <stdlib.h>
#include <cstring>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <queue>
#include <list>
#include <map>
using namespace std;

///////////////////////////////////////////////////////////////////////////
// Class : cProblem
///////////////////////////////////////////////////////////////////////////
class cProblem
{
protected:
	unsigned nb;

public:
	cProblem(const char * infile)
		:	nb(0)	{ }
	void load_data(const char * infile)
	{
		ifstream pfile;
		pfile.open(infile, ifstream::in);
		char textline[1024];
		string key;
		vector<string> vtmp;
		while (!pfile.eof())	{
			pfile.getline(textline,1024);
			if (nb==0)
				nb=atoi(textline);
			else	{
				charge_data(textline);
			}
		}
		pfile.close();
	}
	virtual void charge_data(char * textline)=0;
	virtual void solve()=0;
	virtual ~cProblem()	{}
};
#endif /* AFFINITYTEST_H_ */
