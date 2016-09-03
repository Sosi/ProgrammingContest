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

//int main()
//{
//    ios_base::sync_with_stdio(0);
//////    freopen("1.txt","r",stdin);
////    vector<int> A(200, -1);
////    for(int i = 1; i< 3000000; i++)
////    {
////        int x = i;
////        int num = 0;
////        while( x> 0)
////        {
////            int y = pow(x+0.5, 1/3.0);
//////            cout<<y<<" ";
////            x -= y*y*y;
////            num++;
////        }
////        int y =pow(i+0.5, 1/3.0);
////        A[y] = max(num, A[y]);
//////        cout<<" ! "<<i<<" "<<num<<endl;
////    }
////
////    for(int i = 0; i< A.size(); i++)
////    {
////        cout<<i<<" "<<A[i]<<endl;
////    }
//    return 0;
//}



typedef long long ll;

pair<ll,ll> best;

ll my_pow(ll x) { return x * x * x; }

void rec(ll m, ll steps, ll subtracted) {
	if(m == 0) {
		best = max(best, make_pair(steps, subtracted));
		return;
	}
	ll x = 1;
	while(my_pow(x+1) <= m) ++x;
	rec(m - my_pow(x), steps+1, subtracted + my_pow(x));
	if(x - 1 >= 0)
		rec(my_pow(x)-1-my_pow(x-1), steps+1, subtracted + my_pow(x-1));
}

int main() {
	ll m; cin>>m;
	rec(m, 0, 0);
	printf("%lld %lld\n", best.first, best.second);
	return 0;
}
