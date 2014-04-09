#include <iostream>
#include <vector>
using namespace std;
int main()
{
	freopen("D-large.in","r",stdin);
	freopen("D-large.out","w",stdout);
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
			P[i]--;
		}
		double ret=0;
		vector<int> F(N,-1);
		//F[0]=1;
		for(int j=0;j<N;j++)
		{
			int res=0;
			int prej=j;
			while(F[j]==-1)
			{
				F[j]=1;
				j=P[j];
				res++;
			}
			j=prej;
			if(res>1)
				ret+=res;
		}
		cout<<"Case #"<<Case<<": "<<ret<<endl;
	}
	return 0;
}