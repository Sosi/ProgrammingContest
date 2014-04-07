View Jewelry   Problem Statement
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <utility>
using namespace std;

#define REP(i,n) for(int i=0;i<(n);++i)
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define FORD(i,a,b) for(int i=(a);i>=(b);--i)
#define FOREACH(i,c) for(__typeof((c).begin()) i=(c).begin();i!=(c).end();++i)
typedef long long LL;
const int INF = 1000000000;
typedef vector<int> VI;
template<class T> inline int size(const T&c) { return c.size(); }

char buf1[1000];

string i2s(int x) {
	sprintf(buf1,"%d",x);
	return buf1;
}

const int MAXN = 30;
const int MAX = 30000;

int n;
VI v;

LL B[MAXN+1][MAX+1]; // [n pocz][sum]
LL F[MAXN+1][MAX+1];

LL nk[MAXN+1][MAXN+1];

void cnk() {
	nk[0][0]=1;
	FOR(k,1,MAXN) nk[0][k]=0;
	FOR(n,1,MAXN) {
		nk[n][0]=1;
		FOR(k,1,MAXN) nk[n][k] = nk[n-1][k-1]+nk[n-1][k];
	}
}

void calc(LL T[MAXN+1][MAX+1]) {
	T[0][0] = 1;
	FOR(x,1,MAX) T[0][x]=0;
	FOR(ile,1,n) {
		int a = v[ile-1];
		FOR(x,0,MAX) {
			T[ile][x] = T[ile-1][x];
			if(x>=a) T[ile][x] +=T[ile-1][x-a];
		}
	}
}

struct Jewelry 
{
	// MAIN
	long long howMany(vector <int> vv)
	{
		v = vv;
		n = size(v);
		cnk();
		sort(v.begin(),v.end(),greater<int>());
		calc(F);
		sort(v.begin(),v.end());
		calc(B);
		LL res = 0;
		int done=0;
		while(done<n)
		{
			int p=done;
			while(p<n && v[p]==v[done]) ++p;
			int c=p-done;
			FOR(u,1,c) 
			{
				int uu = u * v[done];
				FOR(x,uu,MAX)
					res += B[done][x-uu] * F[n-done-u][x] * nk[c][u];
			}
			done=p;
		}
		return res;
	}



};