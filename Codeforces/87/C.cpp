#include <iostream>
#include <set>
#include <vector>
using namespace std;
int main()
{
	//freopen("C.txt","r",stdin);
	int n;
	cin>>n;
	int M[2005];
	for(int i=1;i<=n;i++)
	{
		cin>>M[i];
	}
	int vis[2005];
	int h[2005];
	memset(vis,0,sizeof(vis));
	memset(h,0,sizeof(h));
	set<int> C;
	for(int i=1;i<=n;i++)
	{
		if(M[i]==-1)
		{
			vis[i]=1;
			C.insert(i);
			h[i]=1;
		}
	}
	//for(int i=1;i<=n;i++)cout<<h[i]<<endl; cout<<endl;

	set<int> D;
	int lh=2;
	for(int j=1;j<=n;j++)
	{
		for(int i=1;i<=n;i++)
		{
			if(vis[i]==0 && C.find(M[i])!=C.end() )
			{
				//cout<<i<<"  ";
				D.insert(i); h[i]=lh;vis[i]=1;
			}
		}
		C=D;
		D.clear();
		lh++;
	}
	int maxx=-1;
	for(int i=1;i<=n;i++)
	{
		//cout<<h[i]<<endl;
		if(h[i]>maxx) maxx=h[i];
	}
	cout<<maxx<<endl;
}