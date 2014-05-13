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

/*
long long r, ans, q[N][N], w[N][N], x[N][N], a[N][N], y[N][N], i, j, n, m;

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    cin>>n>>m;
    for(i=1; i<=n; i++)
        for(j=1; j<=m; j++)
            cin>>a[i][j];
    for(i=1; i<=n; i++)
        for(j=1; j<=m; j++)
            x[i][j]=max(x[i-1][j], x[i][j-1])+a[i][j];
    for(i=1; i<=n; i++)
        for(j=m; j>0; j--)
            y[i][j]=max(y[i-1][j], y[i][j+1])+a[i][j];
    for(i=n; i>0; i--)
        for(j=1; j<=m; j++)
            q[i][j]=max(q[i+1][j], q[i][j-1])+a[i][j];
    for(i=n; i>0; i--)
        for(j=m; j>0; j--)
            w[i][j]=max(w[i+1][j], w[i][j+1])+a[i][j];
    for(i=2; i<n; i++)
        for(j=2; j<m; j++)
        {
            r=x[i][j-1]+q[i+1][j]+w[i][j+1]+y[i-1][j];
            ans=max(ans, r);
            r=x[i-1][j]+q[i][j-1]+w[i+1][j]+y[i][j+1];
            ans=max(ans, r);
        }
    cout<<ans;
}

Summer is coming! It's time for Iahub and Iahubina to work out,
 as they both want to look hot at the beach.

  The gym where they go is a matrix a with n lines and m columns.
  Let number a[i][j] represents the calories burned by performing workout at the cell of gym in the i-th line and the j-th column.

Iahub starts with workout located at line 1 and column 1.
 He needs to finish with workout a[n][m].
  After finishing workout a[i][j], he can go to workout a[i + 1][j] or a[i][j + 1].
   Similarly, Iahubina starts with workout a[n][1] and she needs to finish with workout a[1][m].
    After finishing workout from cell a[i][j], she goes to either a[i][j + 1] or a[i - 1][j].

There is one additional condition for their training.
 They have to meet in exactly one cell of gym.
 At that cell, none of them will work out.
 They will talk about fast exponentiation (pretty odd small talk) and
  then both of them will move to the next workout.

If a workout was done by either Iahub or Iahubina, it counts as total gain.
Please plan a workout for Iahub and Iahubina such as total gain to be as big as possible.
 Note, that Iahub and Iahubina can perform workouts with different speed,
  so the number of cells that they use to reach meet cell may differs.

Input
The first line of the input contains two integers n and m (3 ≤ n, m ≤ 1000).
Each of the next n lines contains m integers: j-th number from i-th line denotes element a[i][j] (0 ≤ a[i][j] ≤ 105).

Output
The output contains a single number — the maximum total gain possible.

*/

int i,j,k;
#define REP(i,n) for((i)=0;(i)<(int)(n);(i)++)
#define snuke(c,itr) for(__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)
int dirx[]= {1, 1, 0,-1,-1,-1,0,1};
int diry[]= {0,-1,-1,-1, 0, 1,1,1}; //clockwise
long long dpa[1005][1005]; long long dpc[1005][1005];
long long dpb[1005][1005]; long long dpd[1005][1005];
int num[1005][1005];
int main()
{
    ios_base::sync_with_stdio(0);
//    freopen("1.txt","r",stdin);
    memset(dpa, 0LL, sizeof(dpa));
    memset(dpb, 0LL, sizeof(dpb));
    memset(dpc, 0LL, sizeof(dpc));
    memset(dpd, 0LL, sizeof(dpd));
    int n,m; cin>>n>>m;
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
            cin>>num[i][j];
    }
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
            dpa[i][j] = max(dpa[i-1][j], dpa[i][j-1]) + num[i][j];
    }
    for(int i=n; i>=1; i--)
    {
        for(int j=m; j>=1; j--)
        {
            dpb[i][j] = max(dpb[i+1][j], dpb[i][j+1]) + num[i][j];
        }
    }

    for(int i=n; i>=1; i--)
    {
        for(int j=1; j<=m; j++)
            dpc[i][j] = max(dpc[i+1][j], dpc[i][j-1]) +num[i][j];
    }
    for(int i=1; i<=n; i++)
    {
        for(int j=m; j>=1; j--)
            dpd[i][j] = max(dpd[i-1][j],dpd[i][j+1]) + num[i][j];
    }
//    cout<<"a"<<endl;
//    for(int i=1; i<=n; i++)
//    {
//        for(int j=1; j<=m; j++)
//        {
//            cout<<dpa[i][j]<<" ";
//        }
//        cout<<endl;
//    }
//    cout<<"b"<<endl;
//    for(int i=1; i<=n; i++)
//    {
//        for(int j=1; j<=m; j++)
//        {
//            cout<<dpb[i][j]<<" ";
//        }
//        cout<<endl;
//    }
//    cout<<"c"<<endl;
//    for(int i=1; i<=n; i++)
//    {
//        for(int j=1; j<=m; j++)
//        {
//            cout<<dpc[i][j]<<" ";
//        }
//        cout<<endl;
//    }cout<<"d"<<endl;
//    for(int i=1; i<=n; i++)
//    {
//        for(int j=1; j<=m; j++)
//        {
//            cout<<dpd[i][j]<<" ";
//        }
//        cout<<endl;
//    }
    long long ret = 0LL;

    for(int i=2; i<n; i++)
    {
        for(int j=2; j<m; j++)
        {
            long long a = 0;
            a = max(a, (dpa[i-1][j] + dpb[i+1][j] + dpc[i][j-1] + dpd[i][j+1]));
//            a = max(a, dpa[i][j-1] + dpc[i+1][j]);
//            long long b = 0;
            a = max(a, (dpa[i][j-1] + dpb[i][j+1] + dpc[i+1][j]+ dpd[i-1][j]));
//            b = max(b, dpb[i][j+1]+ dpd[i-1][j]);
//            cout<<"a " <<a<<" b "<<b<<endl;
//            cout<<i<<" "<<j<<" "<<a+b<<endl;
//            long long a = dpa[i][j] + dpb[i][j] + dpc[i][j] + dpd[i][j] - 4* num[i][j];
            ret = max(ret, a);
        }
    }
    cout<<ret<<endl;
    return 0;
}
