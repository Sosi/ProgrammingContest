// 压缩状态DP

#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;
int cost[11][11];
int dp[1<<11];
int main()
{
	int N;
	while(cin>>N && N!=0)
	{
		for(int i=0; i<N; i++)
		{
			for(int j=0; j<N; j++)
				cin>>cost[i][j];
		}
		memset(dp, 0, sizeof(dp));
		for(int tag = 0; tag < (1<<N); tag++)  // tag == 0
		{
			for(int i = 0; i<N; i++)
			{
				if(tag & (1<<i)) continue;
				for(int j=0; j<N; j++)
				{
					if(tag & (1<<j) || i==j) continue;
					dp[tag ^ (1<<j)] = max(dp[tag ^ (1<<j)], dp[tag]+ cost[i][j]);
				}
			}
		}

		int ret = 0;
		for(int i=0; i<(1<<N); i++)
			ret = max(ret, dp[i]);
		cout<<ret<<endl;
	}
	return 0;
}