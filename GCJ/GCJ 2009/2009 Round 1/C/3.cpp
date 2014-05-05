#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
using namespace std;

template<class T> T gcd(T a,T b)
{
    if(a<0) return gcd(-a,b);
    if(b<0)return gcd(a,-b);
    return (b==0)?a:gcd(b,a%b);
}
template <class T> T lcm(T a,T b)
{
    return a*(b/gcd(a,b));
}
template<class T> inline vector<pair<T,int> > factorize(T n)
{
    vector<pair<T,int> > R;
    for (T i=2; n>1;)
    {
        if (n%i==0)
        {
            int C=0;
            for (; n%i==0; C++,n/=i);
            R.push_back(make_pair(i,C));
        }
        i++;
        if (i>n/i) i=n;
    }
    if (n>1) R.push_back(make_pair(n,1));
    return R;
}
template<class T> inline bool isPrimeNumber(T n)
{
    if(n<=1)return false;
    for (T i=2; i*i<=n; i++) if (n%i==0) return false;
    return true;
}
template<class T> inline T eularFunction(T n)
{
    vector<pair<T,int> > R=factorize(n);
    T r=n;
    for (int i=0; i<R.size(); i++)r=r/R[i].first*(R[i].first-1);
    return r;
}
template<class T> string toString(T n)
{
    ostringstream ost;
    ost<<n;
    ost.flush();
    return ost.str();
}
int toInt(string s)
{
    int r=0;
    istringstream sin(s);
    sin>>r;
    return r;
}

int i,j,k;
#define REP(i,n) for((i)=0;(i)<(int)(n);(i)++)
#define snuke(c,itr) for(__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)
int dirx[]= {1, 1, 0,-1,-1,-1,0,1};
int diry[]= {0,-1,-1,-1, 0, 1,1,1}; //clockwise
#define INF  1000*105

int dp[105][105];
int main()
{
    //ios_base::sync_with_stdio(0);
    freopen("1.txt","r",stdin);
    int T;
    cin>>T;
    for(int cas = 1; cas <= T; cas++)
    {
        int P,Q;
        cin>>P>>Q;
        vector<int> D(Q+2);
        for(int i=1; i<Q+1; i++) cin>>D[i];
        D[0] = 0;
        D[Q+1] = P+1;
        for(int i=0; i<=Q+1; i++) for(int j=0; j<= Q+1; j++)
                dp[i][j] = INF;
        for(int i=0; i<Q+1; i++) dp[i][i+1] = 0;
//        for(int i=0; i<=Q+1; i++) cout<<D[i]<<" "; cout<<endl;
        for(int dis = 2; dis<=Q+1; dis++)
        {
            for(int i=0; i<=Q+1 - dis; i++)
            {
                int j = i+dis;
                int t = INF;
                for(int k = i+1; k<j; k++)
                {
                    t = min(t, dp[i][k] + dp[k][j]);
                }
                dp[i][j] = t+ D[j]-D[i]-2;
            }
        }
        cout<<"Case #"<<cas<<": "<<dp[0][Q+1]<<endl;
    }
    return 0;
}
