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

/*
PROBLEM:
Given a bracket sequence, print the length of largest prefix that is a regular bracket sequence.

EXPLANATION:
A regular bracket sequence is defined as follows:
1. S="" is regular.
2. S="<" + S1 ">" is regular, if S1 is regular.
3. S=S1 concat S2 is regular, is S1 and S2 are regular.

If S is regular bracket sequence, for any i, number of closing brackets in S[0,i] should not exceed number of opening brackets. Also, if number of opening brackets is equal to number of closing brackets in S[0,i], S[0,i] is a regular bracket sequence.

def check(s):
     t=0,ans=0
     for i=0 to N-1:
          if s[i]=='<': t++;
          else:
               t--;
               //Now, if t=0, means, the string s[0,i] is valid.
               if t==0: ans=max(ans,i+1)
               else if t<0: break   //string s whole is invalid.
     print ans
Complexity: O(N).

*/

int check(string s)
{
    int t = 0; int ans = 0;
    for(int i=0; i<s.size(); i++)
    {
        if(s[i] == '<') t++;
        else
        {
            t--;
            if(t == 0) ans = max(ans, i+1);
            else if(t<0) break;
        }
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
//    freopen("1.txt","r",stdin);
    int T; cin>>T;
    for(int cas = 1; cas<=T; cas++)
    {
        string x; cin>>x;
//        cout<<x<<endl;
        stack < pair<char,int> > s;
        int ok = true;
        pair<char,int > start = make_pair('<', 0);
        int ret = 0;
        for(int i=0; i<x.size(); i++)
        {
            if(x[i] == '<')
            {
                if(s.empty())
                {
                    start = make_pair('<', i);
                }
                s.push(make_pair('<',i));
            }
            else if(x[i] == '>')
            {
                if(s.empty())
                {
                    ok = false;
                    //cout<<i<<endl;
                    break;
                }else
                {
                    pair<char,int> x = s.top();
                    if(x == start) ret = i+1;
                    s.pop();
                }
            }
        }
        cout<<ret<<endl;
//        cout<<"nas "<<check(x)<<endl;
//        if(ok) cout<<x.size() - s.size() - add<<endl;
    }
    return 0;
}
