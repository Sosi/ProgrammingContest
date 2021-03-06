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
//long long max_elementn(vector<long long> A)
//{
//    cout<<"?!"<<endl;
//    long long ret = A[0];
//    for(int i=1; i<A.size(); i++)
//        ret = max(ret, A[i]);
//    cout<<"?!"<<endl;
//    return ret;
//}
int main()
{
    ios_base::sync_with_stdio(0);
//    freopen("1.txt","r",stdin);
    long long N,K; cin>>N>>K;
    vector<long long>A(N);
    for(int i=0; i<N; i++) cin>>A[i];
//    cout<<"?"<<endl;
//    for(int i=0; i<N; i++) cout<<A[i]<<" ";
    vector<long long> B(A);
    long long max_a = *std::max_element(A.begin(), A.end());
//    cout<<"?"<<endl;
    for(int i=0; i<N; i++) B[i] = max_a - A[i];
//    cout<<"?"<<endl;
    vector<long long >C(B);
    long long  max_b = *std::max_element(B.begin(), B.end());
    for(int i=0; i<N; i++) C[i] = max_b - B[i];
    vector<long long >D(C);
    long long max_c = *std::max_element(C.begin(), C.end());
    for(int i=0; i<N; i++) D[i] = max_c -C[i];
    if(K == 0)
    {
        for(int i=0; i<N; i++)
            cout<<A[i]<<" ";
        cout<<endl;
    }else if(K == 1)
    {
        for(int i=0; i<N; i++)
            cout<<B[i]<<" ";
        cout<<endl;
    }else if(K %2LL == 0)
    {
        for(int i=0; i<N; i++)
            cout<<C[i]<<" ";
        cout<<endl;
    }else
    {
        for(int i=0; i<N; i++)
            cout<<D[i]<<" ";
        cout<<endl;
    }
    return 0;
}
