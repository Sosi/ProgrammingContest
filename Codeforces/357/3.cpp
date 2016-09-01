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
    priority_queue<int, std::vector<int>, std::less<int>> Q;
    int n; cin>>n;
    vector<string> ret;
    string s; int p;
    for(int i= 0; i< n; i++)
    {
        cin>>s;
        if(s == "insert")
        {
            cin>>p;
            Q.push(p);
            ostringstream is;
            is<<s;
            is<<" ";
            is<<p;
            ret.push_back(is.str());
        }
        if(s == "removeMin")
        {
            if(Q.empty())
            {
                ret.push_back("insert -1000000000");
            }else
                Q.pop();
            ret.push_back("removeMin");
        }

        if(s == "getMin")
        {
            cin>>p;
            while(!Q.empty() && Q.top() < p)
            {
                ret.push_back("removeMin");
                Q.pop();
            }
            if(Q.empty() || Q.top() > p)
            {
                stringstream is;
                is<<"insert";
                is<<" "; is<<p;
                ret.push_back(is.str());
                Q.push(p);
            }
            {
                stringstream is;
                is<<"getMin";
                is<<" "; is<<p;
                ret.push_back(is.str());
            }
        }
    }
    cout<<ret.size()<<endl;
    for(int i = 0; i< ret.size(); i++)
        cout<<ret[i]<<endl;



    return 0;
}
