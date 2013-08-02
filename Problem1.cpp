//============================================================================
// Name        : Affinity 
// Description : Compatibility test, Audience targeting, Customers profiling
// Version     : 1.0
// Language     : C++
// Copyright   : Co. 2011-2013
// Author      : Habib
// Email	   : habiboulaye@gmail.com
//============================================================================

#include <utility>
#include "Problem.h"

///////////////////////////////////////////////////////////////////////////
// Solution 1
///////////////////////////////////////////////////////////////////////////
class cProblem1: public cProblem
{
private:
	map<string,int> _mapdata;
	int _ntop;

public:
	cProblem1(const char * infile)
		: cProblem(infile)
	{	_ntop=2;
		load_data(infile);
	}

	virtual void charge_data(char * textline)
	{
		string colleg;
		char * pch=strtok (textline,": ");
		while (pch != NULL)
		{
			if (colleg.empty())
				colleg=string(pch);
			else
				_mapdata[string(pch)]++;
			pch = strtok (NULL, ", ");
		}
	}

	void priority_weighting(map<string,int> mdata, priority_queue<pair<int,string> > &priorQue)
	{
		map<string, int >::const_iterator it;
		for (it=mdata.begin(); it!=mdata.end(); it++)
			priorQue.push(make_pair(it->second,it->first));
	}

	virtual void solve()
	{
		priority_queue<pair<int,string> > priorQ;

		priority_weighting(_mapdata,priorQ);

		pair<int,string> X=priorQ.top();
		int max_score=X.first;
		int n=0;
		while (!priorQ.empty())	{
			X=priorQ.top();
			if (++n<=_ntop)
				max_score=X.first;
			if (max_score > X.first)
				break;
			cout<<X.second<<endl;
			priorQ.pop();
		}
	}

	virtual ~cProblem1()
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
	cProblem1 Pb=cProblem1(infile);
	Pb.solve();
	return 0;
}
*/
