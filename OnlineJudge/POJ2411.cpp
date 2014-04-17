// 压缩状态DP

#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

vector<int> s;  // possible state
long long dp[13][1<<12];  // dp[i][j]  the number of (row i state j)

int main()
{
	//freopen("1.txt","r",stdin);
	int M,N;
	while(cin>>M>>N && M!=0 && N!=0)
	{
		s.clear();
		if(M*N%2) {cout<<0<<endl; continue;}
		memset(dp,0,sizeof(dp));
		// 0-0 pair
		for(int tag = 0; tag < (1<<N); tag++)
		{
			for(int i=0; i<N; )
			{
				if(tag & (1<<i)) i++;
				else
				{
					if( i+1< N && !(tag&(1<<(i+1)))) i+=2;
					else break;
				}
				if(i== N) s.push_back(tag);
			}
		}
		for(int i=0; i<s.size(); i++) dp[0][s[i]] = 1;
		for(int step = 1; step< M; step++)
		{
			for(int tag = 0; tag < (1<<N); tag++)
			{
				for(int i=0; i<s.size(); i++)
				{
					if((tag & s[i]) != tag) continue;
					dp[step][tag^ s[i]] += dp[step-1][tag];
				}
			}
		}
		cout<<dp[M-1][0]<<endl;
	}
	return 0;
}