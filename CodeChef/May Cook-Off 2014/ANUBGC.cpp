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

// n 的最高位数字和n的位数
pair<int,int> num_of_bits(long long n)
{
    int k = 0; //初始为0位
    long long ret = 1LL;
    for(long long m = n; m > 0; m /=10)
    {
        k++; ret *=10LL;
    }
    return make_pair(n/(ret/10LL), k);
}

// x*10^y
long long pow10(int x, int y)
{
    long long ret = x;
    for(int i=0; i<y; i++)
    {
        ret *=10LL;
    }
    return ret;
}

//  x个 y位000000 存在某个数的个数
long long all0(int x, int y)
{
    int ret = 1LL;
    for(int i=0; i<y; i++)
        ret *= 9LL;
    return (pow10(1,y) - ret) * x;
}
// from 0-N the number of occuring x
long long num(long long N, int x)
{
//    cout<<"--- "<<N<<" "<<x<<endl;
    if(N < 10)
    {
        if( N>=x) return 1LL;
        return 0LL;
    }
    pair<int,int> t = num_of_bits(N);
//    if(x == 0)
//        return all0( t.first ,t.second-1);
    if(t.first == x)
    {
        cout<<" ?? "<<endl;
        return 1LL + N - t.first * pow10(t.first , t.second -1)  + all0(t.first, t.second - 1);
    }else if(t.first < x){
//        cout<<" ? "<<t.first<<" "<<t.second - 1<<" "<<pow10(t.first, t.second - 1)<<endl;
//        cout<<" ? " <<N - pow10(t.first, t.second-1)<<" "<<all0(t.first, t.second-1)<<endl;
        return num(N - pow10(t.first, t.second-1), x) + all0(t.first, t.second-1);
    }else
    {
        cout<<" ??? "<<endl;
        return num(N - pow(t.first, t.second - 1), x) + all0( t.first - 1 , t.second - 1) + pow10(1, t.second - 1);
        // t.first > x
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    freopen("1.txt","r",stdin);
    int T; cin>>T;
    long long N;

    for(int cas = 1; cas<=T; cas++)
    {
        cin>>N;
        cout<<N<<endl;
        long long ret = 0LL;
        for(int i=0; i<=9; i++)
        {
            long long p= num(N, i);
            cout<<"occ "<<i<<" "<<p<<endl;
            ret += p;
        }

        long long g_ = gcd(ret-1, 10*N);
        cout<<"res "<<(ret-1)/g_<<"/"<<10*N/g_<<endl;
    }
    cout<<"t"<<endl;
//    cout<<pow10(2,2);
    pair<int,int> a = num_of_bits(10);
    cout<<a.first<<" "<<a.second<<endl;
    cout<<all0(2, 3)<<endl;

    return 0;
}
