#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
int main()
{
	freopen("A-large-practice.in","r",stdin);
	freopen("A-large-practice.out","w",stdout);
	int T;
	cin>>T;
	for(int t=1;t<=T;t++)
	{
		int n;
		cin>>n;
		vector<int> R;
		vector<int> B;
		for(int i=0;i<n;i++)
		{
			int a;char b;
			cin>>a>>b;
			//cout<<a<<b<<endl;
			
			if(b=='B') B.push_back(a);
			else
				R.push_back(a);
		}
		sort(R.begin(),R.end());
		sort(B.begin(),B.end());
		int size=min(R.size(),B.size());
		int res=0;
		for(int i=0;i<size;i++)
		{
			res+=R[R.size()-i-1]+B[B.size()-i-1];
		}
		res-=size*2;
		cout<<"Case #"<<t<<": "<<res<<endl;
	}
	return 0;
}