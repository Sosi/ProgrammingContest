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
#define MOD 1000000007
int i,j,k;
#define REP(i,n) for((i)=0;(i)<(int)(n);(i)++)
#define snuke(c,itr) for(__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)
int dirx[]= {1, 1, 0,-1,-1,-1,0,1};
int diry[]= {0,-1,-1,-1, 0, 1,1,1}; //clockwise

long long frac(long long x)
{
    long long ret = 1LL;
    for(long long i=2LL; i<=x; i++)
    {
        ret *= i;
        ret %= MOD;
    }
    return ret;
}
struct link
{
    pair<char, char> c;
    long long num;
};

bool cmp(const link &x, const  link &y)
{
    if(x.c.first == y.c.first)
        return x.c.second < y.c.second;
    return x.c.first < y.c.first;
}
int main()
{
    ios_base::sync_with_stdio(0);
    freopen("B-small-practice.in","r",stdin);
    freopen("B-small-practice.out","w",stdout);
    int T;
    cin>>T;
    for(int cas = 1; cas <= T; cas++)
    {
        int n;
        cin>>n;
        vector<string> s(n);
        for(int i=0; i<n; i++) cin>>s[i];

        vector<link>  l;

        bool possible = true;
        // check single
        for(int i=0; i<n; i++)
        {
            string tmp;
            for(int j=0; j<s[i].size()-1; j++)
            {
                if(s[i][j] != s[i][j+1]) tmp+= s[i][j];
            }
            tmp+= s[i][s[i].size()-1];
            set<char> count;
            for(int j=0; j<tmp.size(); j++)
            {
                if(count.find(tmp[j]) != count.end()) possible = 0;
                else count.insert(tmp[j]);
            }
        }
        // check mutable
        for(int i=0; i<n; i++)
        {
            set<char> count;
            for(int k=0; k<n; k++)
            {
                if(k ==i) continue;
                for(int j=0; j<s[k].size(); j++)
                    count.insert(s[k][j]);
            }

            if(s[i][0] == s[i][s[i].size()-1])
            {
                for(int j=1; j<s[i].size()-1; j++)
                {
                    if(s[i][j]!=s[i][0] && count.find(s[i][j])!= count.end())
                    {
                        possible = false;
                    }
                }
            }
            else
            {
                for(int j=1; j<s[i].size()-1; j++)
                {
                    if(s[i][j] != s[i][0] && s[i][j] != s[i][s[i].size()-1] && count.find(s[i][j])!= count.end())
                    {
                        possible = false;
//                        cout<<"!!!"<<s[i][j]<<endl;
                    }

                }
            }
            link x;
            x.c = make_pair(s[i][0], s[i][s[i].size() - 1]);
            x.num = 1;
            l.push_back(x);
        }
//        cout<<" fist "<<cas<<" "<<possible<<endl;
        sort(l.begin(), l.end(),cmp);
//        cout<<"link "<<endl;
//        if(possible)
//        {
//            for(int i=0; i<l.size(); i++)
//            {
//                cout<<l[i].c.first <<" "<<l[i].c.second<<endl;
//            }
//        }
        vector<link> another;
        for(int i=0; i<l.size();)
        {
            vector<link> p;
            p.push_back(l[i]);
            char start = l[i].c.first;
            char _end;
            i++;
            for(int j=i; j<l.size(); j++)
            {
//                i++;
                if(l[j].c.first == start)
                {
                    i++;
                    p.push_back(l[j]);
                }
                else break;
            }
            int num = 0;
            for(int j=0; j<p.size(); j++)
            {
                if(p[j].c.second != start)
                {
                    _end = p[j].c.second;
                    num++;
//                    possible = 0;
                }
            }
            if(num >=2) possible = 0;
            if(possible)
            {
                link q;
                if(num == 0)
                {
                    q.c = p[0].c;
                    q.num = frac(p.size());
                }
                else
                {
                    q.c = make_pair(start, _end);
                    q.num = frac(p.size()-1);
                }
                another.push_back(q);
            }
//            cout<<i<<endl;
        }
//        cout<<" ! "<<another.size()<<" "<<possible<<endl;
        if(possible)
        {
            for(int i=0; i<another.size(); i++)
            {
                set<char> so;
                if(so.find(another[i].c.second) != so.end())
                    possible = false;
                so.insert(another[i].c.second);
            }
        }
//        cout<<"another "<<endl;
//        if(possible)
//        {
//            for(int i=0; i<another.size(); i++)
//            {
//                cout<<another[i].c.first <<" "<<another[i].c.second<<endl;
//            }
//        }
        vector<long long> sum;
        if(possible)
        {
            vector<bool> vis(another.size());
            fill(vis.begin(), vis.end(), 0);
//            vis[0] = 1;
//            int retn = 0;
            for(int i=0; i<another.size(); i++)
            {
                if(vis[i] == 0)
                {
                    long long ret = 1LL;
                    ret *= another[i].num;
                    ret%=MOD;
                    vis[i] = 1;
                    char target = another[i].c.second;
                    for(int j=0; j<another.size(); j++)
                    {
                        if(!vis[j] && another[j].c.first == target)
                        {
                            vis[j] = 1;
                            target = another[j].c.second;
                            ret*= another[j].num;
                            ret%= MOD;
                            j = 0;
                        }
                    }
                    sum.push_back(ret);
//                    retn++;
                }
            }

        }
//        cout<<"Possible "<<possible<<endl;
//        cout<<"size "<<sum.size()<<endl;
        long long ret = 1LL;
        ret *= frac(sum.size());
        ret%= MOD;
        for(int i=0; i<sum.size(); i++)
        {
            ret*= sum[i];
            ret%= MOD;
        }
        if(possible) cout<<"Case #"<<cas<<": "<<ret<<endl;
        else cout<<"Case #"<<cas<<": "<<0<<endl;
    }

    return 0;
}
