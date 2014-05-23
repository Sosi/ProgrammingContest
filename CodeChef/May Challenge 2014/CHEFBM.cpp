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

int n,m,p;
// 3 2 2
int process(vector<pair<int,int> > tmp)
{
//    cout<<"proces "<<endl;
    if(tmp.size() == 0) return m-1;
    int beginh = 0;
    for(int i= tmp.size()-1; i>=0; i--)
    {
        if(tmp[i].second == 0) beginh ++;
        else break;
    }
    int endh = 0;
    for(int i = 0; i<tmp.size(); i++)
    {
        if(tmp[i].second == m-1)
        {
            endh++;
        }
        else break;
    }
    vector<pair<int,int> > y;
    y.push_back(make_pair(m-1, endh));
    int h = 0; int curidx = m-1;
    for(int i=endh; i<tmp.size(); i++)
    {
        if(tmp[i].second == curidx)
        {
            h++;
        }else
        {
            if(h != 0)
                y.push_back(make_pair(curidx,h));
            curidx = tmp[i].second;
            h=1;
        }
    }
    y.push_back(make_pair(curidx, h));
//
//    cout<<"TMP "<<endl;
//    for(int i=0; i<tmp.size(); i++) cout<<tmp[i].second<<" "; cout<<endl;
//    for(int i=0; i<y.size(); i++) cout<<y[i].first<<" "<<y[i].second<<"! "; cout<<endl;
    for(int i = 1; i<y.size(); i++)
    {
        if(y[i].first == y[i-1].first -1 )
        {
            if(y[i].first + y[i].second > y[i-1].first +y[i-1].second)
                return -1;
        }
        else{
            if(y[i].second > 1) return -1;
        }
    }

    return m-1 + endh - beginh;
}

int main()
{
    ios_base::sync_with_stdio(0);
//    freopen("1.txt","r",stdin);
    cin>>n>>m>>p;
    vector<pair<int,int> > x(p);
    for(int i=0; i<p; i++)
    {
        cin>>x[i].first>>x[i].second;
        x[i].first --;
        x[i].second --;
    }
    sort(x.begin(), x.end());
    vector<int> height(n);
    fill(height.begin(), height.end(), m-1);
//    for(int i=0; i<x.size(); i++)
//        cout<<x[i].first<<" "<<x[i].second<<endl;
    int currow = n-1;
//    int curcol = m-1; int preh = m-1; int curh = m-1;
//    int endh = m-1; int beginh = 0;
    vector<pair<int,int> > tmp;
    for(int i=x.size()-1; i>=0; i--)
    {
//        cout<<x[i].first<<" "<<endl;
        if(x[i].first == currow)
        {
            tmp.push_back(x[i]);
        }
        else
        {
            // process currow
            height[currow] = process(tmp);
            tmp.clear();
            tmp.push_back(x[i]);
            currow = x[i].first;
        }
    }
    if(tmp.size() !=0) height[currow] = process(tmp);

    for(int i=0; i<n; i++) cout<<height[i]<<endl;
    return 0;
}
