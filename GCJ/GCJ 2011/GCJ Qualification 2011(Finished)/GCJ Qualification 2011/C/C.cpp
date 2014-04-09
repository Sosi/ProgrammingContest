#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
	freopen("C-large.in","r",stdin);
	freopen("C-large.out","w",stdout);
	int T;
	cin>>T;
	for(int Case=1;Case<=T;Case++)
	{
		int N;
		cin>>N;
		vector<int> P(N);
		for(int i=0;i<N;i++)
		{
			cin>>P[i];
		}
		sort(P.begin(),P.end());
		int res=P[0];
		for(int i=1;i<P.size();i++)
			res^=P[i];
		if(res!=0)
		{
			cout<<"Case #"<<Case<<": NO"<<endl;
		}
		else
		{
			res=0;
			for(int i=1;i<P.size();i++)
			{
				res+=P[i];
			}
			cout<<"Case #"<<Case<<": "<<res<<endl;
		}
	}
	return 0;
}