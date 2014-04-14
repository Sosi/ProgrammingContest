#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
using namespace std;
int main()
{
	freopen("A-small-attempt0.in","r",stdin);
	freopen("A-small-attempt0.out","w",stdout);
	int T;
	cin>>T;
	for(int t=1; t<=T; t++)
	{
		int x,y;
		cin>>x;
		int m[4][4];
		set<int> X;
		for(int i=0; i<4; i++)
		{
			for(int j=0; j<4; j++)
			{
				cin>>m[i][j];
				if(i+1  == x) X.insert(m[i][j]);
			}
		}
		cin>>y;
		set<int> Y;
		for(int i=0; i<4; i++)
		{
			for(int j=0; j<4; j++)
			{
				cin>>m[i][j];
				if(i+1  == y) Y.insert(m[i][j]);
			}
		}
		vector<int> ret(X.size() + Y.size());
		auto itr = set_intersection(X.begin(),X.end(), Y.begin(),Y.end(), ret.begin());
		ret.resize(itr - ret.begin());
		cout<<"Case #"<<t<<": ";
		if(ret.size() == 1)
			cout<<ret[0]<<endl;
		else if(ret.size() > 1)
		{
			cout<<"Bad magician!"<<endl;
		} else  cout<<"Volunteer cheated!"<<endl;
	}
}