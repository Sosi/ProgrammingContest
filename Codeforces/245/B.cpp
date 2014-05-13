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

int main()
{
    ios_base::sync_with_stdio(0);
//    freopen("1.txt","r",stdin);
    int n,k,x;
    cin>>n>>k>>x;
    vector<int> p(n);
    for(int i=0; i<n; i++) cin>>p[i];

    int ret = 0;
    for(int pos = 1; pos< n; pos++)
    {
        int color = x;
        int i= pos-1;
        int j = pos;
        int num = 0;
//        int tmp = 1;
        while(1)
        {
            int tmp = 1;
            while(i>=0 && p[i] == color)
            {
                tmp++;
                i--;
            }
            while(j<n && p[j] == color)
            {
                j++;
                tmp++;
            }
//            cout<<"!" <<pos<<" "<<i<<" "<<j<<" color "<<color<<endl;
            if(tmp >= 3)
            {
                num+= tmp;
                if(i<0 || j>=n) break;
                else
                {
                    color = p[i];
                    i--;
                }
            }
            else break;
        }
//        cout<<"pos "<<pos<<" "<<num<<endl;
        ret = max(ret, num);
    }
    if(ret > 0) cout<<ret-1<<endl;
    else cout<<0<<endl;
//    cout<<ret-1<<endl;

    return 0;
}
