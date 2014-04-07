#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

struct Coin
{
	int n;
	int g;
};
bool cmp(Coin a,Coin b)
{
	return (a.n-a.g)<(b.n-b.g);
}
class CoinMachinesGame
{
public:
	int maxGames(int coins, vector <int> need, vector <int> give)
	{
		vector<Coin> P(need.size());
		for(int i=0;i<P.size();i++)
		{
			P[i].n=need[i];
			P[i].g=give[i];
		}
		sort(P.begin(),P.end(),cmp);
		int res=0;
		int rem=coins;
		for(int i=0;i<P.size();i++)
		{
			cout<<P[i].n<<"  "<<P[i].g<<endl;
			if(rem>P[i].n)
			{
				res+=(rem-P[i].n)/(P[i].n-P[i].g);
				rem=P[i].n+(rem-P[i].n)%(P[i].n-P[i].g);
				cout<<"res "<<res<<endl;
				cout<<"rem "<<rem<<endl;
			}
			if(rem>P[i].n)
			{
				res++;
				rem-=(P[i].n-P[i].g);
			}
			if(rem==P[i].n)
			{
				res++;
				rem-=(P[i].n-P[i].g);
				cout<<"ddd"<<endl;
				cout<<"res "<<res<<endl;
				cout<<"rem "<<rem<<endl;
			}
		}
		return res;
	}
};