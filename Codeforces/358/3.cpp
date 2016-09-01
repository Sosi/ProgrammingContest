#include <bits/stdc++.h>
using namespace std;

const long long MOD = 1e6+3;
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

template<class T> inline T  qpow(T x,T y)
{
    T ret=1;
    while(y)
    {
        if(y&1) ret=ret*x%MOD;
        x=x*x%MOD;
        y>>=1;
    }
    return ret;
}

int toInt(string s)
{
    int r=0;
    istringstream sin(s);
    sin>>r;
    return r;
}

int main()
{
    ios_base::sync_with_stdio(0);
//    freopen("1.txt","r",stdin);

    int n; cin>>n;
    int A[100005];
    for(int i = 1; i<= n; i++)
        cin>>A[i];

    int p,c;
    map<int,vector<pair<int, int> > > G;
    for(int i = 2; i<=n; i++)
    {
        cin>>p>>c;
        G[i].push_back({p,c});
        G[p].push_back({i,c});
    }

    int num = 0;

    queue< pair<int, int> > Q;
    Q.push({1,0});

    int vis[100005];
    for(int i = 0; i<=n; i++) vis[i] = 0;
    vis[1] = 1; num++;
    while(!Q.empty())
    {
        pair<int,int > x = Q.front();
        Q.pop();

        for(int i = 0; i< G[x.first].size(); i++)
        {
            if(vis[G[x.first][i].first] == 0 && x.second + G[x.first][i].second <= A[ G[x.first][i].first])
            {
//                cout<<"sy "<<G[x.first][i].first<<endl;
                vis[G[x.first][i].first] = 1; num++;
                if(x.second + G[x.first][i].second < 0)
                    Q.push({G[x.first][i].first, 0});
                else
                    Q.push({G[x.first][i].first, x.second + G[x.first][i].second});
            }
        }
    }
    cout<<n - num<<endl;
    return 0;
}
