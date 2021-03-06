#include<stdio.h>
#include<string.h>
#include<iostream>


using namespace std;

int n,m,a,b,c;
char ans[200][200];

int main()
{
	scanf("%d%d%d%d%d",&n,&m,&a,&b,&c);
	if(n%2==1) a -= m/2;
	if(m%2==1) b -= n/2;
	if(n*m%2==1 || a<0 || b<0)
	{
		printf("IMPOSSIBLE\n");
		return 0;
	}
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			ans[i][j] = (i/2%2) == (j/2%2) ? 'a' : 'b';
	c -= (n/2) * (m/2);
	for(int i=0;i<n-n%2;i+=2)
		for(int j=0;j<m-m%2;j+=2)
		{
			if(c<0 && a>=2)
			{
				a-=2; c++;
				ans[i][j] = ans[i][j+1] += 2;
			}
			else if(c<0 && b>=2)
			{
				b-=2; c++;
				ans[i][j] = ans[i+1][j] += 2;
			}
		}
		if(a<0 || b<0 || c<0)
		{
			printf("IMPOSSIBLE\n");
			return 0;
		}
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
				printf("%c",ans[i][j]);
			printf("\n");
		}
		return 0;
}