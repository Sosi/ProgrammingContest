#include<iostream>
#include<algorithm>
#include<stdio.h>
#include<map>
#include<string>
#include<string.h> 
#include<queue> 
using namespace std;

const int N = 1005;
int  a[N][N],b[N];

int main()
{
	int n,i,j;
	while( scanf("%d",&n) != EOF )
	{
		for( i = 0 ; i < n;i++ )
			a[0][i] = i;
		for( i = 1 ; i < n;i++ )
			for( j = 0 ; j < n-1;j++ ) 
			{
				int t = (j+i)%(n-1);
				if( t == 0) t = n-1;
				a[i][j] = t;
			}
			for( i = 1 ; i < n;i++ )
			{
				a[i][n-1] = a[i][i];
				a[i][i] = 0;
			}
			for( i = 0 ; i < n ;i++ )
				a[n-1][i] = a[i][n-1];

			for( i = 0 ; i < n ;i++ ) 
			{
				for( j = 0 ; j < n;j++ ) 
				{
					if( j != 0 ) cout<<" ";
					cout<<a[i][j];
				}
				cout<<endl;
			}  
	}
	return 0;
}
