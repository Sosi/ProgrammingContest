#include <iostream>
using namespace std;
int main()
{
	int n,m;
	cin>>n>>m;
	char M[157][157];
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			cin>>M[i][j];
		}
	}
	int l[157];  fill(l,l+155,200);
	int r[157]; fill(r,r+155,0);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(M[i][j]=='W')
			{
				if(i<l[i]) l[i]=i;
				if(i>r[i]) r[i]=i;
			}
		}
	}
	int dir=1; //right
	for(int i=1;i<=n;i++)
	{
		if(dir==1)
		{

		}
		dir=dir^1;

	}



}