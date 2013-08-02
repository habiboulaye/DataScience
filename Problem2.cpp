//============================================================================
// Name        : Affinity 
// Description : Compatibility test, Audience targeting, Customers profiling
// Version     : 1.0
// Language     : C++
// Copyright   : Co. 2011-2013
// Author      : Habib
// Email	   : habiboulaye@gmail.com
//============================================================================

#include "Problem.h"

///////////////////////////////////////////////////////////////////////////
// Solution 2
///////////////////////////////////////////////////////////////////////////
class cProblem2: public cProblem
{
private:
	map<string, vector<string> > _mapdata;

public:
	cProblem2(const char * infile)
		: cProblem(infile)
	{
		load_data(infile);
	}

	virtual void charge_data(char * textline)
	{
		string collegue;
		char * pch=strtok (textline,": ");
		while (pch != NULL)
		{
			if (collegue.empty())
				collegue=string(pch);
			else
				_mapdata[string(pch)].push_back(collegue);
			pch = strtok (NULL, ", ");
		}
	}

	virtual void solve()
	{
		map<string, vector<string> >::const_iterator it;
		vector<string>::const_iterator jt;
		for (it=_mapdata.begin(); it!=_mapdata.end(); it++)
		{
			cout<<it->first<<": ";
			for (jt=it->second.begin(); jt!=it->second.end(); jt++)
			{
				if (jt < it->second.end()-1)
					cout<<*jt << ", ";
				else
					cout<<*jt <<endl;
			}
		}
	}

	virtual ~cProblem2()
	{
		_mapdata.erase(_mapdata.begin(),_mapdata.end());
	}
};

///////////////////////////////////////////////////////////////////////////
// Principal Main
///////////////////////////////////////////////////////////////////////////
/*
int main(int argC, char *argV[]) {
	const char *infile=argV[1];
	cProblem2 Pb=cProblem2(infile);
	Pb.solve();
	return 0;
}
*/
