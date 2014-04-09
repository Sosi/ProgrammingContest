#include <iostream>
#include <vector>
using namespace std;
int ma[5005][5005];

int main()
{
	freopen("1.txt","r",stdin);
	memset(ma,0,sizeof(ma));
	int n;
	cin>>n;
	vector<int> p(n);
	int temp;
	for(int i=0;i<n;i++)
	{
		cin>>temp;
		p[i]=temp;
	}
	int a,b,c;
	for(int i=0;i<n-1;i++)
	{
		cin>>a>>b>>c;
		ma[a-1][b-1]=c;
		ma[b-1][a-1]=c;
	}
	vector<int> flag(n,0);
	vector<int> father(n,-1);
	father[0]=0;
	for(int k=0;k<n;k++)
	{
		for(int i=0;i<n;i++)
		{
			if(father[i]!=-1&& flag[i]==0)
			{
				for(int j=0;j<n;j++)
				{
					if(ma[i][j]!=0 && father[j]==-1)
						father[j]=i;
				}
				flag[i]=1;
			}
		}
	}
	for(int i=0;i<father.size();i++)
		cout<<father[i]<<" ";
	vector<int>time(n,0);
	for(int i=0;i<n;i++)
	{

	}


	//cout<<p.size()<<endl;
	return 0;
}