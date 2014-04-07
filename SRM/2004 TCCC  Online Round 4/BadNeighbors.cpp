#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

#define REP(i,n) for(int i=0;i<(n);++i)
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define FORD(i,a,b) for(int i=(a);i>=(b);--i)
#define FOREACH(i,c) for(__typeof((c).begin()) i=(c).begin();i!=(c).end();++i)
#define ALL(x) (x).begin(),(x).end()
typedef long long LL;
const int INF = 1000000000;
typedef vector<int> VI;
template<class T> inline int size(const T&c) { return c.size(); }

char buf1[1000];

string i2s(int x) {
	sprintf(buf1,"%d",x);
	return buf1;
}

int f[100][2];
struct BadNeighbors 
{
	int maxDonations(vector <int> donations) 
	{
		int n = size(donations);
		f[0][0] = 0;
		f[0][1] = donations[0];
		f[1][0] = donations[1];
		f[1][1] = max(donations[0],donations[1]);
		for(int i=2;i<=n-1;i++)
		{
			int a = donations[i];
			f[i][0] = max(a + f[i-2][0], f[i-1][0]);
			f[i][1] = max(a + f[i-2][1], f[i-1][1]);
		}
		return max(f[n-1][0], f[n-2][1]);
	}
};