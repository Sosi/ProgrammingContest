#include <iostream>
using namespace std;
int main()
{
	//freopen("B.txt","r",stdin);
	char ma[11][11];
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			cin>>ma[i][j];
		}
	}
	int res=0;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(ma[i][j]=='P')
			{
				if(i-1>=0 && ma[i-1][j]=='W') ma[i-1][j]='.',res++;
				else if( i+1<n && ma[i+1][j]=='W') ma[i+1][j]='.',res++;
				else if(j-1>=0 && ma[i][j-1]=='W') ma[i][j-1]='.',res++;
				else if(j+1 <m && ma[i][j+1]=='W') ma[i][j+1]='.',res++;
			}
		}
	}
	cout<<res<<endl;
	return 0;
}