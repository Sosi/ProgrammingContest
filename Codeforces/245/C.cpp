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
#define MaxL 100005
vector<vector<int> > E(MaxL);
bool vis[MaxL];
int cur[MaxL];
int goal[MaxL];
vector<int> op;
void process(int idx, pair<int,int> mode)
{
    vis[idx] = 1;
//    cout<<idx<<" "<<mode.first<<" "<<mode.second<<endl;
    if(cur[idx] != goal[idx] && mode.second == 0 || cur[idx] == goal[idx] && mode.second == 1)
    {
        op.push_back(idx);
        mode.second ^=1;
    }
    swap(mode.first , mode.second);
    for(int i=0; i<E[idx].size(); i++)
    {
        if(vis[E[idx][i]]) continue;
//        cout<<E[idx][i]<<" !"<<endl;
//        cout<<"?" <<E[idx][i]<<" "<<mode.first<<" "<<mode.second<<endl;
        process(E[idx][i], mode);
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
//    freopen("1.txt","r",stdin);
    int n; cin>>n;
    int a, b;
    memset(vis, 0, sizeof(vis));
    for(int i=1; i<n; i++)
    {
        cin>>a>>b;
        E[a].push_back(b);
        E[b].push_back(a);
    }
    for(int i=1; i<=n; i++) cin>>cur[i];
    for(int i=1; i<=n; i++) cin>>goal[i];
//    vis[1] = 1;
//    int mode = 0;
    pair<int,int> mode = make_pair(0,0);
    process(1, mode);
    cout<<op.size()<<endl;
    for(int i=0; i<op.size(); i++) cout<<op[i]<<endl;
    return 0;
}
