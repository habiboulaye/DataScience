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
// Class : cCollegue
///////////////////////////////////////////////////////////////////////////
class cCollegue	{
private:
	string _name;
	bool _happy;

public:
	cCollegue(string name)
		:_name(name)	{
		_happy=false;
	}
	string name() const {
		return _name;
	}
	bool is_happy()	const {
		return _happy;
	}
	void set_happy()	{
		_happy=true;
	}
};

///////////////////////////////////////////////////////////////////////////
// Solution 3
///////////////////////////////////////////////////////////////////////////
class cProblem3: public cProblem
{
protected:
	map<string, list<cCollegue *> > _mapdata;
	unsigned _nmax_playlist;

public:
	cProblem3(const char * infile)
		: cProblem(infile)	{
		_nmax_playlist = 8*60/5;
		load_data(infile);
	}

	virtual void charge_data(char * textline)
	{
		cCollegue * cclg=NULL;
		char * pch=strtok (textline,": ");
		while (pch != NULL)
		{
			if (cclg==NULL)
				cclg = new cCollegue(string(pch));
			else
				_mapdata[string(pch)].push_back(cclg);
			pch = strtok (NULL, ", ");
		}
	}

	void transpose_map(map<string,list<cCollegue*> > mdata, map<pair<int,string>, list<cCollegue*> > &tmap)
	{
		map<string, list<cCollegue*> >::const_iterator it;
		for (it=mdata.begin(); it!=mdata.end(); it++)	{
			tmap[make_pair(-it->second.size(),it->first)]=it->second;
		}
	}

	virtual void solve()
	{
		map<pair<int,string>,list<cCollegue*> > tmdata;
		transpose_map(_mapdata,tmdata);
		map<pair<int,string>,list<cCollegue*> >::iterator it;
		list<cCollegue*>::iterator jt;
		pair<int,string> prkey;
		list<cCollegue*> lstClg;
		unsigned count=0;
		while (!tmdata.empty())	{
			it=tmdata.begin();
			// stop condition
			if ((it->first.first==0) || (++count == _nmax_playlist))
				break;
			// output result
			cout<<it->first.second<<endl;
			for (jt=it->second.begin();jt!=it->second.end();jt++)
				(*jt)->set_happy();
			// update map
			tmdata.erase(it);
			size_t i;
			while (!tmdata.empty())	{
				it=tmdata.begin();
				i=0;
				for (jt=it->second.begin();jt!=it->second.end();jt++)
					if ((*jt)->is_happy())
						i++;
				if (it->first.first==-(int)(it->second.size()-i))
					break;
				prkey = make_pair(-(it->second.size()-i),it->first.second);
				lstClg=it->second;
				tmdata.erase(it);
				tmdata[prkey]=lstClg;
			}
		}
	}
	virtual ~cProblem3() {
		_mapdata.erase(_mapdata.begin(), _mapdata.end());
	}
};

///////////////////////////////////////////////////////////////////////////
// Principal Main
///////////////////////////////////////////////////////////////////////////
/*
int main(int argC, char *argV[]) {
	const char *infile=argV[1];
	cProblem3 Pb=cProblem3(infile);
	Pb.solve();
	return 0;
}
*/
