/**
  The main observation is that the card at index i (1 <= i <= N) ends up at index K * i % (N + 1) after 1 shuffle. So after x shuffles, the card will be at position K^x * i % (N + 1). We want to find the smallest x such that K^x * i = i for all i. In other words, we want K^x = 1. This is known as the multiplicative order of K mod (N + 1). Lagrange's theorem implies that this will be a factor of phi(N + 1) where phi is the Euler Totient function. So we can check all factors of phi(N + 1) and find the smallest one which works. See: http://en.wikipedia.org/wiki/Euler's_totient_function http://en.wikipedia.org/wiki/Lagrange's_theorem_(group_theory)


  very perfect DFS
  tried each factor in turn and get the smallest one, x, which verifies k^x =1 (mod N+1)
 **/

#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
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
#include <cctype>
#include <string>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
using namespace std;
//const double EPS=1e-11;
//const double PI=acos(-1.0);
//const short INF=32767,NF= -32768;
//const int INF=2147483647,NF= -2147483648;
//const long long INF=9223372036854775807,NF=-9223372036854775808;
//const long double INF=99999999.99999999;

template<class T> T gcd(T a,T b){ if(a<0) return gcd(-a,b);if(b<0)return gcd(a,-b);return (b==0)?a:gcd(b,a%b);}
template <class T> T lcm(T a,T b){ return a*(b/gcd(a,b));}
template<class T> inline vector<pair<T,int> > factorize(T n)
{vector<pair<T,int> > R;for (T i=2;n>1;){if (n%i==0){int C=0;for (;n%i==0;C++,n/=i);R.push_back(make_pair(i,C));}i++;if (i>n/i) i=n;}if (n>1) R.push_back(make_pair(n,1));return R;}
template<class T> inline bool isPrimeNumber(T n) {if(n<=1)return false;for (T i=2;i*i<=n;i++) if (n%i==0) return false;return true;}
template<class T> inline T eularFunction(T n){vector<pair<T,int> > R=factorize(n);T r=n;for (int i=0;i<R.size();i++)r=r/R[i].first*(R[i].first-1);return r;}



template<class T> string toString(T n){ostringstream ost;ost<<n;ost.flush();return ost.str();}
int toInt(string s){int r=0;istringstream sin(s);sin>>r;return r;}//NOTES:toInt(
long long toInt64(string s){long long r=0;istringstream sin(s);sin>>r;return r;}
double toDouble(string s){double r=0;istringstream sin(s);sin>>r;return r;}//NOTES:toDouble(
template<class T> void stoa(string s,int &n,T A[]){n=0;istringstream sin(s);for(T v;sin>>v;A[n++]=v);}
template<class T> void atos(int n,T A[],string &s){ostringstream sout;for(int i=0;i<n;i++){if(i>0)sout<<' ';sout<<A[i];}s=sout.str();}
template<class T> void atov(int n,T A[],vector<T> &vi){vi.clear();for (int i=0;i<n;i++) vi.push_back(A[i]);}
template<class T> void vtoa(vector<T> vi,int &n,T A[]){n=vi.size();for (int i=0;i<n;i++)A[i]=vi[i];}
template<class T> void stov(string s,vector<T> &vi){vi.clear();istringstream sin(s);for(T v;sin>>v;vi.push_bakc(v));}
template<class T> void vtos(vector<T> vi,string &s){ostringstream sout;for (int i=0;i<vi.size();i++){if(i>0)sout<<' ';sout<<vi[i];}s=sout.str();}

int prime[40100]; 
bool isprime[40100];
int N;

int power(int a, int pow)
{
    long long s=a,res = 1;
    for(int i=0; pow>>i; i++)
    {
        if((pow>>i)&1) res = res*s%(N+1);
        s=s*s%(N+1);
    }
    return res;
}
// pr[] is prime, ct[] is the order of prime. cnt is the number of prime, ret is the answer.
// find the smallest one(pow) santisfy the conditions. 
int ret, pr[400],ct[400],cnt;
void dfs(int dep, int k,  int pow )
{
    //cout<<dep<<" "<<k<<" "<<"pow "<<pow<<endl;
    if(pow >= ret) return;
    if(dep == cnt) { if(k==1 && pow !=1) ret = pow; return ;}
    for(int i=0; i<=ct[dep]; i++)
    {
        dfs(dep+1, k, pow);
        k=power(k,pr[dep]);
        pow*=pr[dep];
    }
}

int main()
{
    int tot= 0;
    for(int i=2; i<=40000; i++) if(!isprime[i])
    {
        prime[tot++]=i;
        for(int j=i; j<=40000;j+=i) isprime[j]=1;
    }
    int T,k;
    for(scanf("%d",&T); T; T--)
    {
        scanf("%d%d", &N, &k);
        int x= eularFunction(N+1);
        ret = x;
        cnt = 0;
        for(int j=0; j<tot && prime[j]*prime[j]<=x; j++ )
        {
            if(x%prime[j]==0)
            {
                pr[cnt]=prime[j]; ct[cnt] = 0;
                while(x%prime[j]==0) x/=prime[j],ct[cnt]++;
                cnt++;
            }
        }
        if(x!=1) pr[cnt]=x,ct[cnt]=1,cnt++;
        dfs(0,k,1);
        printf("%d\n", ret);
    }
    return 0;
}
