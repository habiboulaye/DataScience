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
// Class : cProblem4
///////////////////////////////////////////////////////////////////////////
class cProblem4: public cProblem
{
protected:
	map<string, list<string> > _mapdata;
	map<string, list<string> > _rmapdata;
	int _naffinity;
public:
	cProblem4(const char * infile)
		: cProblem(infile)	{
		_naffinity=2;
		load_data(infile);
	}

	virtual void charge_data(char * textline)
	{
		string colleg, band;
		char * pch=strtok (textline,": ");
		while (pch != NULL)
		{
			if (colleg.empty())	{
				colleg=string(pch);
			}
			else	{
				band = string(pch);
				_mapdata[colleg].push_back(band);
				_rmapdata[band].push_back(colleg);
			}
			pch = strtok (NULL, ", ");
		}
	}

	virtual void solve()
	{
		map<pair<string,string>, int> mapres;
		map<string, list<string> >::iterator it;
		list<string>::iterator jt, kt;
		string target, candidat, band;
		pair<string,string> key;
		bool bfirst;
		for (it=_mapdata.begin(); it!=_mapdata.end(); it++)
		{
			target=it->first;
			cout<<target<< ":";
			bfirst=true;
			for (jt=it->second.begin(); jt!=it->second.end(); jt++)
			{
				band = *jt;
				for (kt=_rmapdata[band].begin(); kt!=_rmapdata[band].end(); kt++)
				{
					candidat = *kt;
					if (candidat!=target)
					{
						key = make_pair(target,candidat);
						mapres[key]++;
						if (mapres[key]==_naffinity)
						{
							if (bfirst==true)	{
								cout<<" ";
								bfirst=false;
							}
							else
								cout<<", ";
							cout<<candidat;
						}
					}
				}
			}
			cout<<endl;
		}
	}

	virtual ~cProblem4() {
		_mapdata.erase(_mapdata.begin(), _mapdata.end());
		_rmapdata.erase(_rmapdata.begin(), _rmapdata.end());
	}
};

///////////////////////////////////////////////////////////////////////////
// Principal Main
///////////////////////////////////////////////////////////////////////////

int main(int argC, char *argV[]) {
	const char *infile=argV[1];
	cProblem4 Pb=cProblem4(infile);
	Pb.solve();
	return 0;
}

