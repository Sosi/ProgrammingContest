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

string base7(int x)
{
    string ret = "";
    if(x == 0) return "0";
    while(x != 0)
    {
        ret += x%7 +'0';
        x/= 7;
    }
    reverse(ret.begin(), ret.end());
    return ret;
}
const int MAXN =100005;
int main()
{
    ios_base::sync_with_stdio(0);
//    freopen("1.txt","r",stdin);

    int t; cin>>t;
    while(t--)
    {
        int n; cin>>n;
        int A[MAXN],B[MAXN],C[MAXN];
        for(int i = 0; i< n; i++)
            cin>>A[i]>>B[i]>>C[i];

        nth_element(A,A+n/2, A+n);
        nth_element(B,B+n/2, B+n);
        nth_element(C,C+n/2, C+n);
        cout<<A[n/2]<<" "<<B[n/2]<<" "<<C[n/2]<<endl;
    }
    return 0;
}
