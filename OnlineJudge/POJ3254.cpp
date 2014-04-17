// 压缩状态DP


#include <iostream>
#include <cmath>
#include <cstring>
#include <vector>
using namespace std;
vector<int> t;  // the current map
vector<int> s;  // possible state
int MOD = 100000000;
int dp[15][1<<15];
int main()
{
	//freopen("1.txt","r",stdin);
	int M,N;
	while(cin>>M>>N)
	{
		s.clear(); t.clear();
		for(int tag=0; tag< (1<<N); tag++)
		{
			for(int k=0; k<N-1; k++)
			{
				if((tag &(1<<k)) && (tag &(1<<(k+1)))) break;
				if( k== N-2) s.push_back(tag);
			}
		}
		if(N == 1) {s.push_back(0); s.push_back(1);}
		for(int i=0; i<M; i++)
		{
			int x = 0;
			for(int j=0; j<N; j++)
			{
				int tag; cin>>tag;
				x += tag<<(N - j -1);
			}
			t.push_back(x);
		}

		memset(dp, 0, sizeof(dp));
		for(int i=0; i<s.size(); i++) 
		{
			if((s[i] | t[0]) ^ t[0]) continue;
			dp[0][s[i]] = 1;
		}
		for(int i=1; i< M; i++)   // row i
		{
			for(int j=0; j<s.size(); j++)
			{
				if((s[j] | t[i]) ^ t[i]) continue;
				//cout<<"Possible" <<s[j]<<endl;
				// cur state is s[j], pre is s[k];
				for(int k=0; k<s.size(); k++)
				{
					if(s[j] & s[k]) continue;
					dp[i][s[j]] += dp[i-1][s[k]];
					dp[i][s[j]] %= MOD;
				}
			}
		}
		int ret = 0;
		for(int i=0; i<s.size(); i++)
		{
			ret += dp[M-1][s[i]];
			ret %= MOD;
		}
		cout<<ret<<endl;
	}
	return 0;
}