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
#define MAXN 100005
int main()
{
    ios_base::sync_with_stdio(0);
//    freopen("1.txt","r",stdin);

    int vis[MAXN];
    memset(vis, 0, sizeof(vis));

    map<int, vector<int> > E;

    int n,m;
    cin>>n>>m;
    for(int i = 0; i<m; i++)
    {
        int a,b;
        cin>>a>>b;
        E[a].push_back(b);
        E[b].push_back(a);
    }
    int flag = 1;
    queue< pair<int,int> >Q;
    for(int i = 1; i<= n; i++)
    {
        if(flag == 0) break;
        if(vis[i] == 0 && E.find(i) != E.end())
        {
            Q.push({i,1});
            vis[i] = 1;
            while(!Q.empty())
            {
                pair<int,int> x = Q.front();
                Q.pop();
                if(flag == 0) break;
                for(int j = 0; j< E[x.first].size(); j++)
                {
                    if(vis[E[x.first][j]] == x.second)
                    {
                        flag = 0;
                        break;
                    }
                    else if(vis[ E[x.first][j] ] == 0)
                    {
                        vis[ E[x.first][j] ] = -x.second ;
                        Q.push({ E[x.first][j], -x.second});
                    }

                }


            }


        }
    }
    if(flag == 0) cout<<-1<<endl;
    else
    {
        int numa = 0;
        int numb = 0;
        for(int i =1; i<=n; i++)
        {
            if(vis[i] == 1) numa++;
            if(vis[i] == -1) numb++;
        }
        cout<<numa<<endl;
        for(int i =1; i<= n; i++)
        {
            if(vis[i] == 1) cout<<i<<" ";
        }
        cout<<endl;
        cout<<numb<<endl;
        for(int i = 1;i<=n; i++)
        {
            if(vis[i] == -1) cout<<i<<" ";
        }
        cout<<endl;
    }

    return 0;
}
