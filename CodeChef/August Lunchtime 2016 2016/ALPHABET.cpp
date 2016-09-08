#include <iostream>
#include <cstdio>
#include <string>
#include <sstream>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <ctime>
#include <cassert>
using namespace std;
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define vi vector<int>
#define vpii vector<pii>
#define SZ(x) ((int)(x.size()))
#define fi first
#define se second
#define FOR(i,n) for(int (i)=0;(i)<(n);++(i))
#define FORI(i,n) for(int (i)=1;(i)<=(n);++(i))
#define IN(x,y) ((y).find((x))!=(y).end())
#define ALL(t) t.begin(),t.end()
#define FOREACH(i,t) for (typeof(t.begin()) i=t.begin(); i!=t.end(); i++)
#define REP(i,a,b) for(int (i)=(a);(i)<=(b);++i)
#define REPD(i,a,b) for(int (i)=(a); (i)>=(b);--i)
#define REMAX(a,b) (a)=max((a),(b));
#define REMIN(a,b) (a)=min((a),(b));
#define DBG cerr << "debug here" << endl;
#define DBGV(vari) cerr << #vari<< " = "<< (vari) <<endl;

typedef long long ll;
const int INF = 1e9;

const int S = 26;
const int N = 1000;
const int W = 12;

int knows[S];

int cti(char c)
{
    return (int)(c - 'a');
}
int main()
{
    ios_base::sync_with_stdio(0);
    string s;
    cin >> s;
    assert(s.length() >= 1 && s.length() <= S);
    FOR(i, s.length()) knows[cti(s[i])]++;
    FOR(i, 26) assert(knows[i] <= 1);
    int n;
    cin >> n;
    assert(n >= 1 && n <= N);
    FOR(i, n)
    {
        string w;
        cin >> w;
        assert(w.length() >= 1 && w.length() <= W);
        bool fail = 0;
        FOR(j, w.length())
        {
            if(knows[cti(w[j])] == 0) fail = 1;
        }
        cout << (fail ? "No" : "Yes") << endl;
    }
    return 0;
}
