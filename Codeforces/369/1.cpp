#include <bits/stdc++.h>
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

int main()
{
    ios_base::sync_with_stdio(0);
//    freopen("1.txt","r",stdin);


    int n; cin>>n;

    vector<string> v(n,"");
    for(int i = 0; i< n; i++)
    {
        cin>>v[i];
//        cout<<v[i]<<endl;
    }
    int ret = 0;
    for(int i = 0; i< n; i++)
    {
        if(v[i][0] == 'O' && v[i][1] == 'O')
        {
            ret = 1;
            v[i][0] = '+'; v[i][1] = '+';
            break;
        }

        if(v[i][3] == 'O' && v[i][4] == 'O')
        {
            ret = 1;
            v[i][3] = '+'; v[i][4] = '+';
            break;
        }
    }

    if(ret)
    {
        cout<<"YES"<<endl;
        for(int i = 0; i< n; i++)
            cout<<v[i]<<endl;
    }else
    cout<<"NO"<<endl;

    return 0;
}
